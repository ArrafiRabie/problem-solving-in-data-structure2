#pragma once
#include<iostream>
#include<string>

using namespace std;


template<class T>
class DS
{
public:
	struct Node
	{
		T Data;
		Node* Next;
	};

public:
	Node* _Frist;
	Node* _Last;
	short _SizE;

	Node* Test;
	Node* Test2;

	/*DS() {
		this->_Frist = this->_Last = NULL;
	}*/

	void _Script(string str) {
		cout << str << endl;
	}

	Node* _Return(Node* Head) {
		Node* Return = Head;
		return Return;
	}

	Node* _Insert_Frist(T Data) {

		Node* NewN = new Node();
		NewN->Data = Data;
		if (this->_Frist == NULL)
		{
			NewN->Next = NULL;
			this->_Frist = this->_Last = NewN;
		}
		else
		{
			NewN->Next = this->_Frist;
			this->_Frist = NewN;
		}
		this->_SizE++;
		return _Return(this->_Frist); //this->_Frist
	}

	Node* _Isert_End(T Data) {

		Node* NewN = new Node();
		NewN->Data = Data;
		if (this->_Last == NULL)
		{
			NewN->Next = NULL;
			this->_Frist = this->_Last = NewN;
		}
		else
		{
			this->_Last->Next = NewN;
			this->_Last = NewN;
		}
		this->_SizE++;
		return _Return(this->_Frist);
	}

	Node* _Inser_At_Position(T Data, short Position) {
		if (Position < 0)
			Position = 0;
		Node* NewN = new Node();
		NewN->Data = Data;

		if (Position == 0 || Position < 0)
		{
			_Insert_Frist(NewN->Data);
			return _Return(this->_Frist);
		}
		else if (Position >= this->_SizE)
		{
			_Isert_End(NewN->Data);
			return _Return(this->_Frist);
		}
		Node* Curr = this->_Frist;
		for (short i = 0; i < Position - 1; i++) {
			Curr = Curr->Next;
		}
		NewN->Next = Curr->Next;
		Curr->Next = NewN;
		this->_SizE++;
		Curr = this->_Frist;
		//this->_Frist = NULL;
		//delete this->_Frist;
		return _Return(Curr);
	}

	Node* _Delete_Frist() {

		Node* Curr = this->_Frist;
		this->_Frist = Curr->Next;
		Curr = NULL;
		delete Curr;
		this->_SizE--;
		return _Return(this->_Frist);
	}

	Node* _Delete_End() {

		Node* Curr = this->_Frist;
		while (Curr->Next->Next != NULL)
		{
			Curr = Curr->Next;
		}
		Curr->Next = NULL;
		this->_Last = Curr;
		this->_SizE--;
		Curr = NULL;
		delete Curr;
		return _Return(this->_Frist);
	}

	Node* _Delete_At_Position(short Position) {

		if (Position <= 0)
			return _Delete_Frist();
		else if (Position >= this->_SizE - 1)
			return _Delete_End();
		Node* Curr = this->_Frist;
		Node* Temp = this->_Frist;
		for (short i = 0; i < Position; i++)
		{
			Temp = Curr;
			Curr = Curr->Next;
		}

		Temp->Next = Curr->Next;
		Temp = NULL;
		delete Temp;
		return _Return(this->_Frist);
	}

	Node* _Delete_At_Item(T Item) {

		if (this->_Frist->Data == Item)
			return _Delete_Frist();
		else if (this->_Last->Data == Item)
			return _Delete_End();
		Node* Curr = this->_Frist;
		Node* Temp = this->_Frist;
		while (Curr->Data != Item)
		{
			Temp = Curr;
			Curr = Curr->Next;
		}
		Temp->Next = Curr->Next;
		Temp = NULL;
		delete Temp;
		Curr = NULL;
		delete Curr;
		return _Return(this->_Frist);
	}

	Node* _Reverse_Normal() {

		Node* Prev = NULL, * Curr = this->_Frist, * Temp = this->_Frist;
		// 2 1 3 7 4 
		while (Curr != NULL)
		{
			Curr = Temp->Next;
			Temp->Next = Prev;
			Prev = Temp;
			Temp = Curr;
		}
		this->_Frist = Prev;
		Curr = Temp = Prev = NULL;
		delete Curr;
		delete Temp;
		delete Prev;
		return this->_Frist;
	}

