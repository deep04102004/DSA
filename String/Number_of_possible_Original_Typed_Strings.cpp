//3330. Find the Original Typed String I
#include<bits/stdc++.h>
using namespace std;

int possibleStringCount(string word) {
     int count=1;
    
     for(int i=1;i<word.size();i++){
        if(word[i-1]==word[i]){                 //compare current element with last element.
            count++;
        }
     }
     return count;
}

int main(){
    string word ="abbcccc";
    cout<<possibleStringCount(word);    //Output: 5

    return 0;
}
