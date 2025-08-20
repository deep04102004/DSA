#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Bucket array to count citation frequencies
        vector<int> bucket(n+1, 0);
        
        // Fill bucket
        for (int c : citations) {
            if (c >= n) bucket[n]++;   // all big values go into last bucket
            else bucket[c]++;
        }
        
        // Traverse from high to low
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += bucket[i];   // total papers with >= i citations
            if (count >= i) return i;
        }
        
        return 0;  // default
    }
};

int main() {
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};

    cout << "H-index = " << sol.hIndex(citations) << endl;
    return 0;
}
