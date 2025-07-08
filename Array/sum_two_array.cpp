//Add two Arrays
#include<bits/stdc++.h>
using namespace std;

//Reverse Function
vector<int>reverse(vector<int>ans){
    int i=0,j=ans.size()-1;

    while(i<j){
        swap(ans[i++],ans[j--]);
    }
    return ans;
}
//Sum Function
vector<int>sum(vector<int>arr1,vector<int>arr2){
    int n=arr1.size();
    int m=arr2.size();

    int i=n-1,j=m-1;

    int sum=0;
    int carry=0;

    vector<int>ans;

    while(i>=0 && j>=0){
         sum=arr1[i]+arr2[j]+carry;
         carry=sum/10;
         sum=sum%10;
         
         ans.push_back(sum);

         i--;
         j--;
    }
    //Handled case if arr1 length is greater like 222+6=228
    while(i>=0){
         sum=arr1[i]+carry;
         carry=sum/10;
         sum=sum%10;
         
         ans.push_back(sum);

         i--;
    }
     //Handled case if arr2 length is greater like 6+222=228
    while(j>=0){
         sum=arr2[j]+carry;
         carry=sum/10;
         sum=sum%10;
         
         ans.push_back(sum);

         j--;
    }
    //handled Case where carry is extra and array length increse like 999+999=1998.
    while(carry>0){
         sum=carry;
         carry=sum/10;
         sum=sum%10;
         
         ans.push_back(sum);
         
    }
   return  reverse(ans);
}

int main(){
     vector<int>arr1={9,9,9};
     vector<int>arr2={9,9,9};

     for(int a:sum(arr1,arr2)){
        cout<<a;
     }
   
   return 0;
}