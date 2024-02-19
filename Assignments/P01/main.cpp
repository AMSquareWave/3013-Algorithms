#include <iostream>
#include <vector>

template<typename N> struct Node {
  N data;
  Node<N>* left;
  Node<N>* right;
};

template<typename B> class BST {
public:

private:
  Node<B>* root;
  BST() {
    root = nullptr;
  }

  void destroyBranch (Node<B>* branch){
    destroyBranch(branch->left);
    destroyBranch(branch->right);
    delete branch;
  }

  ~BST() {
    destroyBranch(root->left);
    destroyBranch(root->right);
    delete root;
  }
};

int main() {
 
  return 0;
}
