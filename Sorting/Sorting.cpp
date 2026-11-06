#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include <float.h>
using namespace std;

void selectionSort(vector<int> &v) {
    // you basically find the index of the
    // smallest element in the unsorted part
    for (int i = 0; i < v.size() - 1; i++) {

        int min = i;

        for (int j = i+1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        // int temp = v[min];  smallest element in the sub-array
        // v[min] = v[i];
        // v[i] = temp;

        swap(v[i], v[min]);

        // swap once every ith iteration with the smallest element
        // O(n) = n^2
    }
}
void bubbleSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1 ; j++) {
            if (v[j+1] < v[j]) {
                swap(v[j+1], v[j]);
            }
        }
    } // Time Complexity = O(n^2)
}
void insertionSort(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j-1] > v[j]) { // we only reduce j if j-1 is smaller otherwise we stop
            swap(v[j-1], v[j]);
            j--;
        }
    }
}\
void mergeSort(vector<int> &v) {

}

int main() {
    vector<int> test = {13,46,24,52,20,9,2};
    bubbleSort(test);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " " ;
    }
}