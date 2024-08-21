<h1>Api Fuzzer</h1>


<h2>Key Terminologies used in this project</h2>
API: An API is a set of rules and protocols that allow different applications to communicate with each other <br>
Fuzzing: This is a testing technique that involves sending random inputs to an endpoint to see how the application reacts <br>
Endpoint: This could be a URL or even a form <br>
JSON is a format for representing data, in a way that's readable for Humans and Machines <br>

<h2>The Purpose of my code:</h2>
The purpose of my code is to find the list of possible paths to a URL and to return a JSON if the URL exists. The security team can analyze this JSON reply further to make sure it doesn't contain sensitive information.


<br />


<h2>Languages and Utilities Used</h2>

- <b>Python</b> 

<h2>Environments Used </h2>

- <b>Kali linux</b> 

<h2>Code walk-through:</h2>

<p>
  My script sends an HTTP GET request to the target IP address, using each word in small.txt. If the response status is "200 ok" then the JSON for that URL is printed. If a 404 status code is received, the script loops and continues processing the next word
</p>

<h2>How to run my code:</h2>
<p>
1) install python-nmap by using the command "sudo pip install python-nmap" 
make sure you use sudo otherwise, my code won't recognize that Nmap was installed<br>
2) the code I invented will run from port 1 to 200 but if you want to change the port range then edit the file and change the range values in line 18 and line 24<br>
3) After completing the above stages, type "sudo python3 Portscanner.py" to run the script<br>

</p>

<h2> What I learned: </h2>
<p>I learned how .key work. For example if I run the python command: <br>

udp_ports = nm['192.168.1.1']['udp'] <br>
print(udp_ports) <br>


then the output will look something like this: <br>

{ <br>
    53: { <br>
        'protocol': 'udp', <br>
        'name': 'domain', <br>
        'state': 'open' <br> 
    }, <br>
    67: { <br>
        'protocol': 'udp', <br>
        'name': 'dhcps', <br>
        'state': 'open' <br>
    } <br>
} <br>




So when I type print(udp_ports.key), the function .key will take all the values on the left side of the colon . e.g. 53, 67 etc. <br>

but if I run the command I will get dict_key[53, 67] , so to fix this issue and make the output "prettier", run the command print(list(udp_ports.key))</p> 
