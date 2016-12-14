#include <fstream>
#include "segment_tree.h"

int main() {
	std::fstream file_in("input.txt", std::fstream::in);
	int quantity_of_numbers;
	int quantity_of_queries;
	file_in >> quantity_of_numbers >> quantity_of_queries;
	SegmentTree segment_tree(quantity_of_numbers);
	for (int i = 0; i < quantity_of_numbers; ++i) {
		int current_number;
		file_in >> current_number;
		segment_tree.AddLeaf(current_number, i);
	}
	segment_tree.BuildTree();
	std::fstream file_out("output.txt", std::fstream::out);
	for (int i = 0; i < quantity_of_queries; ++i) {
		std::pair<int, int> segment;
		file_in >> segment.first >> segment.second;
		file_out << segment_tree.FindSecondMin(segment) << std::endl;
	}
	file_in.close();
	file_out.close();
	return 0;
}