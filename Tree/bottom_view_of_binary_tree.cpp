//Bottom View of Binary Tree
#include <iostream>
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
    vector<int> topView(Node *root) {
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        map<int,int>topnode;
        queue<pair<Node*,int> >q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front();
            q.pop();
            
            Node*frontnode = temp.first;
            int hd = temp.second;
            
            topnode[hd] = frontnode->data;
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        
        for(auto i:topnode){
            ans.push_back(i.second);
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
    vector<int> bottom = sol.topView(root);

    for(auto&a : bottom){
        cout<<a<<" ";   //Output: 9 15 20 7 
    }
    return 0;
}