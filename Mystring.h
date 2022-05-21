#pragma once

class Mystring {
private:
	char* str;
public:
	Mystring();							// No-args constructor
	Mystring(const char* s);			// Overloaded constructor
	Mystring(const Mystring& source);	// Copy constructor
	Mystring(Mystring&& source);
	~Mystring();

	Mystring& operator=(const Mystring& rhs);
	Mystring& operator=(Mystring&& rhs);
	Mystring operator-() const;  // makes str lower case
	Mystring& operator+(const Mystring& rhs) const;
	bool operator==(const Mystring& rhs) const;

	void display();
	int get_length() const;
	const char* get_str() const;
};