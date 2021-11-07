/*
#include "ProxyClass.h"
#include "AbstractFileVisitor.h"
#include<iostream>
#include<sstream>

using namespace std;

ProxyClass::ProxyClass(string n) : name(n), parent(nullptr) {}

unsigned int ProxyClass::getSize() {
	return contents.size();
}

string ProxyClass::getName() {
	return name;
}

vector<char> ProxyClass::read() {
	return contents;
}

void ProxyClass::accept(AbstractFileVisitor* fv) {
	if (fv) { fv->visit(this); }
}

int ProxyClass::write(vector<char> data) { // shouldn't be able to write a directory, only append
	return unabletowritedirectory;
}

int ProxyClass::append(vector<char> data) {
	return unabletowritedirectory;
}
AbstractFile* ProxyClass::clone() {
	return nullptr;
}
int ProxyClass::addChild(AbstractFile*) {
	return notacomposite;
}

int ProxyClass::removeChild(string name) {
	return notacomposite;
}

AbstractFile* ProxyClass::getChild(std::string name) {
	return nullptr;
}

AbstractFile* ProxyClass::getParent() {
	return parent;
}
void ProxyClass::setParent(AbstractFile* p) {
	parent = p;
}

*/