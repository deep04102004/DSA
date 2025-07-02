// Book Allocation Problem with minimum pages.
#include<bits/stdc++.h>
using namespace std;

//This functionn tells whether books can allocate according to mid
bool ispossible(vector<int>&arr,int n,int mid,int k){
    int allocatepages=0;
    int studentcount=1;

    for(int i=0;i<n;i++){
        if(allocatepages+arr[i]<=mid){
        allocatepages+=arr[i];
        }
        else{
             studentcount++;
             if(studentcount>k || arr[i]>mid){
                return false;
             }
             allocatepages=arr[i];
        }
    }

   return true;
}

//This function gives maximum minimum pages.
int bookallocate(vector<int> &arr,int k){
    int n=arr.size();
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int s=0,e=sum;
    int ans=-1;

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
     vector<int>arr={12, 34, 67, 90}; //output 113
     int k=2;

     cout<<bookallocate(arr,2);
     return 0;
}