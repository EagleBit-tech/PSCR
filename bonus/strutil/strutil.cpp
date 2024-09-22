#include "strutil.h"
#include <iostream>

namespace strutil{
	/* 	Fonctions	*/
		size_t length(const char* str) {
			size_t count = 0;
			for(const char* cp = str ; *cp ; ++cp)
				count++;
			return count;
		}
		char* newcopy(const char* str) {
			size_t len = length(str);
			char* res = new char[len + 1];
			char* cp = res;
			do{
				*cp++ = *str;
			}while(*str++);
			return res;
		}

		int compare(const char* s1, const char* s2){
			const char* cp1 = s1;
			const char* cp2 = s2;
			while(*cp1 && *cp2){

					if(*cp1 - *cp2 > 0)	return 1;
					else if(*cp1 - *cp2 < 0)	return -1;
					cp1++;
					cp2++;

				}
			return 0;
		}
}