	//==============================
	Node* _Reverse_Normal(Node* Heade) {

		Node* Prev = NULL, * Curr = Heade, * Temp = Heade;
		// 2 1 3 7 4 
		while (Curr != NULL)
		{
			Curr = Temp->Next;
			Temp->Next = Prev;
			Prev = Temp;
			Temp = Curr;
		}
		Heade = Prev;
		Curr = Temp = Prev = NULL;
		delete Curr;
		delete Temp;
		delete Prev;
		return _Return(Heade);
	}
	//==============================

	//==== make sure =====//
	void _Reverse_Recursion(Node* Head) {
		if (Head == NULL)
			return;
		_Reverse_Recursion(Head->Next);
		cout << Head->Data << " ";
	}

	void _Print_Recursion(Node* Head) {
		if (Head == NULL)
			return;
		cout << Head->Data << " ";
		_Print_Recursion(Head->Next);
	}
	//==================//
	bool _Print() {
		if (this->_Frist == NULL)
		{
			_Script("Linked List Is Empty");
			return false;
		}
		Node* Curr = this->_Frist;
		while (Curr != NULL)
		{
			cout << Curr->Data << " ";
			Curr = Curr->Next;
		}
	}

	// ======= Easy Level Problems on Linked List Data Structure ========//

	T Find_Middle_of_the_Linked_List() {
		Node* Curr = this->_Frist;
		short Counter = 0;
		if (this->_SizE % 2 != 0)
		{
			while (Counter != this->_SizE / 2) {
				Curr = Curr->Next;
				Counter++;
			}
			return Curr->Data;
		}
		else if (this->_SizE % 2 == 0)
		{
			while (Counter != this->_SizE / 2) {
				Curr = Curr->Next;
				Counter++;
			}return Curr->Data;
		}
	}
	// correct
	// Merge_a_linked_list_into_another_linked_list_at_alternate_positions();
	// Delete_a_Node_from_linked_list_without_head_pointer();
	Node* Rotate_A_Linked_List() {
		Node* Curr = this->_Frist;
		Node* Temp = this->_Frist;
		Node* Prev = this->_Last;
		if (this->_SizE % 2 != 0)
		{
			while (Curr->Next != NULL) {
				Temp = Curr;
				Curr = Curr->Next;
			}
			Curr->Next = NULL;
			Temp->Next = Curr->Next;
			Temp = Curr = NULL;
			delete Curr;
			delete Temp;
			Prev->Next = this->_Frist;
			this->_Frist = Prev;
			Prev = NULL;
			delete Prev;
			return _Return(this->_Frist);
		}
		//else if (this->_SizE % 2 == 0)
		//{
		//	// Input 2->1->3->4;  4 3 1 2
		//	// Output 3->4->2->1
		//	short Counter = 0;
		//	Prev = this->_Frist;
		//	Temp = NULL;

		//	Node* AR = NULL;
		//	Node* RA = NULL;

		//	while (Curr != NULL)
		//	{
		//		Node* T = new Node();
		//		T = Curr;
		//		if (Counter < this->_SizE / 2)
		//		{
		//			if (Counter == 0) {
		//				AR = T;
		//				Curr = Curr->Next;
		//				Counter++;
		//				continue;
		//			}
		//			AR->Next = T;
		//			while (AR->Next != NULL) {
		//				Temp = AR;
		//				AR = AR->Next;
		//			}
		//		}
		//		Curr = Curr->Next;
		//		Counter++;
		//	}
		//	AR->Next = NULL;
		//	Temp = AR;
		//	return _Return(AR);
		//}
	}
	//===========
	T _Kth_from_End_of_Linked_List(short N = 0) {
		if (N < this->_SizE || N > this->_SizE)
			return -1;
		this->_Frist = _Reverse_Normal();
		Node* Curr = this->_Frist;
		short Counter = 1;
		while (Counter != N)
		{
			Curr = Curr->Next;
			Counter++;
		}

		return Curr->Data;
	}

