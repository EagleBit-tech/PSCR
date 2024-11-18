#ifndef STRING_H_
#define STRING_H_

#include <cstddef>
#include <iostream>
#include "../strutil/strutil.h"

namespace pr{

	/*	Classe String	*/
	class String {
		private:
			// Attributs
			//const char* str;

		public:
			// Attributs
			const char* str;
			//Constructeur
			String(const char* ori = "");

			//Deconstructeur
			~String();

			//Constructeur par copie
			String(const String& s);

			//Méthodes
			size_t length() const;
			char* memcpy(const char*) const;

			friend std::ostream & operator<<(std::ostream &os, const String &s);
			friend bool operator==(const String &a, const String &b);

			bool operator<(const String & b);

	};
	std::ostream & operator<<(std::ostream &os, const String &s);
	bool operator==(const String &a, const String &b);

}/* namespace pr */

#endif /* STRING_H_ */
