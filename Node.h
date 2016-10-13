#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	Node(T item, Node* left, Node* right) {
		this->item = item;
		this->left = left;
		this->right = right;
	};

	Node(Node<T*>*& other) {
		this->item = other->item;
		this->left = other->left;
		this->right = other->right;
	};

	Node& operator=(Node<T>& other)  {
		this->item = other->item;
		this->left = other->left;
		this->right = other->right;
	};
	
	~Node() {
		delete item;
	};
	
	T item;
	
	Node<T>* left;
	
	Node<T>* right;

	bool operator<(const Node<T>* rhs) const {
		return this->item < rhs->item;
	};

	bool operator>=(const Node<T>* rhs) const {
		return this->item >= rhs->item;
	};

	bool operator==(const Node<T>* rhs) const {
		return this->item == rhs->item;
	};
};
#endif
