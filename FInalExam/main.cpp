#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"

using namespace std;

int main()
{
	int numWrite[] = { 5, 8, 9, 2, 22, 16, 18, 1, 4, 21 };
	int numRead[10];
	ofstream file("numbers.dat", ios::out || ios::binary);
	ifstream input("numbers.dat", ios::in || ios::binary);
	fstream output;
	fstream *out = &output;
	output.open("numbers.txt");
	file.write(reinterpret_cast<char *>(numWrite), sizeof(numWrite));
	input.read(reinterpret_cast<char *>(numRead), sizeof(numRead));
	
	/*for (int i = 0; i < 10; i++)
	{
		cout << numRead[i] << " ";
	}*/

	IntBinaryTree tree;
	for (int i = 0; i < 10; i++)
	{
		tree.insert(numRead[i]);
	}
	tree.showInOrder();
	cout << endl;
	tree.showPostOrder();
	cout << endl;
	tree.showPreOrder();
	cout << endl;
	file.open("numbers.txt");
	tree.write(out);

	file.close();
	input.close();
	return 0;
}