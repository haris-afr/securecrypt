#include <iostream>
#include <string>
using namespace std;


string caesarEncryptor(string message){
	string encrypted = "";
	for (int messageIndex = 0; messageIndex < message.size(); messageIndex++){
		char current_letter = 'a';
		int current_letter_index = 0;
		for (int j = 0; j < 26; j++){ //find the current index of the message letter in the alphabet array
			if (message[messageIndex] == alphabet[j]){
				current_letter = alphabet[j];
				current_letter_index = j;
			}
		}
		
		int encrypted_letter_index = current_letter_index - 3;
		if (encrypted_letter_index < 0){
			encrypted_letter_index += 26;
		}
		cout << alphabet[encrypted_letter_index];
		encrypted[messageIndex] = alphabet[encrypted_letter_index];
	}
	return encrypted;
	
}

string caesarDecryptor(string message){
	string decrypted = "";
	
	for (int messageIndex = 0; messageIndex < message.size(); messageIndex++){
		char current_letter = 'a';
		int current_letter_index = 0;
		for (int j = 0; j < 26; j++){ //find the current index of the message letter in the alphabet array
			if (message[messageIndex] == alphabet[j]){
				current_letter = alphabet[j];
				current_letter_index = j;
			}
		}
		
		int decrypted_letter_index = current_letter_index + 3;
		if (decrypted_letter_index > 25){
			decrypted_letter_index -= 26;
		}
		cout << alphabet[decrypted_letter_index];
		decrypted[messageIndex] = alphabet[decrypted_letter_index];
	}
	
	return decrypted;
}