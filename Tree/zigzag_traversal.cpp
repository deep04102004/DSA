//103. Binary Tree Zigzag Level Order Traversal
#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<Node*> q;
        q.push(root);
        bool lefttoright = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++) {
                Node* frontnode = q.front();
                q.pop();

                int index = lefttoright ? i : size - i - 1;
                ans[index] = frontnode->data;

                if (frontnode->left) {
                    q.push(frontnode->left);
                }
                if (frontnode->right) {
                    q.push(frontnode->right);
                }
            }
            result.push_back(ans);
            lefttoright = !lefttoright;
        }
        return result;
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
    vector<vector<int>> zigzag = sol.zigzagLevelOrder(root);

    for(auto a : zigzag){
        for(int b : a){
            cout<<b<<" ";                
        }
        cout<<endl;
    }
    return 0;
}