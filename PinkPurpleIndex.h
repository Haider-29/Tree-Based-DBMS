#pragma once
#include "PinkPurple.h"
#include <fstream>
#include <tuple>
#include <iostream>
#include <string>
#include <stdio.h>
#include <direct.h>

using namespace std;

PinkPurpleTree<int>* ppintIndex(int n) {

	cout << n << endl;

	PinkPurpleTree<int>* pp = new PinkPurpleTree<int>();

	int id = 0;
	int year = 0;
	string cause113 = "";
	string cause = "";
	string state = "";
	int deaths = 0;
	double ageAdjustedDR = 0;
	int numFieldsRead = 0;
	int commasread = 0;
	string fileName = "";
	bool commasImmune = false;

	string* indexFields = new string[7];
	int numFields = 0;
	string tempString = "";
	string field;

	ifstream fin("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_1.csv");

	getline(fin, tempString);

	fin.close();

	for (int i = 0; i < tempString.length(); i++) {

		if (tempString[i] != ',') {

			field += tempString[i];

		}

		else if (field != "") {

			indexFields[numFields++] = field;
			field = "";

		}

	}


	int linenumber = 0;

	for (int j = 0; j <= 10; j++) {

		fin.open("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv");

		getline(fin, tempString);

		linenumber = 1;

		while (getline(fin, tempString)) {

			//getline(fin, tempString);

			linenumber += 1;

			field = "";
			numFieldsRead = 0;
			commasread = 0;
			commasImmune = false;

			for (int i = 0; i < tempString.length(); i++) {

				if (tempString[i] != ',') 
				{

					if (tempString[i] == '\"')
					{
						field += tempString[i];
						i++;
						while (tempString[i] != '\"')
						{
							field += tempString[i];
							i++;
						}
						field += tempString[i];
					}

					else {

						field += tempString[i];

					}

				}

				else if (field != "") {

					//int id;
					//int year;
					//string cause113;
					//string cause;
					//string state;
					//int deaths;
					//int ageAdjustedDR;

					if (numFieldsRead == 0) {

						id = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 1) {

						year = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 2) {

						cause113 = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 3) {

						cause = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 4) {

						state = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 5) {

						deaths = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 6) {

						cout << field << endl;

					}

				}

			}

			ageAdjustedDR = stod(field);
			numFieldsRead++;

			field = "";

			//cout << id << " " << year << " " << cause113 << " " << cause << " " << state << " " << deaths << " " << ageAdjustedDR << endl;

			Node<int>* tempEntry;

			string stuff = "Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv" + "," + to_string(linenumber);

			string filestuff = "";

			if (n == 0) {

				tempEntry = new Node<int>();

				filestuff = "RBID/RBID" + to_string(id) + ".txt";
				tempEntry = pp->insert(id);
				tempEntry->location.insert(stuff);
				tempEntry->filename = filestuff;

			}

			else if(n == 1) {

				tempEntry = pp->search(year);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<int>();

					filestuff = "RBY/RBY" + to_string(year) + ".txt";
					tempEntry = pp->insert(year);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}

			else if (n == 5) {

				tempEntry = pp->search(deaths);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<int>();

					filestuff = "RBD/RBD" + to_string(deaths) + ".txt";
					tempEntry = pp->insert(deaths);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}
			

		}

		fin.close();

	}

	pp->preorder();

	return pp;

}

