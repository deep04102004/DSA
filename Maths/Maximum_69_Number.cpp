//1323. Maximum 69 Number~
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        // change num to string
        string s = to_string(num);

        // Replace first occurrence of 6 with 9
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }

        return stoi(s); // convert string back to int
    }
};

int main() {
    Solution sol;
    int num = 9669;  
    cout << "Maximum number: " << sol.maximum69Number(num) << endl;
    return 0;
}
