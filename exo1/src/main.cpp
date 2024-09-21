#include "List.h"
#include <string>
#include <iostream>
#include <cstring>

int main () {

	std::string abc = "abc";
	char * str = new char [4];   //FAUTE : taille
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';	//FAUTE : Ajout du dernier char '\0'
	size_t i = 0;

	if (! std::strcmp (str, abc.c_str())) {		//FAUTE : Ajout de std::
		std::cout << "Equal !" << std::endl;	//FAUTE : Ajout endl ou flush (flush)
	}

	pr::List list;
	list.push_front(abc);
	list.push_front(abc);

	std::cout << "Liste : " << list << std::endl;
	std::cout << "Taille : " << list.size() << std::endl;

	// Affiche à l'envers
	for (i= list.size() - 1 ; i >= 0 ; i--) {
		std::cout << "elt " << i << ": " << list[i] << std::endl;
	}

	// liberer les char de la chaine
	//FAUTE : ne peut pas supprimer char un par un car ils n'ont pas été alloué individuellement
	/*for (char *cp = str ; *cp ; cp++) {
		delete cp;
	}*/
	// et la chaine elle meme
	delete [] str;	//FAUTE : []

	return 0;	//FAUTE	: Retourner un int : 0
}
