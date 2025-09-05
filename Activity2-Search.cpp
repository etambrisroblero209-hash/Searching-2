//Eduardo Tambris Roblero
// September 04, 2025
// Linear and Binary Search
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