PinkPurpleTree<double>* ppdoubleIndex(int n) {

	cout << n << endl;

	PinkPurpleTree<double>* pp = new PinkPurpleTree<double>();

	int id = 0;
	int year = 0;
	string cause113 = "";
	string cause = "";
	string state = "";
	int deaths = 0;
	double ageAdjustedDR = 0;
	int numFieldsRead = 0;
	int commasread = 0;
	string fileName = "";

	string* indexFields = new string[7];
	int numFields = 0;
	string tempString = "";
	string field;

	ifstream fin("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_1.csv");

	getline(fin, tempString);

	fin.close();

	for (int i = 0; i < tempString.length(); i++) {

		if (tempString[i] != ',') {

			field += tempString[i];

		}

		else if (field != "") {

			indexFields[numFields++] = field;
			field = "";

		}

	}


	int linenumber = 0;

	for (int j = 0; j <= 10; j++) {

		fin.open("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv");

		getline(fin, tempString);

		linenumber = 1;

		while (getline(fin, tempString)) {

			//getline(fin, tempString);

			linenumber += 1;

			field = "";
			numFieldsRead = 0;
			commasread = 0;

			for (int i = 0; i < tempString.length(); i++) {

				if (tempString[i] != ',')
				{

					if (tempString[i] == '\"')
					{
						field += tempString[i];
						i++;
						while (tempString[i] != '\"')
						{
							field += tempString[i];
							i++;
						}
						field += tempString[i];
					}

					else {

						field += tempString[i];

					}

				}

				else if (field != "") {

					//int id;
					//int year;
					//string cause113;
					//string cause;
					//string state;
					//int deaths;
					//int ageAdjustedDR;

					if (numFieldsRead == 0) {

						id = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 1) {

						year = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 2) {

						cause113 = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 3) {

						cause = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 4) {

						state = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 5) {

						deaths = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 6) {

						cout << field << endl;

					}

				}

			}

			ageAdjustedDR = stod(field);
			numFieldsRead++;

			field = "";

			Node<double>* tempEntry;

			string stuff = "Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv" + "," + to_string(linenumber);

			string filestuff = "";

			if (n == 6) {

				tempEntry = pp->search(ageAdjustedDR);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<double>();

					filestuff = "RBAD/RBAD" + to_string(ageAdjustedDR) + ".txt";
					tempEntry = pp->insert(ageAdjustedDR);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}


		}

		fin.close();

	}

	pp->preorder();

	return pp;

}

PinkPurpleTree<string>* ppstringIndex(int n) {

	cout << n << endl;

	PinkPurpleTree<string>* pp = new PinkPurpleTree<string>();

	int id = 0;
	int year = 0;
	string cause113 = "";
	string cause = "";
	string state = "";
	int deaths = 0;
	double ageAdjustedDR = 0;
	int numFieldsRead = 0;
	int commasread = 0;
	string fileName = "";

	string* indexFields = new string[7];
	int numFields = 0;
	string tempString = "";
	string field;

	ifstream fin("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_1.csv");

	getline(fin, tempString);

	fin.close();

	for (int i = 0; i < tempString.length(); i++) {

		if (tempString[i] != ',') {

			field += tempString[i];

		}

		else if (field != "") {

			indexFields[numFields++] = field;
			field = "";

		}

	}


	int linenumber = 0;

	for (int j = 0; j <= 10; j++) {

		fin.open("Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv");

		getline(fin, tempString);

		linenumber = 1;

		while (getline(fin, tempString)) {

			//getline(fin, tempString);

			linenumber += 1;

			field = "";
			numFieldsRead = 0;
			commasread = 0;

			for (int i = 0; i < tempString.length(); i++) {

				if (tempString[i] != ',')
				{

					if (tempString[i] == '\"')
					{
						field += tempString[i];
						i++;
						while (tempString[i] != '\"')
						{
							field += tempString[i];
							i++;
						}
						field += tempString[i];
					}

					else {

						field += tempString[i];

					}

				}

				else if (field != "") {

					//int id;
					//int year;
					//string cause113;
					//string cause;
					//string state;
					//int deaths;
					//int ageAdjustedDR;

					if (numFieldsRead == 0) {

						id = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 1) {

						year = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 2) {

						cause113 = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 3) {

						cause = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 4) {

						state = field;
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 5) {

						deaths = stoi(field);
						numFieldsRead++;
						field = "";

					}

					else if (numFieldsRead == 6) {

						cout << field << endl;

					}

				}

			}

			ageAdjustedDR = stod(field);
			numFieldsRead++;

			field = "";

			Node<string>* tempEntry;

			string stuff = "Dataset/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(j) + ".csv" + "," + to_string(linenumber);

			string filestuff = "";

			if (n == 2) {

				tempEntry = pp->search(cause113);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<string>();

					filestuff = "RBC113/RBC113" + cause113 + ".txt";
					tempEntry = pp->insert(cause113);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}

			else if (n == 3) {

				tempEntry = pp->search(cause);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<string>();

					filestuff = "RBC/RBC" + cause + ".txt";
					tempEntry = pp->insert(cause);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}

			else if (n == 4) {

				tempEntry = pp->search(state);

				if (tempEntry == pp->getTempN()) {

					tempEntry = new Node<string>();

					filestuff = "RBS/RBS" + state + ".txt";
					tempEntry = pp->insert(state);
					tempEntry->location.insert(stuff);
					tempEntry->filename = filestuff;

				}

				else {

					tempEntry->location.insert(stuff);

				}

			}


		}

		fin.close();

	}

	pp->preorder();

	return pp;

}

