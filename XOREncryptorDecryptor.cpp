#include<iostream>
#include<string>

using namespace std;

string XOREncryptorDecryptor(string message){
    string encrypt;
    char XORkey = 'T';
    int length = message.length();
    cout<<"here";
    for(int i=0; i<length; i++){
        encrypt[i]= message[i] ^ XORkey;
        cout<<encrypt[i];
    }

    return encrypt;

}