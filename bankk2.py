from tabulate import tabulate
import os
from random import randint, random
from time import sleep
from turtle import color 
import mysql.connector

# *****************************************************************

class my_sql_connect(object):
    def __init__(self):
        self.mydb=mysql.connector.connect(
            host='localhost',
            user="root",
            password="",
            database='mybank'
        )
        self.mycursor=self.mydb.cursor()   
    
    def show_info_sql(self,nationalidsql):
        self.mycursor.execute("SELECT * FROM info WHERE nationalid =%s",(nationalidsql,))
        myresultsql=self.mycursor.fetchall()
        return(myresultsql)  
    
    def show_info_accountnumber_sql(self,accountbumbersql): 
        self.mycursor.execute("SELECT * FROM info WHERE accountnumber =%s",(accountbumbersql,))
        myresultsql=self.mycursor.fetchall()
        return(myresultsql)
         
    def insert_account_sql(self,fnamesql,lnamesql,nationalidsql,fathernamesql,phonenumbersql,creditsql,accountnumbersql):
        self.mycursor.execute("INSERT INTO info (firstname , lastname,nationalid,fathername,phonenumber,credit,accountnumber) VALUES (%s,%s,%s,%s,%s,%s,%s)",(fnamesql,lnamesql,nationalidsql,fathernamesql,phonenumbersql,creditsql,accountnumbersql))
        self.mydb.commit()
    
    def check_account_num_sql(self,accountnumbersql,nationalidsql):
        self.mycursor.execute('SELECT nationalid FROM info where accountnumber= %s',(accountnumbersql,))
        res=self.mycursor.fetchall()
        os.system('cls')
        self.mycursor.execute("SELECT COUNT('nationalid')")
        number_of_rows=self.mycursor.fetchall()
        if number_of_rows!=0:
            res=int(res[0][0])
        else:
             os.system("cls")
             os.system('color 4')
             return ('''\n\n\n\n\n                  !!!!!!!!!!!!!!!!!!  WRONG INPUT  !!!!!!!!!!!!!!!!! 
                        
                    \n\n Enter to back menu ''')
             
        if res==nationalidsql :
            return(f'                \n\n\n ARE YOU SURE TO OPERATION ON ACCOUNTNUMBER : ({accountnumbersql})       y/n ?')
     
    def delete_commit_sql(self,accountnumbersql):
        self.mycursor.execute("DELETE FROM info WHERE accountnumber= %s",(accountnumbersql,))
        self.mydb.commit() 
    
    def deposit_sql(self,accountnumbersql,moneysql):
        self.mycursor.execute('SELECT credit FROM info WHERE accountnumber= %s',(accountnumbersql,))
        myresult=self.mycursor.fetchall()
        myresult=int(myresult[0][0])
        myresult=myresult+moneysql
        self.mycursor.execute('UPDATE  info SET credit=%s WHERE accountnumber=%s',(myresult,accountnumbersql))
        self.mydb.commit()    
        return('\n\n\n\n\n                              <--------------- DEPOSIT OPERATION DONE SUCCESSFULY ------------->                        ')

    def receive_sql(self,accountnumbersql,moneysql):
        self.mycursor.execute('SELECT credit FROM info WHERE accountnumber= %s',(accountnumbersql,))
        myresult=self.mycursor.fetchall()
        myresult=int(myresult[0][0])
        myresult=myresult-moneysql
        if myresult>=0:    
            self.mycursor.execute('UPDATE  info SET credit=%s WHERE accountnumber=%s',(myresult,accountnumbersql))
            self.mydb.commit()
            os.system('color a')
            return('\n\n\n\n\n                              <--------------- RECEIVE OPERATION DONE SUCCESSFULY ------------->                        ')
        else:
            os.system('color 4')
            return('\n\n\n\n\n                   <--------------- The amount entered is more than the account balance ---------------->')
    
    def client_credit(self):
        self.mycursor.execute("SELECT * FROM info ORDER BY credit")
        myresult=self.mycursor.fetchall()
        os.system('cls')
        return((tabulate(myresult, headers=['firstname', 'lastname','nationalid','fathername','phonenumber','credit','accountnumber'], tablefmt='grid')))
# *****************************************************************

class new_account(my_sql_connect):
    def __init__(self,fname,lname,nationalid,fathername,phonenumber,credit):
        self.fname=fname
        self.lname=lname
        self.nationalid=nationalid
        self.fathername=fathername
        self.phonenumber=phonenumber
        self.credit=credit
        my_sql_connect.__init__(self)
    def make_account(self):
        self.accountnumber=randint(1110000000000,1119999999999)
        self.insert_account_sql (fnamesql=self.fname,lnamesql=self.lname,nationalidsql=self.nationalid,fathernamesql=self.fathername,phonenumbersql=self.phonenumber,creditsql=self.credit,accountnumbersql=self.accountnumber)
        os.system('cls')
        return ('\n\n                            <------------------  INSERT SUCCESSFULY  -------------------->        ')
# *****************************************************************
    
