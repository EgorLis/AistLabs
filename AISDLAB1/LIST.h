#include<iostream>
using namespace std;
template<typename T>
class List
{
private:
	class Node {
	public:
		Node(T data = T(), Node* Next = NULL) {
			this->data = data;
			this->Next = Next;
		}
		Node* Next;
		T data;
	};

	Node* head;
	Node* tail;
	int Size;
public:
	void push_back(T obj); // ���������� � ����� ������ bc
	void push_front(T obj); // ���������� � ������ ������ bc
	void pop_back(); // �������� ���������� �������� bc
	void pop_front(); // �������� ������� �������� bc-+
	void insert(T obj, size_t k); // ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������) bc
	T at(size_t k); // ��������� �������� �� ������� bc
	void remove(int k); // �������� �������� �� ������� bc
	size_t get_size(); // ��������� ������� ������ bc
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������, �� ������������ at bc
	void clear();  // �������� ���� ��������� ������
	void set(size_t k, T obj);  // ������ �������� �� ������� �� ������������ ������� 
	bool isEmpty(); // �������� �� ������� ������ bc
	void reverse();  // ������ ������� ��������� � ������
	List(Node* head = NULL, Node* tail = NULL, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != NULL) {
			this->clear();
		}
	};
};