	Node* _Delete_middle_of_linked_list() {

		Node* Curr = this->_Frist;
		Node* Temp = NULL;
		short Counter = 0;
		while (Counter != this->_SizE / 2)
		{
			Temp = Curr;
			Curr = Curr->Next;
			Counter++;
		}
		Temp->Next = Curr->Next;
		//this->_Frist = Temp;
		Temp = Curr = NULL;
		delete Temp;
		delete Curr;

		return _Return(this->_Frist);
	}

	Node* _Remove_Duplicates_from_a_Sorted_Linked_List() {
		// 1 1 3 3 9 555
		Node* Curr = this->_Frist->Next;
		Node* T = this->_Frist;
		Node* AR = NULL;
		while (T != NULL)
		{
			if (Curr == NULL)
				break;
			if (T->Data == Curr->Data)
				AR = _Delete_At_Item(T->Data);
			T = T->Next;
			Curr = Curr->Next;
		}
		this->_Frist = AR;
		Curr = T = AR = NULL;
		delete Curr;
		delete T;
		delete AR;
		return _Return(this->_Frist);
	}

	bool _Detect_loop_or_cycle_in_a_linked_list() {

		Node* Curr = this->_Frist;
		short Counter = Curr->Data, Chek = 0, Check = 0;

		while (Curr != NULL)
		{
			/*if (Curr == NULL)
				break;*/
			if (Curr->Data != Counter + Chek && Curr->Data != Counter + Check) {
				Curr = NULL;
				delete Curr;
				return false;
			}

			Curr = Curr->Next;
			Chek++;
			Check += 10;
		}
		Curr = NULL;
		delete Curr;
		return true;
	}

	Node* _Delete_N_nodes_after_M_nodes_of_a_linked_list(short N = 0, short M = 0) {
		Node* Curr = this->_Frist;
		if (this->_Frist->Data == (N + M)) {
			return this->_Frist = Curr->Next;
		}
		else if (this->_Last->Data == (N + M))
			return _Delete_End();
		Node* T = NULL;
		while (Curr != NULL)
		{
			if (Curr->Data == N + M)
				break;
			T = Curr;
			Curr = Curr->Next;
		}
		T->Next = Curr->Next;
		return _Return(this->_Frist);
	}

	void _Traversal_of_Circular_Linked_List() {
		Node* Curr = this->_Frist;
		while (Curr != NULL)
		{
			cout << Curr->Data << " ";
			Curr = Curr->Next;
			if (Curr->Next == NULL)
				Curr->Next = this->_Frist;
		}
	}

	Node* _Deletion_and_Reverse_in_Circular_Linked_List(short Key = NULL) {

		Node* Curr = this->_Frist;
		if (this->_Frist->Data == Key)
		{
			this->_Frist = _Delete_Frist();
			return _Return(_Reverse_Normal());
		}
		else if (this->_Last->Data == Key)
		{
			this->_Frist = _Delete_End();
			return _Return(_Reverse_Normal());
		}
		Node* T = NULL;
		bool Check = false;
		while (Curr->Next != NULL)
		{
			if (Curr->Data == Key) {
				Check = true;
				break;
			}
			T = Curr;
			Curr = Curr->Next;
		}
		if (Check == true)
			T->Next = Curr->Next;
		return _Return(_Reverse_Normal());
	}

	Node* _Remove_every_k_th_node_of_the_linked_list(short Key = 0) {
		if (this->_Frist == NULL)
			return NULL;
		Node* Curr = this->_Frist;
		Node* T = NULL;
		while (Curr != NULL)
		{
			if ((Curr->Data % Key) == 0)
				T->Next = Curr->Next;
			T = Curr;
			Curr = Curr->Next;
		}
		T->Next = Curr;
		return _Return(this->_Frist);
	}

