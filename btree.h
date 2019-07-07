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
            if(root->size() == 1){
                if(root->hasKey(k)){
                    root->removeKey(k);
                    root->mergeChildren(0, 1); //must include taking a key downwards
                    root = root->getChild(0);
                    return true;
                }else if(root->childrenInDanger()){ //maybe have a parameter for this?
                    root->mergeChildren(0, 1); //this could be a "mergeRoot()" function
                    root->getChild(0);
                }
            }
            return root->erase(k);
        }

        void printInOrder() {
            root->printInOrder();
        }

        void printByLevel() {
            bool thereAreStillLevels;
            int currentTargetLevel = 0;
            while(thereAreStillLevels){
                cout << "Nivel " << currentTargetLevel << ":\t";
                thereAreStillLevels = root->printByLevel(0, currentTargetLevel);
                currentTargetLevel++;
                cout << endl;
            }
        }

        ~BTree(){
            root->chainDelete();
        }
};

#endif
