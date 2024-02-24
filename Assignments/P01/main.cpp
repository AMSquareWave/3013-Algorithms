#include <iostream>
// # include <vector>

template<typename N> struct Node {
  N data;
  Node<N>* left;
  Node<N>* right;

  Node() {
    left = nullptr;
    right = nullptr;
  }
};

template<typename B> class BST {
public:
  Node<B>* root;
  BST() {
    root = nullptr;
  }

  void print() {
    rPrint(root->left);
    std::cout << root->data << " ";
    rPrint(root->right);
  }

  void insert(B item) {
    if (item == root->data) {
      return;
    }
    if (root == nullptr) {
      root = new Node<B>;
      root->data = item;
    } else if (item > root->data) {
      if (root->right == nullptr) {
        root->right = new Node<B>;
        root->right->data = item;
      }
      else {
        rInsert(item, root->right);
      }
    }
    else {
      if (root->left == nullptr) {
        root->left = new Node<B>;
        root->left->data = item;
      }
      else {
        rInsert(item, root->left);
      }
    }
  }

  void rPrint(Node<B>* printee) {
    rPrint(printee->left);
    std::cout << printee->data << " ";
    rPrint(printee->right);
  }

  ~BST() {
    destroyBranch(root->left);
    destroyBranch(root->right);
    delete root;
  }

private:
  void rInsert(B item, Node<B>* branch) {
    if (item == branch->data) {
      return;
    }
    if (item > branch->data) {
      if (branch->right == nullptr) {
        branch->right = new Node<B>;
        branch->right->data = item;
      }
      else {
        rInsert(item, branch->right);
      }
    }
    else {
      if (branch->left == nullptr) {
        branch->left = new Node<B>;
        branch->left->data = item;
      }
      else {
        rInsert(item, branch->left);
      }
    }
  }

  void destroyBranch (Node<B>* branch){
    destroyBranch(branch->left);
    destroyBranch(branch->right);
    delete branch;
  }
};

int main() {
  BST<int> numtree;

  numtree.insert(16);
  numtree.insert(8);
  numtree.insert(24);
  numtree.insert(4);
  numtree.insert(12);
  numtree.insert(18);
  numtree.insert(32);

  numtree.print();

  return 0;
}
