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
/////////////SORTING ALGO TO USE//////////////////////
void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j-1] > v[j]) {
            swap(v[j-1], v[j]);
            j--;
        }

    }
}
/////////////SORTING ALGO TO USE//////////////////////


/////////////DOING IT BYMYSELF//////////////////////
int largestElement_Myself1(vector<int> &v) {
    insertionSort(v);
    int largest = v.back();
    return largest;
}
int largestElement_Myself2(vector<int> &v) {
    int largest = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > largest) {
            largest = v[i];
        }
    }
    return largest;
}
int secondLargest_Myself1(vector<int> &v) {
    int largest = v[0];
    int secondLargest;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > largest) {
            secondLargest = largest;
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > secondLargest) { // if the second largest element comes in an index after the largest
            secondLargest = v[i];
        }
    }
    return secondLargest;
}
int secondSmallest_Myself1(vector<int> &v) {
    int smallest = v[0];
    int secondSmallest;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < smallest) {
            secondSmallest = smallest;
            smallest = v[i];
        }
        else if (v[i] > smallest && v[i] != smallest) {
            secondSmallest = v[i];
        }
    }
    return secondSmallest;
}
bool sortedArray_Myself(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] <= v[i+1]) { //if you use v.at(i+1) then you will give you an out of bounds error
        }
        else return false;
    }
    return true;
}
void removeDuplicates_Myself(vector<int> &v) {
    set<int> set;
    for (int i = 0; i < v.size(); i++) {
        set.insert(v[i]);
    }
    v.clear(); //clear the whole vector
    for (auto it = set.begin(); it != set.end(); it++){v.push_back(*it);}
}
void leftRotate_Myself(vector<int> &v) {
    int firstElement = v[0];
    for (int i = 1; i < v.size(); i++) {
        v[i-1] = v[i];
    }
    v[v.size()-1] = firstElement;
}
void leftRotatebyD_brute_Myself(vector<int> &v, int d) {
    d = d % v.size();
    vector<int> sup;
    for (int i = 0; i < d; i++) {
        sup.push_back(v[i]);
    }
    for (int j = d; j < v.size(); j++) {
        v[j-d] = v[j];
    }
    for (int k = d+1; k < v.size(); k++) {
        v[k] = sup[k - (k-d-1)]; //line changed
    }
    // }
}

int largestElement_Myself(vector<int> &v) {
    int largest = -100;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > largest) {
            largest = v[i];
        }
    }
    return largest;
}
/////////////DOING IT BYMYSELF//////////////////////





