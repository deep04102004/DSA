//6. Zigzag Conversion
#include<bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
    if(numRows==1){
        return s;
    }
    
    int n=s.size();
    int i=0,rows=0;
    vector<string>zz(numRows);
    bool dir=true;
    while(i<n){
        if(dir){
            while(i<n && rows<numRows){
                zz[rows++].push_back(s[i++]);
            }
            rows-=2;
        }
        else{
            while(i<n && rows>=0){
                zz[rows--].push_back(s[i++]);
            }
            rows=1;
        }
        dir=!dir;
    }
    string ans="";
    for(auto&sh:zz){
       ans+=sh;
    }
    return ans;
}

int main(){
    // Output: "PAHNAPLSIIGYIR"
    string s = "PAYPALISHIRING";int  numRows = 3;

// Output: "PINALSIGYAHRPI"
string s2 = "PAYPALISHIRING";int  numRows2 = 4;
cout<<convert(s,numRows);
cout<<"hello";
return 0;
}
