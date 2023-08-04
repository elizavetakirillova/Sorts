// Сортировка бинарным деревом
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* left;
    struct node* right;
    int id;
} node;

node* create_element (node* tree, int data) {
    if(tree == NULL) {
        node* element = malloc(sizeof(node));
        element->id = data;
        element->left = NULL;
        element->right = NULL;
        return element;
    }
    
    if(data < tree->id) {
        tree->left = create_element(tree->left, data);
    }
    
    if(data > tree->id) {
        tree->right = create_element(tree->right, data);
    }
    
    return tree;
}

void show_tree(node* tree) {
    if(tree == NULL) {
        return;
    }
    show_tree(tree->left);
    printf("%d ", tree->id);
    show_tree(tree->right);
}

void show_tree_addresses(node* tree) {
    if(tree == NULL) {
        return;
    }
    show_tree_addresses(tree->left);
    printf("%p ", &tree->id);
    show_tree_addresses(tree->right);
}

void tree_to_array(node* tree, int arr[], int* i) {
    if (tree->left != NULL)
        tree_to_array(tree->left, arr, i);
    arr[(*i)++] = tree->id;
    if (tree->right != NULL)
        tree_to_array(tree->right, arr, i);
    //return arr;    
}

int main()
{
    node* tree;
    int arr[4] = {22, 16, 6, 20}; 
    int m = 0;
    
    while(m < 4) {
        tree = create_element(tree, arr[m]);
        m++;
    }

    m = 0;
    //show_tree(tree);
    printf("\n");
    int a = 0;
    
    tree_to_array(tree, arr, &a);
    
    while(m < 4) {
        printf("%d ", arr[m]);
        m++;
    }
    
    return 0;
}