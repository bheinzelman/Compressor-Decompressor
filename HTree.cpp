#include "HTree.h"
#include <iostream>
#include <queue>
#include <functional>

typedef std::priority_queue < Node<KeyPair*>*, std::vector<Node<KeyPair*>*>, decltype(&comp)> Pqueue;

HTree::HTree() {
	this->root = NULL;
	this->findPtr = NULL;
	this->size = 0;
}

HTree::HTree(KeyPair* key, int& size) {
	this->root = NULL;
	this->size = size;
	this->key = key;
	buildTree();
}

HTree::~HTree() { 
	this->destroy(root); 
}

void HTree::print() {
	print(root);
}

void HTree::print(Node<KeyPair*>* t) {
	if (t == NULL)
		return;
	print(t->left);
	std::cout << t->item->first << " " << t->item->second << std::endl;
	print(t->right);
}

std::string HTree::getCode(std::string c, Node<KeyPair*>* tree) {
	if (c == tree->item->first) {
		return "";
	}
	else if (checkForLeaf(tree)) {
		throw HuffmanException("Could not find char in tree");
	}

	bool left = false;
	for (int i = 0; i < tree->left->item->first.size(); i++) {
		if (c[0] == tree->left->item->first[i]) {
			left = true;
			break;
		}
	}	

	if (left) {
		return "0" + getCode(c, tree->left);
	}
	else {
		return "1" + getCode(c, tree->right);
	}
}

std::string HTree::getCode(std::string c) {
	return getCode(c, root);
}

void HTree::buildTree() {
	Pqueue queue(&comp);

	for (int i = 0; i < size; i++) {
		KeyPair* k = new KeyPair;
		k->first = key[i].first;
		k->second = key[i].second;
		Node<KeyPair*>* kNode = new Node<KeyPair*>(k, NULL, NULL);
		queue.push(kNode);
	}
	Node<KeyPair*>* tmp = NULL;
	while (queue.size() > 1) {
		//get two smallest values from the heap
		Node<KeyPair*>* least = queue.top();
		queue.pop();

		Node<KeyPair*>* second = queue.top();
		queue.pop();

		KeyPair* new_pair = new KeyPair;
		new_pair->first = least->item->first + second->item->first;
		new_pair->second = least->item->second + second->item->second;
		
		tmp = new Node<KeyPair*>(new_pair, second, least);					  //insert into tree
		queue.push(tmp); //push back on queue
	}

	destroy(root);

	root = tmp;
}

void HTree::destroy(Node<KeyPair*>* t) {
	if (t != NULL){
		if (t->left != NULL)
			destroy(t->left);
		if (t->right != NULL)
			destroy(t->right);
		delete t;
		t = NULL;
	}
}

bool HTree::feedCode(int bit, char*& c) {
	if (findPtr == NULL) {
		findPtr = root;
	}
	if (checkForLeaf(findPtr)) {
		c = new char;
		*c = findPtr->item->first.data()[0];
		findPtr = NULL;
		return true;
	}
	else if (bit == LEFT) {
		if (findPtr->left->item->first.size() == 1) {
			c = new char;
			*c = findPtr->left->item->first.data()[0];
			findPtr = NULL;
			return true;
		}
		findPtr = findPtr->left;
		return false;
	}
	else {
		if (findPtr->right->item->first.size() == 1) {
			c = new char;
			*c = findPtr->right->item->first.data()[0];
			findPtr = NULL;
			return true;
		}
		findPtr = findPtr->right;
		return false;
	}
}

void HTree::setFreqAndSize(KeyPair* freq, int size) {
	this->key = freq;
	this->size = size;
}

inline bool HTree::checkForLeaf(const Node<KeyPair*>* node) const  {
	return node->left == NULL && node->right == NULL;
}

inline bool comp(const Node<KeyPair*>* a, const Node<KeyPair*>* b) {
	return a->item->second > b->item->second;
}