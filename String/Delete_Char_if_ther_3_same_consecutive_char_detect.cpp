//1957. Delete Characters to Make Fancy String
#include<iostream>
#include<string>
using namespace std;

 string makeFancyString(string s) {
        int n = s.length();
        int i = 0;

        string res = "";

        while (i < n) {
            int j = i;
            int count = 0;

            while (j < n) {
                if (s[i] == s[j]) {
                    count++;

                    if (count <= 2) {
                        res += s[j];
                    }
                }

                else {
                    break;
                }
                j++;
            }
            i += count;
        }
        return res;
    }
    
int main(){
    string s = "aaabaaaa";
    cout<<makeFancyString(s);

    return 0;
}