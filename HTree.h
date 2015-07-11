#ifndef H_TREE_H
#define H_TREE_H

#include <utility>
#include <string>
#include "HuffmanException.h"
#include "Node.h"

#define LEFT  0
#define RIGHT 1

typedef std::pair<std::string, int>  KeyPair;

class HTree {
public:
	HTree();

	HTree(KeyPair* key, int& size);

	~HTree();

	void buildTree();

	std::string getCode(std::string s);

	/*
	 * input a 1 or a 0, if a char is found then RETURN will be true and c 
	 * will point to the decoded character
	 */
	bool feedCode(int bin, char*& c);

	/*
	 * For debugging, prints out the tree
	 */
	void print();

	/*
	 * sets the frequency and size, Used for decompression
	 */
	void setFreqAndSize(KeyPair* freq, int size);

private:
	Node<KeyPair*>* root;

	Node<KeyPair*>* findPtr;

	int size;

	KeyPair* key;

	std::string getCode(std::string s, Node<KeyPair*>* tree);

	void print(Node<KeyPair*>* t);

	void destroy(Node<KeyPair*>* t);

	inline bool checkForLeaf(const Node<KeyPair*>* node) const;
};

inline bool comp(const Node<KeyPair*>* a, const Node<KeyPair*>* b);
#endif