	void _Pairwise_Swap_Nodes_of_a_given_Linked_List(Node* Head) {

		// Input  : 1->2->3->4->5->6->NULL
		// Output : 2->1->4->3->6->5->NULL
		Node* Curr = Head;
		short A, B = 0;

		while (Curr != NULL)
		{
			A = Curr->Data;
			B = Curr->Next->Data;
			Curr->Data = B;
			Curr->Next->Data = A;
			Curr = Curr->Next->Next;
		}

		A = B = NULL;
	}

	short _Count_Occurrences_in_a_Linked_List(Node* Head, short Key = NULL) {
		Node* Curr = Head;
		short Counter = 0;
		while (Curr != NULL)
		{
			if (Key == Curr->Data)
				Counter++;
			Curr = Curr->Next;
		}
		return Counter;
	}

	Node* _Sort_a_linked_list_of_0s_1s_and_2s(Node* Head) {
		// Input  : 5->1->0->2->4->3;
		// Output : 0->1->2->3->4->5;
		Node* Curr = Head;
		Node* Frist = new Node();
		this->_Frist = this->_Last = NULL;
		this->_SizE = 0;
		short Counter = 0;

		Node* Temp = NULL;
		while (Curr != NULL)
		{
			Frist->Data = Curr->Data; // 5
			if (this->_Frist == NULL) {
				this->_Frist = _Inser_At_Position(Frist->Data, 0);
				Curr = Curr->Next;
				continue;
			}
			Temp = this->_Frist;
			Counter = 0;
			while (Temp != NULL)
			{
				if (Frist->Data >= this->_Last->Data)
				{
					this->_Frist = _Isert_End(Frist->Data);
					break;
				}
				else if (Frist->Data <= Temp->Data)
				{
					this->_Frist = _Inser_At_Position(Frist->Data, Counter);
					break;
				}
				Temp = Temp->Next;
				Counter++;
			}
			Curr = Curr->Next;
			Counter++;
		}
		Frist = Curr = Temp = NULL;
		delete Curr;
		delete Temp;
		delete Frist;
		return _Return(this->_Frist);
	}
	// ======= Medium Level Problems on Linked List Data Structure ========//
	Node* _Reverse_a_Linked_List_in_Groups(Node* Head = NULL, short Key = NULL) {
		//Input : 1->2->2->4->5->6->7->8; k = 4
		//Output: 4->2->2->1->8->7->6->5;
		Node* Curr = Head;
		Node* Temp = this->_Frist;
		Node* Prev1 = NULL;
		Node* Prev2 = NULL;
		bool Check = true;
		short Counter = 0;
		while (Curr != NULL)
		{
			if (Check) {
				Curr = Temp->Next;
				Temp->Next = Prev1;
				Prev1 = Temp;
				if (Counter == 0)
					this->_Last = Prev1;
				if (Prev1->Data == Key)
					Check = false;
				Counter++;
			}
			else if (!Check) {
				Curr = Temp->Next;
				Temp->Next = Prev2;
				Prev2 = Temp;
				Temp = Curr;
			}
			Temp = Curr;
		}
		this->_Last->Next = Prev2;
		this->_Frist = Prev1;
		Prev1 = Prev2 = Temp = Curr = NULL;
		delete Prev1;
		delete Prev2;
		delete Temp;
		delete Curr;
		Counter = NULL;
		return _Return(this->_Frist);
	}

	Node* _Merge_two_sorted_linked_lists(Node* Head1, Node* Head2) {

		// Input  : a: 5->10->15, b : 2->3->20
		// Output : 2->3->5->10->15->20
		this->_Last->Next = Head2;
		Node* Curr = this->_Frist;
		this->_Frist = _Sort_a_linked_list_of_0s_1s_and_2s(Curr);
		return _Return(this->_Frist);
	}

	char _Palindrome_Linked_List(Node* Heade) {
		//char Check = 'F';
		if (this->_Frist->Data != this->_Last->Data)
			return 'F';
		this->_Last = _Reverse_Normal();
		while (Heade != NULL)
		{
			if (Heade->Data != this->_Last->Data)
				return 'F';
			if (this->_Frist->Next != NULL)
				_Delete_End();
			Heade = Heade->Next;
			_Delete_Frist();
			Heade = this->_Frist;
		}
		return 'T';
	}

