#ifndef COUNT_HH_
#define COUNT_HH_

#include <crtdefs.h>

template<typename iterator>

size_t count(iterator begin, iterator end){
	size_t cpt = 0;
	for( /* No init */ ; begin != end ; begin++)
		cpt++;
	return cpt;
}

template<typename iterator, typename T>
size_t count_if_equal (iterator begin, iterator end, const T & val){
	size_t cpt = 0;
	for( /* No init */ ; begin != end ; begin++)
		if(*begin == val)
			cpt++;
	return cpt;
}

#endif /* COUNT_HH_ */
