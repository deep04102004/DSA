//Find First ans Last Position of Array
#include<bits/stdc++.h>
using namespace std;

//finding first occurrence
int firstoccurrence(vector<int>arr,int target){       
  int n=arr.size();
  int s=0,l=n-1;
  int ans;

  while(s<=l){
    int mid=s+(l-s)/2;

    if(arr[mid]==target){
        ans=mid;
        l=mid-1;
    }

    else if(arr[mid]>target){
        l=mid-1;
    }

    else {
        s=mid+1;
    }

  }
  return ans;
}

//finding last occurrence
int lastoccurrence(vector<int>arr,int target){   
int n=arr.size();
  int s=0,l=n-1;
  int ans;

  while(s<=l){
    int mid=s+(l-s)/2;

    if(arr[mid]==target){
        ans=mid;
        s=mid+1;
    }

    else if(arr[mid]>target){
        l=mid-1;
    }

    else {
        s=mid+1;
    }

  }

  return ans;
}

//return both occurrences
pair<int,int>Solution(vector<int>arr,int target){
       pair<int,int>p={firstoccurrence(arr,target),lastoccurrence(arr,target)};

       return p;
}

int main(){
    vector<int>arr={1,2,2,2,2,3,5,6};
    int target=2;

    pair<int,int>ans=Solution(arr,target);

    cout<<ans.first<<" "<<ans.second;  //output: 2 4

    return 0;
}