#include <fstream>

#include "segment_tree.h"

int main() {
	std::fstream file;
	file.open("input.txt", std::fstream::in);
	int quantity_of_numbers;
	int quantity_of_queries;
	file >> quantity_of_numbers >> quantity_of_queries;
	int leaves_quantity = 1; // quantity, which is power of 2 and >= quantity_of_numbers
	while (leaves_quantity < quantity_of_numbers) {
		leaves_quantity *= 2;
	}

	return 0;
}