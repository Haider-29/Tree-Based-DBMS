#include <iostream>
#include "PinkPurpleIndex.h"
#include "AVLindex.h"
#include "BTreeIndex.h"
#include <iomanip>

using namespace std;

//int main() {
//
//    //BTree<int>* bb = btintIndex(0, 3);
//
//    //btintDelete(bb, 1, 0, 3);
//
//    //btintSearch(bb, 100);
//
//    //btintRangeSearch(bb, 100, 200);
//
//    //BTree<double>* bb = btdoubleIndex(6, 3);
//
//    //btdoubleSearch(bb, 55.5);
//
//    //btdoubleRangeSearch(bb, 55.5, 60.0);
//
//    //BTree<string>* bb = btstringIndex(4, 3);
//
//    //btstringSearch(bb, "Michigan");
//
//    //btstringRangeSearch(bb, "A", "D");
//
//    //BTree<int> t(3); // A B-Tree with minimum degree 3
//
//    //t.insert(1);
//    //t.insert(3);
//    //t.insert(7);
//    //t.insert(10);
//    //t.insert(11);
//    //t.insert(13);
//    //t.insert(14);
//    //t.insert(15);
//    //t.insert(18);
//    //t.insert(16);
//    //t.insert(19);
//    //t.insert(24);
//    //t.insert(25);
//    //t.insert(26);
//    //t.insert(21);
//    //t.insert(4);
//    //t.insert(5);
//    //t.insert(20);
//    //t.insert(22);
//    //t.insert(2);
//    //t.insert(17);
//    //t.insert(12);
//    //t.insert(6);
//
//    //cout << "Traversal of tree constructed is\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(6);
//    //cout << "Traversal of tree after removing 6\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(13);
//    //cout << "Traversal of tree after removing 13\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(7);
//    //cout << "Traversal of tree after removing 7\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(4);
//    //cout << "Traversal of tree after removing 4\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(2);
//    //cout << "Traversal of tree after removing 2\n";
//    //t.traverse();
//    //cout << endl;
//
//    //t.remove(16);
//    //cout << "Traversal of tree after removing 16\n";
//    //t.traverse();
//    //cout << endl;
//    
//    //PinkPurpleTree<string> rbt;
//
//    //rbt.insert("Haider1");
//    //rbt.insert("Haider2");
//    //rbt.insert("Haider3");
//    //rbt.inorder();
//
//    //cout << endl;
//    //
//    //PinkPurpleTree<int> bt;
//
//    //bt.insert(1);
//    //bt.insert(2);
//    //bt.insert(3);
//    //bt.inorder();
//
//    //PinkPurpleTree<int>* poopoo = ppintIndex(0);
//
//    //intRangeSearch(poopoo, 100, 200);
//
//    //PinkPurpleTree<int>* poopoo = ppintIndex(1);
//
//    //intRangeSearch(poopoo, 2016, 2020);
//
//    //PinkPurpleTree<string>* poopoo = ppstringIndex(4);
//
//    //stringRangeSearch(poopoo, "A", "D");
//
//    //PinkPurpleTree<double>* poopoo = ppdoubleIndex(6);
//
//    //doubleRangeSearch(poopoo, 55.5, 60.0);
//
//    //PinkPurpleTree<string>* poopoo = ppstringIndex(4);
//
//    //stringSearch(poopoo, "Minnesota");
//
//    //PinkPurpleTree<double>* poopoo = ppdoubleIndex(6);
//
//    //doubleSearch(poopoo, 55.5);
//
//    //BST<int>* poopoo = avlintIndex(0);
//
//    //avlintUpdate(poopoo, 1, 1, "1999", "2018");
//
//    //PinkPurpleTree<double>* poopoo = ppdoubleIndex(6);
//
//    //doubleUpdate(poopoo, 55.5, 1, "2016", "1999");
//
//    //PinkPurpleTree<string>* poopoo = ppstringIndex(4);
//
//    //stringUpdate(poopoo, "Michigan", 1, "1999", "2000");
//
//    //PinkPurpleTree<int>* poopoo = ppintIndex(1);
//
//    //intDelete(poopoo, 2016, 1);
//
//    //PinkPurpleTree<string>* poopoo = ppstringIndex(4);
//
//    //stringDelete(poopoo, "Michigan", 4);
//
//    //BST<int> a;
//
//    //a.insert(1);
//    //a.insert(2);
//    //a.insert(3);
//    //a.insert(4);
//    //a.insert(5);
//    //a.insert(6);
//    //a.insert(7);
//
//    //a.displayPreOrder();
//
//    //cout << endl;
//
//    //a.deleteN(4);
//    //a.deleteN(5);
//    //a.deleteN(7);
//    //a.deleteN(6);
//
//    //a.displayPreOrder();
//
//    //cout << endl;
//
//    //cout << a.search(2)->getData();
//
//    //BST<int>* bb = avlintIndex(5);    
//    //BST<double>* bb = avldoubleIndex(6);  
//    //BST<string>* bb = avlstringIndex(4);
//
//    //BST<int>* bb = avlintIndex(1); 
//
//    //avlintSearch(bb, 2016);
//
//    //BST<string>* bb = avlstringIndex(4);
//
//    //avlstringSearch(bb, "Michigan");
//
//    //BST<double>* bb = avldoubleIndex(6);  
//
//    //avldoubleSearch(bb, 55.5);
//
//    //BST<int>* bb = avlintIndex(1); 
//
//    //avlintRangeSearch(bb, 2016, 2020);
//
//    //BST<string>* bb = avlstringIndex(4);
//
//    //avlstringRangeSearch(bb, "A", "D");
//
//    //BST<double>* bb = avldoubleIndex(6);  
//
//    //avldoubleRangeSearch(bb, 55.5, 60.0);
//
//    //BST<int>* bb = avlintIndex(0);
//
//    //avlintDelete(bb, 1, 0);
//
//    //PinkPurpleTree<int>* pp = ppintIndex(0);
//
//}


