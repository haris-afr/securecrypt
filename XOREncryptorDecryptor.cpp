#include<iostream>
#include<string>

using namespace std;

string XOREncryptorDecryptor(string message){
    string encrypt, encrypted = "";
    char XORkey = 'T';
    int length = message.length();
    for(int i=0; i<length; i++){
        encrypt[i]= message[i] ^ XORkey;
        encrypted.push_back(encrypt[i]);

    }

    return encrypted;

}
