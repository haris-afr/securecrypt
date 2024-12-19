#include <iostream>
#include <string>
const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
#include "vigenere.cpp"
#include "caesar.cpp"
#include "XOREncryptorDecryptor.cpp"
using namespace std;



int main(){
	string message, encrypted, key;
	int option;

	do{
		cout<<"Would You Like to Encrypt or Decrypt a Message?"<<endl;
		cout<<"1.Encrypt"<<endl;
		cout<<"2.Decrypt"<<endl;
		cin>>option;
		if(option==1){
			cout<<"Please Enter The Message You'd Like To Encrypt:"<<endl;
			cin.ignore();
			getline(cin, message);
			
			do{
				cout<<"Please Choose The Type of Cypher You'd Like:"<<endl;
				cout<<"1.Vingeneres Cipher"<<endl;
				cout<<"2.Caesar Cipher"<<endl;
				cout<<"3.XOR Cipher"<<endl;
				cin>>option;
				switch(option){
					case 1:
					cout<<"Please Enter The Key For The Cipher: ";
					cin.ignore();
					getline(cin,key);
					cout << vigenereEncryptor(message, key);
					break;
					case 2:
					caesarEncryptor(message);
					break;
					case 3:
					XOREncryptorDecryptor(message);

					break;
					default: 
					cout<<"Invalid Input. Try again.";
					option = 4;
				}
			}while(option==4);

			cout<<"The encrypted message is: "<<encrypted;
		}

		else if(option==2){
			cout<<"Please Enter The Message You'd Like To decrypt:"<<endl;
			cin.ignore();
			getline(cin, message);
			
			do{
				cout<<"Please Choose The Type of Cypher You'd Like:"<<endl;
				cout<<"1.Vingeneres Cipher"<<endl;
				cout<<"2.Caesar Cipher"<<endl;
				cout<<"3.XOR Cipher"<<endl;
				cin>>option;
				switch(option){
					case 1:
					cout<<"Please Enter The Key For The Cipher: ";
					getline(cin,key);
					vigenereDecryptor(message, key);
					break;
					case 2:
					caesarDecryptor(message);
					break;
					case 3:
					XOREncryptorDecryptor(message);

					break;
					default: 
					cout<<"Invalid Input. Try again.";
					option = 4;
					
				}
			}while(option==4);

			cout<<"The decrypted message is: "<<encrypted;

		}
		else{
			cout<<"invalid input."<<endl;
			option = 5;
		}
	}while(option==5);


}
