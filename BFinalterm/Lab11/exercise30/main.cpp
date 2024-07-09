#include<iostream>
#include"HeapSort.hpp"
using namespace std;

int main() 
{
    int values[] = { 25, 17, 36, 2, 3, 100, 1, 19, 7 };
    int numValues = sizeof(values) / sizeof(values[0]);

    HeapSort(values, numValues);

    // Á¤·Ä
    cout << "Sorted array: ";
    for (int i = 0; i < numValues; ++i)
        cout << values[i] << " ";
    cout << endl;

}