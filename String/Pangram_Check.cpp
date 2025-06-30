//1832. Check if the Sentence Is Pangram
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v1(26, 0);
        for (char& ch : sentence) v1[ch - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (v1[i] < 1) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string sentence = "thequickbrownfoxjumpsoverthelazydog"; // example pangram
    bool result = sol.checkIfPangram(sentence);
    cout << "Is Pangram: " << (result ? "Yes" : "No") << endl;
    return 0;
}
