//852. Peak Index in a Mountain Array
#include<bits/stdc++.h>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int n=arr.size();
    int s=0,l=n-1;

    while(s<l){
        int mid=s+(l-s)/2;

        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }

        else{
            l=mid;
        }
    }
    return l;
}
int main(){
vector<int>arr = {0,1,0};
cout<<peakIndexInMountainArray(arr);
//Output: 1
}