void intSearch(PinkPurpleTree<int>* pp, int num) {

	Node<int>* s = pp->search(num);

	LinkedList<string> l = s->location;
	LNode<string>* lol = l.getHead();
	string location = "";
	string filename = "";
	int lineNum = -1;
	string temp = "";
	int countedStuff = 0;
	string data = "";

	for (int i = 0; i < l.getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		cout << data << endl;

		fin.close();

	}

}

void stringSearch(PinkPurpleTree<string>* pp, string num) {

	Node<string>* s = pp->search(num);

	LinkedList<string> l = s->location;
	LNode<string>* lol = l.getHead();
	string location = "";
	string filename = "";
	int lineNum = -1;
	string temp = "";
	int countedStuff = 0;
	string data = "";

	for (int i = 0; i < l.getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		cout << data << endl;

		fin.close();

	}

}

void doubleSearch(PinkPurpleTree<double>* pp, double num) {

	Node<double>* s = pp->search(num);

	LinkedList<string> l = s->location;
	LNode<string>* lol = l.getHead();
	string location = "";
	string filename = "";
	int lineNum = -1;
	string temp = "";
	int countedStuff = 0;
	string data = "";

	for (int i = 0; i < l.getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		cout << data << endl;

		fin.close();

	}

}

void intRangeSearch(PinkPurpleTree<int>* pp, int num1, int num2) {

	pp->postorder(num1, num2);

}

void stringRangeSearch(PinkPurpleTree<string>* pp, string num1, string num2) {

	pp->postorder(num1, num2);

}

void doubleRangeSearch(PinkPurpleTree<double>* pp, double num1, double num2) {

	pp->postorder(num1, num2);

}

