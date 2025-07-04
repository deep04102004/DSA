//find position of target in rotated sorted array.
#include<bits/stdc++.h>
using namespace std;

//Find the position of pivot elment in array
int findpivot(vector<int>arr,int n){
    int s=0,e=n-1;

    while(s<e){
        int mid=s+(e-s)/2;

        if(arr[mid]>arr[e]){
            s=mid+1;
        }

        else{
            e=mid;
        }
    }
    return e;
}

//Simply Doing Binary Search
int BinarySearch(vector<int>arr,int s,int e,int target){
   while(s<=e){
     int mid=s+(e-s)/2;

     if(arr[mid]==target){
        return mid;
     }

     else if(arr[mid]>target){
        e=mid-1;
     }

     else{
        s=mid+1;
     }
   }
   return -1;
}

//find the position of target in rotated srted array
int findPosition(vector<int>arr,int target){
    int n=arr.size();
    int pivot=findpivot(arr,n);

    if(arr[pivot]<=target && target<=arr[n-1]){
      return BinarySearch(arr,pivot,n-1,target);
    }

    else{
        return BinarySearch(arr,0,pivot-1,target);
    }

  return -1;
}

int main(){
    vector<int>arr={3,4,1,2,};
    int target=1;

    cout<<findPosition(arr,target);
    
    return 0;
}