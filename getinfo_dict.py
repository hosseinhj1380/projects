
from tarfile import REGTYPE


name=input('enter name1:')
age=int(input('enter age1: '))
address=input("enter address1:")
ave=float(input('enter average1:'))
first_dict={
    'name': name,
    'age': age,
    'address': address,
    'average': ave 
}

name=input('enter name2:')
age=int (input('enter age2: '))
address=input("enter address2:")
ave=float(input('enter average2:'))
second_dict={
    'name': name,
    'age': age,
    'address': address,
    'average': ave 
}

name=input('enter name3:')
age=int (input('enter age3: '))
address=input("enter address3:")
ave=float(input('enter average3:'))
third_dict={
    'name': name,
    'age': age,
    'address': address,
    'average': ave 
}
# ///////////////////////////////////////////////////////

if (first_dict['age']>second_dict['age']):
    if (first_dict['age']>third_dict['age']):
       name=first_dict['name']
       res=first_dict['age']
    else:
        name=third_dict['name']
        res=third_dict['age']
   
elif (second_dict['age']  > third_dict['age']):
    name=second_dict['name']
    
    res=second_dict['age']
else :
    name=third_dict['name']
    
    res=third_dict['age']
    
print('\n \n oldest people is :',name,"and",res,'years old ')
# /////////////////////////////////////////////////////////

var=input('\nplease write person number to take address :')
if var=='1':
    print(first_dict['address'])
elif var=='2':
    print(second_dict['address'])
elif var=='3':
    print(third_dict['address'])
    
# //////////////////////////////////////////////////////
var=input('\nplease write person number to take info :')
if var=='1':
    print(first_dict)
elif var=='2':
    print(second_dict)
elif var=='3':
    print(third_dict)