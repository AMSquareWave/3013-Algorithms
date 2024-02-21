#include <iostream>
// # include <vector>

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

  void rInsert(B item, Node<B>& branch) {
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
