#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr){

    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
     vector<int>arr={20,5,21,4,1,0};

     bubble_sort(arr);
      for(int&a:arr){
        cout<<a<<" ";
    }
    return 0;
}