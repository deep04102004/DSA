//567. Permutation in String
#include<bits/stdc++.h>
using namespace std;

bool isequal(vector<int>count1,vector<int>count2){
    for(int i=0;i<count1.size();i++){
        if(count1[i]!= count2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int n=s1.size(), m=s2.size();

    vector<int>count1(26,0);
    vector<int>count2(26,0);

    for(int i=0;i<n;i++){
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }
     
    int j=n;

    while(j<m){
        if(isequal(count1,count2)){
            return true;
        }
         
        count2[s2[j]-'a']++;
        count2[s2[j-n]-'a']--;

        j++;
    }

    return isequal(count1,count2);
}

int main(){
  string s1 = "ab", s2 = "eidbaooo";
    if(checkInclusion(s1,s2)){    //Output: true
        cout<<"true"; 
    }
    else{
        cout<<"false";
    }                        
}
