//2099. Find Subsequence of Length K With the Largest Sum
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
 vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<P,vector<P>,greater<P>>q;
    vector<int>ans,temp;
    for(int i=0;i<nums.size();i++){
        q.push({nums[i],i});
        if(q.size()>k){
            q.pop();
        }
    }
    while(!q.empty()){
       temp.push_back(q.top().second);
       q.pop();
    }
    
    sort(temp.begin(),temp.end());

    int i=0;
    while(k--){
        ans.push_back(nums[temp[i++]]);
    }
    return ans;
 }

 int main(){
    vector<int>nums= {2,1,3,3}; int k = 2;
   //Output: [3,3]
   for(int&a:maxSubsequence(nums,k)){
    cout<<a<<" ";
   }
 }