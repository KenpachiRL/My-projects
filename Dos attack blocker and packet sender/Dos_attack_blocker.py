import os #this is used to interact with the Operating system
import sys #handles terminal outputs etc
import time #this allows us to determine the transfer rate
from collections import defaultdict
from scapy.all import sniff
from scapy.layers.inet import IP

limit = 100 # this sets the limit per second of allowed packets

print(f"The threshold is: {limit}")

def packet_callback(packet):
    source_ip = packet[IP].src #this extracts the source ip address
    packet_count[source_ip] = packet_count[source_ip] + 1 #increase packet count
    time_count = time.time()    #stores current time
    time_interval = time_count - start_time[0]        #total time that has passed since start_time[0]

    if time_interval >= 1:      #this is use to make the code run forever till its manually closed
        for ip,count in packet_count.items():
            packet_rate = count / time_interval  #this calculates the packet per seconds
            print(f"The ip is: {ip}, The packet rate is: {packet_rate}")
            if packet_rate > limit and ip not in blocked_ips :   #this line checks if the Ip has been already blocked in the firewall table. otherwise 2 rules cause conflict
                print(f"Suspicious ip detected --> Blocking IP: {ip}, packet rate: {packet_rate}")
                os.system(f"iptables -A INPUT -s {ip} -j DROP")
                blocked_ips.add(ip)

    packet_count.clear #this clear the packet count dictionary
    start_time[0] = time_count

if __name__ == "__main__":
    if os.getgid() !=0:     # the function os.getgid gets the user id. If the user id is not 0 then it means that the user running the script isnt running it wih root privileges
        print("This script requires root privileges")
        sys.exit(1)

    packet_count = defaultdict(int)
    start_time = [time.time()] #stores current time in the list
    blocked_ips = set()

    print("monitoring traffic...")
    sniff(filter = "ip", prn= packet_callback)



