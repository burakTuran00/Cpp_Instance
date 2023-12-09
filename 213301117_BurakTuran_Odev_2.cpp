#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

int findLevelUtil(Node *root, int value, int level)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->data == value)
    {
        return level;
    }

    int downLevel = findLevelUtil(root->left, value, level + 1);

    if (downLevel != 0)
    {
        return downLevel;
    }

    downLevel = findLevelUtil(root->right, value, level + 1);

    return downLevel;
}

void findLevel(Node *root, int value, int begin)
{
    int level = findLevelUtil(root, value, begin);

    if (level != 0)
    {
        cout << "Level of " << value << ": " << level << endl;
    }
    else
    {
        cout << "Number Not Found" << endl;
    }
}

int main()
{
    Node *root = newNode(4);

    root->left = newNode(9);
    root->right = newNode(7);

    root->left->left = newNode(2);
    root->left->left->left = newNode(3);

    root->right->left = newNode(6);
    root->right->right = newNode(8);

    root->right->right->left = newNode(10);
    root->right->right->right = newNode(1);

    root->right->right->left->left = newNode(5);

    findLevel(root, 9, 1);
    findLevel(root, 5, 1);
    findLevel(root, 10, 1);
    findLevel(root, 12, 1);

    return 0;
}
