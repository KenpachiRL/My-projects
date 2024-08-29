#include "decryption.hpp"

/**
	 *Author Greater Omorose
	 * @brief Default constructor for Decryption class.
	 */
	Decryption::Decryption() {
		cout << "Creating object..." << endl;
	}

	/**
	 * @brief Destructor for Decryption class.
	 * @details Author: Greater Omorose
	 */
	Decryption::~Decryption() {
		cout << "Destroying object..." << endl;
	}

	/**
	 * @brief Counts the frequency of each character in the input string.
	 *
	 * @param userinput, The input string to analyze.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test decryption.character_count("hello world") ->
	 * A has beeen used: 0 times                                                                                                                                                                                                                   B has been used : 0 times                                                                                                                                                                                                                                                                                      C has been used: 0 times
	 *D has been used: 1 times
	 *E has been used: 1 times
	 *H has been used: 1 times
	 *I has been used: 0 times
	 *J has been used: 0 times
	 *K has been used: 0 times
	 *L has been used: 3 times
	 *M has been used: 0 times
	 *N has been used: 0 times
	 *O has been used: 2 times
	 *P has been used: 0 times
	 *Q has been used: 0 times
	 *R has been used: 1 times
	 *S has been used: 0 times
	 *T has been used: 0 times
	 *U has been used: 0 times
	 *V has been used: 0 times
	 *W has been used: 1 times
	 *X has been used: 0 times
	 *Y has been used: 0 times
	 *Z has been used: 0 times
	 */
	void Decryption::character_count(const string &userinput) {

		int i;
		for (i = 0; i < userinput.length(); i++) //start of loop and it will loop same length as the sentence
				{
			int y;
			for (y = 0; y < alphabet.length(); y++)	//second loop, and loops the length of the array that contains the alphabet
					{
				if (is_alpha(userinput[i]) != 0)	//verify its a character
						{
					if (myToUpper(userinput[i]) == alphabet[y]) //checks if a letter of the alphabet is the same then it adds 1 to the 0 in the number array
							{
						number[y] = number[y] + 1;
					}
				}
			}
		}
	}

	/**
	 * @brief Sorts the characters and their frequencies in descending order and prints them
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * decryption.character_count("heLLo woRd"); decryption.descending_order(); ->
	 * L has been used: 3 times
	 * O has been used: 2 times
	 * W has been used: 1 times
	 * R has been used: 1 times
	 * H has been used: 1 times
	 * E has been used: 1 times
	 * D has been used: 1 times
	 * Z has been used: 0 times
	 * Y has been used: 0 times
	 * X has been used: 0 times
	 * V has been used: 0 times
	 * U has been used: 0 times
	 * T has been used: 0 times
	 * S has been used: 0 times
	 * Q has been used: 0 times
	 * P has been used: 0 times
	 * N has been used: 0 times
	 * M has been used: 0 times
	 * K has been used: 0 times
	 * J has been used: 0 times
	 * I has been used: 0 times
	 * G has been used: 0 times
	 * F has been used: 0 times
	 * C has been used: 0 times
	 * B has been used: 0 times
	 * A has been used: 0 times
	 */
	void Decryption::descending_order() {
		int y;
		int i;
		//this for loop copies the all the elements in alphabet into newalphabet
		for (i = 0; i < 26; i++) {
			newalphabet[i] = alphabet[i];

			//this copies the all the elements in number into newnumber
			newnumber[i] = number[i];
		}

		// i copied theold aray into a new array because i dont want this next for loop to overwrite the original data

		i = 0; //resets the value i
		for (int i = 0; i < 26; i++) {
			for (int j = i + 1; j < 26; j++) {
				if (newnumber[i] < newnumber[j]
						|| (newnumber[i] == newnumber[j]
								&& myToUpper(newalphabet[i])
										< myToUpper(newalphabet[j]))) {
					swap(newalphabet[i], newalphabet[j]);
					swap(newnumber[i], newnumber[j]);
				}
			}
		}

		// Print characters with non-zero frequency
		for (int y = 0; y < 26; y++) {
			if (newnumber[y] > 0) {
				cout << newalphabet[y] << " has been used: " << newnumber[y]
						<< " times" << endl;
			}
		}

		// Print characters with zero frequency alphabetically
		for (int y = 0; y < 26; y++) {
			if (newnumber[y] == 0) {
				cout << newalphabet[y] << " has been used: " << newnumber[y]
						<< " times" << endl;
			}
		}
	}

	/**
	 * @brief finds key based on what was previously analysed.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 *  Newalphabet = {‘B’}
	 void print_analysis_array() ->  Key = 3
	 *
	 */
	void Decryption::print_analysis_array() {
		if (myToUpper(newalphabet[0]) > 'E') {
			key = myToUpper(newalphabet[0]) - 'E';
		} else {
			key = 'E' - myToUpper(newalphabet[0]);
		}
	}

	/**
	 * @brief Decrypts the message using the stored key.
	 *
	 * @param message The message to decrypt.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test
	 * string message = "khoor zruog"
	 decryption.key = 3;
	 void decrypt(message) ->> hello world
	 */
	void Decryption::decrypt(const string &message) {
		decrypted.clear(); // Clear the decrypted string before each decryption attempt
		int i;
		for (i = 0; i < message.length(); i++) {
			if (is_alpha(message[i]) != 0) {
				if (is_upper(message[i])) {
					decrypted += (message[i] - key + 26 - 'A') % 26 + 'A';
				} else {
					decrypted += (message[i] - key + 26 - 'a') % 26 + 'a';
				}
			} else {
				decrypted += message[i];
			}
		}

	}
	/**
	 * @brief Checks if the provided key is a valid integer.
	 *
	 * @param key_valid The key to validate.
	 * @return True if the key is a valid integer, otherwise false.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test decryption.is_valid_integer(“2”) -> 1
	 * @test decryption.is_valid_integer(“l”) -> 0
	 */
	bool Decryption::is_valid_integer(const string &key_valid) { //checks if the inputed key is a number or letters
		for (int i = 0; i < key_valid.length(); ++i) {
			if (key_valid[i] < '0' || key_valid[i] > '9') {
				return false;
			}
		}
		return true;
	}

	/**
	 * @brief Displays a sample of the decrypted text.
	 *
	 * @param message The original message.
	 * @param decryption The Decryption object used for decryption.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test decryption.decrypt("khoor zruog");
	 decryption.providedSample("khoor zruog", decryption); -> Sample of Decrypted Text: hello world
	 */
	void Decryption::providedSample(const string &message, Decryption &decryption) {
		decryption.decrypt(message); // Decrypt the message once
		cout << "Sample of Decrypted Text: ";
		for (int i = 0; i < 40 && i < decryption.decrypted.length(); ++i) {
			if (decryption.is_alpha(message[i]) != 0) {
				cout << decryption.decrypted[i];
			} else {
				cout << message[i];
			}
		}
		cout << endl;
	}
	/**
	 * @brief Finds the index of the character with the maximum frequency.
	 *
	 * @return The index of the character with the maximum frequency.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test  decryption.character_count("hello world");
	 int result = decryption.max_index(); -> result = 7
	 */
	int Decryption::max_index() {
		int maxIndex = 0;
		for (int i = 1; i < 26; ++i) {
			if (newnumber[i] > newnumber[maxIndex]) {
				maxIndex = i;
			}
		}
		return maxIndex;
	}

	/**
	 * @brief Prints the character with the maximum frequency.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test decryption.character_count("hello world");
	 decryption.print_max_index(); ->  The letter with the maximum frequency is: l , Its frequency is: 3 times
	 */
	void Decryption::print_max_index() {
		int index = max_index();
		cout << "The letter with the maximum frequency is: "
				<< newalphabet[index] << endl;
		cout << "Its frequency is: " << newnumber[index] << " times" << endl;
	}
	/**
	 * @brief Checks if a character is an alphabet letter.
	 *
	 * @param alpha The character to check.
	 * @return True if the character is an alphabet letter, otherwise false.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test bool result = decryption.is_alpha('A'); -> 1
	 * @test bool result = decryption.is_alpha('2'); -> 0
	 */
	bool Decryption::is_alpha(char alpha) {
		return (alpha >= 'A' && alpha <= 'Z')
				|| (alpha >= 'a' && alpha <= 'z'); //if any of the conditions is true then the
	}

	/**
	 * @brief Checks if a character is an uppercase letter.
	 *
	 * @param character The character to check.
	 * @return True if the character is an uppercase letter, otherwise false.
	 * @details Author: Greater Omorose
	 * @date 03/01/2024
	 * @test bool result = decryption.is_upper('A'); -> 1
	 * @test bool result = decryption.is_upper('a'); -> 0
	 */
	bool Decryption::is_upper(char character) {
		return (character >= 'A' && character <= 'Z');
	}
	/**
	 * @brief Converts a lowercase character to uppercase.
	 *
	 * @param character The character to convert.
	 * @return The converted uppercase character.
	 * @details Author: Greater Omorose
	 * @test  char character = ‘g’
	 char myToUpper(char character) -> character = ‘G’
	 */
	char Decryption::myToUpper(char character) {
		if (character >= 'a' && character <= 'z') {
			return character - 32; //subtract 32 because (ascii code of a-A is 32)
		}
		return character;
	}
