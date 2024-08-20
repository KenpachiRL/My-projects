import nmap  # Import nmap library

# Initialize the PortScanner
nm = nmap.PortScanner()
version = nmap.__version__  # Store the nmap version in a variable
print(f"Welcome to Greater port scanner. This scanner uses Nmap Version: {version}")

# Get the target IP address from the user
target = input('Please enter the IP address you want to scan: ')

# Get the scan type from the user
resp = input(f"\n What type of scan do you want to perform: \n1) SYN Scan \n2) UDP Scan\n")

print(f"You have selected option: {resp} \n")


if resp == "1":  # SYN Scan
	nm.scan(target, '1-200', '-v -sS')  # sS is the SYN scan
	print("IP status: ", nm[target].state())  # Shows if the IP address is up or down
	print("Protocols: ", nm[target].all_protocols())  # Prints the protocols being scanned (in this case TCP)
	print("Open Ports: ", list(nm[target]['tcp'].keys()))  # Lists all active TCP ports

elif resp == "2":  # UDP Scan
	nm.scan(target, '1-200', '-sU')  # It is a UDP scan
	print(f"IP status: {nm[target].state()}")  # Shows if the IP address is up or down
	print("Protocols: ", nm[target].all_protocols())  # Prints the protocols being scanned (in this case UDP)
	if 'udp' in nm[target].all_protocols():
	    print(f"Open Ports: {list(nm[target]['udp'].keys())}")  # Lists all active UDP ports
	else:
	    print("No UDP ports detected or scan failed.") #error handling

else:
	print("Invalid input")


