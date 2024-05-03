//Binary Search Tree Recursive
//HW do the rrecursive versions
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    
}TreeNode;

typedef struct BinaryTree
{
    TreeNode* root;
}BinaryTree;

TreeNode* create_tree_node(int data){
    TreeNode* new_node = (TreeNode*)(malloc(sizeof(TreeNode)));
    if(new_node == NULL){
        printf("Memory Not Allocated");
        exit(-1);
    }
    new_node->data=data;
    new_node->left=NULL;
    new_node ->right = NULL;
    return new_node;
}

TreeNode* insert_node(TreeNode* root,int data){
    if(root == NULL){
        return create_tree_node(data);
    }
    if(data<root->data){
        root->left = insert_node(root->left,data);
    }else if(data>root->data){
        root -> right=insert_node(root->right,data);
    }
    return root;
}
TreeNode* inOrderTrversal_Print(TreeNode* root){
    if(root!=NULL){
        inOrderTrversal_Print(root->left);
        printf("%d\t",root->data);
        inOrderTrversal_Print(root->right);
}
    return NULL;
}
TreeNode* Delete_Tree(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    Delete_Tree(root->left);
    Delete_Tree(root->right);
    free(root);
}
TreeNode* Clone_Tree(TreeNode* root){
    BinaryTree clone;
    clone.root=NULL;
    clone.root = insert_node(clone.root,root->data);
    Clone_Tree(root->left);
    Clone_Tree(root->right);
    return clone.root;
}
TreeNode* search(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}
int main() {
    BinaryTree tree;

    tree.root = insert_node(tree.root, 8);
    tree.root = insert_node(tree.root, 13);
    tree.root = insert_node(tree.root, 10);
    tree.root = insert_node(tree.root, 1);
    tree.root = insert_node(tree.root, 9);
    tree.root = insert_node(tree.root, 11);
    tree.root = insert_node(tree.root, 6);
    tree.root = insert_node(tree.root, 12);
    tree.root = insert_node(tree.root, 15);
    tree.root = insert_node(tree.root, 2);

    printf("In-order traversal: ");
    inOrderTrversal_Print(tree.root);
    printf("\n");

    // Search for a node
    int search_data = 10;
    TreeNode* found_node = search(tree.root, search_data);
    if (found_node != NULL) {
        printf("Node with data %d found!\n", search_data);
    } else {
        printf("Node with data %d not found.\n", search_data);
    }

    return 0;
}
