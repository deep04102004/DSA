//Last Moment Before All Ants Fall Out (Geeks For Geeks).

#include<iostream>
#include<vector>
using namespace std;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans =0;
        
        for(int i=0;i<left.size();i++){
            ans=max(ans,left[i]);
        }
        
        for(int i=0;i<right.size();i++){
            ans=max(ans,n-right[i]);
        }
        
        return ans;
    }

int main(){
    int n = 4;
    vector<int>left={2},right={0, 1, 3};

    cout<<getLastMoment(n,left,right);

    return 0;
}