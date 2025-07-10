#include<bits/stdc++.h>
using namespace std;
//this approach is called sieve of Erathosthenes.
int countprime(int n){
    vector<bool>isprime(n+1,true);

    isprime[0]=false,isprime[1]=false;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(isprime[i]){
            cnt++;

            for(int j=2*i;j<n;j+=i){
                isprime[j]=false;
            }
        }
    }
    return cnt;
}

int main(){
    int n=50;

    cout<<countprime(n);
     
    return 0;
}