#include<bits/stdc++.h>
using namespace std;

void sortmultiple(vector<int> &arr,int k){
    vector<int>multiofn;

    for(int&a:arr){
        if(a%k == 0){
            multiofn.push_back(a);
        }
    }
    
    sort(multiofn.begin(),multiofn.end());

    int i=0;

    for(int&b:arr){
        if(b%k == 0){
            b=multiofn[i++];
        }
    }
}

int main(){
    vector<int>arr={1,25,3,2,5,15,16,20};
    int k=5;
    sortmultiple(arr,k);

    for(int x:arr){
        cout<<x<<" ";
    }

    return 0;
}