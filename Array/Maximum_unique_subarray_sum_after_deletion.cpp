//3487. Maximum Unique Subarray Sum After Deletion
#include<iostream>
#include<unordered_set>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int maxSum(vector<int>& nums) {
    int ans=0;
    int mini=INT_MIN;
    
    for(int&a: nums){
        mini=max(a,mini);
        if(a<=0)
        continue;

        ans+=a;
    }
    return (ans == 0) ? mini : ans;
}

int main(){
   vector<int>nums={2,-10,6};
   cout<<maxSum(nums);
   
   return 0;
}