#include <iostream>
#include <vector>
#include "Count.hh"
using namespace std;

int main() {

	 vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

	cout << count(cars.begin(), cars.end())<< endl;

	cout << count_if_equal(cars.begin(), cars.end(), "Volvo")<< endl;

	return 0;
}
