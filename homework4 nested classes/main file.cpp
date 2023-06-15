#include"Linked_list.h"


int main() {


	cout << "linked list" << endl << endl;
	LinkedList<int> list;
	list.add(2);
	list.add(5);
	list.add(15);
	list.add(25);
	list.print();
	list.remove();
	list.print();

	LinkedList<int>::Node<int>* node = list.find(5);
	if (node != 0) {
		node->value = 35;
	}
	list.print();

	list.addAfter(135, node);
	list.print();
	list.clear();
	list.print();


}

