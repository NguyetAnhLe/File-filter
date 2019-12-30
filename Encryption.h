#pragma once
#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "FileFilter.h"

//sub class
class Encryption : public FileFilter {	
public:
	// rewrite pure virtual function
	char transform(char ch);

};

#endif // 

