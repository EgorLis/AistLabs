#define RED 1
#define BLACK 0

#include"List.cpp"

using namespace std;

template<typename T, typename T1>
class Map {
public:
	class Node
	{
	public:
		Node(bool color = RED, T key = T(), Node* parent = NULL, Node* left = NULL, Node* right = NULL, T1 value = T1()) :color(color), key(key), parent(parent), left(left), right(right), value(value) {}
		T key;
		T1 value;
		bool color;
		Node* parent;
		Node* left;
		Node* right;
	};

	~Map() {
		if (this->Top != NULL)
			this->clear();
		Top = NULL;
		delete TNULL;
		TNULL = NULL;
	}

	Map(Node* Top = NULL, Node* TNULL = new Node(0)) :Top(Top), TNULL(TNULL) {}

	void printTree();

	void  insert(T key, T1 value);

	List<T>* get_keys();
	List<T1>* get_values();
	T1 find(T key);
	void clear();
	
	void Delete(T key);
	
private:
	Node* Top;
	Node* TNULL;

	void deleteNode(Node* z);
	void deleteFixup(Node* x); 

	//swap links(parent and other) for rotate



	void clear_tree(Node* tree);

	Node* minimum(Node* node);

	Node* maximum(Node* node);

	Node* grandparent(Node* cur);

	Node* uncle(Node* cur);

	Node* sibling(Node* n);

	Node* find_key(T key);
	//all print function
	void print_Helper(Node* Top, string indent, bool last);
	void ListKeyOrValue(int mode, List<T>* list);
	void KeyOrValue(Node* tree, List<T>* list, int mode);

	//fix before add
	void rbtree_fixup_add(Node* node);
	

	//Rotates
	void left_rotate(Node* node);
	void right_rotate(Node* node);
};