void intUpdate(PinkPurpleTree<int>* pp, int field, int fieldToEdit, string oldField, string newField) {

	Node<int>* s = pp->search(field);

	LinkedList<string>* l = &(s->location);
	string location = "";
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	int numMatchingFields = 0;
	string matchingLocation[2][10];
	string matchingData[7][10];


	for (int i = 0; i < l->getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		string fielder = "";
		int numFieldsRead = 0;
		int commasread = 0;
		int id = 0;
		int year = 0;
		string cause = "";
		string cause113 = "";
		string state = "";
		int deaths = 0;
		double ageAdjustedDR = 0;
		string khassiDeaths = "";

		for (int i = 0; i < data.length(); i++) {

			if (data[i] != ',')
			{

				if (data[i] == '\"')
				{
					fielder += data[i];
					i++;
					while (data[i] != '\"')
					{
						fielder += data[i];
						i++;
					}
					fielder += data[i];
				}

				else {

					fielder += data[i];

				}

			}

			else if (fielder != "") {

				//int id;
				//int year;
				//string cause113;
				//string cause;
				//string state;
				//int deaths;
				//int ageAdjustedDR;

				if (numFieldsRead == 0) {

					id = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 1) {

					year = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 2) {

					cause113 = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 3) {

					cause = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 4) {

					state = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 5) {

					deaths = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 6) {

					cout << fielder << endl;

				}

			}

		}

		khassiDeaths = fielder;
		ageAdjustedDR = stod(fielder);
		numFieldsRead++;

		if (fieldToEdit == 0) {

			if (to_string(id) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 1) {

			if (to_string(year) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 2) {

			if (cause113 == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 3) {

			if (cause == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 4) {

			if (state == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 5) {

			if (to_string(deaths) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 6) {

			if (ageAdjustedDR == stod(oldField)) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		if (numMatchingFields >= 2) {

			break;

		}

		fin.close();

	}

	//cout << numMatchingFields << endl;

	for (int i = 0; i < numMatchingFields; i++) {
	
		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	if (numMatchingFields == 0 || numMatchingFields >= 2) {

		cout << "The database could not update your information due to some error" << endl;
		return;

	}

	else {

		if (fieldToEdit == 0) {

			matchingData[0][0] = newField;

		}

		else if (fieldToEdit == 1) {

			matchingData[1][0] = newField;

		}

		else if (fieldToEdit == 2) {

			matchingData[2][0] = newField;

		}

		else if (fieldToEdit == 3) {

			matchingData[3][0] = newField;

		}

		else if (fieldToEdit == 4) {

			matchingData[4][0] = newField;

		}

		else if (fieldToEdit == 5) {

			matchingData[5][0] = newField;

		}

		else if (fieldToEdit == 6) {

			matchingData[6][0] = newField;

		}

	}

	cout << endl << endl;

	for (int i = 0; i < numMatchingFields; i++) {

		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	cout << endl << endl;

	string tempstorage = "";
	int tempLineNumber = 0;

	ifstream fin(matchingLocation[0][0]);
	ofstream fout("Dataset/tempfile.csv");

	while (getline(fin, tempstorage)) {

		if (tempLineNumber == (stoi(matchingLocation[1][0]) - 1)) {

			fout << matchingData[0][0] << "," << matchingData[1][0] << "," << matchingData[2][0] << "," << matchingData[3][0] << "," << matchingData[4][0] << "," << matchingData[5][0] << "," << matchingData[6][0] << endl;

		}

		else {

			fout << tempstorage << endl;

		}

		tempLineNumber++;;

	}

	fin.close();
	fout.close();

	char* arr = new char[(matchingLocation[0][0]).length() + 1];

	for (int i = 0; i < matchingLocation[0][0].length(); i++)
		arr[i] = matchingLocation[0][0][i];

	arr[matchingLocation[0][0].length()] = '\0';

	remove(arr);
	int result = rename("Dataset/tempfile.csv", arr);

	if (result == 0) {

		cout << "yep";

	}

}

void doubleUpdate(PinkPurpleTree<double>* pp, double field, int fieldToEdit, string oldField, string newField) {

	Node<double>* s = pp->search(field);

	LinkedList<string>* l = &(s->location);
	string location = "";
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	int numMatchingFields = 0;
	string matchingLocation[2][10];
	string matchingData[7][10];


	for (int i = 0; i < l->getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		cout << data << endl;

		string fielder = "";
		int numFieldsRead = 0;
		int commasread = 0;
		int id = 0;
		int year = 0;
		string cause = "";
		string cause113 = "";
		string state = "";
		int deaths = 0;
		double ageAdjustedDR = 0;
		string khassiDeaths = "";

		for (int i = 0; i < data.length(); i++) {

			if (data[i] != ',')
			{
				if (data[i] == '\"')
				{
					fielder += data[i];
					i++;
					while (data[i] != '\"')
					{
						fielder += data[i];
						i++;
					}
					fielder += data[i];
				}

				else {

					fielder += data[i];

				}

			}

			else if (fielder != "") {

				//int id;
				//int year;
				//string cause113;
				//string cause;
				//string state;
				//int deaths;
				//int ageAdjustedDR;

				if (numFieldsRead == 0) {

					id = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 1) {

					year = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 2) {

					cause113 = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 3) {

					cause = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 4) {

					state = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 5) {

					deaths = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 6) {

					cout << fielder << endl;

				}

			}

		}

		khassiDeaths = fielder;
		ageAdjustedDR = stod(fielder);
		numFieldsRead++;

		if (fieldToEdit == 0) {

			if (to_string(id) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 1) {

			if (to_string(year) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 2) {

			if (cause113 == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 3) {

			if (cause == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 4) {

			if (state == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 5) {

			if (to_string(deaths) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 6) {

			if (ageAdjustedDR == stod(oldField)) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		if (numMatchingFields >= 2) {

			break;

		}

		fin.close();

	}

	//cout << numMatchingFields << endl;

	for (int i = 0; i < numMatchingFields; i++) {

		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	if (numMatchingFields == 0 || numMatchingFields >= 2) {

		cout << "The database could not update your information due to some error" << endl;
		return;

	}

	else {

		if (fieldToEdit == 0) {

			matchingData[0][0] = newField;

		}

		else if (fieldToEdit == 1) {

			matchingData[1][0] = newField;

		}

		else if (fieldToEdit == 2) {

			matchingData[2][0] = newField;

		}

		else if (fieldToEdit == 3) {

			matchingData[3][0] = newField;

		}

		else if (fieldToEdit == 4) {

			matchingData[4][0] = newField;

		}

		else if (fieldToEdit == 5) {

			matchingData[5][0] = newField;

		}

		else if (fieldToEdit == 6) {

			matchingData[6][0] = newField;

		}

	}

	cout << endl << endl;

	for (int i = 0; i < numMatchingFields; i++) {

		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	cout << endl << endl;

	string tempstorage = "";
	int tempLineNumber = 0;

	ifstream fin(matchingLocation[0][0]);
	ofstream fout("Dataset/tempfile.csv");

	while (getline(fin, tempstorage)) {

		if (tempLineNumber == (stoi(matchingLocation[1][0]) - 1)) {

			fout << matchingData[0][0] << "," << matchingData[1][0] << "," << matchingData[2][0] << "," << matchingData[3][0] << "," << matchingData[4][0] << "," << matchingData[5][0] << "," << matchingData[6][0] << endl;

		}

		else {

			fout << tempstorage << endl;

		}

		tempLineNumber++;;

	}

	fin.close();
	fout.close();

	char* arr = new char[(matchingLocation[0][0]).length() + 1];

	for (int i = 0; i < matchingLocation[0][0].length(); i++)
		arr[i] = matchingLocation[0][0][i];

	arr[matchingLocation[0][0].length()] = '\0';

	remove(arr);
	int result = rename("Dataset/tempfile.csv", arr);

	if (result == 0) {

		cout << "yep";

	}

}

void stringUpdate(PinkPurpleTree<string>* pp, string field, int fieldToEdit, string oldField, string newField) {

	Node<string>* s = pp->search(field);

	LinkedList<string>* l = &(s->location);
	string location = "";
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	int numMatchingFields = 0;
	string matchingLocation[2][10];
	string matchingData[7][10];


	for (int i = 0; i < l->getSize(); i++) {

		location = lol->getData();

		//cout << location << endl;

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);

		temp = "";

		lol = lol->getNext();

		ifstream fin(filename);

		for (int i = 0; i < lineNum; i++) {

			getline(fin, data);

		}

		cout << data << endl;

		string fielder = "";
		int numFieldsRead = 0;
		int commasread = 0;
		int id = 0;
		int year = 0;
		string cause = "";
		string cause113 = "";
		string state = "";
		int deaths = 0;
		double ageAdjustedDR = 0;
		string khassiDeaths = "";

		for (int i = 0; i < data.length(); i++) {

			if (data[i] != ',')
			{

				if (data[i] == '\"')
				{
					fielder += data[i];
					i++;
					while (data[i] != '\"')
					{
						fielder += data[i];
						i++;
					}
					fielder += data[i];
				}

				else {

					fielder += data[i];

				}

			}

			else if (fielder != "") {

				//int id;
				//int year;
				//string cause113;
				//string cause;
				//string state;
				//int deaths;
				//int ageAdjustedDR;

				if (numFieldsRead == 0) {

					id = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 1) {

					year = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 2) {

					cause113 = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 3) {

					cause = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 4) {

					state = fielder;
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 5) {

					deaths = stoi(fielder);
					numFieldsRead++;
					fielder = "";

				}

				else if (numFieldsRead == 6) {

					cout << fielder << endl;

				}

			}

		}

		khassiDeaths = fielder;
		ageAdjustedDR = stod(fielder);
		numFieldsRead++;

		if (fieldToEdit == 0) {

			if (to_string(id) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 1) {

			if (to_string(year) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 2) {

			if (cause113 == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 3) {

			if (cause == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 4) {

			if (state == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 5) {

			if (to_string(deaths) == oldField) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		else if (fieldToEdit == 6) {

			if (ageAdjustedDR == stod(oldField)) {

				matchingLocation[0][numMatchingFields] = filename;
				matchingLocation[1][numMatchingFields] = to_string(lineNum);
				matchingData[0][numMatchingFields] = to_string(id);
				matchingData[1][numMatchingFields] = to_string(year);
				matchingData[2][numMatchingFields] = cause113;
				matchingData[3][numMatchingFields] = cause;
				matchingData[4][numMatchingFields] = state;
				matchingData[5][numMatchingFields] = to_string(deaths);
				matchingData[6][numMatchingFields++] = khassiDeaths;

			}

		}

		if (numMatchingFields >= 2) {

			break;

		}

		fin.close();

	}

	//cout << numMatchingFields << endl;

	for (int i = 0; i < numMatchingFields; i++) {

		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	if (numMatchingFields == 0 || numMatchingFields >= 2) {

		cout << "The database could not update your information due to some error" << endl;
		return;

	}

	else {

		if (fieldToEdit == 0) {

			matchingData[0][0] = newField;

		}

		else if (fieldToEdit == 1) {

			matchingData[1][0] = newField;

		}

		else if (fieldToEdit == 2) {

			matchingData[2][0] = newField;

		}

		else if (fieldToEdit == 3) {

			matchingData[3][0] = newField;

		}

		else if (fieldToEdit == 4) {

			matchingData[4][0] = newField;

		}

		else if (fieldToEdit == 5) {

			matchingData[5][0] = newField;

		}

		else if (fieldToEdit == 6) {

			matchingData[6][0] = newField;

		}

	}

	cout << endl << endl;

	for (int i = 0; i < numMatchingFields; i++) {

		cout << matchingLocation[0][i] << endl;
		cout << matchingLocation[1][i] << endl;
		cout << matchingData[0][i] << endl;
		cout << matchingData[1][i] << endl;
		cout << matchingData[2][i] << endl;
		cout << matchingData[3][i] << endl;
		cout << matchingData[4][i] << endl;
		cout << matchingData[5][i] << endl;
		cout << matchingData[6][i] << endl;

	}

	cout << endl << endl;

	string tempstorage = "";
	int tempLineNumber = 0;

	ifstream fin(matchingLocation[0][0]);
	ofstream fout("Dataset/tempfile.csv");

	while (getline(fin, tempstorage)) {

		if (tempLineNumber == (stoi(matchingLocation[1][0]) - 1)) {

			fout << matchingData[0][0] << "," << matchingData[1][0] << "," << matchingData[2][0] << "," << matchingData[3][0] << "," << matchingData[4][0] << "," << matchingData[5][0] << "," << matchingData[6][0] << endl;

		}

		else {

			fout << tempstorage << endl;

		}

		tempLineNumber++;;

	}

	fin.close();
	fout.close();

	char* arr = new char[(matchingLocation[0][0]).length() + 1];

	for (int i = 0; i < matchingLocation[0][0].length(); i++)
		arr[i] = matchingLocation[0][0][i];

	arr[matchingLocation[0][0].length()] = '\0';

	remove(arr);
	int result = rename("Dataset/tempfile.csv", arr);

	if (result == 0) {

		cout << "yep";

	}

}

void intDelete(PinkPurpleTree<int>* pp, int field, int indexField) {

	Node<int>* s = pp->search(field);
	LinkedList<string>* l = &(s->location);
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	string location = "";
	int counter = 0;
	int initialSize = l->getSize();

	for (int i = 0; i < initialSize; i++) {

		s = pp->search(field);
		l = l = &(s->location);
		lol = l->getHead();
		location = lol->getData();

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);
		int tempLineNumber = 0;

		cout << filename << " " << lineNum << endl;

		temp = "";

		ifstream fin(filename);
		ofstream fout("Dataset/tempfile.csv");

		while (getline(fin, temp)) {

			if (tempLineNumber == (lineNum - 1)) {


			}

			else {

				fout << temp << endl;

			}

			tempLineNumber++;;

		}

		fin.close();
		fout.close();

		char* arr = new char[filename.length() + 1];

		for (int i = 0; i < filename.length(); i++)
			arr[i] = filename[i];

		arr[filename.length()] = '\0';

		remove(arr);
		int result = rename("Dataset/tempfile.csv", arr);

		//if (result == 0) {

		//	cout << "yep";

		//}

		counter++;
		cout << counter;

		delete pp;

		pp = ppintIndex(indexField);

	}

}

void doubleDelete(PinkPurpleTree<double>* pp, double field, int indexField) {

	Node<double>* s = pp->search(field);
	LinkedList<string>* l = &(s->location);
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	string location = "";
	int counter = 0;
	int initialSize = l->getSize();

	for (int i = 0; i < initialSize; i++) {

		s = pp->search(field);
		l = l = &(s->location);
		lol = l->getHead();
		location = lol->getData();

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);
		int tempLineNumber = 0;

		cout << filename << " " << lineNum << endl;

		temp = "";

		ifstream fin(filename);
		ofstream fout("Dataset/tempfile.csv");

		while (getline(fin, temp)) {

			if (tempLineNumber == (lineNum - 1)) {


			}

			else {

				fout << temp << endl;

			}

			tempLineNumber++;;

		}

		fin.close();
		fout.close();

		char* arr = new char[filename.length() + 1];

		for (int i = 0; i < filename.length(); i++)
			arr[i] = filename[i];

		arr[filename.length()] = '\0';

		remove(arr);
		int result = rename("Dataset/tempfile.csv", arr);

		//if (result == 0) {

		//	cout << "yep";

		//}

		counter++;
		cout << counter;

		delete pp;

		pp = ppdoubleIndex(indexField);

	}

}

void stringDelete(PinkPurpleTree<string>* pp, string field, int indexField) {

	Node<string>* s = pp->search(field);
	LinkedList<string>* l = &(s->location);
	LNode<string>* lol = l->getHead();
	int countedStuff = 0;
	string filename = "";
	int lineNum = 0;
	string data = "";
	string temp = "";
	string location = "";
	int counter = 0;
	int initialSize = l->getSize();

	for (int i = 0; i < initialSize; i++) {

		s = pp->search(field);
		l = l = &(s->location);
		lol = l->getHead();
		location = lol->getData();

		countedStuff = 0;

		for (int j = 0; j < location.length(); j++) {

			if (location[j] != ',') {

				temp += location[j];

			}

			else {

				if (countedStuff == 0) {

					filename = temp;
					temp = "";
					countedStuff++;

				}

			}

		}

		lineNum = stoi(temp);
		int tempLineNumber = 0;

		cout << filename << " " << lineNum << endl;

		temp = "";

		ifstream fin(filename);
		ofstream fout("Dataset/tempfile.csv");

		while (getline(fin, temp)) {

			if (tempLineNumber == (lineNum - 1)) {


			}

			else {

				fout << temp << endl;

			}

			tempLineNumber++;;

		}

		fin.close();
		fout.close();

		char* arr = new char[filename.length() + 1];

		for (int i = 0; i < filename.length(); i++)
			arr[i] = filename[i];

		arr[filename.length()] = '\0';

		remove(arr);
		int result = rename("Dataset/tempfile.csv", arr);

		//if (result == 0) {

		//	cout << "yep";

		//}

		counter++;
		cout << counter;

		delete pp;

		pp = ppstringIndex(indexField);

	}

}