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
    if(root != nullptr) {
      rPrint(root->left);
      std::cout << root->data << " ";
      rPrint(root->right);
    }
  }

  void insert(B item) {
    if (root != nullptr && item == root->data) {
//      std::cout << "item is at root already.\n";
      return;
    }
    if (root == nullptr) {
//      std::cout << "Adding item at root.\n";
      root = new Node<B>;
      root->data = item;
    }
    else if (item > root->data) {
      if (root->right == nullptr) {
//        std::cout << "placing " << item << "\n";
        
        root->right = new Node<B>;
        root->right->data = item;
      }
      else {
//        std::cout << "going right\n";
        rInsert(item, root->right);
      }
    }
    else {
      if (root->left == nullptr) {
//        std::cout << "placing " << item << "\n";
        root->left = new Node<B>;
        root->left->data = item;
      }
      else {
//        std::cout << "going left\n";
        rInsert(item, root->left);
      }
    }
  }

  ~BST() {
    if(root != nullptr) {
      destroyBranch(root->left);
      destroyBranch(root->right);
      delete root;
    }
  }

private:
  void rPrint(Node<B>* printee) {
    if(printee != nullptr) {
      rPrint(printee->left);
      std::cout << printee->data << " ";
      rPrint(printee->right);
    }
  }

  void rInsert(B item, Node<B>* branch) {
    if (branch != nullptr && item == branch->data) {
//      std::cout << "item is duplicate\n";
      return;
    }
    if (item > branch->data) {
//      std::cout << "placing " << item << "\n";
      if (branch->right == nullptr) {
        branch->right = new Node<B>;
        branch->right->data = item;
      }
      else {
//        std::cout << "going right\n";
        rInsert(item, branch->right);
      }
    }
    else {
      if (branch->left == nullptr) {
//        std::cout << "placing " << item << "\n";
        branch->left = new Node<B>;
        branch->left->data = item;
      }
      else {
//        std::cout << "going left\n";
        rInsert(item, branch->left);
      }
    }
  }

  void destroyBranch (Node<B>* branch){
    if(branch != nullptr) {
      destroyBranch(branch->left);
      destroyBranch(branch->right);
      delete branch;
    }
  }
};

int main() {
  BST<int> numtree;

//  std::cout << "inserting numbers...\n";

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
