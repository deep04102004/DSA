#include <iostream>
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
    void inorder(Node* root, int &count) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, count);

        if (root->left == NULL && root->right == NULL) {
            count++;
        }

        inorder(root->right, count);
    }

public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};

Node* buildtree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    
    
    cout<<"Enter data for Left Node "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data for right node "<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}

int main() {
    Node* root = NULL; 
    root = buildtree(root);  //input: 1 2 -1 -1 3 -1 -1

    Solution sol;
    int leafCount = sol.countLeaves(root);

    cout << "Number of leaf nodes: " << leafCount << endl; // output: 2

    return 0;
}