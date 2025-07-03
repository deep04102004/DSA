//Selection sort
#include<bits/stdc++.h>
using namespace std;

void Selection_sort(vector<int> &arr){
    
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                 swap(arr[i],arr[j]);
            }
        }
    }
}

int main(){
    vector<int>arr={20,5,21,4,1,0};

    Selection_sort(arr);
    for(int&a:arr){
        cout<<a<<" ";
    }

    return 0;
}