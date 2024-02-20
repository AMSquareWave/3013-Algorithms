#include <iostream>
#include <vector>

template<typename N> struct Node {
  N data;
  Node<N>* left;
  Node<N>* right;
};

template<typename B> class BST {
public:
void print() {
    print(root->left);
    std::cout << root->data << " ";
    print(root->right);
  }

private:
  Node<B>* root;
  BST() {
    root = nullptr;
  }

  void print(Node<B>* printee) {
    print(printee->left);
    std::cout << printee->data << " ";
    print(printee->right);
  }

  void destroyBranch (Node<B>& branch){
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
