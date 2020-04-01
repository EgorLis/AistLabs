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
	void push_back(T obj); // добавление в конец списка bc
	void push_front(T obj); // добавление в начало списка bc
	void pop_back(); // удаление последнего элемента bc
	void pop_front(); // удаление первого элемента bc-+
	void insert(T obj, size_t k); // добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу) bc
	T at(size_t k); // получение элемента по индексу bc
	void remove(int k); // удаление элемента по индексу bc
	size_t get_size(); // получение размера списка bc
	void print_to_console(); // вывод элементов списка в консоль через разделитель, не использовать at bc
	void clear();  // удаление всех элементов списка
	void set(size_t k, T obj);  // замена элемента по индексу на передаваемый элемент 
	bool isEmpty(); // проверка на пустоту списка bc
	void reverse();  // меняет порядок элементов в списке
	List(Node* head = NULL, Node* tail = NULL, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != NULL) {
			this->clear();
		}
	};
};