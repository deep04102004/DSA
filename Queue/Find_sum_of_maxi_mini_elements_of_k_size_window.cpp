#include<iostream>
#include<queue>
using namespace std;

int solve(vector<int>arr,int n, int k){
      deque<int> maxi(k);
      deque<int> mini(k);

      for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
      }
      
      int ans = 0;
      ans+= arr[maxi.front()] + arr[mini.front()];

      for(int i=k;i<n;i++){
        //Removal
        while(!maxi.empty() && i-maxi.front() >= k){
            maxi.pop_back();
        }
        while(!mini.empty() && i- mini.front() >= k){
            mini.pop_back();
        }
        
        //Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans+= arr[maxi.front()] + arr[mini.front()];
      }
      return ans;
}


int main(){
   vector<int>arr = {2, 5, -1, 7, -3, -1, -2};
   int n= arr.size();
   int k = 4;

   cout<<solve(arr,n,k);
}