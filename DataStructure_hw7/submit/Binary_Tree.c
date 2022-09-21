//Binary_Tree.c

#define _CRT_SECURE_NO_WARNINGS
#include "Binary_Tree.h"
#include "Tree_Queue.h"

void Preorder(TreeNode* root)
{
    if (root == NULL)
        return;
    
    printf("%s", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(TreeNode* root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    printf("%s", root->data);
    Inorder(root->right);
}

void Postorder(TreeNode* root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%s", root->data);
}

void Process(Element item)
{
    printf("%s", item);
    return;
}

void Levelorder(TreeNode* root)
{
    Queue* queue = NULL;
    if (root == NULL)
        return;
    queue = CreateQueue(1000);//size not used;
    
    while (root)
    {
        Process(root->data);
        if (root->left)
            Enqueue(queue, root->left);
        if (root->right)
            Enqueue(queue, root->right);
        if (!IsEmptyQueue(queue))
            root = Dequeue(queue);
        else
            root = NULL;
    }
    DestroyQueue(queue);    queue = NULL;
}

int main()
{
    int getchk = 0;
    char* item=(char*)malloc(sizeof(char)*100);
    Queue* pTree_Queue = CreateQueue(1000);//size not used;    
    
    printf("./main\n");
    printf("input a String : ");

    getchk = scanf(" %s", item);
    if (getchk < 0 || item == NULL)
        return 0;

    TreeNode* pTree[100] = { 0, };
    int index = 0, currentIndex = 0, i = 0;
    char* temp = malloc(sizeof(char) * 2); 
    
    if (temp == NULL)
        { free(temp);   return 0; }
    else 
        { temp[0] = item[i++];    temp[1] = '\0'; }

    pTree[index] = CreateTree(NULL, temp, NULL);
    currentIndex = index;
    free(temp);

    void* root = pTree[index];
    
    while (root)
    {
        if (pTree[currentIndex]->left == NULL && i<strlen(item))    {
            char* temp = malloc(sizeof(char) * 2);
            if (temp == NULL)   { free(temp); break; }
            else  {temp[0] = item[i++];    temp[1] = '\0';  }

            pTree[++index] = CreateTree(NULL, temp, NULL);
            pTree[currentIndex]->left = pTree[index];

            Enqueue(pTree_Queue, pTree[currentIndex]->left);
            free(temp);
        }

        if (pTree[currentIndex]->right == NULL && i < strlen(item))  {
            char* temp = malloc(sizeof(char) * 2);
            if (temp == NULL)  { free(temp); break; }
            else   { temp[0] = item[i++];    temp[1] = '\0'; }

            pTree[++index] = CreateTree(NULL, temp, NULL);
            pTree[currentIndex]->right = pTree[index];

            Enqueue(pTree_Queue, pTree[currentIndex]->right);
            free(temp);
        }

        if (!IsEmptyQueue(pTree_Queue)) {
            currentIndex++;            root = Dequeue(pTree_Queue);
        }
        else
            root = NULL;
    }

    printf("\nPre-order : ");   Preorder(pTree[0]);
    printf("\n\nIn-order : ");    Inorder(pTree[0]);
    printf("\n\nPost-order : ");    Postorder(pTree[0]);
    printf("\n\nBreadth First : ");     Levelorder(pTree[0]);   printf("\n\n");

    DestroyQueue(pTree_Queue);    pTree_Queue = NULL;
    DestroyTree(pTree[0]); 
    for (int i = 0; i < strlen(item); i++) {
        pTree[i] = NULL;
    }
    free(item);

    return 0;
}