using namespace std;

void multi_Indexing();
void AVLMenu();
int  getField();
void PinkPurpleMenu();
void BTreeMenu();
int fieldSelectionForUpdate();
void avlcase4();
void avlcase5();
void ppcase4();
void ppcase5();
void btcase5(int ord);
void btcase4(int ord);

int main()
{
	int op1;

	cout << "\n\n";
	cout << setw(25);
	for (int i = 0; i < 73; i++)
		cout << "*";
	cout << endl;

	//cout << setw(35);
	cout << "\t\t\t*\tWelcome to the Database of Leading Causes of Deaths in USA\t*\n";

	cout << setw(25);
	for (int i = 0; i < 73; i++)
		cout << "*";
	cout << endl << endl;

	cout << setw(62);
	cout << "BY\n";

	cout << "\n";
	cout << setw(25);
	for (int i = 0; i < 73; i++)
		cout << "*";
	cout << endl;

	//cout << setw(35);
	cout << "\t\t\t*\t\t\t   THE PINK PURPLE GANG      \t\t\t*\n";
	cout << "\t\t\t*\t\t\t\t\t\t\t\t\t*\n";

	cout << "\t\t\t*\t\t\tSyed Haider Naqvi -- 20I-0816\t\t\t*\n";
	cout << "\t\t\t*\t\t\t\t\t\t\t\t\t*\n";
	cout << "\t\t\t*\t\tMuhammad Raees Shujaan Azhar -- 21I-0406\t\t*\n";
	cout << "\t\t\t*\t\t\t\t\t\t\t\t\t*\n";
	cout << "\t\t\t*\t\t\t Saman Ali Ahmed -- 21I-2499\t\t\t*\n";

	cout << setw(25);
	for (int i = 0; i < 73; i++)
		cout << "*";
	cout << endl << endl;

	//cout << setw(15);
	cout << "\t\t\tPlease enter number of the tree you want to index the DataBase with:\n\n";
	cout << "\t\t\t1.\t AVL TREE\n";
	cout << "\t\t\t2.\t PINK PURPLE TREE\n";
	cout << "\t\t\t3.\t B TREE\n";
	cout << "\t\t\t4.\t MULTI-INDEXING WITH MULTIPLE TREES\n";
	cout << "\n\t\t\tOption Selected: ";
	cin >> op1;

	switch (op1)
	{
	case 1:
		AVLMenu();
		break;
	case 2:

		PinkPurpleMenu();
		break;
	case 3:
		BTreeMenu();
		break;

	case 4:
		multi_Indexing();
		break;

	default:
		cout << "\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!Invalid Input!!!!!!!!!!!!!!!!!!!!!\n\n";
		break;
	}



}


