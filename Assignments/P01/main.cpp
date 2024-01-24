#include <iostream>

// Vector monomer struct (what the Vector container will be made of)
struct Vbit {
	Vbit* next;
	Vbit* prev;
	int data;
};

//Vector class
class Vector {
	private:
	Vbit* front;
	Vbit* back;
	int size;
	public:
	Vector () {
		front = back = NULL;
		size = 0;
	}
	Vector (int num) {
		front = new Vbit;
		back = front;
		front->data = num;
		size = 1;
	}
	Vector (int* nums, int s) {
		size = s;
		front = new Vbit;
		back = front;
		front->data = nums[0];
		for (int i=1; i<size, i++) {
			back->next = new Vbit;
			back->next->prev = back;
			back = back->next;
			back->data = nums[i];
		}
	}
	void pushFront (int num) {
		Vbit temp = new Vbit;
		temp->data = num;
		temp->next = front;
		front->prev = temp;
		front = temp;
	}
	void pushBack (int num) {
		back->next = new Vbit;
		back->next->prev = back;
		back = back->next;
		back->data = num;
	}
	int pullFront () {
		Vbit temp = front;
		front = front->next;
		int num = temp->data;
		delete temp;
		return num;
	}
	int pullBack() {
		Vbit temp = front;
		front = front->next;
		int num = temp->data;
		delete temp;
		return num;
	}
}

int main() {
	return 0;
}
