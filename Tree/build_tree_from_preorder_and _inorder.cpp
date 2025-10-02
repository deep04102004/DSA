//105. Construct Binary Tree from Preorder and Inorder Traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    void createmapping(vector<int> inorder, map<int,int>& nodetoindex, int n) {
        for (int i = 0; i < n; i++) {
            nodetoindex[inorder[i]] = i;
        }
    }
    
    Node* Solve(vector<int>& inorder, vector<int>& preorder,
                int& index, int instart, int inend, int n, map<int,int>& nodetoindex) {
        if (index >= n || instart > inend) {
            return NULL;
        }
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = nodetoindex[element];
        
        root->left = Solve(inorder, preorder, index, instart, position - 1, n, nodetoindex);
        root->right = Solve(inorder, preorder, index, position + 1, inend, n, nodetoindex);
        
        return root;
    }
    
  public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preorderindex = 0;
        int n = inorder.size();
        map<int,int> nodetoindex;
        
        createmapping(inorder, nodetoindex, n);
        
        Node* ans = Solve(inorder, preorder, preorderindex, 0, n - 1, n, nodetoindex);
        
        return ans;
    }
};

// Helper function to print postorder traversal (to check tree correctness)
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Example input
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    
    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);
    
    cout << "Postorder Traversal of Constructed Tree: ";
    printPostorder(root);
    cout << endl;
    
    return 0;
}
