#include "String/String.h"
#include "strutil/strutil.h"
int main(){

	pr::String string("Hello, World!");
	pr::String s2("Hello !");

	std::cout << "@ : " << &string << " String : " << string << " et length : " << string.length() << std::endl;

	pr::String copy = string;   // Constructeur de copie

	std::cout << "@ : " << &copy << " String : " << copy << " et length : " << copy.length() << std::endl;

	bool x = string == copy;

	std::cout << std::boolalpha; // Affiche true/false au lieu de 1/0
	std::cout << x << std::endl;

	std::cout << (s2 < copy) << std::endl;

	return 0;
}
