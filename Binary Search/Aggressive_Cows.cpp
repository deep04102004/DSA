//Aggressive Cow Problem. 

#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &stalls,int mid,int k){
    int cow_count=1;
    int lastpos=stalls[0];

    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            cow_count++;
            if(cow_count==k){
                return true;
            }
            lastpos=stalls[i];
        }
    }
    return false;
}

int aggressive_cows(vector<int> &stalls,int k){
    sort(stalls.begin(),stalls.end());

    int n=stalls.size();
    int s=0,e=stalls[n-1]-stalls[0];
    int ans=-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(ispossible(stalls,mid,k)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
vector<int>stalls = {10, 1, 2, 7, 5}; 
int k = 3;
  cout<<aggressive_cows(stalls,k);//Output: 3
}