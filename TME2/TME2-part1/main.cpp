#include <stddef.h>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

/*
 * Total mot lus = 566193
 * Mots distincts = 20333
 * */

int main () {

	using namespace std;
	using namespace std::chrono;

	// ouvrir le fichier en lecture
	ifstream input = ifstream("WarAndPeace.txt");

	auto start = steady_clock::now();

	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;

	// prochain mot lu
	string word;

	// le vecteur qui contient les mots distincts
	vector<string> distinct_words;

	// le vecteur qui contient la pair (mot, occurence)
	vector<pair<string,int>> occurrence;

	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");

	while (input >> word) {

		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");

		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		// cherche si le mot a déjà été lu
		auto it = find(distinct_words.begin(), distinct_words.end(), word);

		// si c'est un nouveau mot
		if(it == distinct_words.end()){

			// ajouter le nouveau mot dans le vecteur
			distinct_words.push_back(word);

			auto first = std::make_pair(word, 1);
			occurrence.push_back(first);

		}

		// si le mot existe déjà
		else{

			// récupère la position exacte du mot
			int pos = distance(distinct_words.begin(), it);

			// récupère la pair
			auto& pair = occurrence[pos];

			// incrémente l'occurrence
			pair.second++;
		}

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		nombre_lu++;

	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;

    std::cout << distinct_words.size()<< ' ';

    // Afficher les occurrences
	for (auto& pair : occurrence) {
		if(pair.first == "war" || pair.first == "peace" || pair.first == "toto")
			cout << pair.first << ": " << pair.second << endl; // Affiche chaque mot et son occurrence
	}

    return 0;
}