int largestElement(vector<int> &v) {
    int largest = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > largest) {
            largest = v[i];
        }
    } return largest;
}
int secondLargest_bruteforce(vector<int> &v) {
    insertionSort(v);
    int largest = v[v.size()-1];
    int secondlargest;
    for (int i = v.size()-2; i >= 0; i--) {
        if (v[i] != largest) {
            secondlargest = v[i];
            break;
        }
    }
    return secondlargest;
}
int secondLargest_better(vector<int> &v) {
    int largest = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > largest) {
            largest = v[i];
        }
    } //FIRST PASS
    int slargest = -1; //assuming that all values are greater than 0.
    for (int i = 0; i <= v.size(); i++) {
        if (v[i] > slargest && v[i] != largest) {
            slargest = v[i];
        }
    } return slargest;
}//SECOND PASS
int secondLargest_optimal(vector<int> &v) {
    int largest = v[0];
    int slargest = -1; //array doesn't contain negative numbers or take integer minimum.
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > largest) {
            slargest = largest;
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > slargest) {
            slargest = v[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &v) {
    int smallest = v[0];
    int secondSmallest = INT_MAX;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < smallest) {
            smallest = v[i];
            secondSmallest = smallest;
        }
        else if (v[i] != smallest && v[i] < secondSmallest) {
            secondSmallest = v[i];
        }
    }
    return secondSmallest;

}
int sortedArray(vector<int> &v) { //Sorted in an ascending order.
    for (int i = 1; i < v.size();i++) {
        if (v[i] >= v[i-1]) {

        }
        else {
            return false;
        }
    } return true;
}
void removeDuplicates(vector<int> &v) {
    set<int> unique;
    for (int i = 0; i < v.size(); i++) {
        unique.insert(v[i]);
    }
    vector<int> final(10);
    int index = 0;

    for (auto it: unique) {
        final[index] = it;
        index++;
    }
    for (int i = 0; i < final.size(); i++) {
        cout << final[i] << ' ';
    }
}
int removeduplicates_optimal(vector<int> &v) {
    int i = 0;
    for (int j = 1; j < v.size(); j++) {
        if (v[j] != v[i]) {
            v[i+1] = v[j];
            i++;
        }
    }return i+1;
} //????????DO IT AGAIN / SEARCHHHHH
void leftRotate(vector<int> &v) {
    int temp = v[0];
    for (int i = 1; i < v.size(); i++) {
        v[i-1] = v[i];
    }
    v[v.size()-1] = temp;
}
void leftRotatebyD_brute(vector<int> &v, int d) {
    d = d % v.size();
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = v[i];
    }
    for (int j = d; j < v.size(); j++) {
        v[j-d] = v[j];
    }
    for (int k = v.size()-d; k < v.size(); k++) {
        v[k] = temp[k - (v.size()-d)];
    }
} //HARD LOOK AT YT
void zeroesToTheEnd(vector<int> &v) {
    vector<int> temp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            temp.push_back(v[i]);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] = temp[i];
    }
    for (int i = temp.size(); i < v.size(); i++) {
        v[i] = 0;
    }
}
void zeroesToTheEnd_optimal(vector<int> &v) {
    int j = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            j = i;
            break;
        };
    }
    for (int i = j+1; i < v.size(); i++) {
        if (v[i] != 0) {
            swap(v[i], v[j]);
            j++;
        }
    }
}
int linearSearch(vector<int> v, int num) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == num) {
            return i;
        }
    }
    return -1;
}
vector<int> unionOfTwoSets(vector<int> v, vector<int> w) {
    set<int> sett;
    vector<int> vec;
    for (int i = 0; i < v.size(); i++) {
        sett.insert(v[i]);
    }
    for (int j = 0; j < v.size(); j++) {
        sett.insert(w[j]);
    }
    for (auto k : sett)
        vec.push_back(k);
    return vec;
}
vector<int> unionOfTwoSets_optimal(vector<int> v, vector<int> w) {
    int i = 0;
    int j = 0;
    vector<int> mod;
    while (i < v.size() && j < w.size()) {
        if (v[i] <= w[j]) {
            if ( mod.size() == 0 || v[i] != mod.back()) {
                mod.push_back(v[i]);
            }
            i++;
        }
        else {
            if (w[j] != mod.back()) {
                mod.push_back(w[j]);
            }
            j++;
        }
    }
    while (i < v.size()) {
        if (v[i] != mod.back()) {
                mod.push_back(v[i]);
            }
        i++;
    }
    while (j < w.size()) {
        if (w[j] != mod.back()) {
                mod.push_back(w[j]);
            }
        j++;
    }
    return mod;
}
vector<int> intersectionOfTwoArrays(vector<int> v, vector<int> w) {
    vector<int> vis(w.size());
    vector<int> intersect;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < w.size(); j++) {
            if (v[i] == w[j] && vis[j] == 0) {
                intersect.push_back(v[i]);
                vis[j] = 1;
                break;
            }
            if (w[j] > v[i]) break;
        }
    }
}
vector<int> intersectionOfTwoArrays_optimal(vector<int> v, vector<int> w) {
    //2 Pointer Approach
    int i = 0;
    int j = 0;
    vector<int> intersect;
    while (i < v.size() && j < w.size()) {
        if (v[i] == w[j]) {
            intersect.push_back(v[i]);
            i++;
            j++;
        }
        else if(v[i] < w[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return intersect;
}
int findMissingNumbers(vector<int> v, int size) {
    for (int i = 1; i <= size; i++) {
        int flag = 0;
        for (int j = 0; j < size-1; j++) {
            if (v[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
}
int findMissingNumbers_better(vector<int> v, int size) {
    vector<int> hash(size+1);
    for (int i = 0; i < size - 1; i++) {
        hash[v[i]] = 1;
    }
    for (int i = 1; i <= size; i++) {
        if (hash[i] == 0) return i;
    }
}
int findMissingNumbers_optimal1(vector<int> v, int size) {
    int sum = 0;
    int sumInVector = 0;
    sum = size * (size + 1)/ 2;
    for (int i = 0; i < v.size(); i++) {
        sumInVector += v[i];
    }
    return sum - sumInVector;
}
int findMissingNumbers_optimal2(vector<int> v, int size) {
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 1; i <= size; i++) {
        xor1 ^= i;
    }
    for (int j = 0; j < size-1; j++) {
        xor2 ^= v[j];
    }
    return xor1 ^ xor2;
}
int findMissingNumbers_optimal3(vector<int> v, int size) {
    int xor1 = 0;
    int xor2 = 0;

    for (int j = 0; j < size-1; j++) {
        xor1 ^= j+1;
        xor2 ^= v[j];
    }
    xor1 ^= size;
    return xor1 ^ xor2;
}
int maxConsecutiveOnes(vector<int> v) {
    int consec = 0;
    int maxi = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            consec += 1;
            maxi = max(consec,maxi);
        }
        else {
            consec = 0;
        }
    }
    return maxi;
}
int numberAppearingOnce_brute(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        int count = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == num) {
                count++;
            }
        }
        if (count == 1) return num;
    }
}
int numberAppearingOnce_better1(vector<int> v) {
    int maxi = 0;
    for (int i = 0; i < v.size(); i++) {
        maxi = max(maxi, v[i]);
    }
    vector<int> hash(maxi + 1);
    for (int j = 0; j < v.size(); j++) {
        hash[v[j]] += 1;
    }
    for (int k = 1; k <= hash.size(); k++) {
        if (hash[k] == 1) return k ;
    }
}
int numberAppearingOnce_better2(vector<int> v) {
    map<int, int> mapp;
    for (int i = 0; i < v.size(); i++) {
        mapp[v[i]]++;
    }
    for (auto it : mapp) {
        if (it.second == 1) return it.first;
    }
}
int numberAppearingOnce_optimal(vector<int> v) {
    int zor = 0;
    for (int i = 0; i < v.size(); i++) {
        zor ^= v[i];
    }
    return zor;
}
int longestSubarray_brute1(vector<int> v, int target) {
    int len = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size();j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) { //adds each value in the subarray
                sum += v[k];
            }
            if (sum == target) {
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}
int longestSubarray_brute2(vector<int> v, int target){
    int len = 0;
    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        for (int k = i; k < v.size(); k++) {
            sum += v[k];
            if (sum == target) {
                len = max(len,k-i+1);
            }
        }
    }
    return len;
}
int longestSubarray_better(vector<int> v, int target) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum == target) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - target;
        if (preSumMap.find(rem) != preSumMap.end()) { //if we find rem in the map
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {  //If we don't find 'sum' in the vector add it to the map
            preSumMap[sum] = i;
        }
    }
    return maxLen;
} //HARDDDDDDD
int longestSubarray_optimal(vector<int> v, int target) {
    int left = 0;
    int right = 0;
    long long sum = v[0];
    int maxLen = 0;
    while (right < v.size()) {
        while (left <= right && sum > target ) {
            sum -= v[left];
            left++;
        }
        if (sum == target) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < v.size()) {
            sum += v[right];
        }
    }
    return maxLen;
} //HARDDDDDDD
vector<int> twoSum_brute(vector<int> v, int target) {
    vector<int> index;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            if (v[i] + v[j] == target) {
                index.push_back(i);
                index.push_back(j);
                goto hello;
            }
        }
    }
    hello:
    return index;
}
string twoSum_better(vector<int> v, int target) {
    map<int, int> mapp;
    for (int i = 0; i < v.size(); i++) {
        int elem = v[i];
        int extra = target - elem;
        if (mapp.find(extra) != mapp.end()) {
            return "Yes";
        }
        mapp[elem] = i;
    }
    return "No";
}
string twoSum_optimal(vector<int> v, int target) {
    insertionSort(v);
    int left = 0;
     int right = v.size()-1;
    while (left != right) {
        if (v[left] + v[right] == target) return "True";
        if (v[left] + v[right] < target) {
            left++;
        }
        else if (v[left] + v[right] > target) {
            right--;
        }
    }
    return "False";
}
void sortZeroOneTwo_brute(vector<int> &v) {}             //just sort
void sortZeroOneTwo_better(vector<int> &v) {
    int ones = 0;
    int twos = 0;
    int zeroes = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) zeroes++;
        else if (v[i] == 1) ones ++;
        else twos++;
    }
    for (int j = 0; j < zeroes; j++) v[j] = 0;
    for (int k = zeroes ; k < ones + zeroes; k++) v[k] = 1;
    for (int l = ones + zeroes; l < v.size(); l++) v[l] = 2;
}
void sortZeroOneTwo_optimal(vector<int> &v) { //Dutch National Flag Algorithm
    int low = 0;
    int mid = 0;
    int high = v.size()-1;
    while (mid <= high) {
        if (v[mid] == 0) {
            swap(v[low], v[mid]);
            mid++;
            low++;
        }
        else if (v[mid] == 1) {
            mid++;
        }
        else {
            swap(v[mid], v[high]);
            high--;
        }

    }
}
int majorityElement(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int element = v[i];
        int count  = 0;
        for (int j = i; j < v.size(); j++) {
            if (element == v[j]) count++;
            else if (element != v[j]) break;
        }
        if (count > v.size()/2) {
            return v[i];
        }
    }
    return -1;
}


int main() {
    vector<int> test = {1,2,3,9,7,2};
    // leftRotatebyD_brute_Myself(test, 4);
    // for (auto it = test.begin(); it != test.end(); it++) { cout << *(it) << " ";}
    // int test1[] = {1,0,3,4};
    cout << largestElement_Myself(test);
    // for (int i = 0; i < test.size(); i++) {
    //     cout << test[i] ;
    // }
}