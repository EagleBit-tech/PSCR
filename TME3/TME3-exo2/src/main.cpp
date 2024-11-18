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
#include "HashMap.hh"


int main() {

	using namespace std;

    HashMap<string, int> map(3000);

    // ouvrir le fichier en lecture
    ifstream input = ifstream("E:\\workplace-C-Plus-Plus\\HashMap\\src\\WarAndPeace.txt");

    string word;

    regex re( R"([^a-zA-Z])");
    int nombre_lu = 0;
    while (input >> word) {

		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");

		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		// cherche si le mot a déjà été lu
		auto it = map.get(word);
		int occ = 1;
		// si c'est un ancien mot
		if(it){
			occ = *it + 1;
			map.put(word, occ);
		}

		map.put(word, occ);
    }
	input.close();

    /*for (const auto& bucket : map.buckets)
		for (const auto& entry : bucket)
			cout << entry.key << ": " << entry.value << endl;
	cout << map.current_size << endl;*/

	vector<pair<string, int>> vector;

	for (auto bucket_it = map.buckets.begin(); bucket_it != map.buckets.end(); ++bucket_it) {
		for (auto entry_it = bucket_it->begin(); entry_it != bucket_it->end(); ++entry_it) {
			vector.push_back(make_pair(entry_it->key, entry_it->value));
		}
	}

	sort(vector.begin(), vector.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
	        return a.second > b.second;
	    });

	cout << "Les 10 mots les plus fréquents : " << endl;
	    for (int i = 0; i < 10 && i < vector.size(); ++i) {
	        cout << vector[i].first << ": " << vector[i].second << endl;
	    }

    return 0;
}
