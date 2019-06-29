#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;

    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr) {};

        bool search(int k) { 
            return root->search(k);
        } 

        bool insert(int k) {
           if(!root) root = new Node<T>(degree);
           if(root->size() == degree-1){
                auto newRoot = new Node<T>(degree);
                newRoot->addChild(root);
                root = newRoot;
                root->splitChild(0);
           }
           return root->insertNonFull(k);
        }

        bool remove(int k) {
            auto target = root->findPrevious(k);
            if(!target->hasKey(k)) return false;
        }

        void print() {
            // TODO
        }

        //~BTree();
};

#endif
