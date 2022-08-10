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



node *deleteBST(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int minval = min(root->right);
            root->data = minval;
            root->right = deleteBST(root->right, minval);
            return root;
        }
    }

    else if (val > root->data)
    {
        root->right = deleteBST(root->right, val);
        return root;
    }
    else
    {
        root->left = deleteBST(root->left, val);
        return root;
    }
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
