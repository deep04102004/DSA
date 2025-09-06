#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter the data of left child "<< data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data of right child "<<data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversel(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;

    root = buildtree(root);

    levelordertraversel(root);

    return 0;
}