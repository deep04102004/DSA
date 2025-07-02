//69. Sqrt(x)

#include<bits/stdc++.h>
using namespace std;
int Squroot(int n){
    if(n==0){
        return 0;
    }
    int s=1,e=n;
     int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(mid==n/mid){
            return mid;
        }

        else if(mid<n/mid){
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
     int n=18;
     cout<<Squroot(n);
}