	Node* Delete_all_occurrences_of_a_given_key_in_a_linked_list(Node* Heade, T Key = NULL) {
		while (Heade != NULL)
		{
			if (Heade->Data == Key)
				_Delete_At_Item(Heade->Data);
			Heade = Heade->Next;
		}

		return _Return(this->_Frist);
	}

	Node* Intersection_Point_in_Y_Shaped_Linked_Lists(Node* head1, Node* head2) {

		// Input: Linked list1 : 4->1->8->4->5,
		//        Linked List2 : 5->6->1->8->4->5

		
	}

	Node* _Intersection_Sorted_Linked_Lists(Node* Heade1, Node* Heade2) {
		Node* Curr = NULL;
		while (Heade1 && Heade2) {

			if (Heade1->Data == Heade2->Data)
				Curr = _Isert_End(Heade1->Data);
			Heade1 = Heade1->Next;
			Heade2 = Heade2->Next;
		}

		return _Return(Curr);
	}

	pair<Node*, Node*> _Split_a_Circular_Linked_List_into_two_halves(Node* Heade) {

		Node* Curr1 = NULL;
		//Node* Curr2 = NULL;
		short Counter = 0;
		short size = this->_SizE;
		this->_SizE = 0;
		Heade = this->_Frist;
		this, _Frist = this->_Last = NULL;
		if (size % 2 == 0)
		{
			while (Counter != size / 2) {
				Node* Prev = Heade;
				Curr1 = _Isert_End(Prev->Data);
				Heade = Heade->Next;
				Counter++;
				Prev = NULL;
				delete Prev; 
			}
			Counter = size = NULL;
			return { Curr1,Heade };
		}
		else
		{
			while (Counter != size - 1) {
				Node* Prev = Heade;
				Curr1 = _Isert_End(Prev->Data);
				Heade = Heade->Next;
				Counter++;
				Prev = NULL;
				delete Prev;
			}
			Counter = size = NULL;
			return { Curr1,Heade };
		}
	}

	void _Find_pairs_with_given_sum_in_doubly_linked_list(Node* Heade, short Target = 0) {
		bool Check = false;
		while (Heade != NULL) {
			Node* Temp = Heade;
			if (Temp->Next == NULL)
				break;
			Temp = Temp->Next;
			while (Temp != NULL) {
				if (Heade->Data + Temp->Data == Target) {
					cout << Heade->Data << " + " << Temp->Data << " = " << Target << endl;
					Check = true;
				}
				Temp = Temp->Next;
			}
			Heade = Heade->Next;
		}

		if (Check == false)
			cout << "False" << endl;

	}

	Node* _Remove_duplicates_from_an_unsorted_doubly_linked_list(Node* Heade) {
		this->_Frist = this->_Last = NULL;
		Node* Curr = _Isert_End(Heade->Data);
		while (Heade != NULL) {
			Node* Temp = Heade;
			while (Temp != NULL) {
				Temp = Temp->Next;
				if(Temp == NULL)
					return this->_Frist = Curr;
				if (Temp->Data == Heade->Data)
					break;
				Curr = _Isert_End(Temp->Data); break;
			}
			Heade = Heade->Next;
		}
		this->_Frist = Curr;
		return _Return(this->_Frist);
	}

	Node* _Add_Number_Linked_Lists(Node* Heade1, Node* Heade2) {
		string Totale1 = "";
		string Totale2 = "";
		while (Heade1 != NULL || Heade2 != NULL) {
			if (Heade1 != NULL)
				Totale1 += to_string(Heade1->Data);
			if (Heade2 != NULL)
				Totale2 += to_string(Heade2->Data);
			if (Heade1 != NULL)
				Heade1 = Heade1->Next;
			if (Heade2 != NULL)
				Heade2 = Heade2->Next;
			/*if (Heade1 != NULL || Heade2 != NULL)
				continue;*/
		}

		int ChengeToint = stoi(Totale1);
		ChengeToint += stoi(Totale2);
		Totale2 = to_string(ChengeToint);
		Node* Curr = NULL;
		this->_Frist = this->_Last = NULL;
		short Num = 0;
		for (short i = 0; i < Totale2.length(); i++)
		{
			Num = Totale2[i] - '0';
			Curr = _Isert_End(Num);
		}
		this->_Frist = Curr;
		Totale1 = Totale2 = "";
		ChengeToint = NULL;
		Curr = NULL;
		delete Curr;
		return _Return(this->_Frist);
	}