void AVLMenu()
{
	int op2;
	system("CLS");

	cout << "\n\t\t\t\t\tPerform the following actions using AVL tree: \n\n";
	cout << "\n\t\t\tPress the corresponding number: \n\n";
	cout << "\t\t\t1. \t Create Index\n";
	cout << "\t\t\t2. \t Point Search\n";
	cout << "\t\t\t3. \t Range Search\n";
	cout << "\t\t\t4. \t Update Field\n";
	cout << "\t\t\t5. \t Delete Key\n";

	cin >> op2;

	while (op2 < 1 || op2 > 5)
	{
		cout << "\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!Invalid Input!!!!!!!!!!!!!!!!!!!!!\n\n";
		cout << "\t\t\t\tEnter again: ";
		cin >> op2;
	}

	int x;

	switch (op2)
	{

	case 1:
		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			avlintIndex(x)->displayInOrder();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			avlstringIndex(x)->displayInOrder();
		}

		else if (x == 6)
		{
			avldoubleIndex(x)->displayInOrder();
		}

		break;
	case 2:

		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			int t2;
			if (x == 0)
				cout << "Enter ID to search for: ";
			else if (x == 1)
				cout << "Enter Year to search for: ";
			else if (x == 5)
				cout << "Enter Number of deaths to search for: ";
			cin >> t2;

			avlintSearch(avlintIndex(x), t2);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2;
			if (x == 2)
				cout << "Enter 113 Cause Name to search for: ";
			else if (x == 3)
				cout << "Enter Cause Name to search for: ";
			else if (x == 4)
				cout << "Enter State to search for: ";

			cin >> t2;

			avlstringSearch(avlstringIndex(x), t2);
		}

		else if (x == 6)
		{
			double t2;
			cout << "Enter Age-adjusted Death Rate to search for: ";

			cin >> t2;

			avldoubleSearch(avldoubleIndex(x), t2);
		}
		break;
	case 3:

		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			int t2, t3;
			if (x == 0)
			{
				cout << "Enter starting range of ID: ";
				cin >> t2;

				cout << "Enter ending range of ID: ";
				cin >> t3;
			}

			else if (x == 1)
			{
				cout << "Enter Starting range for Year: ";
				cin >> t2;
				cout << "Enter ending range for Year: ";
				cin >> t3;

			}

			else if (x == 5)
			{
				cout << "Enter starting range of deaths: ";
				cin >> t2;
				cout << "Enter ending range of deaths: ";
				cin >> t3;
			}

			avlintRangeSearch(avlintIndex(x), t2, t3);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2, t3;
			if (x == 2)
			{
				cout << "Enter Starting Range of 113 Cause Name: ";
				cin >> t2;

				cout << "Enter ending range of 113 Cause Name: ";
				cin >> t3;
			}

			else if (x == 3)
			{
				cout << "Enter Starting range for  Cause Name: ";
				cin >> t2;
				cout << "Enter ending range for  Cause Name: ";
				cin >> t3;

			}

			else if (x == 4)
			{
				cout << "Enter starting range of State: ";
				cin >> t2;
				cout << "Enter ending range of  State: ";
				cin >> t3;
			}

			avlstringRangeSearch(avlstringIndex(x), t2, t3);

		}

		else if (x == 6)
		{

			double t2, t3;
			cout << "Enter starting range of Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter ending range of Age-adjusted Death Rate: ";
			cin >> t3;

			avldoubleRangeSearch(avldoubleIndex(x), t2, t3);
		}

		break;

	case 4:
		avlcase4();

		break;

	case 5:
		avlcase5();
		break;

	default:

		break;

	}

}

