// 905. Sort Array By Parity

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();

    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (nums[i] % 2 != 0 && nums[j] % 2 == 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        if (nums[i] % 2 == 0)
        {
            i++;
        }

        if (nums[j] % 2 != 0)
        {
            j--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {3, 1, 2, 4, 5};

    for (int a : sortArrayByParity(nums))
    {
        cout << a << " ";
    }

    return 0;
}