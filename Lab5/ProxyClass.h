#pragma once
#include "AbstractFileSystem.h"

class ProxyClass : public AbstractFileSystem {
public:
	AbstractFile* af; 
	int Counter;

};