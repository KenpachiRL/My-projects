#Code written by Greater

import requests #make sure the request package is installed in your system
import sys
def loop():
    for word in sys.stdin: #this reads the command line e.g. the output coming from "cat small.txt"
        res = requests.get(url=f"http://10.10.11.161/{word}") #a HTTTP get request is sent to this url
        if res.status_code == 404:
            loop()
        else:
            data = res.json()   #this provides the json of the url thats stored in the variable "RES"
            print(data)     #prints json
            print(res.status_code)  #prints the status code e.g. 200
            print(word)     #prints the word
loop()  #initiate the function
