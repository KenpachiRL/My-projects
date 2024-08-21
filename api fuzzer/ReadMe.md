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
Open fuzz.py and in line 5, Replace the URL with anything of your choice e.g. "http://google.com/" then type in your terminal the following code: cat small.txt| python3 fuzz.py

</p>






So when I type print(udp_ports.key), the function .key will take all the values on the left side of the colon . e.g. 53, 67 etc. <br>

but if I run the command I will get dict_key[53, 67] , so to fix this issue and make the output "prettier", run the command print(list(udp_ports.key))</p> 
