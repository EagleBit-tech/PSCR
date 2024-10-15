/*
 * There's no .cpp files, since there's the template
 * Implements in the header files
 */

#ifndef __HASHMAP_HH__
#define __HASHMAP_HH__

#include <forward_list>
#include <vector>

// Add grow for the capacity
template <typename K, typename V>

class HashMap {

	class Entry{
		public:
			const K key;
			V value;
			Entry(const K key, V value) : key(key), value(value) {}
	};

public:
	// Vecteur de liste :
	typedef std::vector<std::forward_list<Entry>> buckets_t;

	buckets_t buckets;

	size_t current_size;

	// remplir les listes de 0 -> buckets(capacity) -> init par défaut
	HashMap(size_t capacity) : buckets(capacity), current_size(0){}

	bool put(const K & key, const V & value) {
		// key -> int = index
		int h = std::hash<K>()(key);
		// pour que l'index soit compris entre 0 et la taille du buckets
		int index = h % buckets.size();

		for(Entry & elt : buckets[index])
			if(elt.key == key){
				elt.value = value;
				return true;
			}

		buckets[index].push_front(Entry(key, value));
		current_size++;
		return false;
	}

	V* get(const K & key) {
		// key -> int = index
		int h = std::hash<K>()(key);
		// pour que l'index soit compris entre 0 et la taille du buckets
		int index = h % buckets.size();

		for(Entry & elt : buckets[index])
			if(elt.key == key)
				return &elt.value;
		return nullptr;

	}

};



#endif
