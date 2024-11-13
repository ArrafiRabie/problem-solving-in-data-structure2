#include<iostream>
#include"DS.h"
#include"doubly_Linked.h"
#include<string>

using namespace std;

int main() {

	doubly_Linked<short>LK;
	
	LK.First = LK.InsertEnd(10);
	LK.First = LK.InsertEnd(20);
	LK.First = LK.InsertEnd(30);
	LK.First = LK.InsertEnd(40);
	LK.First = LK.InsertEnd(50);
	LK.First = LK.DeleteAtPosition(3);
	LK.Print_Linked(LK.First, 'N');

	return 0;
}