#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <cstddef>
#include <string>
#include <ostream>

namespace pr {

class Chainon {
public :
	//Attributs
	std::string data;
	Chainon * next;

	//Constructeur
	Chainon (const std::string & data, Chainon * next=nullptr);

	//Methodes
	size_t length() ;
	void print (std::ostream & os) const;
};

class List {
public:

	Chainon * tete;

	List();  //FAUTE : Supprimer l'implementation du constructeur

	~List();  //FAUTE : Supprimer l'implementation du deconstructeur

	const std::string & operator[] (size_t index) const ;

	void push_back (const std::string& val) ;

	void push_front (const std::string& val) ;	//FAUTE : Supprimer implementation de la méthode

	bool empty() ;

	size_t size() const ;
};


std::ostream & operator<< (std::ostream & os, const List & vec) ;

} /* namespace pr */

#endif /* SRC_LIST_H_ */
