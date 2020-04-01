#include "map.h"

template<typename T, typename T1> void Map<T, T1>::printTree()
{
	if (Top)
	{
		print_Helper(this->Top, "", true);
	}
	else throw std::out_of_range("Tree is empty!");
}

template<typename T, typename T1> void  Map<T, T1>::insert(T key, T1 value)
{

	if (this->Top != NULL) {
		Node* node = NULL;
		Node* parent = NULL;
		for (node = this->Top; node != TNULL; )// Search leaf for new element 
		{
			parent = node;
			if (key < node->key)
				node = node->left;
			else if (key > node->key)
				node = node->right;
			else if (key == node->key)
				throw std::out_of_range("key is repeated");
		}
		node = new Node(RED, key, TNULL, TNULL, TNULL, value);
		node->parent = parent;
		if (parent != TNULL) {
			if (key < parent->key)
				parent->left = node;
			else
				parent->right = node;
		}
		rbtree_fixup_add(node);
	}
	else {
		this->Top = new Node(BLACK, key, TNULL, TNULL, TNULL, value);
	}
}

template<typename T, typename T1> List<T>* Map<T, T1>::get_keys() {
	List<T>* list = new List<T>();
	this->ListKeyOrValue(1, list);
	return list;
}

template<typename T, typename T1> List<T1>* Map<T, T1>::get_values() {
	List<T1>* list = new List<T1>();
	this->ListKeyOrValue(2, list);
	return list;
}

template<typename T, typename T1> T1 Map<T, T1>::find(T key) {
	Node* node = Top;
	while (node != TNULL && node->key != key) {
		if (node->key > key)
			node = node->left;
		else
			if (node->key < key)
				node = node->right;
	}
	if (node != TNULL)
		return node->value;
	else
		throw std::out_of_range("Key is missing");
}

template<typename T, typename T1> void Map<T, T1>::Delete(T key)
{
	Node* needed = Top;
	// находим узел с ключом key
	while (needed->key != key) {
		if (needed->key < key)
			needed = needed->right;
		else
			needed = needed->left;
	}
	deleteNode(needed);
}

template<typename T, typename T1> void Map<T, T1>::deleteNode(Node* z) {
	Node* x, * y;

	
	 // delete node z from tree  

	if (!z || z == TNULL) return;


	if (z->left == TNULL || z->right == TNULL) {
		/* y has a TNULL node as a child */
		y = z;
	}
	else {
		/* find tree successor with a TNULL node as a child */
		y = z->right;
		while (y->left != TNULL) y = y->left;
	}

	/* x is y's only child */
	if (y->left != TNULL)
		x = y->left;
	else
		x = y->right;

	/* remove y from the parent chain */
	x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
		Top = x;

	if (y != z) {
		z->key = y->key;
		z->value = y->value;
	}

	if (y->color == BLACK)
		deleteFixup(x);

}
template<typename T, typename T1> void Map<T, T1>::deleteFixup(Node* x) {

	/* maintain Red-Black tree balance  
	   after deleting node x  */

	while (x != Top && x->color == BLACK) {
		if (x == x->parent->left) {
			Node* w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				left_rotate(x->parent);
				x = Top;
			}
		}
		else {
			Node* w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				right_rotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(x->parent);
				x = Top;
			}
		}
	}
	x->color = BLACK;
}