void PinkPurpleMenu()
{
	int op2;
	system("CLS");

	cout << "\n\t\t\t\t\tPerform the following actions using AVL tree: \n\n";
	cout << "\n\t\t\tPress the corresponding number: \n\n";
	cout << "\t\t\t1. \t Create Index\n";
	cout << "\t\t\t2. \t Point Search\n";
	cout << "\t\t\t3. \t Range Search\n";
	cout << "\t\t\t4. \t Update Field\n";
	cout << "\t\t\t5. \t Delete Key\n";

	cin >> op2;

	int x;
	x = getField();
	x--;

	switch (op2)
	{

	case 1:

		if (x == 0 || x == 1 || x == 5)
		{
			ppintIndex(x)->inorder();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			ppstringIndex(x)->inorder();
		}

		else if (x == 6)
		{
			ppdoubleIndex(x)->inorder();
		}

		break;
	case 2:
		if (x == 0 || x == 1 || x == 5)
		{
			int t2;
			if (x == 0)
				cout << "Enter ID to search for: ";
			else if (x == 1)
				cout << "Enter Year to search for: ";
			else if (x == 5)
				cout << "Enter Number of deaths to search for: ";
			cin >> t2;

			intSearch(ppintIndex(x), t2);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2;
			if (x == 2)
				cout << "Enter 113 Cause Name to search for: ";
			else if (x == 3)
				cout << "Enter Cause Name to search for: ";
			else if (x == 4)
				cout << "Enter State to search for: ";

			cin >> t2;

			stringSearch(ppstringIndex(x), t2);
		}

		else if (x == 6)
		{
			double t2;
			cout << "Enter Age-adjusted Death Rate to search for: ";

			cin >> t2;

			doubleSearch(ppdoubleIndex(x), t2);
		}
		break;
	case 3:
		if (x == 0 || x == 1 || x == 5)
		{
			int t2, t3;
			if (x == 0)
			{
				cout << "Enter starting range of ID: ";
				cin >> t2;

				cout << "Enter ending range of ID: ";
				cin >> t3;
			}

			else if (x == 1)
			{
				cout << "Enter Starting range for Year: ";
				cin >> t2;
				cout << "Enter ending range for Year: ";
				cin >> t3;

			}

			else if (x == 5)
			{
				cout << "Enter starting range of deaths: ";
				cin >> t2;
				cout << "Enter ending range of deaths: ";
				cin >> t3;
			}

			intRangeSearch(ppintIndex(x), t2, t3);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2, t3;
			if (x == 2)
			{
				cout << "Enter Starting Range of 113 Cause Name: ";
				cin >> t2;

				cout << "Enter ending range of 113 Cause Name: ";
				cin >> t3;
			}

			else if (x == 3)
			{
				cout << "Enter Starting range for  Cause Name: ";
				cin >> t2;
				cout << "Enter ending range for  Cause Name: ";
				cin >> t3;

			}

			else if (x == 4)
			{
				cout << "Enter starting range of State: ";
				cin >> t2;
				cout << "Enter ending range of  State: ";
				cin >> t3;
			}

			stringRangeSearch(ppstringIndex(x), t2, t3);

		}

		else if (x == 6)
		{

			double t2, t3;
			cout << "Enter starting range of Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter ending range of Age-adjusted Death Rate: ";
			cin >> t3;

			doubleRangeSearch(ppdoubleIndex(x), t2, t3);
		}

		break;
	case 4:
		ppcase4();
		break;
	case 5:

		ppcase5();
		break;
	default:
		break;

	}



}

void btcase4(int ord)
{
	int x = getField();
	x--;

	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btintUpdate(btintIndex(x, ord), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}
			//-------------

		}

		else if (x == 1)
		{
			cout << "Enter Year to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btintUpdate(btintIndex(x, ord), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btintUpdate(btintIndex(x, ord), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btintUpdate(btintIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}
		}

	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btstringUpdate(btstringIndex(x, ord), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}
		}


		else if (x == 3)
		{
			cout << "Enter Cause Name to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btstringUpdate(btstringIndex(x, ord), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}
		}

		else if (x == 4)
		{
			cout << "Enter State to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				btstringUpdate(btstringIndex(x, ord), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				btstringUpdate(btstringIndex(x, ord), abc, y, to_string(t2), to_string(t3));
			}
		}


	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to update field: ";
		cin >> abc;

		int y = fieldSelectionForUpdate();
		y--;

		if (y == 0 || y == 1 || y == 5)
		{
			int t2, t3;
			if (y == 0)
			{
				cout << "Enter old ID: ";
				cin >> t2;

				cout << "Enter new ID: ";
				cin >> t3;
			}

			else if (y == 1)
			{
				cout << "Enter old Year: ";
				cin >> t2;
				cout << "Enter new Year: ";
				cin >> t3;

			}

			else if (y == 5)
			{
				cout << "Enter old deaths: ";
				cin >> t2;
				cout << "Enter new deaths: ";
				cin >> t3;
			}

			btdoubleUpdate(btdoubleIndex(x, ord), abc, y, to_string(t2), to_string(t3));

		}

		else if (y == 2 || y == 3 || y == 4)
		{
			string t2, t3;
			if (y == 2)
			{
				cout << "Enter old 113 Cause Name: ";
				cin >> t2;

				cout << "Enter new 113 Cause Name: ";
				cin >> t3;
			}

			else if (y == 3)
			{
				cout << "Enter old Cause Name: ";
				cin >> t2;
				cout << "Enter new Cause Name: ";
				cin >> t3;

			}

			else if (y == 4)
			{
				cout << "Enter old State: ";
				cin >> t2;
				cout << "Enter new State: ";
				cin >> t3;
			}


			btdoubleUpdate(btdoubleIndex(x, ord), abc, y, t2, t3);

		}

		else if (y == 6)
		{

			double t2, t3;
			cout << "Enter old Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter new Age-adjusted Death Rate: ";
			cin >> t3;

			btdoubleUpdate(btdoubleIndex(x, ord), abc, y, to_string(t2), to_string(t3));
		}


	}

}

