#include <iostream>

class Stack{
private:
  int* container;
  int size;
public:
  Stack(int s) {
    container = new int[size];
    size = s;
  }
  Stack(int s, int* data) {
    container = data;
    size = s;
  }
};
int main () {
  Stack pile(10);
  return 0;
}

