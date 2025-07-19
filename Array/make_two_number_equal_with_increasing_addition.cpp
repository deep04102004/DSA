#include<iostream>
#include<cstdlib>
using namespace std;

int minimum_operations(int a,int b){
     if(a == b){
        return 0;
     }

     int diff= abs(a-b);
     int sum=0;
     int k=1;
     while(diff > sum || abs(sum-diff)%2 != 0){
        sum+=k;
        k++;
     }

     return k;
}

int main(){
    int a=3,b=6;
    cout<<minimum_operations(a,b);

    return 0;
}