	Node* Multiply_two_numbers_represented_by_Linked_Lists(Node* Heade1, Node* Heade2) {
		string Totale1 = "";
		string Totale2 = "";
		while (Heade1 != NULL || Heade2 != NULL) {
			if (Heade1 != NULL)
				Totale1 += to_string(Heade1->Data);
			if (Heade2 != NULL)
				Totale2 += to_string(Heade2->Data);
			if (Heade1 != NULL)
				Heade1 = Heade1->Next;
			if (Heade2 != NULL)
				Heade2 = Heade2->Next;
			/*if (Heade1 != NULL || Heade2 != NULL)
				continue;*/
		}

		int ChengeToint = stoi(Totale1);
		ChengeToint *= stoi(Totale2);
		Totale2 = to_string(ChengeToint);
		Node* Curr = NULL;
		this->_Frist = this->_Last = NULL;
		short Num = 0;
		for (short i = 0; i < Totale2.length(); i++)
		{
			Num = Totale2[i] - '0';
			Curr = _Isert_End(Num);
		}
		this->_Frist = Curr;
		Totale1 = Totale2 = "";
		ChengeToint = NULL;
		Curr = NULL;
		delete Curr;
		return _Return(this->_Frist);
	}

	Node* Swap_Kth_nodes_from_ends(Node* Heade,short Key = NULL) {
	
		T Chenge;
		short Check = this->_SizE / 2;
		if (this->_SizE % 2 != 0)
			Check += 1;

		if (Key <= 0 || Check == this->_SizE / 2) {
			return this->_Frist = Heade;
		}
		else if (Key == this->_SizE || Key == 1)
		{
			Chenge = this->_Frist->Data;
			this->_Frist->Data = this->_Last->Data;
			this->_Last->Data = Chenge;
			return this->_Frist;
		} 

		short Counter1 = 1;
		short Counter2 = 1;
		bool Check1, Check2;
		Check1 = Check2 = false;
		Node* Curr = this->_Frist;

		while (Heade != NULL && Curr != NULL) {
			if (Counter1 != Key) {
				Heade = Heade->Next;
				Counter1++;
			}
			if (Counter2 != this->_SizE - (Key - 1)) {
				Curr = Curr->Next;
				Counter2++;
			}
			if (Counter1 == Key && Counter2 == this->_SizE - (Key - 1))
			{
				T Chng = Heade->Data;
				Heade->Data = Curr->Data;
				Curr->Data = Chng;
				break;
			}
		}
		Curr = NULL;
		delete Curr;
		return _Return(this->_Frist);
	}

	Node* _Reverse_a_sublist_of_linked_list(Node* Heade,  short Start, short End){
		this->_Frist = this->_Last = NULL;
		Node* Curr = NULL;
		Node* Temp = NULL;
		Node* Prev = Heade;
		short Counter = 1;
		while (Heade != NULL) {
			if (Counter >= Start && Counter <= End) {
				if (Counter == Start)
					this->_Frist = this->_Last = NULL;
				Temp = _Isert_End(Prev->Data);
				Prev = Prev->Next;
				if (Counter == End) {
					Temp = _Reverse_Normal(Temp);
					this->_Frist->Next = Prev;
					Heade = Prev;
					//==============
					if (Start == 1)
						return(Temp);
					//==============
					this->_Frist = this->_Last = NULL;
					while (Curr != NULL) {
						this->_Frist = _Isert_End(Curr->Data);
						Curr = Curr->Next;
					}
					if (this->_Last != NULL)
						this->_Last->Next = Temp;
					break;
				}
				Counter++;
				continue;
			}
			Curr = _Isert_End(Heade->Data);
			Heade = Heade->Next;
			Prev = Prev->Next;
			Counter++;
		}

		return _Return(this->_Frist);
	}

