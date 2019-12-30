#pragma once
#ifndef COPYFILE_H
#define COPYFILE_H
#include "FileFilter.h"

//sub class
class CopyFile : public FileFilter {
	// rewrite pure virtual function
	char transform(char ch);
};

#endif