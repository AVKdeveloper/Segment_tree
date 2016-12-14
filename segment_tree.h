// Эта библиотека хранит класс дерево отрезков.
// Асимптотики: построение O(n), 
// нахождение 2-ой порядковой статистики по отрезку за O(logn)
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
#include <limits>
#include <algorithm>

class SegmentTree {
	const int kInfinity_;
	int leaves_quantity_;
	std::vector<std::pair<int, int>> vertices;
public:
	SegmentTree(const int& quantity_of_numbers);
	void AddLeaf(const int& number, const int& leaf_position);
	void BuildTree();
	int FindSecondMin(const std::pair<int, int>& segment) const;
};

#endif // SEGMENT_TREE_H