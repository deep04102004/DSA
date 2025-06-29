//74. Search a 2D Matrix
#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size();
    int s=0,l=n*m;
    while(s<=l){
        int mid=s+(l-s)/2;
        if(matrix[mid/n][mid%n]==target){
              return true;
        }
        else if(matrix[mid/n][mid%n]>target){
            l=mid-1;
        }
        else s=mid+1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    if(searchMatrix(matrix,target)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}