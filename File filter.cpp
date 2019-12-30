//class AbstractFilter{
//
//	// open inputFile into open outputFile, returning number of bytes written
//
//	virtual int doFilter(inputFile, outputFile) = 0;
//};
//class IdentFilter : public AbstractFilter {
//	//copy byte for byte
//		// ...
//
//};
//class UpperCaseFilter : public AbstractFilter {
//	// change any char to its uppercase equivalent
//	// ...
//
//};
//	class EncryptFilter : public AbstractFilter {
//	// encrypt the input file using (whatever you like)
//	// ...
//
//	};
//	int main(int argc, char** argv) {
//		// user enters what to do, what files to do it to
//		// then we instantiate the appropriate Filter class
//		// and use it
//		// and report that it was used
//	}
//
//	#include <iostream>
//	#include <iomanip>
//	#include <fstream>
//	#include <cctype>
//	using namespace std;
//
//	void printFile(fstream &); // Prototype
//
//	int main( )
//	{
//	// Explain the program
//	cout << "This program creates an uppercase version of a file of text." << endl;
//	cout << "Enter name of input file (input-file.txt): ";
//	string inFileName;
//	cin >> inFileName;
//	fstream inputFile(inFileName.data(), ios::in);
//	if (!inputFile)
//	{
//	cout << "The file " << inFileName << " cannot be opened." << endl;
//	exit(1);
//	}
//
//	// Echo the input file
//	cout << "\nOriginal file: " << endl << endl;
//
//	printFile(inputFile);
//	cout << endl << endl;
//
//	cout << "Enter name of 3 output files (upper.txt encrypt.txt noop.txt): ";
//	cout << endl;
//
//	string upperFileName;
//	cin >> upperFileName;
//	fstream upperFile(upperFileName.data(), ios::out);
//	if (! upperFile)
//	{
//	cout << "The file " << upperFileName << " cannot be opened." << endl;
//	exit(1);
//	}
//
//	string encryptFileName;
//	cin >> encryptFileName;
//	fstream encryptFile(encryptFileName.data(), ios::out);
//	if (! encryptFile)
//	{
//	cout << "The file " << encryptFileName << " cannot be opened." << endl;
//	exit(1);
//	}
//
//	string noopFileName;
//	cin >> noopFileName;
//	fstream noopFile(noopFileName.data(), ios::out);
//	if (! noopFile)
//	{
//	cout << "The file " << noopFileName << " cannot be opened." << endl;
//	exit(1);
//	}
//
//	cout << "Enter an integer offset for the encryption filter: ";
//	int encryptOffset = 0;
//	cin >> encryptOffset;
//
//	// For each filter, open the file, run it through the Filter object,
//	// the print the results
//	UpperCaseFilter upperFilter;
//	upperFilter.doFilter(inputFile, upperFile);
//	upperFile.close();
//
//	// Re-open for reading
//	upperFile.open(upperFileName.data(), ios::in);
//	cout << endl << "Uppercase-filtered file: " << endl << endl;
//	printFile(upperFile);
//	upperFile.close();
//
//	EncryptionFilter encryptFilter(encryptOffset);
//	inputFile.clear();
//	inputFile.seekg(0, ios::beg);
//	encryptFilter.doFilter(inputFile, encryptFile);
//	encryptFile.close();
//	encryptFile.open(encryptFileName.data(), ios::in);
//	cout << endl << "Encrypted file: " << endl << endl;
//	printFile(encryptFile);
//	encryptFile.close();
//
//	NoOpFilter noopFilter;
//	inputFile.clear();
//	inputFile.seekg(0, ios::beg);
//	noopFilter.doFilter(inputFile, noopFile);
//	noopFile.close();
//	noopFile.open(noopFileName.data(), ios::in);
//	cout << endl << endl << "Unmodified (no-op filtered) file: "
//	<< endl << endl;
//	printFile(noopFile);
//	noopFile.close();
//
//	inputFile.close();
//
//	system("pause");
//	return 0;
//	}
//
//	// *******************
//	//    printFile      *
//	// Print file        *
//	// *******************
//	void printFile(fstream &file)
//	{
//	// Start at beginning of file
//	file.clear();
//	file.seekg(0, ios::beg);
//
//	// Print the file contents
//	char ch = file.get();
//	while (ch != EOF)
//	{
//	// If t
//	he character is "non-printable", write its integer value instead.
//	// (This is primarily needed for the encryption case.)
//	if ((ch != '\n') && (ch != '\r') && ((ch < ' ') || (ch > 126)))
//	{
//	cout << '\\' << oct << setw(3) << fixed << setfill('0')
//	<< static_cast<int>(ch) << dec;
//	}
//	else
//	cout << ch;
//	ch = file.get();
//	}
//
//	// Go back to beginning of file for further processing
//	file.clear();
//	file.seekg(0, ios::beg);
//	}
//
//
//	}