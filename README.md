# Searching-2

Task 1:
A linear search checks each element in the array one by one so it would four steps to find 8 in the array [2,4,6,8,10,12,13].

Task 2: 
A binary search has a different method compared to a linear search in that it repeatidly divides the search interval in half
when it comes to a sorted array. It would find 8 in one step in the array [2,4,6,8,10,12,13].

Task 3: 
The maximum number of steps it would take to do a binary search in array the size of n would be given by the formula log(n) 
with a base of two. In the question the value of n is 1000,000. So putting 100,000 in the equation would be log(100,000)
with base 2 would give us the maxium amount of steps it would take. The following eqaution gives us a value of 16.61 steps

Task 4:
// Eduardo Tambris Roblero
// September 4, 2025
// Linear and Binary Search- Activity 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int linearSearch(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    for (int i = 0; i < arr.size(); ++i) {
        steps++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int target, int& steps) {
    steps = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> data = {2, 4, 6, 8, 10, 12, 13};
    int target = 8;
    int steps;

    int linearIndex = linearSearch(data, target, steps);
    if (linearIndex != -1) {
        cout << "Linear search: Found " << target << " at index " << linearIndex << " in " << steps << " steps." << endl;
    } else {
        cout << "Linear search: " << target << " not found." << endl;
    }

    cout << "-----------------------------------" << endl;

    int binaryIndex = binarySearch(data, target, steps);
    if (binaryIndex != -1) {
        cout << "Binary search: Found " << target << " at index " << binaryIndex << " in " << steps << " steps." << endl;
    } else {
        cout << "Binary search: " << target << " not found." << endl;
    }

    return 0;
}
