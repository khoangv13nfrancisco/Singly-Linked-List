#include <iostream>
using namespace std;
 
struct Node {
	float data;
	Node *next;
};
 
struct LinkedList{
	Node *head;
	Node *tail;
};
 
Node* create_node(float x) {
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
 
void init(LinkedList &lst) {
	lst.head = NULL;
	lst.tail = NULL;
}
 
 
 
void remove_head(LinkedList &lst) {
	if (lst.head = NULL){
		return;
	}
	Node *cur = lst.head;
	lst.head = lst.head->next;
	delete cur;
}
 
void insert_tail(LinkedList &lst, float x) {
	Node *p = create_node(x);
	if (lst.head == NULL) {
		lst.head = lst.tail = p;
	}
	else {
		lst.tail->next = p;
		lst.tail = p;
	}
}
 
float second_max(LinkedList lst) {
	if (lst.head == NULL) {
		return -1;
	}
 
	float max1 = lst.head->data;
	float max2 = -1;
 
	Node *cur = lst.head->next;
	while (cur != NULL) {
		if (cur->data > max1) {
			max2 = max1;
			max1 = cur->data;
		}
		else if (cur->data > max2 && cur->data < max1) {
			max2 = cur->data;
		}
		cur = cur->next;
	}
	return max2;
}
 
int main() {
	float x;
	LinkedList lst;
	init(lst);
	while (true) {
		cin >> x;
		if (x == -1) {
			break;
		}
		insert_tail(lst, x);
	}
	cout << second_max(lst);
	return 0;
}