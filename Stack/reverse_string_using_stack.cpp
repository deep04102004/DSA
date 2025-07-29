#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse_string(string &s)
{
    int n = s.length();
    stack<char> st;

    for (char &ch : s){
        st.push(ch); // Push every character of string into stack
    }

    int i = 0;
    /*As we know stack is Follow LIFO rule so thats why when we replace these char from top in original string than it become reverse*/
    while (!st.empty() && i < n){
        char c = st.top();
        s[i] = c;
        st.pop();
        i++;
    }
}

int main()
{
    string s = "leetcode";
    reverse_string(s);

    cout << s;
}