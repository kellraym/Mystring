#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mystring.h"


Mystring::Mystring()
	: str{ nullptr } {
	str = new char[1];
	*str = '\0';
}

Mystring::Mystring(const char* s)
	: str{ nullptr } {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	} else {
		str = new char[std::strlen(s) + 1];
		std::strcpy(str, s);
	}
}

Mystring::Mystring(const Mystring& source)
	: str{ nullptr } {
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);

}
Mystring::~Mystring() {
	delete[] str;
}

Mystring::Mystring(Mystring&& source)
	: str(source.str) {
	source.str = nullptr;
	std::cout << "Move constructor used" << std::endl;
}

// s2.operator=(s1);
// overloads = operator, you can just use = with Mystring and it will know what to do
Mystring& Mystring::operator=(const Mystring& rhs) {
	// assigns deep copy of rhs to this
	std::cout << "Copy assignment" << std::endl;
	if (this == &rhs)
		return *this;

	// delete str that was initially assigned, it will probably need to be a different length
	delete[] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);

	return *this;
}

//Move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
	std::cout << "Using move assignment" << std::endl;
	if (this == &rhs)
		return *this;

	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

bool Mystring::operator==(const Mystring& rhs) const {
	return std::strcmp(str, rhs.str);
}

Mystring& Mystring::operator+(const Mystring& rhs) const {
	size_t buff_size = std::strlen(str) + std::strlen(rhs.str);
	char* buff = new char[buff_size];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str);

	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

//Mystring Mystring::operator-() const {
//	size_t buff_size = std::strlen(str);
//	char* buff = new char[buff_size];
//	for (size_t i = 0; i < buff_size; i++) {
//		std::strcat(buff, )
//	}
//}

void Mystring::display() {
	std::cout << str << " : " << get_length() << std::endl;
}
int Mystring::get_length() const { return std::strlen(str); }

const char* Mystring::get_str() const { return str; }