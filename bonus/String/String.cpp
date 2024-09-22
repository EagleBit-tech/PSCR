#include "String.h"

namespace pr {


	/*	Classe String	*/
	String::String(const char* ori) : str(ori){}

	String::~String() {
		delete [] str;
	}

	String::String(const String& s) : str(strutil::newcopy(s.str)) {}

	size_t String::length() const {
		return strutil::length(str);
	}

	std::ostream & operator<<(std::ostream &os, const String &s){
		return (os << s.str);
	}

	bool operator==(const String &a, const String &b){
		return strutil::compare(a.str, b.str) == 0;
	}

	bool String::operator<(const String & b){
		return strutil::compare(str, b.str) < 0;
	}

}/* namespace pr */