	Node* _Reverse_alternate_K_nodes_in_a_Singly_Linked_List(Node* Heade, short Key) {
		return(_Reverse_a_sublist_of_linked_list(Heade,1,Key));
	}

	Node* Reverse_a_Linked_List_in_groups_of_given_size(Node* Heade, short N_G) {
		this->_Frist = this->_Last = NULL;
		this->_SizE = 0;
		Node* Curr = NULL;
		short Counter = 1;
		short CK = 0;
		while (Heade != NULL) {
			Curr = _Inser_At_Position(Heade->Data,CK);
			if (Counter == N_G) {
				CK += this->_SizE;
				Counter = 0;
			}
			Heade = Heade->Next;
			Counter++;
		}
		return Curr;
	}

	Node* _Merge_K_sorted_linked_lists(Node* ND1 = NULL, Node* ND2 = NULL, Node* ND3 = NULL) {

	}

	Node* _Partitoin_Insert_Funtion(T Data) {
		Node* NewN = new Node();
		NewN->Data = Data;
		if (this->Test == NULL)
		{
			NewN->Next = NULL;
			this->Test  = NewN;
		}
		else
		{
			NewN->Next = this->Test;
			this->Test = NewN;
		}
		this->_SizE++;
		return this->Test;
	}

	Node* _Partitoin_Insert_Funtion_2(T Data) {
		Node* NewN = new Node();
		NewN->Data = Data;
		if (this->Test2 == NULL)
		{
			NewN->Next = NULL;
			this->Test2 = NewN;
		}
		else
		{
			NewN->Next = this->Test2;
			this->Test2 = NewN;
		}
		this->_SizE++;
		return this->Test2;
	}

	Node* _Partition_a_Linked_List_around_a_given_value(Node* Heade, short Key = NULL) {
		this->_Frist = this->_Last = NULL;
		this->_SizE = 0;
		Node* Curr = NULL;
		Node* Temp = NULL;
		Node* Prev = NULL;
		short Counter1 = 0, Counter2 = 0, Counter3 = 0;
		while (Heade != NULL) {
			if (Heade->Data < Key)
				Curr = _Partitoin_Insert_Funtion(Heade->Data);
			if(Heade->Data == Key)
				Temp = _Partitoin_Insert_Funtion_2(Heade->Data);
			if(Heade->Data > Key)
				Prev = _Inser_At_Position(Heade->Data,0);
			Heade = Heade->Next;
			if (Heade == NULL) {
				this->_Frist = this->_Last = NULL;
				Node* AR = Curr;
				while (AR != NULL) {
					this->_Frist = _Isert_End(AR->Data);
					AR = AR->Next;
					if (AR == NULL) {
						if (Temp != NULL) {
							AR = Temp;
							Temp = NULL;
							continue;
						}
						if (Prev != NULL) {
							AR = Prev;
							Prev = NULL;
						}
					}
				}
			}
		}
		this->_Frist = _Sort_a_linked_list_of_0s_1s_and_2s(this->_Frist);
		Curr = Temp = Prev = NULL;
		delete Curr;
		delete Temp;
		delete Prev;
		return this->_Frist;
	}



	//protected:
	//public:

	~DS() {
		this->_Frist = this->_Last = NULL;
		this->_SizE = 0;
		this->Test = NULL;
		this->Test2 = NULL;
	}
};


//Node* Curr = NULL;
//Node* Temp = Heade;
//short Counter = 1;
//this->_Frist = this->_Last = NULL;
//while (Heade != NULL) {
//	if (Counter == 1) {
//		Temp = Temp->Next;
//		Counter++;
//		continue;
//	}
//	if (Counter >= Start && Counter <= End) {
//		Curr = _Isert_End(Temp->Data);
//		Temp = Temp->Next;
//		Counter++;
//		continue;
//	}
//	if (Counter == End + 1) {
//		Curr = _Reverse_Normal(Curr);
//		Heade->Next = Curr;
//		this->_Frist->Next = Temp;
//	}
//	Temp = Temp->Next;
//	Heade = Heade->Next;
//	Counter++;
//}
//return _Return(Curr);
