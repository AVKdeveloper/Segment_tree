#include "segment_tree.h"


SegmentTree::SegmentTree(const int& quantity_of_numbers) 
	: kInfinity_(std::numeric_limits<int>::max()) {
	leaves_quantity_ = 1; // quantity, which is power of 2 and >= quantity_of_numbers
	while (leaves_quantity_ < quantity_of_numbers) {
		leaves_quantity_ *= 2;
	}
	// ¬ мыссиве vertices последние quantity_of_numbers элементов - листь€
	vertices.resize(2 * leaves_quantity_ - 1, { kInfinity_, kInfinity_ });
}

void SegmentTree::AddLeaf(const int& number, const int& leaf_position) {
	vertices[leaves_quantity_ - 1 + leaf_position].first = number;
}

void SegmentTree::BuildTree() {
	// Before call this method we need to add all the leaves
	// for element vertices[i] there are two his children: 2i+1 and 2i+2
	for (int i = leaves_quantity_ - 2; i >= 0; --i) {
		int first_min = std::min(vertices[2 * i + 1].first, vertices[2 * i + 2].first);
		int second_min = std::min(std::max(vertices[2 * i + 1].first, vertices[2 * i + 2].first),
			std::min(vertices[2 * i + 1].second, vertices[2 * i + 2].second));
		vertices[i].first = first_min;
		vertices[i].second = second_min;
	}
}

int SegmentTree::FindSecondMin(const std::pair<int, int>& segment) const {
	// «апрос минимума "снизу"
	int current_min = kInfinity_;
	int current_second_min = kInfinity_;
	// 1) »нициализируем левую и правую границы отрезка дл€ листов
	int left = leaves_quantity_ - 1 + segment.first;
	int right = leaves_quantity_ - 1 + segment.second;
	while (left < right) { // ѕока текущий отрезок €вл€етс€ корректным
		// ”читываем крайние вершины на данном уровне, 
		// если они будут лежать вне вершин, охватываемых на уровень выше
		int new_left = (left - 1) / 2;
		int new_right = (right - 1) / 2;
		if (left == 2 * new_left + 2) {
			++new_left;
			current_second_min = std::min(std::max(current_min, vertices[left].first),
				std::min(current_second_min, vertices[left].second));
			current_min = std::min(current_min, vertices[left].first);
		}
		if (right == 2 * new_right + 1) {
			--new_right;
			current_second_min = std::min(std::max(current_min, vertices[right].first),
				std::min(current_second_min, vertices[right].second));
			current_min = std::min(current_min, vertices[right].first);
		}
		left = new_left;
		right = new_right;
	}
	if (left == right) { // ≈сли от отрезка осталась одна вершина на текущем уровне
		current_second_min = std::min(std::max(current_min, vertices[left].first),
			std::min(current_second_min, vertices[left].second));
		current_min = std::min(current_min, vertices[left].first);
	}
	return current_second_min;
}