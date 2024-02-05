#include <iostream>

class Stack{
private:
  int* container;
  int size;
  int offset;
public:
  Stack(int s) {
    container = new int[size];
    size = s;
    offset = 0;
  }
  Stack(int s, int* data) {
    container = data;
    size = s;
    offset = size;
  }

  bool isFull() {
    return offset == size;
  }

  bool isEmpty() {
    return offset == 0;
  }

  void push(int x) {
    container[offset++] = x;
  }

  int pop() {
    if (!isEmpty())
      return container[--offset];
  }
};

int main() {
  Stack pile(10);
  return 0;
}

