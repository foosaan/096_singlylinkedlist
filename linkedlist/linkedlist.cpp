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
void list::addnode() /*menambahkan sebuah node kedalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukkan nomor mahasiswa : ";
	cin >> nim;
	cout << "\nMasukkan nama : ";
	cin >> nm;

	node* nodeBaru = new node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs) {
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current->next;
	}
	/*jika lood di atas dieksekusi, previous dan current akan menempati posisi dimana*/
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool list::delnode(int nim) /*menghapus node dari dalam list*/
{
	node* current, * previous;
	if (search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

/*Check apakah node yang dimaksud ada didalam list atau tidak*/
bool list::search(int nim, node** previous, node** current) {
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void list::traverse() /*mengunjungi dan membaca data dalam list*/
