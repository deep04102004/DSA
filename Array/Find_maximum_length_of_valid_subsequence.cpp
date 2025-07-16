//3201. Find the Maximum Length of Valid Subsequence I

#include<bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums) {
    int cnt1=0,cnt2=0;

    //Check for Even Sum because odd+odd = even and even+even=even.
    for(int n:nums){
        if(n%2==0){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }

    int odd=0,even=0;
    
    //check for odd sum because even+odd=odd and vice versa.
    for(int n:nums){
        if(n%2==0){
            even=max(even,odd+1);
        }
        else{
            odd=max(odd,even+1);
        }
    }

    return max({cnt1,cnt2,odd,even});
}

int main(){
     vector<int>nums={1,2,1,1,2,1,2};

     cout<<maximumLength(nums);

     return 0;
}