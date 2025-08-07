#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  private:
    // Convert "HH:MM:SS" to total seconds
    int tosec(string &time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return (h * 3600 + m * 60 + s);
    }

  public:
    // Return minimum difference in seconds between any two times
    int minDifference(vector<string> &arr) {
        int n = arr.size();
        vector<int> sec;

        for (int i = 0; i < n; i++) {
            sec.push_back(tosec(arr[i]));
        }

        sort(sec.begin(), sec.end());

        int mindiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            int diff = sec[i] - sec[i - 1];
            mindiff = min(mindiff, diff);
        }

        // Circular difference: last and first (across midnight)
        int cirdiff = 86400 - sec[n - 1] + sec[0];
        mindiff = min(mindiff, cirdiff);

        return mindiff;
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"12:30:15", "12:30:45", "14:00:00"};

    int result = sol.minDifference(arr);
    cout << "Minimum time difference in seconds: " << result << endl;

    return 0;
}
