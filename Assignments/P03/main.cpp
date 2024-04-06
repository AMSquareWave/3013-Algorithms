#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

template <typename N>
struct Node {
  public:
    N data;
    Node* left;
    Node* right;
};

template <typename B>
class BST {
  private:
    Node<B>* root;
    bool empty;

    void rInsert (Node<B>* node, B data) {
      if (node->data == data) {
        return;
      } else if (node->data > data) {
        if (node->left) {
          rInsert(node->left, data);
        } else {
          node->left = new Node<B>;
          node->left->data = data;
          node->left->left = nullptr;
          node->left->right = nullptr;
        }
      } else {
        if (node->right) {
          rInsert(node->right, data);
        } else {
          node->right = new Node<B>;
          node->right->data = data;
          node->right->left = nullptr;
          node->right->right = nullptr;
        }
      }
    }

    void rprint (Node<B>* node) {
      if (node) {
        rprint(node->left);
        std::cout << node->data << '\n';
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

int main () {
  BST<int> treeOne;
  std::srand(time(0));

  for (int i=0; i<32;++i) {
    treeOne.insert(std::rand()%256);
  }

  treeOne.print();

  return 0;
}
