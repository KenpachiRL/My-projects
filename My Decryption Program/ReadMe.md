<h1>My Decryption Program</h1>


<h2>Description</h2>
This C++ program is designed to decrypt messages encrypted with a Caesar cipher. The program analyzes the frequency of each letter in the encrypted message, suggests a decryption key based on frequency analysis, and allows the user to either use the suggested key or input their own custom key for decryption. The decrypted message is then displayed and saved to an output file.

Key Features:
<br>
<br> 
Frequency Analysis: The program counts the frequency of each letter in the encrypted message and sorts them in descending order.
<br>Suggested Key: Based on the frequency analysis, the program suggests a key for decryption, typically assuming that the most frequent letter in the encrypted message corresponds to the letter 'E' in English.
<br>Custom Key Option: Users can choose to use the suggested key or input their own custom key for decryption.
<br>Validation: The program validates the custom key input to ensure it is a valid integer.
<br>Decryption: Once the key is determined, the program decrypts the message and provides a preview of the decrypted text.
<br>File Handling: The program reads the encrypted message from an input file and writes the decrypted message to an output file.


<br />


<h2>Languages and Utilities Used</h2>

- <b>C++</b> 

<h2>Environments Used </h2>

- <b>Ubuntu</b> 

<h2>How It Works:</h2>

<p>
<br>File Input/Output: The program reads an encrypted message from a text file specified by the user and outputs the decrypted message to another specified file.
<br>Decryption Process: The Decryption class handles the decryption process, including character frequency counting, sorting, and actual decryption using the Caesar cipher method.
<br>User Interaction: The program interacts with the user to choose between the suggested decryption key and a custom key, providing flexibility in the decryption process.

</p>

<h2>How to run my code:</h2>
<p>
Download all 3 files, then type in your terminal the command "g++ -o decrypt main.cpp decryption.cpp", and then after it is successfully compiled type the command ./decrypt encrypted_text.txt decrypted_text.txt
<br><br> Important: encrypted_text.txt is the file that has to be decrypted, after it has been decrypted the output will be sent to decrypt_text.txt
  
</p>
