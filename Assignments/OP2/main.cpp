#include <ctime>
#include <iostream>
#include <random>

template <typename N>
struct Node {
  public:
    N data;
    int balance;
    Node* left;
    Node* right;
};

template <typename B>
class BST {
  protected:
    Node<B>* root;
    bool empty;

    void rInsert (Node<B>* node, B data) {
      if (node->data == data) {
        return;
      } else if (node->data > data) {
        if (node->left) {
          node->balance -= 1;
          rInsert(node->left, data);
        } else {
          node->left = new Node<B>;
          node->left->balance = 0;
          node->left->data = data;
          node->left->left = nullptr;
          node->left->right = nullptr;
        }
      } else {
        if (node->right) {
          node->balance += 1;
          rInsert(node->right, data);
        } else {
          node->right = new Node<B>;
          node->right->balance = 0;
          node->right->data = data;
          node->right->left = nullptr;
          node->right->right = nullptr;
        }
      }
    }

    void rprint (Node<B>* node) {
      if (node) {
        rprint(node->left);
        std::cout << node->data << ", balance = " << node->balance << '\n';
        rprint(node->right);
      }
    }
  public:
    BST () {
      root = nullptr;
      empty = true;
    }

    BST (B data) {
      root = new Node<B>;
      root->data = data;
      root->left = nullptr;
      root->right = nullptr;
      empty = false;
    }

    void insert (B data) {
      if (empty) {
        root = new Node<B>;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        empty = false;
      } else {
        rInsert(root, data);
      }
    }

    void print () {
      rprint(root);
    }
};

template<typename B>
class AVL: public BST<B> {
  private:
    void balance(Node<B>* node){
      if (node->balance == 2) {
        
      } else if (node->balance == -2) {

      }
    }
};

int main () {
  BST<int> treeOne;
  std::srand(time(0));

  for (int i=0; i<32;++i) {
    treeOne.insert(std::rand()%256);
  }

  treeOne.print();

  return 0;
}
