//812. Largest Triangle Area
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    double area = 0.5 * abs((points[i][0] * (points[j][1] - points[k][1])) +
                                            (points[j][0] * (points[k][1] - points[i][1])) +
                                            (points[k][0] * (points[i][1] - points[j][1])));
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    double result = sol.largestTriangleArea(points);

    cout << "Largest Triangle Area: " << result << endl;

    return 0;
}
