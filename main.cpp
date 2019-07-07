#include <iostream>

#include "btree.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[]) {
    int degree = 4;

    auto myBTree = new BTree<int>(degree);
    myBTree->insert(1);
    myBTree->insert(4);
    myBTree->insert(6);
    myBTree->insert(8);
    myBTree->insert(12);
    myBTree->insert(0);
    myBTree->insert(3);
    myBTree->insert(14);
    myBTree->insert(7);
    myBTree->insert(5);
    myBTree->insert(11);
    myBTree->insert(10);
    myBTree->printInOrder();
    delete myBTree;

    cout << "Success\n";

/*    Node<int> root(degree);
    root.insertKey(7);
    root.insertKey(9);
    root.insertKey(10);
    root.showKeys();

    auto child0 = new Node<int>(degree);
    child0->insertKey(6);
    child0->showKeys();
    
    auto child1 = new Node<int>(degree);
    child1->insertKey(8);
    child1->showKeys();

    root.addChild(child0);
    root.addChild(child1);
    
    root.mergeChildren(0, 1);
    cout << "Root:\n";
    root.showKeys();
    cout << "Child0:\n";
    child1->showKeys();
    cout << "Child1:\n";
    child1->showKeys();
*/
   /* vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    v.insert(v.begin() + 0, 8);
    v.insert(v.begin() + 1, 9);
    v.insert(v.begin() + 3, 10);*/


    return EXIT_SUCCESS;
}
