#ifndef MODULE5_TREE_H
#define MODULE5_TREE_H

#include "common.h"

// Aðacýn her bir düðümü burada
struct TreeNode {
    Record data;       // Ana veri
    TreeNode *left;    // Sol node
    TreeNode *right;   // Sað node
};

// Aðaç class
class TreeModule {
public:
    TreeNode* root;
    
    TreeModule() { root = NULL; }

    // 1. Ýþçi fonksiyon - node creator
    TreeNode* createNode(Record data) {
        TreeNode* newNode = new TreeNode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // 2. Yönetici fonksiyon - call upon
    void insert(Record data) {
        insertRecursive(root, data);
    }
    
        // Aðacý ekrana yazdýran fonksiyon
    void printTree() {
        printInOrder(root);
    }

private:
    // 3. Rekürsif fonksiyon - aðaçta yer bulma
    void insertRecursive(TreeNode*& node, Record data) {
        if (node == NULL) {
            node = createNode(data); // iþçi fonk.
        } else if (data.id < node->data.id) {
            insertRecursive(node->left, data);
        } else {
            insertRecursive(node->right, data);
        }
    }


private:
    // içerdeki yardýmcý fonk
    void printInOrder(TreeNode* node) {
        if (node != NULL) {
            printInOrder(node->left); // sol (küçük)
            cout << "ID: " << node->data.id << " | Baslik: " << node->data.title << endl; // self func.
            printInOrder(node->right); // sað (büyük)
        }
    }
    
};

#endif
