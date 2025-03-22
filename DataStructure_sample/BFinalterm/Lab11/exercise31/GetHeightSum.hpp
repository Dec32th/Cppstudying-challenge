#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

template <class ItemType>
int GetHeightSum(ItemType values[], int numValues);

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues);

template <class ItemType>
int GetHeightSum(ItemType values[], int numValues) {
    int index, sum = 0;
    // non-leaf 노드에 대해 그 노드를 루트로 하는 subtree의 height 계산
    for (index = numValues / 2 - 1; index >= 0; index--)
        sum += GetHeight(values, index, numValues - 1);

    cout << "sum of heights = " << sum << endl;
    return sum;
}

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues) {
    if (start > numValues) return 0; // start가 leaf이거나 tree 밖에 있는 경우
    int l_height = GetHeight(values, 2 * start + 1, numValues); // left subtree의 height
    int r_height = GetHeight(values, 2 * start + 2, numValues); // right subtree의 height
    return max(l_height, r_height) + 1; // “subtree height 중 큰 값 + 1” 을 리턴
}

// Helper function to print the tree for visualization
template <class ItemType>
void PrintTree(ItemType values[], int numValues, int index, int indent = 0) {
    if (index < numValues) {
        if (2 * index + 2 < numValues)
            PrintTree(values, numValues, 2 * index + 2, indent + 4);

        if (indent)
            cout << setw(indent) << ' ';
        if (2 * index + 2 < numValues)
            cout << " /\n" << setw(indent) << ' ';

        std::cout << values[index] << "\n ";

        if (2 * index + 1 < numValues) {
            cout << setw(indent) << ' ' << " \\\n";
            PrintTree(values, numValues, 2 * index + 1, indent + 4);
        }
    }
}