void btcase5(int ord)
{
	int	x = getField();
	x--;


	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to delete all data: ";
			cin >> abc;

		}

		else if (x == 1)
		{
			cout << "Enter Year to delete all data: ";
			cin >> abc;

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to delete all data: ";
			cin >> abc;
		}

		btintDelete(btintIndex(x, ord), abc, x, ord);
	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name: ";
			cin >> abc;
		}

		else if (x == 3)
		{
			cout << "Enter Cause Name to delete: ";
			cin >> abc;

		}

		else if (x == 4)
		{
			cout << "Enter State to delete: ";
			cin >> abc;

		}

		btstringDelete(btstringIndex(x, ord), abc, x, ord);

	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to delete all tuples: ";
		cin >> abc;

		btdoubleDelete(btdoubleIndex(x, ord), abc, x, ord);

	}

}

int  getField()
{
	int ind;
	cout << "\t\t\tChoose a key: " << endl;
	cout << "\t\t\t1. \t Via ID\n";
	cout << "\t\t\t2. \t Via YEAR\n";
	cout << "\t\t\t3. \t Via 113 CAUSE NAME\n";
	cout << "\t\t\t4. \t Via CAUSE NAME\n";
	cout << "\t\t\t5. \t Via STATE\n";
	cout << "\t\t\t6. \t Via DEATHS\n";
	cout << "\t\t\t7. \t Via AGE-ADJUSTED DEATH RATE\n";

	cin >> ind;

	while (ind < 1 || ind > 7)
	{
		cout << "\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!Invalid Input!!!!!!!!!!!!!!!!!!!!!\n\n";
		cout << "\t\t\t\tEnter again: ";
		cin >> ind;

	}

	return ind;
}

int fieldSelectionForUpdate()
{
	int ind;
	cout << "\t\t\tChoose a field: " << endl;
	cout << "\t\t\t1. \t ID\n";
	cout << "\t\t\t2. \t YEAR\n";
	cout << "\t\t\t3. \t 113 CAUSE NAME\n";
	cout << "\t\t\t4. \t CAUSE NAME\n";
	cout << "\t\t\t5. \t STATE\n";
	cout << "\t\t\t6. \t DEATHS\n";
	cout << "\t\t\t7. \t AGE-ADJUSTED DEATH RATE\n";

	cin >> ind;

	while (ind < 1 || ind > 7)
	{
		cout << "\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!Invalid Input!!!!!!!!!!!!!!!!!!!!!\n\n";
		cout << "\t\t\t\tEnter again: ";
		cin >> ind;

	}

	return ind;

}


