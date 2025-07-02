//Painter's Problem With maximum Minimum time taken by painters.
 
#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> arr,int n, int mid, int k){
    int allocateboard=0;
    int painters=1;

    for(int i=0;i<n;i++){
        if(allocateboard+arr[i]<=mid){
            allocateboard+=arr[i];
        }
        
        else{
            painters++;
            if(painters>k || arr[i]>mid){
                return false;
            }
            allocateboard=arr[i];
        }
    }
   return true;
}

int minimum_time(vector<int>&arr,int k){
    int n= arr.size();
    int sum=0;
    int ans=0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int s=0,e=sum;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(ispossible(arr,n,mid,k)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
  vector<int>arr={5, 10, 30, 20, 15};
  int k=3;

  cout<<minimum_time(arr,k);  //output: 35
}