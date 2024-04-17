#include <strings.h>
#include <vector>
#include <string>

class TrieNode {
  protected:
    std::vector<TrieNode*> alphabet;
    int alphabetSize;
    bool isWord;
  public:
    TrieNode (int space) {
      alphabetSize = space;
      alphabet.resize(space);
    }

    TrieNode* traverse (int index) {
      return alphabet[index];
    }

    bool exists (int index) {
      return bool(alphabet[index]);
    }

    void insert (int index) {
      alphabet[index] = new TrieNode(alphabetSize);
      for (auto i=alphabet.begin();i!=alphabet.end();++i){
        *i = nullptr;
      }
    }

    void remove (int index) {
      delete alphabet[index];
      alphabet[index] = nullptr;
    }

    void setWordStatus (bool query) {
      isWord = query;
    }

    bool wordStatus () {
      return isWord;
    }
};

class TrieTree {
  private:
    TrieNode* root;
    int alphabetSize;

  public:
    TrieTree (int space) {
      alphabetSize = space;
      root = new TrieNode(space);
    }

    void insert (std::string word) {
      TrieNode* temp = root;
      for (auto i=word.begin(); i!=word.end(); ++i) {
        if (temp->exists(*i)) {
          temp = temp->traverse(*i);
        } else {
          temp->insert(*i);
          temp = temp->traverse(char(*i));
        }
      }
    }
};
