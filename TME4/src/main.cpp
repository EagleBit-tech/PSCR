#include <cstdlib>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "Banque.h"
#include "Compte.h"

using namespace std;

// Constantes pour la simulation
const int NB_THREAD = 10;  // Nombre de threads (clients) exécutant des transactions
const int NB_TRANSACTIONS = 1000;  // Nombre de transactions effectuées par chaque thread
const int SOLDE_INITIAL = 1000;  // Solde initial de chaque compte

// Générateur de nombres aléatoires thread-safe
int threadRandom(int min, int max){
	static thread_local mt19937 gen;  // Générateur aléatoire spécifique au thread
	uniform_int_distribution<int> distrib(min, max);  // Distribution uniforme
	return distrib(gen);  // Retourne un nombre aléatoire dans [min, max]
}

// Fonction simulant des transactions bancaires entre comptes
void transactionJob(pr::Banque &banque, int nombreTransactions) {
    for (int i = 0; i < nombreTransactions; ++i) {

    	// Génère deux indices aléatoires pour les comptes source et destination
        size_t i_compte = threadRandom(0, banque.size() - 1);
        size_t j_compte = threadRandom(0, banque.size() - 1);

        // Montant aléatoire à transférer
        unsigned int montant = threadRandom(1, 100);

        // Effectue un transfert entre deux comptes
        banque.transfert(i_compte, j_compte, montant);

        // Pause aléatoire entre les transactions pour simuler un délai réel
        this_thread::sleep_for(chrono::milliseconds(threadRandom(0, 20)));
    }
}

// Job pour le comptable
void comptableJob(const pr::Banque &banque, int iterations, int bilanAttendu) {
    for (int i = 0; i < iterations; ++i) {
    	banque.afficherBilan();
        if (!banque.comptabiliser(bilanAttendu)) {
            cout << "Erreur !" << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}


// Fonction principale
int main () {

	// Initialise une banque avec 100 comptes, chacun ayant un solde initial
	pr::Banque banque(100, SOLDE_INITIAL);

	// Vector pour stocker les threads
    vector<thread> threads;

    // Calcul du bilan attendu après toutes les transactions
    int bilanAttendu = NB_THREAD * NB_TRANSACTIONS * (SOLDE_INITIAL / 100);

    // Création et lancement des threads
    for (int i = 0; i < NB_THREAD; ++i) {
    	// Chaque thread exécute la fonction transaction
		threads.emplace_back(transactionJob, ref(banque), NB_TRANSACTIONS);
    }

    // Lancer le thread comptable
    thread comptable(comptableJob, ref(banque), 50, bilanAttendu);

    // Attente de la fin de l'exécution de tous les threads
    for (auto &t : threads) {
    	t.join();
    }

    // Attendre le thread comptable
    comptable.join();

    // Vérifie que le total des soldes dans la banque correspond au bilan attendu
    //banque.comptabiliser(bilanAttendu);

	return 0;
}