template<typename T, typename T1> void Map<T, T1>::clear() {
	this->clear_tree(this->Top);
	this->Top = NULL;
}


    
	//swap links(parent and other) for rotate


    template<typename T, typename T1> void Map<T, T1>::clear_tree(Node* tree) {
		if (tree != TNULL) {
			clear_tree(tree->left);
			clear_tree(tree->right);
			delete tree;
		}
	}

    template<typename T, typename T1> typename Map<T, T1>::Node* Map<T, T1>::minimum(Node* node) //finding minimal element
	{
		while (node->left != TNULL)
		{
			node = node->left;
		}
		return node;
	}

    template<typename T, typename T1> typename Map<T, T1>::Node* Map<T, T1>::maximum(Node* node)//finding max element
	{
		while (node->right != TNULL)
		{
			node = node->right;
		}
		return node;
	}

    template<typename T, typename T1> typename Map<T, T1>::Node* Map<T, T1>::grandparent(Node* cur)//finding  grandparent
	{
		if ((cur != TNULL) && (cur->parent != TNULL))
			return cur->parent->parent;
		else
			return TNULL;
	}

    template<typename T, typename T1> typename Map<T, T1>::Node* Map<T, T1>::uncle(Node* cur) //finding uncle
	{
		Node* cur1 = grandparent(cur);
		if (cur1 == TNULL)
			return TNULL; // No grandparent means no uncle
		if (cur->parent == cur1->left)
			return cur1->right;
		else
			return cur1->left;
	}

    template<typename T, typename T1>	typename Map<T, T1>::Node* Map<T, T1>::sibling(Node* n)
	{
		if (n == n->parent->left)
			return n->parent->right;
		else
			return n->parent->left;
	}

    template<typename T, typename T1> typename Map<T, T1>::Node* Map<T, T1>::find_key(T key) {
		Node* node = this->Top;
		while (node != TNULL && node->key != key) {
			if (node->key > key)
				node = node->left;
			else
				if (node->key < key)
					node = node->right;
		}
		if (node != TNULL)
			return node;
		else
			throw std::out_of_range("Key is missing");
	}
	//all print function
    template<typename T, typename T1>	void Map<T, T1>::print_Helper(Node* root, string indent, bool last)
	{
		if (root != TNULL)
		{
			cout << indent;
			if (last)
			{
				cout << "R----";
				indent += "   ";
			}
			else
			{
				cout << "L----";
				indent += "|  ";
			}
			string sColor = !root->color ? "BLACK" : "RED";
			cout << root->key << "(" << sColor << ")" << endl;
			print_Helper(root->left, indent, false);
			print_Helper(root->right, indent, true);
		}
	}
    template<typename T, typename T1>	void Map<T, T1>::ListKeyOrValue(int mode, List<T>* list) {
		if (this->Top != TNULL)
			this->KeyOrValue(Top, list, mode);
		else
			throw std::out_of_range("Tree empty!");
	}
template<typename T, typename T1>	void Map<T, T1>::KeyOrValue(Node* tree, List<T>* list, int mode) {

		if (tree != TNULL) {
			KeyOrValue(tree->left, list, mode);
			if (mode == 1)
				list->push_back(tree->key);
			else
				list->push_back(tree->value);
			KeyOrValue(tree->right, list, mode);
		}
	}

	//fix before add
    template<typename T, typename T1> void Map<T, T1>::rbtree_fixup_add(Node* node)
	{
		Node* uncle;
		/* Current node is RED */
		while (node != this->Top && node->parent->color == RED)//
		{
			/* node in left tree of grandfather */
			if (node->parent == this->grandparent(node)->left)//
			{
				/* node in left tree of grandfather */
				uncle = this->uncle(node);
				if (uncle->color == RED) {
					/* Case 1 - uncle is RED */
					node->parent->color = BLACK;
					uncle->color = BLACK;
					this->grandparent(node)->color = RED;
					node = this->grandparent(node);
				}
				else {
					/* Cases 2 & 3 - uncle is BLACK */
					if (node == node->parent->right) {
						/*Reduce case 2 to case 3 */
						node = node->parent;
						this->left_rotate(node);
					}
					/* Case 3 */
					node->parent->color = BLACK;
					this->grandparent(node)->color = RED;
					this->right_rotate(this->grandparent(node));
				}
			}
			else {
				/* Node in right tree of grandfather */
				uncle = this->uncle(node);
				if (uncle->color == RED) {
					/* Uncle is RED */
					node->parent->color = BLACK;
					uncle->color = BLACK;
					this->grandparent(node)->color = RED;
					node = this->grandparent(node);
				}
				else {
					/* Uncle is BLACK */
					if (node == node->parent->left) {
						node = node->parent;
						this->right_rotate(node);
					}
					node->parent->color = BLACK;
					this->grandparent(node)->color = RED;
					this->left_rotate(this->grandparent(node));
				}
			}
		}
		this->Top->color = BLACK;
	}

	//Rotates
    template<typename T, typename T1> void Map<T, T1>::left_rotate(Node* node)
	{
		Node* right = node->right;
		/* Create node->right link */
		node->right = right->left;
		if (right->left != TNULL)
			right->left->parent = node;
		/* Create right->parent link */
		if (right != TNULL)
			right->parent = node->parent;
		if (node->parent != TNULL) {
			if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;
		}
		else {
			this->Top = right;
		}
		right->left = node;
		if (node != TNULL)
			node->parent = right;
	}

    template<typename T, typename T1> void Map<T, T1>::right_rotate(Node* node)
	{
		Node* left = node->left;
		/* Create node->left link */
		node->left = left->right;
		if (left->right != TNULL)
			left->right->parent = node;
		/* Create left->parent link */
		if (left != TNULL)
			left->parent = node->parent;
		if (node->parent != TNULL) {
			if (node == node->parent->right)
				node->parent->right = left;
			else
				node->parent->left = left;
		}
		else {
			this->Top = left;
		}
		left->right = node;
		if (node != TNULL)
			node->parent = left;
	}