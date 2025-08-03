#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void NextSmaller(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    st.push(-1);  // Sentinel value

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Pop elements from stack until we find a smaller one
        while (st.top() >= curr) {
            st.pop();
        }

        arr[i] = st.top();  // Next smaller element to the right
        st.push(curr);      // Push current element onto stack
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 5, 3};

    NextSmaller(arr);

    cout << "Next smaller elements: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
