#include <iostream>
#include "vigenere.cpp"
using namespace std;

int main(){
	string message = "hello";
	message = vigenereDecryptor("vvvrbacp", "cover");
	cout << message;
}