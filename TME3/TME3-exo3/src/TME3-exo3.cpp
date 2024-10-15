#include <algorithm>
#include <cctype>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <unordered_map>

int main() {
    using namespace std;

    unordered_map<string, int> map;
    ifstream input = ifstream("E:\\workplace-C-Plus-Plus\\HashMap\\src\\WarAndPeace.txt");

	string word;

	regex re( R"([^a-zA-Z])");
	while (input >> word) {

		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");

		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		auto result = map.insert({word, 1});
		if (!result.second) {
			result.first->second += 1;
		}
	}
    input.close();

    unordered_map<int, forward_list<string>> frequency;

    for (const auto& entry : map) {
    	frequency[entry.second].push_front(entry.first);
    }

    int N = 10;
    cout << "Les mots avec " << N << " occurrences : " << endl;
    if (frequency.find(N) != frequency.end()) {
        for (const string& word : frequency[N]) {
            cout << word << endl;
        }
    } else {
        cout << "Aucun mot trouvé avec " << N << " occurrences." << endl;
    }

    return 0;
}
