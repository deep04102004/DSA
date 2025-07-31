//898. Bitwise ORs of Subarrays
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> curr;
    unordered_set<int> result;

    for (int a : arr) {
        unordered_set<int> next;
        next.insert(a);  // start new subarray

        for (int x : curr) {
            next.insert(x | a);  // extend previous subarrays
        }

        curr = next;

        for (int x : curr) {
            result.insert(x);  // store unique ORs
        }
    }

    return result.size();
}

int main() {
    vector<int> arr = {1, 2, 4};

    int uniqueORs = subarrayBitwiseORs(arr);
    cout << "Number of unique subarray ORs: " << uniqueORs << endl;

    return 0;
}
