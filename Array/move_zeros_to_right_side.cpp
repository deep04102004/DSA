//Move Zeros to Right side of an Array
#include<bits/stdc++.h>
using namespace std;

void movezeros(vector<int>&arr1){
    int nonzero=0;
    
    for(int i=0;i<arr1.size();i++){
        if(arr1[i]!=0){
               if(i!=nonzero)
               swap(arr1[i],arr1[nonzero]);

         nonzero++;
         }
        }
    }

int main(){
    vector<int>arr1={1,0,2,0,3,4};

    movezeros(arr1);

    for(int&a:arr1){
        cout<<a<<" ";
    }
}