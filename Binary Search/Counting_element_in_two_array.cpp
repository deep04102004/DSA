//Counting elements in two arrays
#include<bits/stdc++.h>
using namespace std;
vector<int> countLessEq(vector<int>& a, vector<int>& b) {
    vector<int>ans;
    sort(b.begin(),b.end());
        
        for(int&i:a){
        int s=0,l=b.size()-1;
            int solve=0;
        while(s<=l){
            int mid= s+((l-s)/2);
             if(b[mid]<=i){
                s=mid+1;
                solve=mid+1;
            }
            else 
            l=mid-1;
        }
        ans.push_back(solve);
        }
        return ans;
    }

int main(){
    vector<int>a={4, 8, 7, 5, 1},b{4, 48, 3, 0, 1, 1, 5};
    for(int&a:countLessEq(a,b)){
        cout<<a<<" ";
    }
}
