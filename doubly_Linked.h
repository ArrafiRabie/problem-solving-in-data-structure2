#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class doubly_Linked
{
private:
	struct Node
	{
		T Data;
		Node* Next;
		Node* Prev;
	};
	//Node* First, * Last;
	//short Size;
	void _Script(string Str) {
		cout << Str << this->Size + 1 << endl;
	}

	bool _Check_Node(Node* node) {
		/*if (node != NULL)
			return true;
		else
			return false;*/
		return (node != NULL) ? true : false;
	}

	Node* _Insert_First(T Item = NULL) {
		if (Item == NULL) {
			_Script(" Please give me a value in Function Number ");
			return this->First;
		}
		Node* NewNode = new Node();
		NewNode->Data = Item;
		if (_Check_Node(this->First) == false) {
			this->First = this->Last = NewNode;
			NewNode->Prev = NewNode->Next = NULL;
		}
		else {
			NewNode->Next = this->First;
			NewNode->Prev = NULL;
			this->First->Prev = NewNode;
			this->First = NewNode;
		}
		this->Size++;
		return this->First;
	}

	Node* _InsertEnd(T Item) {
		Node* NewNode = new Node();
		NewNode->Data = Item;
		if (this->First == NULL) {
			this->First = this->Last = NewNode;
			NewNode->Prev = NewNode->Next = NULL;
		}
		else {
			NewNode->Next = NULL;
			NewNode->Prev = this->Last;
			this->Last->Next = NewNode;
			this->Last = NewNode;
		}
		this->Size++;
		return this->First;
	}

	Node* _InsertAtPosition(T Item, short Position) {
		if (Position <= 0)
			return _Insert_First(Item);
		else if (Position > this->Size)
			return _InsertEnd(Item);
		else { Node* Temp = this->First;
		Node* NewNode = new Node();
		NewNode->Data = Item;
			for (short i = 0; i < Position-1; i++) 
				Temp = Temp->Next;

			NewNode->Prev = Temp;
			NewNode->Next = Temp->Next;
			Temp->Next = NewNode;
			Temp->Next->Prev = NewNode;
			this->Size++;
		}
		return this->First;
	}

	Node* _DeleteFirst() {
		if (this->First == NULL) {
			_Script(" Linked List Is Empty ");
			return NULL;
		}
		else if (this->First->Next == NULL) {
			delete this->First;
			this->First = this->Last;
			return this->First;
		}
		else {
			Node* Curr = this->First;
			this->First = this->First->Next;
			this->First->Prev = NULL;
			delete Curr;
			this->Size--;
		}
		return this->First;
	}

	Node* _DeleteEnde() {
		if (this->Last == NULL) {
			_Script(" Linked List Is Empty ");
			return NULL;
		}
		else if (this->First->Next == NULL) {
			delete this->Last;
			this->First = this->Last;
			return this->First;
		}
		Node* Curr = this->Last;
		this->Last = this->Last->Prev;
		this->Last->Next = NULL;
		delete Curr;
		this->Size--;
		return this->First;
	}

	Node* _DeleteAtPosition(short Position = 0) {
		if (Position < 0 || Position > this->Size) {
			_Script(" this Number Is Out Of Range. ");
			return NULL;
		}
		else if (Position == 0)
			return _DeleteFirst();
		else if (Position == this->Size)
			return _DeleteEnde();
		else {
			Node* Curr = this->First->Next;
			for (short i = 1; i < Position - 1; i++)
				Curr = Curr->Next; // 30
			Curr->Next = Curr->Next->Prev;
			delete Curr;
			this->Size--;
			return this->First;
		}
	}

	void _Print_Linked(Node* node = NULL, char Check = NULL) {
		if (_Check_Node(this->First) == false) {
			cout << " Linked Is Empty " << endl;
			return;
		}

		if (Check == 'N') {
			while (node != NULL) {
				cout << node->Data << " ";
				node = node->Next;
			}
		}
		else if (Check == 'P') {
			node = this->Last;
			while (node != NULL) {
				cout << node->Data << " ";
				node = node->Prev;
			}
		}
		else {
			cout << " Please specify the header of the list " << endl;
		}
	}

protected:
public:
	doubly_Linked() {
		this->First = this->Last = NULL;
		this->Size = NULL;
	}
	Node* First, * Last;
	short Size;

	Node* Insert_First(T Item = NULL) {
		return _Insert_First(Item);
	}

	Node* InsertEnd(T Item) {
		return _InsertEnd(Item);
	}

	Node* InsertAtPosition(T Item, short Position) {
		return _InsertAtPosition(Item, Position);
	}

	Node* DeleteFirst() {
		return _DeleteFirst();
	}

	Node* DeleteEnde() {
		return _DeleteEnde();
	}

	Node* DeleteAtPosition(short Position = 0) {
		return _DeleteAtPosition(Position);
	}

	void Print_Linked(Node* node = NULL, char Check = NULL) {
		_Print_Linked(node, Check);
	}
};

