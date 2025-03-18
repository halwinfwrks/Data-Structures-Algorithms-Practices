#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    Node *root;
    void traversalHelper(const Node *node, int mode) const;
    void destroyTree(Node *node);
    Node *findSuccessor(Node *node) const;
    void deleteNodeHelper(Node *&, int);

public:
    Tree() : root(nullptr) {}
    ~Tree() { destroyTree(root); }
    void insert(int data);
    void deleteNode(int data);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void search(int data) const;
};

// ==============================================================================

void Tree::insert(int data)
{
    Node *newNode = new Node(data);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node *current = root, *parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        if (data <= current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data <= parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// ==============================================================================

void Tree::traversalHelper(const Node *node, int mode) const
{
    if (node == nullptr)
        return;
    if (mode == 1)
        std::cout << node->data << " "; // Preorder
    traversalHelper(node->left, mode);
    if (mode == 2)
        std::cout << node->data << " "; // Inorder
    traversalHelper(node->right, mode);
    if (mode == 3)
        std::cout << node->data << " "; // Postorder
}

// ==============================================================================

void Tree::inorder() const
{
    traversalHelper(root, 2);
    std::cout << std::endl;
}

// ==============================================================================

void Tree::preorder() const
{
    traversalHelper(root, 1);
    std::cout << std::endl;
}

// ==============================================================================

void Tree::postorder() const
{
    traversalHelper(root, 3);
    std::cout << std::endl;
}

// ==============================================================================

void Tree::search(int key) const
{
    Node *current = root;
    while (current != nullptr)
    {
        if (key == current->data)
        {
            std::cout << "Element found: " << key << std::endl;
            return;
        }
        current = (key < current->data) ? current->left : current->right;
    }
    std::cout << "Element not found" << std::endl;
}

// ==============================================================================

void Tree::destroyTree(Node *node)
{
    if (node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
// ==============================================================================

Node *Tree::findSuccessor(Node *node) const
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void Tree::deleteNodeHelper(Node *&node, int key)
{
    if (node == nullptr)
    {
        std::cout << "Node not found" << std::endl;
        return;
    }

    if (key < node->data)
    {
        deleteNodeHelper(node->left, key);
    }
    else if (key > node->data)
    {
        deleteNodeHelper(node->right, key);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node *successor = findSuccessor(node->right);
            node->data = successor->data;
            deleteNodeHelper(node->right, successor->data);
        }
    }
}

void Tree::deleteNode(int data)
{
    deleteNodeHelper(root, data);
}

// ==============================================================================

int main()
{
    Tree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(21);
    tree.insert(35);
    tree.insert(35);
    tree.insert(64);
    tree.insert(12);
    tree.insert(4);

    std::cout << "Inorder traversal: ";
    tree.inorder();


    tree.search(2);
    tree.search(35);
    tree.deleteNode(35);
    std::cout << "Preorder traversal: ";
    tree.preorder();

    return 0;
}
