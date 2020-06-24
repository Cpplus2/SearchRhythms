#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include "TreeType.h"

template<class ItemType>
class Traversals
{
    private:
        TreeNode<ItemType>* root;

    public:
        Traversals();
        Traversals(TreeNode<ItemType>);
        ~Traversals();
        bool IsEmpty() const;
        void inorder(TreeNode<ItemType>*);
        void preorder(TreeNode<ItemType>*);
        void postorder(TreeNode<ItemType>*);
};

#include "Traversals.cpp"

#endif // TRAVERSALS_H
