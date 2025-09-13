//100. Same Tree
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
public:
    bool isSameTree(Node* p, Node* q) {
        if(p == NULL && q == NULL){
            return true;
        }

        if(p == NULL && q != NULL){
            return false;
        }

        if(p != NULL && q == NULL){
            return false;
        }

        bool left = isSameTree(p->left , q->left);
        bool right = isSameTree(p->right , q->right);
        bool value = p->data == q->data;

        if(left && right && value){
            return true;
        }
        else{
            return false;
        }
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
    Node* p = NULL;
    cout<<"Enter the data for first tree: "<<endl; //Input1: 1 2 -1 -1 1 -1 -1
    p = buildtree(p);

    Node* q = NULL;
    cout<<"Enter the data for second tree: "<<endl; //Input2: 1 1 -1 -1 2 -1 -1
    q = buildtree(q);

    Solution sol;

    cout << (sol.isSameTree(p,q) ? "Same" : "Not Same") << endl; // output: Not Same

    return 0;
}