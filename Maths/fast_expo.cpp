//Fast Exponentiation 
#include<bits/stdc++.h>
using namespace std;
int fastpower(int a,int b){
    if(b==0){
        return 1;
    }

    int res=1;

    while(b>0){
         if(b&1){
            res=res*a;
         }

         a*=a;
         b=b>>1;
    }
    return res;
}
int main(){

    int a=2,b=5;
    cout<<fastpower(a,b);

    return 0;
}