#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    if(a==0)
    return b;

    if(b==0)
    return a;
    
    if(a>b){
        return GCD(a-b,b);
    }
    
    return GCD(a,b-a);
}

int main(){
   int a=24,b=48;
   cout<<GCD(a,b);
}