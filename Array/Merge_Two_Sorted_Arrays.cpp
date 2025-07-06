// Merge two sorted array.
#include<bits/stdc++.h>
using namespace std;

vector<int> merge_array(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size(),m=arr2.size();
    int i=0,j=0;

    vector<int>arr3;

    while(i<n && j<m){

        if(arr1[i]<arr2[j]){
        arr3.push_back(arr1[i++]);
        }

        else{
          arr3.push_back(arr2[j++]);
        }
    }

    while(i<n){
        arr3.push_back(arr1[i++]);
    }
    
    while(j<n){
        arr3.push_back(arr2[j++]);
    }

    return arr3;

}

int main(){
    vector<int>arr1={1,3,5,9};
    vector<int>arr2={2,4,6,7,8};

    vector<int>arr3=merge_array(arr1,arr2);

    for(int a:arr3){
        cout<<a<<" ";
    }
}