#ifndef TRAVERSALS_CPP
#define TRAVERSALS_CPP

#include "Traversals.h"

template<class ItemType>
Traversals<ItemType>::Traversals()
{
    root = NULL;
}

template<class ItemType>
Traversals<ItemType>::Traversals(TreeNode<ItemType> newRoot)
{
    root = newRoot;
}

template<class ItemType>
Traversals<ItemType>::~Traversals()
{
    root = NULL;
}

template<class ItemType>
bool Traversals<ItemType>::IsEmpty() const
{
    return ( root == NULL );
}

template<class ItemType>
void Traversals<ItemType>::postorder(TreeNode<ItemType> * node)
{
    if(node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->info << " ";
}

template<class ItemType>
void Traversals<ItemType>::inorder(TreeNode<ItemType> * node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    cout << node->info << " ";
    inorder(node->right);
}

template<class ItemType>
void Traversals<ItemType>::preorder(TreeNode<ItemType> * node)
{
    if(node == NULL)
        return;

    cout << node->info << " ";
    preorder(node->left);
    preorder(node->right);
}

#endif // TRAVERSALS_CPP
