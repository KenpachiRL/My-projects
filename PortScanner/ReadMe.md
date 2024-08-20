<h1>Port Scanner</h1>


<h2>Description</h2>
A port scan is a common technique hackers use to discover open doors or weak points in a network

<br />


<h2>Languages and Utilities Used</h2>

- <b>Python</b> 

<h2>Environments Used </h2>

- <b>Kali linux</b> 

<h2>Code walk-through:</h2>

<p>
  This Python script utilizes the 'nmap' library to perform network port scanning on a specified target ip address. The script allows the user to select between 2 types of scans: SYN Scan and UDP scan. After selecting the scan type, the results will show the status of the ip address, the protocol being used, and the list of open ports using either TCP or UDP. 
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
