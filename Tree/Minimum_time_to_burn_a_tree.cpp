// Burning Tree Problem
#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
private:
    // Step 1: Create mapping of each node to its parent, and find target node
    Node* ParentMapping(Node* root, int target, map<Node*, Node*>& nodetoparent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodetoparent[root] = NULL;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                res = front;
            }

            if (front->left) {
                nodetoparent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodetoparent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    // Step 2: Burn tree using BFS starting from target node
    int burntree(Node* targetNode, map<Node*, Node*>& nodetoparent) {
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int ans = 0;

        while (!q.empty()) {
            bool flag = false;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (nodetoparent[front] && !visited[nodetoparent[front]]) {
                    flag = true;
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]] = true;
                }
            }

            if (flag == true) {
                ans++;
            }
        }
        return ans;
    }

public:
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodetoparent;
        Node* targetNode = ParentMapping(root, target, nodetoparent);
        return burntree(targetNode, nodetoparent);
    }
};

// Function to build binary tree interactively
Node* buildtree(Node* root) {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);  //  input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    Solution sol;
    int target;
    cout << "Enter target node to start burning: "; // input: 5
    cin >> target;

    int time = sol.minTime(root, target);
    cout << "Minimum time to burn the tree from target " << target << " is: " << time << endl; // output: 4

    return 0;
}
