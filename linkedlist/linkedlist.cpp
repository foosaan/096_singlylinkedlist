#include <iostream>
#include <string.h>
using namespace std;

class node
{
public:
	int noMhs;
	char nama[20];
	node* next;
};

class list {
	node* START;
public:
	list();
	void addnode();
	bool search(int nim, node** current, node** previous);
	bool listEmpety();
	bool delnode(int element);
	void traverse();
};

list::list() {
	START = NULL;
}
void list::addnode()/*menambahkan sebuah node kedalam list*/
{
	