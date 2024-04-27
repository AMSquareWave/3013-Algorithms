#include <iostream>
#include <fstream>

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
		for (int i=1; i<size; i++) {
			back->next = new Vbit;
			back->next->prev = back;
			back = back->next;
			back->data = nums[i];
		}
	}
	void pushFront (int num) {
		Vbit* temp = new Vbit;
		if (front) {
			temp->data = num;
			temp->next = front;
			front->prev = temp;
			front = temp;
		} else {
			front = new Vbit;
			back = front;
			front->data = num;
		}
		size++;
	}
	void pushBack (int num) {
		if (front) {
			back->next = new Vbit;
			back->next->prev = back;
			back = back->next;
		} else {
			front = new Vbit;
			back = front;
		}
		back->data = num;
		size++;
	}
	int pullFront () {
		Vbit* temp = front;
		front = front->next;
		int num = temp->data;
		delete temp;
		size--;
		return num;
	}
	int pullBack() {
		Vbit* temp = back;
		back = back->prev;
		int num = temp->data;
		delete temp;
		size--;
		return num;
	}
	int getSize () {
		return size;
	}
};

int main() {
	std::fstream fin;
	Vector victor;

	fin.open("./input.dat");

	while (!fin.eof()) {
		int temp;
		fin >> temp;
		victor.pushBack(temp);
	}

	std::cout << "victor's size is " << victor.getSize() << "\n";

	std::cout << "the last item in victor was " << victor.pullBack() << " and the first was " << victor.pullFront() << "\n";

	std::cout << "victor's new size is " << victor.getSize() << "\n";

	fin.close();

	return 0;	
}
