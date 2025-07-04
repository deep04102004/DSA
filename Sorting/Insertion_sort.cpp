//insertion sort

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
    int n= arr.size();

    for(int i=1;i<n;i++){
         int key=arr[i];
         int j=i-1;
         
         while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
         }
         arr[j+1]=key;
    }
}

int main(){
   vector<int>arr={20,5,21,4,1,0};

     insertion_sort(arr);
      for(int&a:arr){
        cout<<a<<" ";
    }
    return 0;
}