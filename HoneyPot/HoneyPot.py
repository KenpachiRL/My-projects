#
#Code written by Greater
#

import socket
import threading

#server configuration
host = '192.168.232.135'  # the ip address of the server
port = 222  # specifies the listening port, in this case i choose port 22 to simulate ssh
listener = socket.socket(socket.AF_INET,socket.SOCK_STREAM)  # the first argument in the class, specifies that my code uses ipv4 and the second argument specifies that the connection being used is tcp
file_list = "Desktop Documents Downloads " # this will be used when the attacker types ls


#the auth_user function handles the username authentication
def auth_user(c):
    for i in range(0, 3):  # you have 3 attempts to guess the right password
        c.sendall(b'Username: ')
        username = c.recv(1024).decode('utf-8').strip()
        prompt = "The user typed this as username: "
        log_input(prompt, username)
        if username != 'root':
            c.sendall(b'invalid username \n')
        else:
            auth_pass(c)
    c.close()
#the auth_pass function handles the password authentication
def auth_pass(c):
    for i in range(0,3): #you have 3 attempts to guess the right password
        c.sendall(bytes('Password: ', 'utf-8'))
        password = c.recv(1024).decode('utf-8').strip()   #this strip is important because it sanitizes my user input because maybe input has been passed with other random characters like \n
        prompt = "The user typed this as password: "
        log_input(prompt, password)
        if password == 'admin':
            c.sendall(bytes('Kali GNU/Linux Rolling\n','utf-8'))  # this uses the object 'bytes', and utf-8 is the encoding format.
            c.sendall(bytes('(', 'utf-8'))
            c.sendall(bytes(host, 'utf-8'))  # host represents the hostname/ip adrress of the server
            c.sendall(bytes(') :anonymous\n', 'utf-8'))
            cmd(c)
        else:
            i += 1
    c.sendall(bytes('Authentication failed. Goodbye.\n', 'utf-8'))
    c.close()

def cmd(c):
    while True: # loops forever
        c.sendall(b"Root-telnet:~$ ")
        command = c.recv(1024).decode('utf-8').strip()  #this strip is important because it sanitizes my user input
        prompt = "The user typed this as command: "
        log_input(prompt, command)
        if command == 'ls':
            c.sendall(file_list.encode('utf-8') +(b'\n') )
        elif command == 'whoami':
            c.sendall(b'Root\n')
        elif command == 'cd Desktop' or command == 'cd Desktop/':
            dir_desktop(c)
        elif command == 'cd Downloads' or command == 'cd Downloads/':
            dir_download(c)
        elif command == 'cd Documents' or command == 'cd Documents/':
            dir_document(c)
        elif command == 'help': #i should remove this line in case i use this code for real scenarios
            c.sendall(b'The available commands are:ls, cat, cd, whoami')
        else:
            c.sendall(b"Command not found\n")


#the function dir_desktop is used for when the user types 'cd Desktop/'
def dir_desktop(c):
    while True:  # loops forever
        c.sendall(b"Root-telnet:~/Desktop$ ")
        command = c.recv(1024).decode('utf-8').strip()  # this strip is important because it sanitizes my user input
        prompt = "The user typed this as command while being in the desktop directory: "
        log_input(prompt, command)
        print(f"Received command: {command}")
        if command == 'ls':
            c.sendall(b"Password.txt \n")
        elif command == 'cd ..':
            cmd(c)
        elif command == 'cat Password.txt':
            c.sendall(b"5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8 \n")   #this is the hash digest of the string 'password' i used sha256( so 32 bytes)
        elif command == 'whoami':
            c.sendall(b'Root \n')
        elif command == 'help': #i should remove this line in case i use this code for real scenarios
            c.sendall(b'The available commands are:ls, cat, cd, whoami\n')
        else:
            c.sendall(b"Command not found \n")

#the function dir_download is used for when the user types 'cd Downloads/'
def dir_download(c):
    while True:  # loops forever
        c.sendall(b"Root-telnet:~/Downloads$ ")
        command = c.recv(1024).decode('utf-8').strip()  # this strip is important because it sanitizes my user input
        prompt = "The user typed this as command while being in the downloads directory: "
        log_input(prompt, command)
        if command == 'ls':
            c.sendall(b"User.txt work.doc \n")
        elif command == 'cd ..':
            cmd(c)
        elif command == 'cat User.txt':
            c.sendall(b'Thanks for running this code written by Greater\n')
        elif command == 'cat work.doc':
            c.sendall(b'Reminder: There will be a meeting at 13:00\n')
        elif command == 'whoami':
            c.sendall(b'Root \n')
        elif command == 'help': #i should remove this line in case i use this code for real scenarios
            c.sendall(b'The available commands are:ls, cat, cd, whoami')
        else:
            c.sendall(b"Command not found \n")

#the function dir_document is used for when the user types 'cd Documents/'
def dir_document(c):
    while True:  # loops forever
        c.sendall(b"Root-telnet:~/Documents$ ")
        command = c.recv(1024).decode('utf-8').strip()  # this strip is important because it sanitizes my user input
        prompt = "The user typed this as command while being in the documents directory: "
        log_input(prompt, command)
        if command == 'ls':
            c.sendall(b"info.doc \n")
        elif command == 'cd ..':
            cmd(c)
        elif command == 'cat info.doc':
            c.sendall(b'This is a honeypot written by Greater\n')
        elif command == 'whoami':
            c.sendall(b'Root\n')
        elif command == 'help': #i should remove this line in case i use this code for real scenarios
            c.sendall(b'The available commands are:ls, cat, cd, whoami\n')
        else:
            c.sendall(b"Command not found\n")

#The log_input funtion is used to open the log file and write in it
def log_input(prompt, user_input):
    f = open("Honeypot_log.txt", "a") #this opens the log file in which all user input will be typed in
    f.write(prompt + str(user_input) + "\n")    #this will take a prompt such as "the user input was: " and then user_input is what the user inputted
    f.close() #This closes the file because if is left open it can cause resource exaustion

# Server startup
def start_server():
    listener.bind((host, port)) #this lets the code know on what ip address and port he has to listen
    listener.listen(5) #This starts the listening process and i set the limit to 5 maximum number(so 5 people can connect)

    print(f"Listening on {host}:{port}...")

    while True:     #this will loop infinitely
        connection = listener.accept()
        c = connection[0] #this is used to send and receive a message from the client
        addr = connection[1]    #contains the ip address
        prompt = "The Ip address of the connecting device is: "
        log_input(prompt, addr)
        print(f"Connection from {addr}")

        auth_user(c)



start_server()
# Accept a connection from a client
