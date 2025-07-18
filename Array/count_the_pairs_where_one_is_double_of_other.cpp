#include<bits/stdc++.h>
using namespace std;

int countpairs(vector<int>arr){
    int n=arr.size();
    int i=0;

    int count=0;

    while(i<n){
        int j=i+1;
        
        while(j<n){
            if((arr[i]*2 == arr[j]) || (arr[i] == arr[j]*2)){
                count++;
                break;
            }

            j++;
        }
        i++;
    }
    return count;
}

int main(){
    vector<int>arr={5,6,8,14,16,12,28};

    cout<<countpairs(arr);

}