#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

class Decryption {
private:
  	char newalphabet[26]; //it will contain the letters in ascending order of most frequent
	int newnumber[26]; //it will contain the number in ascending number

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //it will be used in character count
	int number[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0 };
public:
    string decrypted; //store decrypted message thats later printed in console
	int key = 0;  //decrypt key

    Decryption();
    ~Decryption();
    void character_count(const string &userinput);
    void descending_order();
    void print_analysis_array();
    void decrypt(const string &message);
    bool is_valid_integer(const string &key_valid);
    void providedSample(const string &message, Decryption &decryption);
    int max_index();
    void print_max_index();
    bool is_alpha(char alpha);
    bool is_upper(char character);
    char myToUpper(char character);
};
