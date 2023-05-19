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
{
	if (listEmpety())
		cout << "\nlist kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah :" << endl;
		node* currrentnode;
		for (currrentnode = START; currrentnode != NULL; currrentnode = currrentnode->next);
		{
			cout << currrentnode->noMhs << " " << currrentnode->nama << "\n";
		}
		cout << endl;
	}
}

int main()

{
	list mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. menambah data kedalam list" << endl;
		cout << "2. menghapus data dari dalam list" << endl;
		cout << "3. menampilkan semua data di dalam list" << endl;
		cout << "4. mencari data didalam list" << endl;
		cout << endl << "masukkan pilihan (1-5) : ";
		cin >> (ch);
		switch (ch)
		{
		case '1':
		{
			mhs.addnode();
		}
		break;

		case '2':
		{
			if (mhs.listEmpety())
			{
				cout << endl << "list kosong" << endl;
				break;
			}
			cout << endl << "\nmasukkan no mahasiswa yang akan dihapus :";
			cin >> nim;
			if (mhs.delnode(nim) == false)
				cout << endl << "data tidak ditemukan" << endl;
			else
				cout << endl << "data dengan nomor mahasiswa" << nim << "berhasil";
		}
		break;
		case '3':
		{
			mhs.traverse();
		}
		break;

		case '4':
		{
			if (mhs.listEmpety() == true)
			{
				cout << "\nlist kosong\n";
				break;
			}
			node* previous, * current;
			cout << endl << "Masukkan no mahasiswa yang dicari :";
			cin >> nim;
			if (mhs.search(nim, &previous, &current) == false)
				cout << endl << "data tidak ditemukan" << endl;
			else
			{
				cout << endl << "data ditemukan" << endl;
				cout << "\nNo mahasiswa: " << current->noMhs;
				cout << "\nNama :" << current->nama;
				cout << "\n";
			}
		}
		break;
		case '5':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "pilihan salah !." << endl;
		}
		break;
		}
	}
}