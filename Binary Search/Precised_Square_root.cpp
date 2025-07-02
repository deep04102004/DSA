//Precise Square Root
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

double precise(int temp,int decimal, int n){
  double ans=temp;
  double factor=1;
  for(int i=0;i<decimal;i++){
    factor/=10;
    for(double j=ans;j<=n/j;j+=factor){
      ans=j;
    }
  }
  return ans;
}

int main(){
     int n=18;
     int temp = Squroot(n);
     int decimal=5;
     cout<<precise(temp,decimal,n);
}