void avlcase4()
{
	int x = getField();
	x--;

	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlintUpdate(avlintIndex(x), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));
			}
			//-------------

		}

		else if (x == 1)
		{
			cout << "Enter Year to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlintUpdate(avlintIndex(x), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));
			}

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlintUpdate(avlintIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlintUpdate(avlintIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}

	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlstringUpdate(avlstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}


		else if (x == 3)
		{
			cout << "Enter Cause Name to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlstringUpdate(avlstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}

		else if (x == 4)
		{
			cout << "Enter State to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				avlstringUpdate(avlstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				avlstringUpdate(avlstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}


	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to update field: ";
		cin >> abc;

		int y = fieldSelectionForUpdate();
		y--;

		if (y == 0 || y == 1 || y == 5)
		{
			int t2, t3;
			if (y == 0)
			{
				cout << "Enter old ID: ";
				cin >> t2;

				cout << "Enter new ID: ";
				cin >> t3;
			}

			else if (y == 1)
			{
				cout << "Enter old Year: ";
				cin >> t2;
				cout << "Enter new Year: ";
				cin >> t3;

			}

			else if (y == 5)
			{
				cout << "Enter old deaths: ";
				cin >> t2;
				cout << "Enter new deaths: ";
				cin >> t3;
			}

			avldoubleUpdate(avldoubleIndex(x), abc, y, to_string(t2), to_string(t3));

		}

		else if (y == 2 || y == 3 || y == 4)
		{
			string t2, t3;
			if (y == 2)
			{
				cout << "Enter old 113 Cause Name: ";
				cin >> t2;

				cout << "Enter new 113 Cause Name: ";
				cin >> t3;
			}

			else if (y == 3)
			{
				cout << "Enter old Cause Name: ";
				cin >> t2;
				cout << "Enter new Cause Name: ";
				cin >> t3;

			}

			else if (y == 4)
			{
				cout << "Enter old State: ";
				cin >> t2;
				cout << "Enter new State: ";
				cin >> t3;
			}


			avldoubleUpdate(avldoubleIndex(x), abc, y, t2, t3);

		}

		else if (y == 6)
		{

			double t2, t3;
			cout << "Enter old Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter new Age-adjusted Death Rate: ";
			cin >> t3;

			avldoubleUpdate(avldoubleIndex(x), abc, y, to_string(t2), to_string(t3));
		}


	}

}


void avlcase5()
{
	int	x = getField();
	x--;


	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to delete all data: ";
			cin >> abc;

		}

		else if (x == 1)
		{
			cout << "Enter Year to delete all data: ";
			cin >> abc;

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to delete all data: ";
			cin >> abc;
		}

		avlintDelete(avlintIndex(x), abc, x);
	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name: ";
			cin >> abc;
		}

		else if (x == 3)
		{
			cout << "Enter Cause Name to delete: ";
			cin >> abc;

		}

		else if (x == 4)
		{
			cout << "Enter State to delete: ";
			cin >> abc;

		}

		avlstringDelete(avlstringIndex(x), abc, x);

	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to delete all tuples: ";
		cin >> abc;

		avldoubleDelete(avldoubleIndex(x), abc, x);

	}

}

