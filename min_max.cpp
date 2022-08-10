#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int val)
{
    node *ptr = (node *)malloc(sizeof(node *));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *curr = q.front();
            q.pop();

            cout << curr->data << ' ';

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << '\n';
    }
}

node *insertion(node *root, int d)
{
    if (root == NULL)
    {
        root = createNode(d);
        return root;
    }
    else if (d > root->data)
    {
        root->right = insertion(root->right, d);
    }
    else
    {
        root->left = insertion(root->left, d);
    }

    return root;
}

int min(node *root)
{
    node *temp = root;

    while (temp->left != NULL)
    {
        temp = root->left;
    }
    return temp->data;
}

int max(node *root)
{
    node *temp = root;

    while (temp->left != NULL)
    {
        temp = root->left;
    }
    return temp->data;
}


void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertion(root, data);
        cin >> data;
    }
}

int main()
{
    node *root = NULL;
    takeInput(root);
    levelorder(root);
}
