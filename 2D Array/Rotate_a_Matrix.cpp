//48. Rotate Image
#include<bits/stdc++.h>
using namespace std;

void RotateImage(vector<vector<int>>&arr){
    int n=arr.size();
    //Transpose the matrix.
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    //Now,Reverse the Rows of Transpose Matrix.
    for(auto&row:arr){
        reverse(row.begin(),row.end());
    }
}

int main(){
 vector<vector<int>>arr={{1,2,3},
                         {4,5,6},
                         {7,8,9}};
        
        RotateImage(arr);

        for(auto&row:arr){
            for(auto&column:row){
                cout<<column<<" ";     //Output: [[7,4,1],[8,5,2],[9,6,3]]
            }
            cout<<endl;
        }
}