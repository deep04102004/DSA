//543. Diameter of Binary Tree
#include <iostream>
#include<algorithm>
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
    pair<int, int> diameterfast(Node* root) {
        if (root == NULL) {
            pair<int, int> p = {0, 0};
            return p;
        }

        pair<int,int>left = diameterfast(root->left);
        pair<int,int>right = diameterfast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int,int>ans;
        ans.first = max({op1,op2,op3});
        ans.second = max(left.second,right.second)+1;

        return ans;
    }

public:
    int diameterOfBinaryTree(Node* root) {
        return diameterfast(root).first;
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
    int Diameter = sol.diameterOfBinaryTree(root);

    cout << "Maximum Diameter of tree is: " << Diameter << endl; // output: 3

    return 0;
}