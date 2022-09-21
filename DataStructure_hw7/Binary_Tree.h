//Binaray_Tree.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//int count = 1;
typedef char* Element;

typedef struct tTreeNode {
    Element data;
    struct tTreeNode *left, * right;
}TreeNode;

TreeNode* CreateTree(TreeNode* left, Element item, TreeNode* right)
{
    TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (pNewNode == NULL)
        return NULL;
    /*
    pNewNode->data = (Element)malloc(sizeof(char) * 30);
    if (pNewNode->data == NULL ||  item ==NULL)
    {
        free(pNewNode->data);        return NULL;
    }
    strcpy(pNewNode->data, item);
    */
    pNewNode->data = item;
    pNewNode->left = left;
    pNewNode->right = right;

    return pNewNode;
}

bool IsEmpty(TreeNode* root)
{
    if (root)
    {
        if (root->data == NULL)
            return true;
        else
            return false;
    }
    return true;
}

TreeNode* LeftTree(TreeNode *root)
{
    if(IsEmpty(root))
        return NULL;
    return root->left;
}

Element TreeData(TreeNode* root)
{
    if (IsEmpty(root))
        return NULL;
    return root->data;
}

TreeNode* RightTree(TreeNode* root)
{
    if (IsEmpty(root))
        return NULL;
    return root->right;
}

void DestroyTree(TreeNode* root)
{
    if (root == NULL)
        return;
    if (root->left)
        DestroyTree(root->left);
    if (root->right)
        DestroyTree(root->right);

    free(root->data);
    root->data = NULL;
    free(root);
    //printf("Destroyed : %d\n", count++);
}


