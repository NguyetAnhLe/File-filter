#include "FileFilter.h"

void FileFilter :: doFilter(ifstream &in, ofstream &out){
	char ch;
	char transCh;
	//chet the first char
	in.get(ch);
	// then if not the end of file
	while (!in.fail())
	{
		//transform that char using transform function
		transCh = transform(ch);
		// write out the char in output file
		out.put(transCh);
		// get the next char from input file
		in.get(ch);
	}
}
