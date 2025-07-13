//2410. Maximum Matching of Players With Trainers
#include <bits/stdc++.h>
using namespace std;

int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int n = players.size(), m = trainers.size();
    int i = 0, j = 0;
    int count = 0;

    while (i < n && j < m)
    {
        if (players[i] <= trainers[j])
        {
            count++;
            i++;
            j++;
        }

        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    vector<int>players = {4,7,9}, trainers = {8,2,5,8};
    cout<<matchPlayersAndTrainers(players,trainers);  //Output: 2

    return 0;
}