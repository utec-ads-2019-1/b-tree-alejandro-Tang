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

    cout << "Nodos en el BTree:\n";
    myBTree->printInOrder();

    cout << endl;
    for(int i = 0; i <= 15; i++) {
        cout << "El nodo con el valor " << i;
        if(myBTree->search(i)) cout << " se encuentra en el BTree.";
        else cout << " no se encuentra en el BTree.";
        cout << endl;
    }

    myBTree->printByLevel();
    delete myBTree;

    cout << "Success\n";

    return EXIT_SUCCESS;
}
