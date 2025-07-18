//922. Sort Array By Parity II

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n= nums.size();

        while (j < n && i < n) {
            if(nums[i]%2 == 0){
                i+=2;
            }
            else if(nums[j]%2 !=0){
                j+=2;
            }
            else{
                swap(nums[i],nums[j]);
                i+=2;
                j+=2;
            }
        }
            return nums;
    }

int main()
{
    vector<int> nums = {3, 1, 2, 4, 5};

    for (int a : sortArrayByParityII(nums))
    {
        cout << a << " ";
    }

    return 0;
}