#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree
{
private:
    Node<T> *root;
    void traversalHelper(const Node<T> *node, int mode) const;
    void destroyTree(Node<T> *node);
    Node<T> *findSuccessor(Node<T> *node) const;
    void deleteNodeHelper(Node<T> *&node, T key);

public:
    Tree() : root(nullptr) {}
    ~Tree() { destroyTree(root); }
    void insert(T data);
    void deleteNode(T data);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void search(T data) const;
};

// ==============================================================================

template <typename T>
void Tree<T>::insert(T data)
{
    Node<T> *newNode = new Node<T>(data);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node<T> *current = root, *parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data) // Không cho phép giá trị trùng
            current = current->right;
        else
        {
            std::cout << "Duplicate value not allowed: " << data << std::endl;
            delete newNode;
            return;
        }
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// ==============================================================================

template <typename T>
void Tree<T>::traversalHelper(const Node<T> *node, int mode) const
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

template <typename T>
void Tree<T>::inorder() const
{
    traversalHelper(root, 2);
    std::cout << std::endl;
}

// ==============================================================================

template <typename T>
void Tree<T>::preorder() const
{
    traversalHelper(root, 1);
    std::cout << std::endl;
}

// ==============================================================================

template <typename T>
void Tree<T>::postorder() const
{
    traversalHelper(root, 3);
    std::cout << std::endl;
}

// ==============================================================================

template <typename T>
void Tree<T>::search(T key) const
{
    Node<T> *current = root;
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

template <typename T>
void Tree<T>::destroyTree(Node<T> *node)
{
    if (node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// ==============================================================================

template <typename T>
Node<T> *Tree<T>::findSuccessor(Node<T> *node) const
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// ==============================================================================

template <typename T>
void Tree<T>::deleteNodeHelper(Node<T> *&node, T key)
{
    if (node == nullptr)
    {
        std::cout << "Node not found: " << key << std::endl;
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
            Node<T> *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node<T> *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node<T> *successor = findSuccessor(node->right);
            node->data = successor->data;
            deleteNodeHelper(node->right, successor->data);
        }
    }
}

// ==============================================================================

template <typename T>
void Tree<T>::deleteNode(T data)
{
    deleteNodeHelper(root, data);
}

// ==============================================================================
#include "Person.h"
int main()
{
    Tree<Person> tree;

    tree.insert(Person(1, 25, (char *)"Alice"));
    tree.insert(Person(2, 30, (char *)"Bob"));
    tree.insert(Person(3, 22, (char *)"Charlie"));
    tree.insert(Person(4, 27, (char *)"David"));
    tree.insert(Person(5, 35, (char *)"Eve"));

    std::cout << "Inorder traversal:\n";
    tree.inorder();

    Person searchTarget(3, 22, (char *)"Charlie");
    tree.search(searchTarget);

    Person missingTarget(6, 40, (char *)"Frank");
    tree.search(missingTarget);

    tree.deleteNode(searchTarget);
    std::cout << "Inorder traversal after deleting Charlie:\n";
    tree.inorder();

    tree.deleteNode(missingTarget);
    std::cout << "Inorder traversal after trying to delete Frank:\n";
    tree.inorder();
}
