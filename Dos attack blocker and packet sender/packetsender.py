from scapy.all import IP, ICMP, send
import time

def send_packets(target_ip, rate):
    # Create an ICMP packet
    packet = IP(dst=target_ip)/ICMP() # the slash is used to create a packet in scapy
    
    # Calculate the delay between packets
    delay = 1 / rate
    
    while True:		# this will let the script run permanetely till its manually terminated
        send(packet, verbose=False)
        print(f"Packet sent to {target_ip}")
        time.sleep(delay)

if __name__ == "__main__":
    target_ip = "192.168.232.135"  # Replace with the target IP address
    rate = 100  # Packets per second
    
    send_packets(target_ip, rate)
