#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void printPreorder(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printInorder(Node *node)
    {
        if (node == nullptr)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    void printPostorder(Node *node)
    {
        if (node == nullptr)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    Node *findMinNode(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void printNodesWithOnlyLeftChild(Node *node)
    {
        if (node == nullptr)
            return;

        if (node->left != nullptr && node->right == nullptr)
        {
            cout << node->data << " ";
        }

        printNodesWithOnlyLeftChild(node->left);
        printNodesWithOnlyLeftChild(node->right);
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void printPreorder()
    {
        cout << "Preorder Traversal: ";
        printPreorder(root);
        cout << endl;
    }

    void printInorder()
    {
        cout << "Inorder Traversal: ";
        printInorder(root);
        cout << endl;
    }

    void printPostorder()
    {
        cout << "Postorder Traversal: ";
        printPostorder(root);
        cout << endl;
    }

    int findMinValue()
    {
        Node *minNode = findMinNode(root);
        return minNode->data;
    }

    void printNodesWithOnlyLeftChild()
    {
        cout << "Nodes with Only Left Child: ";
        printNodesWithOnlyLeftChild(root);
        cout << endl;
    }

    void setRootData(int data)
    {
        root->data = data;
    }
};

int main()
{
    BinarySearchTree tree;
    int userInput;

    int rootData;
    cout << "Enter Root: ";
    cin >> rootData;

    tree.setRootData(rootData);

    while (userInput != 0)
    {
        cout << "Enter a number to insert into the tree (enter 0 to quit): ";
        cin >> userInput;

        if (userInput != 0)
        {
            tree.insert(userInput);
        }
    }

    tree.printPreorder();
    tree.printInorder();
    tree.printPostorder();

    cout << "Minimum element: " << tree.findMinValue() << endl;

    tree.printNodesWithOnlyLeftChild();

    return 0;
}
