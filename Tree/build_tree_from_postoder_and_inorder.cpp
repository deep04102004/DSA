//106. Construct Binary Tree from Inorder and Postorder Traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  private:
    void createmapping(vector<int> inorder, map<int,int>& nodetoindex, int n) {
        for (int i = 0; i < n; i++) {
            nodetoindex[inorder[i]] = i;
        }
    }
    
    Node* Solve(vector<int>& inorder, vector<int>& postorder,
                int& index, int instart, int inend, int n, map<int,int>& nodetoindex) {
        if (index < 0 || instart > inend) {
            return NULL;
        }
        
        int element = postorder[index--];   // root from postorder
        Node* root = new Node(element);
        int position = nodetoindex[element];
        
        // Build right first, then left (since postorder is L-R-Root)
        root->right = Solve(inorder, postorder, index, position + 1, inend, n, nodetoindex);
        root->left = Solve(inorder, postorder, index, instart, position - 1, n, nodetoindex);
        
        return root;
    }
    
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int postorderindex = n - 1;   // start from last index
        map<int,int> nodetoindex;
        
        createmapping(inorder, nodetoindex, n);
        
        Node* ans = Solve(inorder, postorder, postorderindex, 0, n - 1, n, nodetoindex);
        return ans;
    }
};

// Helper: print preorder traversal to verify correctness
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Example input
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    Solution obj;
    Node* root = obj.buildTree(inorder, postorder);
    
    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;
    
    return 0;
}
