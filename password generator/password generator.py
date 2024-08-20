#Password generator code written by Greater

import random       #used to pick a random character
import string       #used to automatically generate letters, digits and punctuation

def passGenerator(length):          #this is the function that generates the random password
    alphabet = string.ascii_letters + string.digits + string.punctuation    #the characters are stored in this variable
    password = ''.join(random.choice(alphabet) for i in range(length))      #this is where the characters stored in the variable alphabet are randomized
    return password     #You need this, otherwise the password variable cant be used outside of this function


print(f"Welcome to my password generator")
length_choice = int(input(f"How long do you want the password to be? "))        #the user can choice how long they want their password to be

password = passGenerator(length_choice)     #this calls the functioon passGenerator and it stores the return password into this new variable also called password

print(f"Since your preferred length was {length_choice} The password generated is {password} \n Thanks for running this code created by Greater" ) #this shows you what the generated password is

input("Press Enter to exit...")