//Reverse Array after Given Position.
#include<bits/stdc++.h>
using namespace std;

void array_reverse(vector<int> &arr,int pos){
    int n=arr.size();
    int i=pos+1,j=n-1;

    while(i<j){
        swap(arr[i++],arr[j--]);
    }
}

int main(){
    vector<int>arr={0,1,2,3,4,5};
    int pos=3;
    array_reverse(arr,pos);

    for(int a:arr){
        cout<<a<<" ";
    }
}