void ppcase4()
{
	int x = getField();
	x--;

	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				intUpdate(ppintIndex(x), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));
			}
			//-------------

		}

		else if (x == 1)
		{
			cout << "Enter Year to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				intUpdate(ppintIndex(x), abc, y, t2, t3);

			}

			else if (x == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));
			}

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				intUpdate(ppintIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				intUpdate(ppintIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}

	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name to update field: ";
			cin >> abc;


			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				stringUpdate(ppstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}


		else if (x == 3)
		{
			cout << "Enter Cause Name to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				stringUpdate(ppstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}

		else if (x == 4)
		{
			cout << "Enter State to update field: ";
			cin >> abc;

			int y = fieldSelectionForUpdate();
			y--;

			if (y == 0 || y == 1 || y == 5)
			{
				int t2, t3;
				if (y == 0)
				{
					cout << "Enter old ID: ";
					cin >> t2;

					cout << "Enter new ID: ";
					cin >> t3;
				}

				else if (y == 1)
				{
					cout << "Enter old Year: ";
					cin >> t2;
					cout << "Enter new Year: ";
					cin >> t3;

				}

				else if (y == 5)
				{
					cout << "Enter old deaths: ";
					cin >> t2;
					cout << "Enter new deaths: ";
					cin >> t3;
				}

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));

			}

			else if (y == 2 || y == 3 || y == 4)
			{
				string t2, t3;
				if (y == 2)
				{
					cout << "Enter old 113 Cause Name: ";
					cin >> t2;

					cout << "Enter new 113 Cause Name: ";
					cin >> t3;
				}

				else if (y == 3)
				{
					cout << "Enter old Cause Name: ";
					cin >> t2;
					cout << "Enter new Cause Name: ";
					cin >> t3;

				}

				else if (y == 4)
				{
					cout << "Enter old State: ";
					cin >> t2;
					cout << "Enter new State: ";
					cin >> t3;
				}


				stringUpdate(ppstringIndex(x), abc, y, t2, t3);

			}

			else if (y == 6)
			{

				double t2, t3;
				cout << "Enter old Age-adjusted Death Rate: ";
				cin >> t2;
				cout << "Enter new Age-adjusted Death Rate: ";
				cin >> t3;

				stringUpdate(ppstringIndex(x), abc, y, to_string(t2), to_string(t3));
			}
		}


	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to update field: ";
		cin >> abc;

		int y = fieldSelectionForUpdate();
		y--;

		if (y == 0 || y == 1 || y == 5)
		{
			int t2, t3;
			if (y == 0)
			{
				cout << "Enter old ID: ";
				cin >> t2;

				cout << "Enter new ID: ";
				cin >> t3;
			}

			else if (y == 1)
			{
				cout << "Enter old Year: ";
				cin >> t2;
				cout << "Enter new Year: ";
				cin >> t3;

			}

			else if (y == 5)
			{
				cout << "Enter old deaths: ";
				cin >> t2;
				cout << "Enter new deaths: ";
				cin >> t3;
			}

			doubleUpdate(ppdoubleIndex(x), abc, y, to_string(t2), to_string(t3));

		}

		else if (y == 2 || y == 3 || y == 4)
		{
			string t2, t3;
			if (y == 2)
			{
				cout << "Enter old 113 Cause Name: ";
				cin >> t2;

				cout << "Enter new 113 Cause Name: ";
				cin >> t3;
			}

			else if (y == 3)
			{
				cout << "Enter old Cause Name: ";
				cin >> t2;
				cout << "Enter new Cause Name: ";
				cin >> t3;

			}

			else if (y == 4)
			{
				cout << "Enter old State: ";
				cin >> t2;
				cout << "Enter new State: ";
				cin >> t3;
			}


			doubleUpdate(ppdoubleIndex(x), abc, y, t2, t3);

		}

		else if (y == 6)
		{

			double t2, t3;
			cout << "Enter old Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter new Age-adjusted Death Rate: ";
			cin >> t3;

			doubleUpdate(ppdoubleIndex(x), abc, y, to_string(t2), to_string(t3));
		}


	}

}

void ppcase5()
{
	int	x = getField();
	x--;


	if (x == 0 || x == 1 || x == 5)
	{
		int abc;
		if (x == 0)
		{
			cout << "Enter ID to delete all data: ";
			cin >> abc;

		}

		else if (x == 1)
		{
			cout << "Enter Year to delete all data: ";
			cin >> abc;

		}

		else if (x == 5)
		{
			cout << "Enter number of deaths to delete all data: ";
			cin >> abc;
		}

		intDelete(ppintIndex(x), abc, x);
	}

	else if (x == 2 || x == 3 || x == 4)
	{
		string abc;

		if (x == 2)
		{
			cout << "Enter 113 Cause Name: ";
			cin >> abc;
		}

		else if (x == 3)
		{
			cout << "Enter Cause Name to delete: ";
			cin >> abc;

		}

		else if (x == 4)
		{
			cout << "Enter State to delete: ";
			cin >> abc;

		}

		stringDelete(ppstringIndex(x), abc, x);

	}

	else if (x == 6)
	{
		double abc;

		cout << "Enter an Age-adjusted Death Rate to delete all tuples: ";
		cin >> abc;

		doubleDelete(ppdoubleIndex(x), abc, x);

	}

}

