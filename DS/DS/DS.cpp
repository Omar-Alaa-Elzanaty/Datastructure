// DS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// C++ program to demonstrate All Datastructures 
#include<bits/stdc++.h>

using namespace std;

struct doublenode {
	int data;
	doublenode* prev = nullptr, * next = nullptr;
	doublenode(int input) {
		data = input;
	}
};
struct node {
	int data;
	node* next;
	node(int input) {
		data = input;
		next = nullptr;
	}
};
class doublelinkedlist {
private:
	doublenode* head, * tail, * tempnode;
	int size = 0;
public:
	doublelinkedlist() :head(nullptr), tail(nullptr) {
		/*fucntions of doublelinkedlist:
		* pushback(data)
		* pushfront(data)
		* insert(data) at position
		* size()
		* is_empty
		* remove from began
		* remove from end
		* display
		* remove point
		* clear  remove all doublelinkedlist
		* reverse
		*/
	}// default constructor
	doublelinkedlist(int data) { //copy constructor
		head = tail = new doublenode(data);
		size++;
	}
	void push_back(int input) {//add to end of doulbelinkedlist
		tempnode = new doublenode(input);
		if (head == nullptr) {
			tempnode = new doublenode(input);
			head = tail = tempnode;
		}
		else {
			tempnode->prev = tail;
			tail->next = tempnode;
			tail = tempnode;
		}
		size++;
	}
	void push_front(int input) {// add to front of doublelinkedlist
		tempnode = new doublenode(input);
		if (head == nullptr) {
			head = tail = tempnode;
		}
		else {
			head->next = tempnode;
			tempnode->next = head;
			head = tempnode;
		}
		size++;
	}
	void insert(int input, int pos) {
		if (pos == size) {//at the end and increase size
			push_back(input);
		}
		else if (pos == 1) {// at the begin and increase size
			push_front(input);
		}
		else if (pos > size || pos < 1) {
			cout << "out of range" << endl;
		}
		else {// at position 
			tempnode = new doublenode(input);
			doublenode* temp = head;
			int i = 0;
			while (i < pos - 1) {
				temp = temp->next;
				i++;
			}
			tempnode->next = temp->next->prev;
			tempnode->prev = temp->next;
			temp->next->prev = tempnode;
			temp->next = tempnode;
			size++;
		}
	}
	bool empty() { // rturn true if list is empty
		return (head == nullptr && tail == nullptr);
	}
	int sizeoflist() { //return size of list
		return size;
	}
	void display() { //display from left to right
		doublenode* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}cout << endl;
	}
	void clear() { //remove all element
		doublenode* temp;
		while (head != nullptr) {
			temp = head->next;
			delete temp;
			head = temp;
		}
		tail = head = nullptr;
	}
	void remove_at_begin() {// romove first element
		if (size == 0) {
			cout << "list is empty" << endl;
		}
		else {
			doublenode* temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}
	void remove_at_end() {// remove last one
		if (size == 0) {
			cout << "list is empty" << endl;
		}
		else {
			doublenode* temp = tail->prev;
			delete tail;
			tail = temp;
			size--;
		}
	}
	void remove_item(int pos) {
		if (pos == 1 && size == 1) {
			delete head;
			head = tail = nullptr;
		}
		else if (size == 0) {
			cout << "list is empty" << endl;
		}
		else if (pos > size || pos < 1) {
			cout << "out of range" << endl;
		}
		else {
			doublenode* temp = head;
			int i = 0;
			while (i < pos) {
				temp = temp->next;
				i++;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			size--;
		}
	}
	void reverse() {
		if (size == 0) {
			cout << "list is empty" << endl;
		}
		else {
			doublenode* temp = nullptr, * cur = head;
			while (cur != nullptr) {
				temp = cur->next;
				swap(cur->next, cur->prev);
				cur = temp;
			}
			swap(head, tail);
		}
	}
};
class staack {
private:
	node* head = nullptr;
	int sze = 0;
public:
	void push(int data) {
		if (head == nullptr)
			head = new node(data);	//head 3 --> 2 --> 1 --> nullptr
		else {
			node* temp = new node(data);
			temp->next = head;
			head = temp;
		}
		sze++;
	}
	void pop() {
		if (sze == 0) {
			cout << "underflow" << endl;
			return;
		}
		node* temp = head;
		head = head->next;
		delete temp;
		sze--;
	}
	int top() {
		if (head != nullptr)
			return head->data;
	}
	int size() {
		return sze;
	}
	void display() {
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
class que {
private:
	node* front, * rear;
	int size = 0;
public:
	que() :front(nullptr), rear(nullptr) {};
	void push(int data) {
		node* temp = new node(data);
		if (rear == nullptr) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		size++;
	}
	int top() {
		if (front == nullptr) {
			cout << "underflow";
			return 0;
		}
		return front->data;
	}
	void pop() {
		if (front == nullptr) {
			cout << "queue is empty" << endl;
			return;
		}
		node* temp = front;
		front = front->next;
		if (front == nullptr)
			rear = nullptr;
		delete temp;
		size--;
	}
	int sizeofqueue() {
		return size;
	}
};
class BST {
private:
	BST* left, * right;
	int data;
public:
	BST() :left(nullptr), right(nullptr), data(0) {
	}
	BST(int dat) {
		data = dat;
		left = NULL;
		right = NULL;
	}
	BST* insert(int dat, BST* root) {
		if (root == NULL) {
			return new BST(dat);
		}
		if (dat > root->data)
			root->right = insert(dat, root->right);
		else
			root->left = insert(dat, root->left);
		return root;
	}
	void inorder(BST* root) {
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	void preorder(BST* root) {
		if (root == NULL)
			return;
		cout << root->data << " ";
		preorder(root->right);
		preorder(root->left);
	}
	void postorder(BST* root) {
		if (root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	BST* find_minimum(BST* node) {
		BST* curr = node;
		while (curr != NULL && curr->right != NULL) {
			curr = curr->right;
		}
		return curr;
	}
	BST* deletenode(BST* root, int dat) {
		if (root == NULL)
			return root;
		if (dat > root->data)
			root->right = deletenode(root->right, dat);
		else if (dat < root->data)
			root->left = deletenode(root->left, dat);
		else if (dat == root->data) {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				return NULL;
			}
			else if (root->left == NULL) {
				BST* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL) {
				BST* temp = root->left;
				delete root;
				return temp;
			}
			else {
				BST* temp = find_minimum(root->left);
				root->data = temp->data;
				root->left = deletenode(root->left, temp->data);
			}

		}
		return root;
	}

};
int main()
{


	return 0;
}
