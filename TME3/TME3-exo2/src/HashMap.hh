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

	class iterator {
	        typename buckets_t::iterator vit;
	        typename std::forward_list<Entry>::iterator lit;
	        buckets_t &buckets;

	        iterator(typename buckets_t::iterator v_it, buckets_t &buckets) : vit(v_it), lit(v_it->begin()), buckets(buckets) {}

	        Entry& operator*() { return *lit; }

	        iterator & operator ++(){
	        	++lit;
	        	if(lit == vit->end())
	        		for(++vit ; vit != buckets.end(); ++vit)
	        			if(!vit->empty()){
	        				lit = vit->begin();
	        				break;
	        			}
	        	return *this;
	        }

	        bool operator!=(const iterator & other){
	        	return &buckets != &other.buckets;
	        }
	};
};



#endif
