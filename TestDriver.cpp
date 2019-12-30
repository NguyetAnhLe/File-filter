// This is a group project call file filter that has 1 base class and 3 subclass to 
// read , transform and write out file.
// The base funtion has to have a pure virtual function to transform the character that get form input file
// and a function to read the fileand call the transformation
// 3 others sub class will have to perform : Encryption, Capitalization, and Copy the file.
// Last Modified: 11/16/16
// Programmer : ANH N LE
// Group members : LYDIE, SUMAN


#include "Encryption.h";
#include "CopyFile.h";
#include "CapitalizedFile.h";
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//Function propotype
double getDouble();
double getNumber();
double getWholeNumber();
double getRangeNumber(int, int);
string getNoSpace();
string checkForTXT(string);
string getString();
char getYesNo();
void printStarter();

//Function definition
void printStarter() {
	cout
		<< "\t   ********************************************************************\n"
		<< "\t   *             Welcome to File Transformation program               *\n"
		<< "\t   *               - Group Project : File Filter -                    *\n"
		<< "\t   *                  By : Anh Le, Lydie, Suman                       *\n"
		<< "\t   ********************************************************************\n";
}

char getYesNo() {
	char ch;
	cin >> ch;
	// ONLY take Y for yes and N for no
	while (toupper(ch) != 'N' && toupper(ch) != 'Y') {
		cout << "Please put 'Y' for yes or 'N' for No: ";
		cin >> ch;
	}
	return ch;
}

string getString() {
	char str[100];
	cin >> ws;
	cin.get(str, 100);
	return str;
}
//Take only letters that are before the space
string getNoSpace() {
	string str = getString();
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
			str.erase(i, 1); // erase the space / 1 char
			i--; // put back 1 char
		}
	}
	return str;
}
//Check for ".txt" at the the end of file name
string checkForTXT(string fileName) {
	string newName;
	//Count for string length
	int length = fileName.length();
	int i = (length - 4); // intitial the point  when the .txt start (last 4 char of the string)
	if (i <= 0) {
		newName = fileName + ".txt";
		return newName;
	}
	else {
		// check if the input name has .txt at the end
		if (fileName[i] != '.' && fileName[i + 1] != 't' && fileName[i + 2] != 'x' && fileName[i + 3] != 't') {
			// of not, add the .txt and return new file name
			newName = fileName + ".txt";
			return newName;
		}
		else
			// if it alreay has .txt, return the original name
			return fileName;
	}
}

// take only number in the set range
double getRangeNumber(int MIN, int MAX) {
	double num = getWholeNumber();
	while (num < MIN || num > MAX) {
		cout << "\tPlease enter a number from " << MIN << " to " << MAX << " : ";
		 num = getWholeNumber();
	}
	return num;
}

// Get whole number only
double getWholeNumber() {
	double num;
	num = getDouble();
	while (num != (int)num) {
		cout << "\tWhole number only. Try again: ";
		num = getDouble();
	}
	return num;
}

//Letter input validation
// only get number
double getNumber() {
	double number;
	while (!(cin >> number)) {
		cin.clear(); cin.ignore(10000, '\n');
		cout << "\tNo letter please. Try again: ";
	}
	cin.ignore(80, '\n');
	return number;
}

// Get a number
double getDouble() {
	double number;
	number = getNumber();
	return number;
}

//Main function
void main() {
	system("Title File Filter");

	ifstream input;
	ofstream output;
	string fileName, transformFileName, line, name, nameNoSpace;
	CopyFile copyFile;
	Encryption encryptFile;
	CapitalizedFile uppercaseFile;
	int choice;
	const int ENCRYPT = 1, CAPTITALIZE = 2, COPY= 3; // the choice of specifit performance
	char yesNo; // for user choice to continue or quit

	//print banner
	printStarter();
	cout << endl << endl;

	while (true) {
		//ASk user for input file
		// check for txt
		cout << "Please enter the name of the file: ";
		name = getNoSpace();
		fileName = checkForTXT(name);

		//open input file
		input.open(fileName);
		while(!input)
		{
			// Display an error message.
			cout 
				<< "\tError opening the input file.\n"
				<< "\tPlease enter the name of the file: ";
			//prompt for file name again
			// check for .txt
			name = getNoSpace();
			fileName = checkForTXT(name);

			input.open(fileName);
		}
		cout << "Opening " << fileName << ".....\n";
		// Print out option choice 
		cout
			<< "\nPlease choose the option that you want to peform on the file: \n"
			<< "\t 1. Encrypt\n"
			<< "\t 2. Capitalize\n"
			<< "\t 3. Copy\n"
			<< "Choice: ";

		// validation for choice only in given range
		// here is for encrypt to copy
		choice = getRangeNumber(ENCRYPT, COPY);

		// Perforn=m choice
		switch (choice) {
		case ENCRYPT:
			//Prompt for output file name
			cout << "Enter the OUTPUT file name: ";
			 // take a temporary name form user
			// check for .txt and spaces
			name = getNoSpace();
			transformFileName = checkForTXT(name);
			//open out put file to write in
			output.open(transformFileName);
			//Call functions to encrypt file
			encryptFile.doFilter(input, output);
			// end reading and writing file
			input.close();
			output.close();
			break;

		case CAPTITALIZE:
			cout << "Enter the OUTPUT file name: ";
			//validate file name
			name = getNoSpace();
			transformFileName = checkForTXT(name);
			// open file name
			output.open(transformFileName);
			//transform to uppercase letter
			uppercaseFile.doFilter(input, output);
			// end reading and writing file
			input.close();
			output.close();
			break;

		case COPY:
			cout << "Enter the OUTPUT file name: ";
			// validate file name
			name = getNoSpace();
			transformFileName = checkForTXT(name);
			// open out put file to write in
			output.open(transformFileName);
			// transform function  - copy file.
			copyFile.doFilter(input, output);
			// end reading and writing file
			input.close();
			output.close();
			break;

		}

		// print out report
		cout
			<< "\n---------------------------------------------------------------------------------------"
			<< "\n      ** A file named " << transformFileName << " has been created in your folder.   "
			<< "\n    **Here is how the file look like:                                                 \n\n ";
		
		//open just created output file just as input 
		// print out each line in the file
		input.open(transformFileName);
		if (!input.fail())
		{
			while (getline(input, line))
			{
				cout << line << '\n';
			}
			input.close();
		}
		else
			cout << "Open Error. Did you add the .txt?\n";
		
		cout << "\n-------------------------------------------------------------------------------------\n\n";

		// ask for loop again
		cout << " Do you want to try again?(Y/N) ";
		yesNo = getYesNo(); // get only Y and N char

		//If terminate
		if (toupper(yesNo) == 'N') {
			system("CLS");
			cout 
				<< "\nThank you for trying. \n"
				<< "Terminating the program.....\n";
			system("pause");
			break; // stop the program
		}

		cout << endl;
		system("pause");
		system("CLS");
	}
}

