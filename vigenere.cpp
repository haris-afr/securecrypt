#include <iostream>
#include <string>
using namespace std;


string vigenereEncryptor(string message, string key){
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
		int key_letter_index = 0;
		
		for (int j = 0; j < 26; j++){ //use same process to find the current index of the key letter in the alphabet array
			if (key[messageIndex % key.size()] == alphabet[j]){//in order to repeat key we use modulo operator
				key_letter_index = j;
			}
		}
		
		int encrypted_letter_index = current_letter_index + key_letter_index; 
		if (encrypted_letter_index > 25){
			encrypted_letter_index -= 26; //whenever alphabet index overflows we reset it
		}
		encrypted.push_back(alphabet[encrypted_letter_index]);
	}
	return encrypted;
	
}

string vigenereDecryptor(string message, string key){
	string decrypted = ""; //same logic is used in decryptor but reversed
	
	for (int messageIndex = 0; messageIndex < message.size(); messageIndex++){
		char current_letter = 'a';
		int current_letter_index = 0;
		for (int j = 0; j < 26; j++){
			if (message[messageIndex] == alphabet[j]){
				current_letter = alphabet[j];
				current_letter_index = j;
			}
		}
		int key_letter_index = 0;
		
		for (int j = 0; j < 26; j++){
			if (key[messageIndex % key.size()] == alphabet[j]){
				key_letter_index = j;
			}
		}
		
		int decrypted_letter_index = current_letter_index - key_letter_index;
		if (decrypted_letter_index < 0){
			decrypted_letter_index += 26;
		}
		decrypted.push_back(alphabet[decrypted_letter_index]);
	}
	
	return decrypted;
}