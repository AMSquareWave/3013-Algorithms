#include <iostream>
#include <strings.h>
#include <vector>
#include <string>
#include <stack>

#pragma once

class TrieNode {
  protected:
    std::vector<TrieNode*> alphabet;
    int alphabetSize;
    bool isWord;
    int alphIndex;
  public:
    TrieNode (int space, int index) {
      alphabetSize = space;
      alphIndex = index;
      for(int i=0; i<space; ++i) {
        alphabet.push_back(nullptr);
      }
    }

    TrieNode* traverse (int index) {
      return alphabet[index];
    }

    bool exists (int index) {
      return bool(alphabet[index]);
    }

    void insert (int index) {
      TrieNode* temp = new TrieNode(alphabetSize, index);
      alphabet[index] = temp;
    }

    void remove (int index) {
      TrieNode* temp = alphabet[index];
      alphabet[index] = nullptr;
      delete temp;
    }

    void setWordStatus (bool query) {
      isWord = query;
    }

    int getIndex () {
      return alphIndex;
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
      root = new TrieNode(space, 0);
    }

    void insert (std::string word) {
      TrieNode* temp = root;
      for (auto i=word.begin(); i!=word.end(); ++i) {
        if (temp->exists(*i)) {
          temp = temp->traverse(*i);
        } else {
          temp->insert(*i);
          temp = temp->traverse(*i);
        }
      }
      temp->setWordStatus(true);
    }

    std::vector<std::string> partialMatches (std::string query) {
      std::string tempStr = query;
      std::vector<std::string> results;
      TrieNode* tempNode = root;

      for(auto i=query.begin(); i!=query.end();++i){
        tempNode = tempNode->traverse(*i);
      }

      std::stack<TrieNode*> traversalStack;
      traversalStack.push(tempNode);

      std::string stackStr = tempStr;

      std::vector<TrieNode*> visited;
      visited.push_back(tempNode);

      while (!traversalStack.empty()) {
        TrieNode* stackNode = traversalStack.top();
        traversalStack.pop();

        for (auto i=visited.begin(); i!=visited.end(); ++i) {
          if (stackNode == *i) {
            stackStr = tempStr;
          }
        }

        visited.push_back(stackNode);

        if (stackNode != tempNode) {
          stackStr.push_back(char(stackNode->getIndex()));
        }

        if (stackNode->wordStatus()) {
          results.push_back(stackStr);
        }

        for (int i=alphabetSize-1; i>=0; --i) {
          if(stackNode->traverse(i)) {
            traversalStack.push(stackNode->traverse(i));
          }
        }
      }

      return results;
    }
};
