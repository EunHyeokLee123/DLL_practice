#include "linklist.h"

using namespace std;

Node::Node(const Data& data) : pdata(data), prev(nullptr), next(nullptr) {}

DoubleLinkedList::DoubleLinkedList() {
	header = new Node();
	tail = new Node();
	header->next = tail;
	header->prev = nullptr;
	tail->prev = header;
	tail->next = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
	while (!isEmpty()) {                            
		removeHead();
	}     
	delete header; delete tail;
}

Node* DoubleLinkedList::returnHead() {
	return header->next;
}

Node* DoubleLinkedList::returnTail() {
	return tail->prev;
}

bool DoubleLinkedList::isEmpty() const {
	if (header->next == tail && tail->prev == header)
		return true;
	return false;
}

const Node* DoubleLinkedList::front(const Node* now) const{
	return now->prev;
}

const Node* DoubleLinkedList::back(const Node* now) const {
	return now->next;
}

const Data& DoubleLinkedList::content(const Node* now) const {
	return now->pdata;
}

void DoubleLinkedList::insertHead(const Data& in) {
	Node* cur = new Node(in);

	if (isEmpty()) {
		header->next = cur;
		tail->prev = cur;
		cur->next = tail;
		cur->prev = header;
	}
	else {
		cur->next = header->next;
		cur->prev = header;
		header->next->prev = cur;
		header->next = cur;
	}
}

void DoubleLinkedList::insertTail(const Data& in) {
	Node* cur = new Node(in);
	if (isEmpty()) {
		header->next = cur;
		tail->prev = cur;
		cur->next = tail;
		cur->prev = header;
	}
	else {
		cur->prev = tail->prev;
		cur->next = tail;
		tail->prev->next = cur;
		tail->prev = cur;
	}
}

void DoubleLinkedList::insert(const Data& in, Node* prev) {
	Node* cur = new Node(in);

	cur->prev = prev;
	cur->next = prev->next;

	prev->next->prev = cur;
	prev->next = cur;

}

bool DoubleLinkedList::removeHead() {
	if (isEmpty()) {
		return false;
	}
	Node* tmp = header->next;

	header->next = tmp->next;
	header->next->prev = tmp->prev;

	delete tmp;
	return true;
}

bool DoubleLinkedList::removeTail() {
	if (isEmpty()) {
		return false;
	}
	Node* tmp = tail->prev;

	tail->prev = tmp->prev;
	tmp->prev->next = tmp->next;

	delete tmp;
	return true;
}

bool DoubleLinkedList::remove(const Data& in) {
	Node* cur = find(in);
	if (cur != nullptr) {
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		delete cur;
		return true;
	}
	else
		return false;
}

Node* DoubleLinkedList::find(const Data& tar) {
	Node* cur = returnHead(); bool tmp = false;
	while (cur != tail) {
		if (cur->pdata == tar)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}

void DoubleLinkedList::display() {
	Node* cur = header->next;
	while (cur != tail) {
 		cout << cur->pdata << " <-> ";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}