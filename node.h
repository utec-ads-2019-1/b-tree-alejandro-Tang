#ifndef NODE_H
#define NODE_H

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Node {
    unsigned int degree;
    vector<unsigned int> keys;
    vector<Node<T>*> children;
    public: 
        Node(unsigned int degree) : degree(degree) {};
        Node * search(int k){
            int i = 0;
            while(i < degree - 1 and k > keys[i]) i++;

            if(keys[i] == k) return this;
            if (this->isLeaf()) return nullptr;
            if (keys[i] > k) return children[i]->search(k);
            return children[i+1]->search(k);
        }

        bool splitChild(int childNum){
            auto child = children[childNum];
            auto newSibling = new Node<int>(degree);
            int middle = child->getMiddleKey();
            this->insertKey(middle);

            child->transferData((degree-1)/2, degree-1, newSibling);
            child->deleteHalf();

            int it = keys.size() - 1;
            while(middle != keys[it]) it--;                 //hazard
            children.insert(children.begin() + it + 1, newSibling);
        }

        bool insertNonFull(int k){
            if(this->isLeaf()) return this->insertKey(k);

            int it = keys.size() - 1;
            while(it >= 0 and k < keys[it]) it--;
            it++;

            //if(keys[it] == k) return false;

            auto child = children[it];
            if(child->size() != degree - 1) return child->insertNonFull(k);

            this->splitChild(it);
            if(k > keys[it]) child = children[it+1];
            child->insertNonFull(k);
        }


        int getMiddleKey(){
            return keys[(degree-1)/2];
        }

        void deleteHalf(){
            if(!this->isLeaf()) {
                for (int i = degree/2; i < degree; i++) {
                    children.pop_back();
                }
            }
            for (int i = (degree-1)/2 + 1; i < degree; i++) {
                keys.pop_back();
            }
        }

        bool insertKey(int k){
            keys.push_back(k);
            sort(keys.begin(), keys.end());
            return true;
        }

        void addChild(Node * newChild){
            children.push_back(newChild);
        }

        bool operator< (const Node& otherNode) {
            if(this->lesserKey() < otherNode->lesserKey()) return true;
            return false;
        }

        void transferData(int start, int end, Node * sibling){
            if(!this->isLeaf()){
                for(int i = start + 1; i <= end; i++){
                    sibling->addChild(children[i]);
                }
            }
            for(int j = start + 1; j < end; j++){
                sibling->insertKey(keys[j]);
            }
        }

        bool hasKey(int k){
            if(find(keys.begin(), keys.end(), k) == keys.end()) return false;
            return true;
        }
    
        unsigned int size(){
            return keys.size();
        }

        void showKeys(){
            for(int i = 0; i < keys.size(); i++){
                cout << keys[i] << endl;
            }
        };

        bool isLeaf(){
            if(children.size()) return false;
            return true;
        }
 
};

#endif
