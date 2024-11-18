#include "Banque.h"

#include <iostream>

using namespace std;

namespace pr {

void Banque::transfert(size_t deb, size_t cred, unsigned int val) {
	if (deb == cred) {
	        return;
	    }

	    Compte& compteA = comptes[std::min(deb, cred)];
	    Compte& compteB = comptes[std::max(deb, cred)];

	    std::lock(compteA.getMutex(), compteB.getMutex());

	    std::unique_lock<std::recursive_mutex> lockA(compteA.getMutex(), std::adopt_lock);
	    std::unique_lock<std::recursive_mutex> lockB(compteB.getMutex(), std::adopt_lock);

	    if (compteA.debiter(val)) {
	        compteB.crediter(val);
	    }
}

size_t Banque::size() const {
	std::unique_lock<std::mutex> lock(m);
	return comptes.size();
}
bool Banque::comptabiliser (int attendu) const {
	int bilan = 0;
	int id = 0;
	for (const auto & compte : comptes) {
		std::unique_lock<std::recursive_mutex> lock(compte.getMutex());
		if (compte.getSolde() < 0) {
			cout << "Compte " << id << " en négatif : " << compte.getSolde() << endl;
		}
		bilan += compte.getSolde();
		id++;
	}
	if (bilan != attendu) {
		cout << "Bilan comptable faux : attendu " << attendu << " obtenu : " << bilan << endl;
	}
	return bilan == attendu;
}

void Banque::afficherBilan() const {
    int bilan = 0;
    for (const auto& compte : comptes) {
        std::unique_lock<std::recursive_mutex> lock(compte.getMutex());
        bilan += compte.getSolde();
    }
    cout << "Bilan actuel : " << bilan << endl;
}
}
