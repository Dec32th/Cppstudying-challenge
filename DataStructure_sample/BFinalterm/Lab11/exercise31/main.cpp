#include<iostream>
#include"GetHeightSum.hpp"

using namespace std;

int main()
{
    int values[] = { 25, 17, 26, 2, 3, 100, 1, 19, 7 };
    int numValues = sizeof(values) / sizeof(values[0]);

    cout << "Initial array: ";
    for (int i = 0; i < numValues; ++i)
        cout << values[i] << " ";
    cout << std::endl;

    // Print the tree
    cout << "Binary tree representation:\n";
    PrintTree(values, numValues, 0);
    cout << std::endl;

    // Calculate the sum of heights
    GetHeightSum(values, numValues);
}