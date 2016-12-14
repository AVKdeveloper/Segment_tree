#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

class SegmentTree {
	const int kInfinity;
	int leaves_quantity_;
	std::vector<std::pair<int, int>> vertices;
public:
	SegmentTree(const int& quantity_of_numbers);
};

#endif // SEGMENT_TREE_H