//437. Path Sum III
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
     void solve(Node *root,int k,int currsum,int&count,unordered_map<int,int>&mp){
         if(root == NULL){
             return;
         }
         
         currsum+=root->data;
         
         if(currsum == k) count++;
         
         count+=mp[currsum-k];
         
         mp[currsum]++;
         
         solve(root->left,k,currsum,count,mp);
         solve(root->right,k,currsum,count,mp);
         
         mp[currsum]--;
    }
  public:
    int sumK(Node *root, int k) {
        unordered_map<int,int>mp;
        int count = 0;
        
        solve(root,k,0,count,mp);
        return count;
    }
};

Node* buildtree(Node* root){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    cout<<"Enter the data: "<<endl; 
    root = buildtree(root);  //input: 8 4 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 5 -1 2 -1 -1
    int k;
    cout<<"Enter k: "<<endl;  // input:7
    cin>>k;
    Solution sol;
    int sumk = sol.sumK(root,k);

    cout<<"Number of paths with sum k is: "<<sumk;  // output: 3
    return 0;
}