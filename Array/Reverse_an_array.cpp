//Reverse an Array.
#include<bits/stdc++.h>
using namespace std;

void array_reverse(vector<int> &arr){
    int n=arr.size();
    int i=0,j=n-1;

    while(i<j){
        swap(arr[i++],arr[j--]);
    }
}

int main(){
    vector<int>arr={0,1,2,3,4,5};
    
    array_reverse(arr);

    for(int a:arr){
        cout<<a<<" ";
    }
}