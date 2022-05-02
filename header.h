#ifndef _BST_MAP_
#define _BST_MAP_

#include <iostream>

using std::cout;
using std::endl;

template<typename Key, typename Value>
class BSTMap {
  // You may add functionality to the Node class if you want to, but you must
  // not remove any functionality or change any variable/method names!
  // Ask if you'd like to make a change and you're not sure if it is safe.
  struct Node {
    Key key;
    Value value;
    Node *left, *right;

    Node(Key key)
        : key(key), left(nullptr), right(nullptr) {}
  };

  // This private root attribute is how you must store the root of your BST.
  Node *root;

  // You may change this method if you want.
  void print(Node *cur) const {
    if (cur != nullptr) {
      print(cur->left);
      cout << cur->key << ": " << cur->value << endl;
      print(cur->right);
    }
  }

  // You may add code here if you want to.

public:
  BSTMap() : root(nullptr) {}

  Value& get_or_insert(const Key& key) {
    // TODO: You must implement this method. You may create other methods if
    Node* current;
    current = root;
    Node* current2;
    if(root == nullptr) {
        root = new Node(key);
        current = root;
        return  root->key;
    } else if (current->key == key) {
        return current->value; 
    }
    if (key < current->key) {
        current2 = current;
        return get_or_insert(key, current->left);
    } else {
        current2 = current;
        return get_or_insert(key, current->right);
    }
  }

  // You may change this method if you want.
  void print() const {
    print(root);
  }
};

#endif // _BST_MAP_