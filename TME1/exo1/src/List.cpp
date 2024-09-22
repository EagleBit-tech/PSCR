#include "List.h" //FAUTE : Ajout du include

namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	return len; //FAUTE : Retourner len et non length()
}

void Chainon::print (std::ostream & os) const{
	os << data ;
	if (next != nullptr) {
		os << ", ";
		next->print(os);  //FAUTE : Appeler print que si next != nullptr
	}
}

// ******************  List

// FAUTE : Ajout implementation constructeur et deconstructeur
List::List(): tete(nullptr)  {}

List::~List() {
		for (Chainon * c = tete ; c ; ) {
			Chainon * tmp = c->next;
			delete c;
			c = tmp;
		}
	}

const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val, tete);   // FAUTE : Chainon attend 2 args
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

void List::push_front (const std::string& val) {
	tete = new Chainon(val,tete);
}

// FAUTE : Preciser List::
bool List::empty() {
	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}

// In pr namespace
std::ostream & operator<< (std::ostream & os, const pr::List & vec)
{
	os << "[";
	if (vec.tete != nullptr) {
		vec.tete->print (os) ;
	}
	os << "]";
	return os;
}

} // namespace pr



