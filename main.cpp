#include <iostream>

#include "btree.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[]) {
    int degree = 4;

    /*Node<int> myNode(degree);
    auto otherNode = new Node<int>(degree); 
    for(int i = 0; i < degree; i++){
        myNode.insertKey(i);
    }
    
    myNode.showKeys();
    
    cout << "Otro nodo\n";

    myNode.transferData(degree/2, degree, otherNode);

    otherNode->showKeys();

    for(int i = 0; i < degree + 1; i++){
        if(myNode.hasKey(i)) cout << "Tiene la key " << i << endl;
        else cout << "No tiene la key " << i << endl;

    }*/

    BTree<int> myBTree(degree);
    myBTree.insert(1);
    myBTree.insert(4);
    myBTree.insert(6);
    myBTree.insert(8);
    myBTree.insert(12);
    myBTree.insert(0);
    myBTree.insert(3);
    myBTree.insert(14);
    myBTree.insert(7);
    myBTree.insert(5);
    myBTree.insert(11);
    myBTree.insert(10);

   /* vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    v.insert(v.begin() + 0, 8);
    v.insert(v.begin() + 1, 9);
    v.insert(v.begin() + 3, 10);*/


    return EXIT_SUCCESS;
}
