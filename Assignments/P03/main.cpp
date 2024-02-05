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
    if(!isFull()) {
      container[offset++] = x;
    } else {
      std::cout << "Stack Full, Please pop() and Try Again.\n";
    }
  }

  int pop() {
    if (!isEmpty()) {
      return container[--offset];
    } else {
      return 0;
    }
  }
};

int main() {
  Stack pile(10);

  for (int i=1; i<=10; i++) {
    pile.push(i);
  }

  pile.push(11);

  std::cout << "The top of the pile is " << pile.pop() << "\n";
  std::cout << "Now it's " << pile.pop() << "\n";

  pile.push(21);
  std::cout << "This time it's " << pile.pop() << "\n";

  return 0;
}

