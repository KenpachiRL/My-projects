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