class delete_account(my_sql_connect):
    def __init__(self,accountnumber,nationalid):
        self.accountnumber=accountnumber
        self.nationalid=nationalid   
        my_sql_connect.__init__(self)   
    
    def delete_commit(self):
        self.delete_commit_sql(accountnumbersql=self.accountnumber)
        os.system("cls")
        os.system("color a")
        return(f'\n\n\n\n\n                < -----------ACCOUNT NUMBER {self.accountnumber} SUCCESSFULY CLOSED ------------ >')
# *****************************************************************

class show_info(my_sql_connect):
    def __init__(self,nationalid,accountnumber=None):
        self.nationalid=nationalid
        self.accountnumber=accountnumber
        my_sql_connect.__init__(self)
        
    def sh_info(self):
        myres=self.show_info_sql(nationalidsql=self.nationalid)
        return((tabulate(myres, headers=['firstname', 'lastname','nationalid','fathername','phonenumber','credit','accountnumber'], tablefmt='grid')))
    
    def sh_info_account(self):
        os.system('cls')
        myres=self.show_info_accountnumber_sql(accountbumbersql=self.accountnumber)
        return((tabulate(myres, headers=['firstname', 'lastname','nationalid','fathername','phonenumber','credit','accountnumber'], tablefmt='grid')))
# *****************************************************************

class deposit_money(my_sql_connect):
    def __init__(self,nationalid,accountnumber,money):
        self.nationalid=nationalid
        self.accountnumber=accountnumber
        self.money=money
        my_sql_connect.__init__(self)
    def deposit(self):
        os.system('color a')
        return(self.deposit_sql(accountnumbersql=self.accountnumber,moneysql=self.money))
# *****************************************************************

class receive_payment(delete_account):
    def __init__(self,nationalid,accountnumber,money):
        self.money=money
        self.accountnumber=accountnumber
        self.nationalid=nationalid
        my_sql_connect.__init__(self) 
    def   receive(self):
        return(self.receive_sql(accountnumber=self.accountnumber,money=self.money))
# *****************************************************************

class transfer_money(my_sql_connect):
    def __init__(self, accountnumber01,nationalid01,accountnumber02,money0):
        self.accountnumber01=accountnumber01
        self.nationalid01=nationalid01
        self.accountnumber02=accountnumber02
        self.money0=money0
        # receive_payment.__init__(self,nationalid=self.nationalid01,accountnumber=self.accountnumber01,money=self.money0)
        # deposit_money.__init__(self,accountnumber=self.accountnumber02, nationalid=None,money=self.money0)
        my_sql_connect.__init__(self)
# *****************************************************************
        
class bank_value(my_sql_connect):
    def __init__(self):
        my_sql_connect.__init__(self)
# *****************************************************************
     
     
     
     
     
        
    
def greeting_show():
    os.system('cls')
    os.system('color f')
    print('''
                  =============================================================================
                    
                  ****************************   BANK  ****************************************
                  *************************** ACCOUNTING **************************************
                  *************************** MANAGEMENT ************************************** 
                  ****************************  SYSTEM ****************************************
                  
                  =============================================================================
                                            
                                            CHOOSE YOUR OPTION
                                            
                                           +++++++++++++++++++++++
                                            1)  CREATE NEW ACCOUNT 
                                         +++++++++++++++++++++++++++
                                            2)  CLOSE THE ACCOUNT
                                       +++++++++++++++++++++++++++++++
                                            3)  DEPOSIT MONEY    
                                     +++++++++++++++++++++++++++++++++++
                                            4)  RECEIVE PAYMENT
                                   +++++++++++++++++++++++++++++++++++++++                
                                            5)  TRANSFER MONEY           
                                 +++++++++++++++++++++++++++++++++++++++++++ 
                                            6)  SHOW ACCOUNT INFORMATION               
                               +++++++++++++++++++++++++++++++++++++++++++++++
                                            7)  SHOW  BANK VALUE 
                             +++++++++++++++++++++++++++++++++++++++++++++++++++        
                                    
                    exit(e)
    ''')
    i=input()
    if i=='1':
        os.system('cls')
        fname1=input('please write firstname :')
        lname1=input('please write laastname :')
        fathername1=input('please write fathername :' )
        nationalid1=input('please write nationalid :' )
        phonenumber1=input('please write phonenumber :' )
        credit1=int(input('enter the first account credit : '))
        nw1=new_account(fname=fname1,lname=lname1,fathername=fathername1,nationalid=nationalid1,phonenumber=phonenumber1,credit=credit1)
        os.system('cls')
        os.system('color a')
        print(nw1.make_account())
        sh1=show_info(nationalid=nationalid1)
        os.system('color f')
        print(sh1.sh_info())
        ch=input('\n\n  press any key to back menu : ')
        if bool(ch)==0 or bool(ch)==1:
            greeting_show()
