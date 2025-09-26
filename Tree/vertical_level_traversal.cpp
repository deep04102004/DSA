//987. Vertical Order Traversal of a Binary Tree
#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
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
    vector<vector<int>> verticalTraversal(Node* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        vector<vector<int>> ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();

            Node* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontnode->data);

            if (frontnode->left) {
                q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
            }

            if (frontnode->right) {
                q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                auto&vec= j.second;
                sort(vec.begin(),vec.end());
                col.insert(col.end(), vec.begin(), vec.end());
            }
            ans.push_back(col);
        }
        return ans;
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
    vector<vector<int>> vertical = sol.verticalTraversal(root);

    for(auto a : vertical){
        cout<<" {";
        for(int b : a){
            cout<<" "<<b<<" ";  //Output: { 9 } { 3  15 } { 20 } { 7 }       
        }
        cout<<"}";
    }
    return 0;
}