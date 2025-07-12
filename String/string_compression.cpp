//443. String Compression
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int ansindex = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            chars[ansindex++] = chars[i];  // place current character

            int count = j - i;

            if (count > 1) {
                string s = to_string(count);
                for (char ch : s) {
                    chars[ansindex++] = ch;  // place each digit
                }
            }

            i = j;  // move to the next group
        }

        return ansindex;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    // Call compress function
    int length = sol.compress(chars);

    // Output compressed result
    cout << "Compressed Length: " << length << endl;
    cout << "Compressed Output: ";
    for (int i = 0; i < length; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
