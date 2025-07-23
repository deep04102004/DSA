//Sum of Subarrays

#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& arr) {
        int n= arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]*(i+1)*(n-i);
        }
        return sum;
    }

int main(){
      vector<int>arr={1,2,3,4};
      cout<<subarraySum(arr);

      return 0;
}