void BTreeMenu()
{
	int op2, ord;
	system("CLS");

	cout << "\n\t\t\t\t\t Enter order of b tree: ";
	cin >> ord;

	cout << "\n\t\t\t\t\tPerform the following actions using B - tree: \n\n";
	cout << "\n\t\t\tPress the corresponding number: \n\n";
	cout << "\t\t\t1. \t Create Index\n";
	cout << "\t\t\t2. \t Point Search\n";
	cout << "\t\t\t3. \t Range Search\n";
	cout << "\t\t\t4. \t Update Field\n";
	cout << "\t\t\t5. \t Delete Key\n";

	cin >> op2;

	while (op2 < 1 || op2 > 5)
	{
		cout << "\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!Invalid Input!!!!!!!!!!!!!!!!!!!!!\n\n";
		cout << "\t\t\t\tEnter again: ";
		cin >> op2;
	}

	int x;

	switch (op2)
	{

	case 1:
		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			btintIndex(x, ord)->traverse();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			btstringIndex(x, ord)->traverse();
		}

		else if (x == 6)
		{
			btdoubleIndex(x, ord)->traverse();
		}

		break;
	case 2:

		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			int t2;
			if (x == 0)
				cout << "Enter ID to search for: ";
			else if (x == 1)
				cout << "Enter Year to search for: ";
			else if (x == 5)
				cout << "Enter Number of deaths to search for: ";
			cin >> t2;

			btintSearch(btintIndex(x, ord), t2);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2;
			if (x == 2)
				cout << "Enter 113 Cause Name to search for: ";
			else if (x == 3)
				cout << "Enter Cause Name to search for: ";
			else if (x == 4)
				cout << "Enter State to search for: ";

			cin >> t2;

			btstringSearch(btstringIndex(x, ord), t2);
		}

		else if (x == 6)
		{
			double t2;
			cout << "Enter Age-adjusted Death Rate to search for: ";

			cin >> t2;

			btdoubleSearch(btdoubleIndex(x, ord), t2);
		}
		break;
	case 3:

		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			int t2, t3;
			if (x == 0)
			{
				cout << "Enter starting range of ID: ";
				cin >> t2;

				cout << "Enter ending range of ID: ";
				cin >> t3;
			}

			else if (x == 1)
			{
				cout << "Enter Starting range for Year: ";
				cin >> t2;
				cout << "Enter ending range for Year: ";
				cin >> t3;

			}

			else if (x == 5)
			{
				cout << "Enter starting range of deaths: ";
				cin >> t2;
				cout << "Enter ending range of deaths: ";
				cin >> t3;
			}

			btintRangeSearch(btintIndex(x, ord), t2, t3);
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			string t2, t3;
			if (x == 2)
			{
				cout << "Enter Starting Range of 113 Cause Name: ";
				cin >> t2;

				cout << "Enter ending range of 113 Cause Name: ";
				cin >> t3;
			}

			else if (x == 3)
			{
				cout << "Enter Starting range for  Cause Name: ";
				cin >> t2;
				cout << "Enter ending range for  Cause Name: ";
				cin >> t3;

			}

			else if (x == 4)
			{
				cout << "Enter starting range of State: ";
				cin >> t2;
				cout << "Enter ending range of  State: ";
				cin >> t3;
			}

			btstringRangeSearch(btstringIndex(x, ord), t2, t3);

		}

		else if (x == 6)
		{

			double t2, t3;
			cout << "Enter starting range of Age-adjusted Death Rate: ";
			cin >> t2;
			cout << "Enter ending range of Age-adjusted Death Rate: ";
			cin >> t3;

			btdoubleRangeSearch(btdoubleIndex(x, ord), t2, t3);
		}

		break;

	case 4:
		btcase4(ord);

		break;

	case 5:
		btcase5(ord);
		break;

	default:

		break;

	}

}

void multi_Indexing()
{
	system("CLS");
	bool b, p, a;
	cout << "\t\t\tPress 1 for YES, 0 for NO" << endl << endl << endl;
	cout << "\t\t\tDo you want to index with b tree? " << endl;
	cin >> b;

	cout << "\t\t\tDo you want to index with pink purple tree? " << endl;
	cin >> p;

	cout << "\t\t\tDo you want to index with avl tree? " << endl;
	cin >> a;

	if (p)
	{
		system("CLS");

		int x;
		x = getField();
		x--;

		if (x == 0 || x == 1 || x == 5)
		{
			ppintIndex(x)->inorder();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			ppstringIndex(x)->inorder();
		}

		else if (x == 6)
		{
			ppdoubleIndex(x)->inorder();
		}
	}

	if (b)
	{
		system("CLS");
		int ord;

		cout << "\t\t\tEnter order of B Tree: ";
		cin >> ord;
		int x;

		system("CLS");
		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			btintIndex(x, ord)->traverse();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			btstringIndex(x, ord)->traverse();
		}

		else if (x == 6)
		{
			btdoubleIndex(x, ord)->traverse();
		}
	}

	if (a)
	{
		int x;

		x = getField();
		x--;


		if (x == 0 || x == 1 || x == 5)
		{
			avlintIndex(x)->displayInOrder();
		}

		else if (x == 2 || x == 3 || x == 4)
		{
			avlstringIndex(x)->displayInOrder();
		}

		else if (x == 6)
		{
			avldoubleIndex(x)->displayInOrder();
		}
	}


}