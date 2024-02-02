#include <iostream>

struct Qubit {
	int num;
	Qubit* next;
};

class Queue {
	private:
		Qubit* front;
		Qubit* back;
		int size;
	public:
	Queue() {
		size = 0;
		front = new Qubit;
		back = front;
	}
	Queue(int x) {
		size = 1;
		front = new Qubit;
		back = front;
		back->num = x;
	}
	void push(int x) {
		if (size) {
			back->next = new Qubit;
			back = back->next;
		}
		back->num = x;
		size++;
	}
	int pull() {
		if (size) {
			Qubit* temp = front;
			int x = front->num;
			front = front->next;
			delete temp;
			size--;
			return x;
		} else {
			return 0;
		}
	}
	int getSize() {
		return size;
	}
};

int main() {
	Queue testq;

	std::cout << "testq size = " << testq.getSize() << "\n";

	testq.push(3);
	testq.push(6);
	testq.push(9);

	std::cout << "testq size after 3 pushes = " << testq.getSize() << "\n";

	int x = testq.pull();
	int y = testq.pull();
	int z = testq.pull();

	std::cout << "testq contents: " << x << " " << y << " " << z << "\n";

	std::cout << "testq size after 3 pulls = " << testq.getSize() << "\n";
}
