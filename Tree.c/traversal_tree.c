#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
struct node 
{     
    int data;     
    struct node* left;     
    struct node* right; 
};  
struct node* createNode(int value)  
{     
    struct node* newNode = (struct node*)malloc(sizeof(struct node));     
    if (!newNode)      
    {         
        printf("Memory allocation failed\n");         
        return NULL;     
    }     
    newNode->data = value;     
    newNode->left = NULL;     
    newNode->right = NULL;     
    return newNode; 
}  
void inorderTraversal(struct node* root)  
{     
    if (root == NULL)         
        return;     
    inorderTraversal(root->left);     
    printf("%d ", root->data);     
    inorderTraversal(root->right); 
}  
void preorderTraversal(struct node* root)  
{     
    if (root == NULL)         
        return;     
    printf("%d ", root->data);     
    preorderTraversal(root->left);     
    preorderTraversal(root->right); 
}  
void postorderTraversal(struct node* root)  
{     
    if (root == NULL)         
        return;     
    postorderTraversal(root->left);     
    postorderTraversal(root->right);     
    printf("%d ", root->data); 
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        
        if (lheight > rheight)
            return(lheight + 1);
        else 
            return(rheight + 1);
    }
}
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
    {
        printf("  ");
        return;
    }
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
void displayTree(struct node* root)
{
    printf("\nTree Structure:\n");
    int h = height(root);
    int i;

    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}
int main()  
{     
    struct node* root = createNode(1);     
    root->left = createNode(2);     
    root->right = createNode(3);     
    root->left->left = createNode(4);     
    root->left->right = createNode(5);      
    printf("Inorder Traversal: ");     
    inorderTraversal(root);     
    printf("\n");      
    printf("Preorder Traversal: ");     
    preorderTraversal(root);     
    printf("\n");      
    printf("Postorder Traversal: ");     
    postorderTraversal(root);     
    printf("\n");      
    displayTree(root);
    free(root->left->left);     
    free(root->left->right);     
    free(root->right);     
    free(root->left);     
    free(root);      
    return 0; 
}