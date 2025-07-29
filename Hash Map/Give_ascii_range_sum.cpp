//ASCII Range Sum (GFG)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> asciirange(string& s) {
    int n = s.size();
    unordered_map<char, pair<int, int>> mp;
    vector<int> result;

    // Save first and last occurrence of each character
    for (int i = 0; i < n; i++) {
        if (mp.count(s[i]) == 0) {
            mp[s[i]].first = i;   // first occurrence
        }
        mp[s[i]].second = i;      // always update last occurrence
    }

    // Calculate sum of ASCII values between first and last occurrence
    for (auto& ch : mp) {
        int start = ch.second.first;
        int last = ch.second.second;

        if (start < last) {
            int sum = 0;
            for (int i = start + 1; i < last; i++) {
                sum += (int)s[i];
            }

            if (sum > 0) {
                result.push_back(sum);
            }
        }
    }

    return result;
}

// 🔽 Driver code to test
int main() {
    string s = "abcbad";
    vector<int> res = asciirange(s);

    cout << "ASCII Sums Between First and Last Occurrences:" << endl;
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
