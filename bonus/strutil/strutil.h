#ifndef STRUTIL_H_
#define STRUTIL_H_

#include <iostream>

namespace strutil {
	/* 	Fonctions	*/
	size_t length(const char*);
	char* newcopy(const char*);
	int compare(const char* s1, const char* s2);
}



#endif /* STRUTIL_H_ */
