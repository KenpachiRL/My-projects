<h1>Honeypot creation using python</h1>


<h2>Description</h2>
A honeypot is a decoy system, used to lure attackers and to study their attack techniques.

<br />


<h2>Languages and Utilities Used</h2>

- <b>Python</b> 

<h2>Environments Used </h2>

- <b>Kali linux</b> 

<h2>Code walk-through:</h2>

<p>
My Python code simulates a honeypot. It initially sets up a server that listens on a specified IP address and port. (My code supports up to 5 connections simultaneously). When a user tries to connect using the command "telnet {Ip address} {port number}", they are prompted to type a username and a password with 3 attempts allowed for each. Once authenticated, the server provides a command-line interface with several commands, such as ls, cat, whoami, and cd to specific directories (e.g., Desktop, Downloads, Documents). The attacker's input, such as the usernames, passwords, and commands executed are stored in the file named Honeypot.txt so that further analysis of the attacker's behavior can be done    
</p>

<h2>How to run my code:</h2>
<p>
You can change IP address and port of the Honeypot on lines 9 and 10 <br>
1) make sure you download both my Honeypot code and my Honeypot log file. <br>
2) open the terminal and type sudo python3 HoneyPot.py  <br>
3) If you want to see if the honeypot really works then use another computer and type telnet {Ip address} {port number}. <br>


</p>

