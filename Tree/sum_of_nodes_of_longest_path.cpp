//Sum of nodes on the longest path
#include <iostream>
#include<vector>
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
     void solve(Node *root,int sum,int &maxsum,int len, int &maxlen){
         if(root == NULL){
             if(len > maxlen){
                 maxlen = len;
                 maxsum = sum;
             }
             else if(len == maxlen){
                 maxsum = max(sum,maxsum);
             }
             return;
         }
         
         sum = sum + root->data;
         
         solve(root->left,sum,maxsum,len+1,maxlen);
         solve(root->right,sum,maxsum,len+1,maxlen);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxlen = 0;
        
        int sum = 0;
        int maxsum = 0;
        
        solve(root,sum,maxsum,len,maxlen);
        
        return maxsum;
        
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
    root = buildtree(root);  //input: 3 9 -1 -1 20 15 -1 -1 7 -1 -1

    Solution sol;
    int sum = sol.sumOfLongRootToLeafPath(root);

    cout<<"Sum of longest path is: "<<sum;  // output: 38
    return 0;
}