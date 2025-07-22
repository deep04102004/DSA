#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int missingNumber(vector<int> &arr) {
        int n= arr.size();
        unordered_set<int>mp;
        
        for(int a:arr){
            if(a>0){
                mp.insert(a);
            }
        }
        
        for(int i=1;i<=n;i++){
            if(!mp.count(i)){
                return i;
            }
        }
        return n+1;
    }

int main(){
    vector<int> arr={2, -3, 4, 1, 1, 7};
    cout<<missingNumber(arr); 

    return 0;
}
