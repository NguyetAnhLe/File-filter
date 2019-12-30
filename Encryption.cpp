#include "Encryption.h";

char Encryption::transform(char ch) {
	//This is to encrypt a file
	// Simple encryption function
	// using XOR 
	// From wikipedia : With this logic, a string of text can be encrypted by applying the bitwise XOR operator to every character using a given key.
	// To decrypt the output, merely reapplying the XOR function with the key will remove the cipher.
	char key[3] = { 'K', 'C', 'Q' }; // any char will do, just for the length
	char output = ch;
	return output = ch^key[1 % (sizeof(key) / sizeof(char))];

}