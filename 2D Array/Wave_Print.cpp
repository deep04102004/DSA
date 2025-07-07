#include<bits/stdc++.h>
using namespace std;

vector<int>waveprint(vector<vector<int>>&arr){
    int rows=arr.size();
    int cols=arr[0].size();

    vector<int>ans;
    
    for(int i=0;i<cols;i++){
    if(i&1){
        for(int j=rows-1;j>=0;j--){
            ans.push_back(arr[j][i]);
        }
    }

    else{
        for(int j=0;j<rows;j++){
            ans.push_back(arr[j][i]);
        }
    }
    }
    return ans;
}

int main(){
      vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};

      for(int&a:waveprint(arr)){
        cout<<a<<" ";
      }
}