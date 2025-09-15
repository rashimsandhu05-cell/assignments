#include <iostream>
#include <vector>
using namespace std;

// Linear Search: O(n)
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i; // index found
    }
    return -1; // not found
}

// Binary Search: O(log n) - works only on sorted arrays
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // prevent overflow
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1; // search right half
        else
            right = mid - 1; // search left half
    }
    return -1; 
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 9;

    int linearResult = linearSearch(arr, target);
    int binaryResult = binarySearch(arr, target);

    cout << "Linear Search Result: ";
    if (linearResult != -1)
        cout << "Found at index " << linearResult << endl;
    else
        cout << "Not found" << endl;

    cout << "Binary Search Result: ";
    if (binaryResult != -1)
        cout << "Found at index " << binaryResult << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
