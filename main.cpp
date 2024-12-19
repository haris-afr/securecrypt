#include <iostream>
#include <string>
#include <fstream>
const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
#include "vigenere.cpp"
#include "caesar.cpp"
#include "XOREncryptorDecryptor.cpp"
using namespace std;

string getInput(){
	int readoption;
	string message;
	ifstream file;
	cout << "Would you like to enter the message(1) or read from the file(2)?" << endl;
	cin >> readoption;
	switch (readoption){
		case 1:
			cout<<"Please Enter The Message You'd Like To Encrypt:"<<endl;
			cin.ignore();
			getline(cin, message);
			break;
		case 2:
			file.open("securecrypt.txt"); 
			if (file.is_open()){
				file >> message;	
			}
			else{
				cerr << "file can't be opened" << endl;
			}
			break;
	}
	return message;
}

int main(){
	ofstream file;
	string message, output, key;
	int option;
	int readoption;

	do{
		cout<<"Would You Like to Encrypt or Decrypt a Message?"<<endl;
		cout<<"1.Encrypt"<<endl;
		cout<<"2.Decrypt"<<endl;
		cin>>option;
		if(option==1){
			message = getInput();
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
					output = vigenereEncryptor(message, key);
					break;
					case 2:
					output = caesarEncryptor(message);
					break;
					case 3:
					output = XOREncryptorDecryptor(message);

					break;
					default: 
					cout<<"Invalid Input. Try again.";
					option = 4;
				}
			}while(option==4);

			cout<<"The encrypted message is: "<<output << endl;
		}

		else if(option==2){
			message = getInput(); 
			
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
					output = vigenereDecryptor(message, key);
					break;
					case 2:
					output = caesarDecryptor(message);
					break;
					case 3:
					output = XOREncryptorDecryptor(message);

					break;
					default: 
					cout<<"Invalid Input. Try again.";
					option = 4;
					
				}
			}while(option==4);

			cout<<"The decrypted message is: "<< output << endl;

		}
		else{
			cout<<"invalid input."<<endl;
			option = 5;
		}
	}while(option==5);
	
	cout << "Would you like to store your output in a file (1/0)" << endl;
	bool outputoption;
	cin >> outputoption;
	if (outputoption){
		file.open("securecrypt.txt");
		if(file.is_open()){
			file<<output;
			file.close();
		}
		else{
			cerr<<"could not open file";
		}
	}

	return 0;

}
