#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <string>
#include "SimpleList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

template <typename T>
SimpleList<T>* searchSimpleList(string name, list<SimpleList<T> *> &li) {
	for (typename list<SimpleList<T> *>::iterator ci = li.begin(); ci != li.end(); ++ci) {
		string listName = (*ci)->getName();
		if(listName == name) {
			return *ci;
		}
	}
	return NULL;
};

template <typename T>
void addToList(list<SimpleList<T> *> &li, string name, string listType, T dummyValue, ofstream &output) {
	SimpleList<T> *found = searchSimpleLIst(name, li);
	if(found) {
		output << "ERROR: This name already exists!" << endl;
	} 
	else {
		SimpleList<T> *pSL;
		if(listType == "queue") {
			pSL = new Queue<T>(name, dummyValue);
		}
		else {
			pSL = new Stack<T>(name, dummyValue);
		}
		li.push_front(pSL);
	}
};

template <typename T>
void popValue(list<SimpleList<T> *> &li, string name, ofstream &output) {
	SimpleList<T> *found = searchSimpleList(name, li);
	if(found) {
		if(found->empty()) {
			output << "ERROR: This list is empty!" << endl;
		}
		else {
			output << "Value popped: " << found->pop() << endl;
		}
	}
	else {
		output << "ERROR: This name does not exist!" << endl;
	}
};

int main() {
	string inputFile;
	string outputFile;
	cout << "Enter name of input file: ";
	cin >> inputFile;

	cout << "Enter name of output file: ";
	cin >> outputFile;

	list<SimpleList<int> *> listSli;
	list<SimpleList<double> *> listSLd;
	list<SimpleList<string> *> listSLs;

	ifstream input (inputFile.c_str());
	string line;

	ofstream output (outputFile.c_str());
	if(input.is_open()) {
		while(getline(input, line)) {
			output << "PROCESSING COMMAND: " << line << endl;
			int split1 = line.find_first_of(" ");
			int pslit2 = line.find_last_of(" ");

			char classType = line.as(split1 + 1);

			if (split1 == split2) {
				string name = line.substr(split1 + 2);
				if(classType == 'i') {
					popValue(listSLi, name, output);
				}
				else if(classType == 'd') {
					popValue(listSLd, name, output);
				}
				else {
					popValue(listSLs, name, output);
				}
			}
			else if(line.at(0) == 'c') {
				string name = line.substr(split1 + 2, split2 - (split1 + 2));
				string listType = line.substr(split2 + 1);
				if(classType == 'i') {
					addToList(listSLi, name, listType, 0, output);
				}
				else if(classType == 'd') {
					addToList(listSLd, namype, 0.0, output);
				}
				else {
					string dummy = "0";
					addToList(listSLs, name, listType, dummy, output);
				}
			}
			else {
				string name = line.substr(split1 + 2, split2 - (split1 + 2));
				string listType = line.substr(split2 + 1);
				if(classType == 'i') {
					pushValue(listSLi, name, atoi(value.c_str()), output);
				}
				else if(classType == 'd') {
					pushValue(listSLd, name, atof(value.c_str()), output);
				}
				else {
					pushValue(listSLs, name, value, output);
				}
			}
		}
		input.close();
		output.close();
	}
	else {
		cout <<"Failed to open file." << endl;
	}
	input.close();
	output.close();
};