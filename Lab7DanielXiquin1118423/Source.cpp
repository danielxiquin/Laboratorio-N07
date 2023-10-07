#include <iostream>

using namespace std;


class List {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev; //es el nodo anterior al nodo actual al que se apuntra

		Node(int val) : data(val), next(nullptr), prev(nullptr){}

	};

	Node* header = nullptr;
	Node* tail = nullptr; // este es l ultimo nodo


public:
	void Add(int item) {
		if (!header) {
			header = new Node(item);
			tail = header; // Si es el primer elemento, tanto header como tail apuntan al mismo nodo
		}
		else {
			Node* new_node = new Node(item);
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node; //actualiza tail al nuevo nodo

		}
	}

	void clear() {
		while (header) {
			Node* temp = header;
			header = header->next;
			delete temp;
		}
		tail = nullptr; //Tambien debemos resetear el puntero tail
	}


	//Metodo para eliminar un elemento por valor
	
	void Remove(int value) {
		if (!header) {
			return;
		}

		if (header->data == value) {
			Node* temp = header;
			header = header->next;
			if (header) header->prev = nullptr; // actualiza el prev del nuevo header si existe 
			delete temp;
			return;
		}

		Node* current = header;
		while (current->next) {
			if (current->next->data == value) {
				Node* temp = current->next;
				current->next = current->next->next;
				//actualizamos el prev al sigyiente nodo si existe;
				if (current->next) current->next->prev = current;
				delete temp;
				return;
			}
			current = current->next;
		}

	}

	void removeposition(int position) {


		if (!header) {
			cout << "No hay elemento a eliminar";
			return;
		}
		if (position < 0) {
			cout << "la posicion es invalida";
			return;
		}

		if (position == 0) {
			Node* temp = header;
			header = header->next;

			if (header) header->prev = nullptr;
			delete temp;
			return;

		}

		
		if (header->next == tail) {
			Node* temp = tail;
			tail = tail->prev;

			if (tail) tail->next = nullptr;
			delete temp;
			return;

		}


		Node* current = header;
		int index = 0;

		while (current->next && index < position - 1) {
			current = current->next;
			index++;

		}
		Node* temp = current->next;
		current->next = current->next->next;
		
		if (current->next) {
			current->next->prev = current;
		}
		delete temp;
		

	}

	void insert(int item, int position) {
		if (position < 0) {
			cout << "posicion invalida " << endl;
			return;

		}

		if (position == 0 || !header) {
			Node* new_node = new Node(item);
			new_node->next = header;
			//actualizamos el prev del anterior nodo si existe
			if (header) header->prev = new_node;
			header = new_node;
			//si la lista estaba vacia, tail tambien apunta al nuevo nodo
			if (tail) tail = header;
			return;

		}

		Node* current = header;
		int index = 0;

		while (current->next && index < position - 1) {
			current = current->next;
			index++;
		}

		Node* new_node = new Node(item);

		new_node->next = current->next;
		//actualizamos el prev deñ siguientre nodo si existe
		if (current->next) current->next->prev = new_node;
		current->next = new_node;
		new_node->prev = current;
	}

	void print() {
		Node* current = header;
		while (current) {
			cout << current->data << "";
			current = current->next;

		}
		cout << endl;
	}


	void printexe() {
		Node* current = tail;
		while (current) {
			cout << current->data << "";
			current = current->prev;
		}

	}
};

int main() {

	List mylist;

	mylist.Add(1);
	mylist.Add(2);
	mylist.Add(3);

	cout << "lista original:";
	mylist.print();

	mylist.Remove(2);
	cout << "se elimino el dato con el valor 2" << endl;
	mylist.print();

	mylist.insert(4, 1);
	cout << "Despues de insertar eñ elemento 4 en la pocision 1: " << endl;
	mylist.print();

	cout << endl;
	cout << "Representacion de lista impresa alreves" << endl; 
	mylist.printexe();


	mylist.insert(6, 2);
	cout << "Insertamos un dato como prueba" << endl;
	mylist.printexe();
	cout << endl;
	mylist.print();

	cout << endl;

	mylist.removeposition(3);
	cout << "Despues de eliminar por posicion" << endl;
	mylist.print();

	mylist.removeposition(2);
	cout << "Despues de eliminar por posicion" << endl;
	mylist.print();



	mylist.clear();
	cout << "Despues de borrar la lista: " << endl;
	mylist.print();


	


	






};