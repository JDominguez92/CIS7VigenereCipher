#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Variables to use throughout the void functions
string message;
string keyWord;

// Gets the message and maps the keyword to its length
// HEAVILY BASED ON EXAMPLE CODE "DK Vigenere Encryption"
// As such the same function name was used with only minor changes made
void messageAndKey() 
{
  string msg;
  string key;
  
  //Gets user input from the console
  cout << "Enter Message: ";
  getline(cin, msg);

	cout << "Enter key: ";
	getline(cin, key);

  //Changes the keyword inputed by user to upper case
  for (int i = 0; i < key.length(); i++)
  {
		key[i] = toupper(key[i]);
	}

  //Takes the uppercase keyword and repeats it to the length of
  //the message
  string keyMap = "";
	for (int i = 0, j = 0; i < msg.length(); i++) {
		if (msg[i] == 32) {
			keyMap += 32;
		}
		else {

			if (j < key.length()) {
      //Adds every letter to the mapped keyword except
      //the first letter when the keyword repeats
				keyMap += key[j];
				j++;
			} 
			else {
      //Resets the position in the keyword and
      //Adds the first letter of the word
				j = 0;
				keyMap += key[j];
				j++;
			} // Second if else statement
		} // First if else statement
  }// For loop bracket

//Assigns the local variables to be used in other functions
 message = msg;
 keyWord = keyMap;
}

//Shifts text certain amount based on keyword
void encryptText(string message, string keyMap) 
{
  cout << "Message: " << message << endl;
  cout << "Keyword: " << keyWord << endl;
  
  char text[message.size()];

  //For the legnth of the user input, the charater ascii value
  //shifts based on the ascii value of the keyword letter
  //that is in the same place when the string is turned
  //into an array
  for (int i = 0; i < message.length(); i++){
    if (isupper(message[i]))
    {
      //Shifts the uppercase letters in the message
      text[i] = char(int(message[i]+keyWord[i] - 78) %26 + 65);
    } else {
      //Shifts the lowercase letters in the message
      text[i] = char(int(message[i]+keyWord[i] - 110) %26 + 97);
    }
      
  }
  cout << "\nEncrypted Message: " << text << endl;
}

//Does the reverse of the encrypt function, simmilar process
//with a the reverse signs when taking the shift into account
void decryptText(string message, string keyWord)
{
  cout << "Message: " << message << endl;
  cout << "Keyword: " << keyWord << endl;
  
  char text[message.size()];

  for (int i = 0; i < message.length(); i++){
    if (isupper(message[i]))
    {
      text[i] = char(int(message[i]-keyWord[i] + 78) %26 + 65);
    } else {
      text[i] = char(int(message[i]-keyWord[i] + 98) %26 + 97);
    }
      
  }
  cout << "Decryted Message: " << text << endl;
}

int restart() {
  string rstart;
  int rchoice;

  // Prompts user to input if they would like to restart the program
  cout << "Restart Program?\nPlease Enter 'Yes' or 'No':\n";
  getline(cin, rstart);

  // Changes the input to uppercase
  for (int i = 0; i < rstart.length(); i++)
    {
		  rstart[i] = toupper(rstart[i]);
	  }
  
  //If the answer is yes, then the program restarts, otherwise it ends
  if (rstart == "YES" || rstart == "Y" )
  {
    rchoice = 1;
    return rchoice;
  } else {
    rchoice = 2;
    return rchoice;

  }
  
}

int main() {
  int choice;

  //Displays intro prompt and asks user to make a choice
  cout << "\n****\nWelcome to the Encryption Tool!\n";
  cout << "Menu:\n1: Encrypt\n2: Decrypt\n****\n";
  cout << "\nPlease Enter Choice: ";

  cin >> choice;
  cin.ignore();

  //Directs user based off of their choice
  if (choice == 1) {
    messageAndKey();
    encryptText(message, keyWord);
    }
  else if (choice == 2) {
    messageAndKey();
    decryptText(message, keyWord);
  } else {
    cout << "Invalid Choice\nPlease Try Again\n";
    return 0;
  }

  //Asks user if they would like to restart program  
  choice = restart();

  if (choice == 1) {
    main();
  }

  //Exit message
  cout << "Thank You for Using the Encrytion Tool!";
  
  return 0;
}
