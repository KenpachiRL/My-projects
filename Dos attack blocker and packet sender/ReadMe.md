<h1>Dos Attack Blocker</h1>


<h2>Description</h2>
A Dos attack is a type of attack in which the attacker typically floods the targeted host or network with traffic until the target can't respond or crashes, this prevents legitimate users from accessing their services and resources.

A DOS blocker is a type of defense strategy in which a suspicious IP address that generates an excessive amount of network traffic is automatically detected and blocked to prevent a DOS attack from successfully occuring

<br />


<h2>Languages and Utilities Used</h2>

- <b>Python</b> 

<h2>Environments Used </h2>

- <b>Kali linux</b> 

<h2>Code walk-through:</h2>

<p>
My Python script uses the "scapy" library to capture and analyze incoming packets and track the packet rate per second for each source IP address. If an IP packet exceeds the packet rate limit(which is set to 100 by default), then the script will block the IP address by adding a rule to 'iptables'(iptables are used by the Kernel built-in firewall). While the code is running the packet rate is recalculated every second and the packet count is regularly resetted to maintain accurate monitoring. Root privileges are required to run the script because it interacts with the system firewall, so make sure you use Sudo when running the script.   
<br><br>
 You can ignore packetsender.py because its just a code used to test if my dos blocker was working. What packetsender.py does is send 100 packets per second to the target IP of my choice to simulate a DOS attack.
</p>

<h2>How to run my code:</h2>
<p>
You can edit the maximum number of allowed packets by changing the value of the variable "limit" to whatever you want. To run the code type sudo python3 Dos_attack_blocker.py
 <br>


</p>
