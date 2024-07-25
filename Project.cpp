#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;
    BST() : root(nullptr) {}

    // Function to insert a new node in the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Function to search a key in the BST
    bool search(int key) {
        return searchRec(root, key);
    }

    // Function to delete a node in the BST
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    // In-order traversal
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Post-order traversal
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // Pre-order traversal
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

private:
    // Helper function for insert
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->val) {
            node->left = insertRec(node->left, key);
        } else if (key > node->val) {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    // Helper function for search
    bool searchRec(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == key) {
            return true;
        }
        if (key < node->val) {
            return searchRec(node->left, key);
        }
        return searchRec(node->right, key);
    }

    // Helper function for delete
    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == nullptr) return node;
        if (key < node->val) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->val) {
            node->right = deleteRec(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    // Helper function to find the node with minimum value
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // In-order traversal helper
    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->val << " ";
            inorderRec(node->right);
        }
    }

    // Post-order traversal helper
    void postorderRec(TreeNode* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->val << " ";
        }
    }

    // Pre-order traversal helper
    void preorderRec(TreeNode* node) {
        if (node != nullptr) {
            cout << node->val << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inorder();

    cout << "Pre-order traversal: ";
    tree.preorder();

    cout << "Post-order traversal: ";
    tree.postorder();

    cout << "Delete 20\n";
    tree.deleteNode(20);
    cout << "In-order traversal after deletion: ";
    tree.inorder();

    cout << "Delete 30\n";
    tree.deleteNode(30);
    cout << "In-order traversal after deletion: ";
    tree.inorder();

    cout << "Delete 50\n";
    tree.deleteNode(50);
    cout << "In-order traversal after deletion: ";
    tree.inorder();

    return 0;
}