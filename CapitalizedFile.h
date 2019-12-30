#pragma once
#ifndef CAPITALIZEDFILE_H
#define CAPITALIZEDFILE_H
#include "FileFilter.h"

//sub class
class CapitalizedFile : public FileFilter {
public:
	// rewrite pure virtual function
	char transform(char ch);

};

#endif 
