//151. Reverse Words in a String
#include<bits/stdc++.h>
using namespace std;

string reverseword(string s){
    stringstream ss(s);
    string word;
    vector<string>words;

    while(ss>>word){
        words.push_back(word);
    }
     
    string res="";

    for(int i=words.size()-1;i>=0;i--){
        res+=words[i];

        if(i>0){
            res+=" ";
        }
    }
    return res;
}

int main(){
  string  s = "the sky is blue";
  cout<<reverseword(s);  //Output: "blue is sky the"

  return 0;
}