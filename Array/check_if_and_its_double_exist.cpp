//1346. Check If N and Its Double Exist

#include<bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        int i=0;

        while(i<n){
            int j=i+1;
            
            while(j<n){
                if(2*arr[i]==arr[j] || arr[i]==2*arr[j]){
                    return true;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return false;
    }

int main(){
    vector<int>arr={3,1,7,11};
    if(checkIfExist(arr)){
        cout<<"true";
    }

    else{
        cout<<"false";
    }

    return 0;
}