# *****************************************************************
    elif i=='2': 
        os.system("cls")
        nationalid2=int(input('please write nationalid to show accounts :'))
        nw2=show_info(nationalid=nationalid2)
        os.system('cls')
        print(nw2.sh_info())
        accountnumber2=input('please write which account you want to close : ')
        nw2_1=delete_account(accountnumber=accountnumber2,nationalid=nationalid2)    
        os.system("cls")    
        print (nw2_1.check_account_num_sql(accountnumbersql=accountnumber2,nationalidsql=nationalid2))
        s=input()
        if s=='y' :
            print( nw2_1.delete_commit())
            
            ch=input('\n\n press any key to back menu : ')
            if bool(ch)==0 or bool(ch)==1:
    
                greeting_show()
        else:
            greeting_show()
# *****************************************************************
    elif i=='3':
        os.system('cls')
        nationalid3=int(input('please write nationalid to show accounts :'))
        os.system('cls')
        nwd=show_info(nationalid=nationalid3)
        print(nwd.sh_info())
        accountnumber3=input('please write which account you want to deposit money  : ')
        money3=int(input('how much do you want to deposit on account :'))
        nwdm=deposit_money(nationalid=nationalid3,accountnumber=accountnumber3,money=money3)
        # print(nwdm.deposit())
        print(nwdm.check_account_num_sql(accountnumbersql=accountnumber3,nationalidsql=nationalid3))
        s=input()
        if s=='y' :
            os.system('cls')
            os.system('color a')
            print(nwdm.deposit())
            ch=input('\n\n press any key to back menu : ')
            if bool(ch)==0 or bool(ch)==1: 
                greeting_show()
        else:
            greeting_show()
# *****************************************************************
    elif i=='4':
        os.system('cls')
        nationalid4=int(input('please write nationalid to show accounts :'))
        os.system('cls')
        nw4=show_info(nationalid=nationalid4)
        print(nw4.sh_info())
        accountnumber4=input('please write which account you want to  receive payment  : ')
        money4=int(input('how much do you want to receive from account :'))
        nw4_1=receive_payment(nationalid=nationalid4,accountnumber=accountnumber4,money=money4)
        print(nw4_1.check_account_num_sql(accountnumbersql=accountnumber4,nationalidsql=nationalid4))
        s=input()
        if s=='y' :
            os.system('cls')
            print(nw4_1.receive())
            ch=input('\n\n press any key to back menu : ')
            if bool(ch)==0 or bool(ch)==1: 
                greeting_show()
        else:
            greeting_show()
# *****************************************************************
    elif i=='5':
        
        os.system('cls')
        nationalid5=int(input('please write nationalid to show accounts :'))
        os.system('cls')
        nw5=show_info(nationalid=nationalid5)
        print(nw5.sh_info())
        accountnumber5=input('please write which account you want to  receive payment  : ')
        money5=int(input('how much do you want to transfer from  this account :'))
        accountnumber5_2=input('please write destination account number : ')
        os.system('cls')
        tr2=show_info(nationalid=None,accountnumber=accountnumber5_2)
        c1=input(f'''{tr2.sh_info_account()}\n\n\nare you sure to transfer money to this account   y/n ?''')
        if c1=='y':
            # trm=delete_account()
            tr1=transfer_money(nationalid01=nationalid5,accountnumber01=accountnumber5,money0=money5,accountnumber02=accountnumber5_2)
            os.system('cls')
            s=input(tr1.check_account_num_sql(accountnumbersql=accountnumber5,nationalidsql=nationalid5))
            if s=='y' :
                os.system('cls')
                print(tr1.receive_sql(accountnumbersql=accountnumber5,moneysql=money5))
                print(tr1.deposit_sql(accountnumbersql=accountnumber5_2,moneysql=money5))
                 
                ch=input('\n\n press any key to back menu : ')
                if bool(ch)==0 or bool(ch)==1: 
                    greeting_show()
            else:
                greeting_show()
        else:
            greeting_show()    
# *****************************************************************
    elif i=='6':
        os.system("cls")
        nationalid6=input('please write the nationalid : ')
        os.system('cls')
        nw1=show_info(nationalid=nationalid6)
        os.system("cls")
        print(nw1.sh_info())
        ch=input('press any key  to back menu : ')
        if bool(ch)==0 or bool(ch)==1:
            greeting_show()
# *****************************************************************
    elif i=='7':
        # user=input('please write username : ')
        # password=input('please write password :')
        bv=bank_value()
        print(bv.client_credit())
        ch=input('\n\npress any key  to back menu : ')
        if bool(ch)==0 or bool(ch)==1:
            greeting_show()
# *****************************************************************
    elif i=='e':
        os.system('cls')
        print('\n\n\n\n\n                              < ------------------  GOODBYE  -------------------- >       ')
        sleep(2)
        os.system('cls')
        exit(0)
# *****************************************************************
    else:
        os.system('cls')
        os.system('color 4')
        print("\n\n\n\n\n                               !!!!!!!!!!!!!!!!!!  WRONG INPUT  !!!!!!!!!!!!!!!! ")
        sleep(1)
        
        greeting_show()
# *****************************************************************

        
greeting_show()
