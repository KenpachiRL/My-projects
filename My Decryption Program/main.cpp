#include "decryption.hpp"

int main(int argc, char *argv[]) {

	ifstream inputFile(argv[1]); // open the file name


	//returns error if unable to open
	if (!inputFile.is_open()) {
		cout << "Unable to open the input file." << endl;
		return 1; // Return an error code
	}

	string line;
	string message = ""; //my functions use this variable.

	while (getline(inputFile, line)) // the txt file content will initially be transfered to this "line@ variable
	{
		message += line + "\n"; // Add a newline character after each line and adds the outcome(of line + /n) to message
	}

	inputFile.close(); // close the input file

	ofstream outputFile(argv[2]); //open output file
	
	//checks if open
	if (!outputFile.is_open()) {
		cout
				<< "Unable to open the output file.Probably because you created the file using 'sudo' e.g. 'sudo nano nameof file' so create the file name without using sudo"
				<< endl;
		return 1;
	}
	Decryption decryption; // Create a Decryption object for each message
	string choice;
	string choice1;

	decryption.character_count(message);
	decryption.descending_order();
	decryption.print_analysis_array();
	decryption.print_max_index();

	cout << "Welcome to my code, the key suggested key you should use to decrypt message: '"
			<< decryption.key << "'" << endl;
	cout << " Do you wish to use a custom key ? [y/n]" << endl;
	cin >> choice;	//response
	//only way to break loop is by writing valid responses in terminal
	while (true) {

		if ((choice == "y") || (choice == "Y")) {
			cout << "Enter key: " << endl;
			string key_value;
			cin >> key_value; //this is where the number of the key the user chooses will be stored at

			if (decryption.is_valid_integer(key_value)) { //checks if key is an integer
				decryption.key = stoi(key_value);  //converts key
				decryption.decrypt(message);  
				decryption.providedSample(message, decryption);
				cout << "Do you wish to continue with this key? [y/n]"
						<< endl;
				cin >> choice1; //stores decision
				if ((choice1 == "y") || (choice1 == "Y")) { 
					cout << endl << endl << "Decrypted message: "
							<< decryption.decrypted << endl;
					outputFile << "Decrypted message: "
							<< decryption.decrypted << endl;
					break; // Exit the loop
				} else if ((choice1 == "n") || (choice1 == "N")) {

				} else {
					cout << "Invalid key, try again" << endl;
				}
			}

		} else if ((choice == "n") || (choice == "N")) {
			cout << "You answered no" << endl;
			decryption.decrypt(message);
			cout << endl << endl << "Decrypted message: "
					<< decryption.decrypted << endl;
			outputFile << "Decrypted message: " << decryption.decrypted
					<< endl;
			break; // Exit the loop
		} else {
			cout << "invalid input,the programm is restarting. Try again!!!!"
					<< endl;
			cout
					<< " Do you wish to use a custom key (Remember, This time your response should be within available answers)? [y/n]"
					<< endl;
			cin >> choice;
		}
	}
	outputFile.close();	//close output file
	return 0;

}
