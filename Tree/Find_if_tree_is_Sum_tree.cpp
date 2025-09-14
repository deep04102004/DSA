//Sum Tree (GFG)
#include <iostream>
#include<algorithm>
#include<cmath>
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
    pair<bool,int>isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool,int>p = {true,0};
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p ={true,root->data};
            return p;
        }
        
        pair<bool,int>left = isSumTreeFast(root->left);
        pair<bool,int>right = isSumTreeFast(root->right);
        
        bool leftans = left.first;
        bool rightans = right.first;
        
        bool condn = left.second + right.second == root->data;
        
        pair<bool,int>ans;
        
        if(leftans && rightans && condn){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
        
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
    root = buildtree(root);  //input: 3 1 -1 -1 2 -1 -1

    Solution sol;

    cout << (sol.isSumTree(root) ? "True" : "False") << endl; // output: True

    return 0;
}