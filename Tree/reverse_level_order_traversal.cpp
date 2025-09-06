#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

//Buildtree Function
node* buildtree(node* root){
     cout<<"Enter the data: "<<endl;
     int data;
     cin>>data;

     if(data == -1){
        return NULL;
     }
     root = new node(data);

     cout<<"Enter the data of left node of "<<data<<endl;
     root->left = buildtree(root->left);
     cout<<"Enter the data of right node of "<<data<<endl;
     root->right = buildtree(root->right);

     return root;
}

// reverse Level order travesal Function
void reverseLOT(node* root){
    queue<node*>q;
    vector<vector<int>>levels;

    q.push(root);

    while(!q.empty()){
       int n = q.size();
       vector<int>level;

       for(int i=0;i<n;i++){
        node*temp = q.front();
        q.pop();

        level.push_back(temp->data);

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
       }
       levels.push_back(level);
    }

    for(int i = levels.size();i>=0;i--){
        for(int a:levels[i]){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}

int main(){
    node*root = NULL;
    root = buildtree(root);
    reverseLOT(root);

    return 0;
}
