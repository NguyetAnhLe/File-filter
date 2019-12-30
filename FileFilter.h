#pragma once
#ifndef FILEFILTER_H
#define FILEFILTER_H
#include <iostream>
#include <fstream> 
using namespace std;

//Base Class
class FileFilter {
public:
	// pure virtual function
	virtual char transform(char ch) = 0;
	//DoFilter funtion
	// to filter and read the file
	// then call transform function
	void doFilter(ifstream &in, ofstream &out);

};
#endif 
