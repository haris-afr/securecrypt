#include <iostream>
#include <string>
using namespace std;

const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

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
			if (key[messageIndex % key.size()] == alphabet[j]){
				key_letter_index = j;
			}
		}
		
		int encrypted_letter_index = current_letter_index + key_letter_index;
		if (encrypted_letter_index > 25){
			encrypted_letter_index -= 26;
		}
		cout << alphabet[encrypted_letter_index];
		encrypted[messageIndex] = alphabet[encrypted_letter_index];
	}
	return encrypted;
	
}

string vigenereDecryptor(string message, string key){
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
		int key_letter_index = 0;
		
		for (int j = 0; j < 26; j++){ //use same process to find the current index of the key letter in the alphabet array
			if (key[messageIndex % key.size()] == alphabet[j]){
				key_letter_index = j;
			}
		}
		
		int encrypted_letter_index = current_letter_index - key_letter_index;
		if (encrypted_letter_index < 0){
			encrypted_letter_index += 26;
		}
		cout << alphabet[encrypted_letter_index];
		decrypted[messageIndex] = alphabet[encrypted_letter_index];
	}
	
	return decrypted;
}