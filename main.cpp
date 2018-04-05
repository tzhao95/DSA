//Tony Zhao
//DSA Programming Project 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <string>
#include "SimpleList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

//Searches for a SimpleList of name and returns it. If not found NULL is returned
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

//Adds a SimpleLIst to list of lists if it does not exist.
template <typename T>
void addList(list<SimpleList<T> *> &li, string name, string listType, T dummyValue, ofstream &output) {
	SimpleList<T> *found = searchSimpleList(name, li);
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

//Pushes the "value" into SimpleList of "name" if possible. Prints ERROR message otherwise.
template <typename T>
void pushValue(list<SimpleList<T> *> &li, string name, T value, ofstream &output) {
	SimpleList<T> *found = searchSimpleList(name, li);
	if(found) {
		found->push(value);
	}
	else {
		output << "ERROR: This name does not exist!" << endl;
	}
};

//Pops the top value of SimpleList "name" and prints it if possible. Prints ERROR if list is empty or DNE.
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

//Main function takes asks for input and output file names. Executes commands in the input file.
//Writes the performed task into output file or error.
int main() {
	string inputFile;
	string outputFile;
	cout << "Enter name of input file: ";
	cin >> inputFile;

	cout << "Enter name of output file: ";
	cin >> outputFile;

	list<SimpleList<int> *> listSLi;	//all integer stacks and queues
	list<SimpleList<double> *> listSLd;	//all double stacks and queues
	list<SimpleList<string> *> listSLs;	//all string stacks and queues

	ifstream input (inputFile.c_str());
	string line;

	ofstream output (outputFile.c_str());
	if(input.is_open()) {
		while(getline(input, line)) {
			output << "PROCESSING COMMAND: " << line << endl;
			//Parsing through input command to 'split' up the words
			int space1 = line.find_first_of(" ");
			int space2 = line.find_last_of(" ");

			char classType = line.at(space1 + 1);

			if (space1 == space2) { //checking for one split means Pop command
				string name = line.substr(space1 + 2);
				if(classType == 'i') { //check if list is integer list
					popValue(listSLi, name, output);
				}
				else if(classType == 'd') { //check if list is double list
					popValue(listSLd, name, output);
				}
				else { //list must be string list
					popValue(listSLs, name, output);
				}
			}
			else if(space1 == 6) { //space1 = 6 must be Create command
				string name = line.substr(space1 + 2, space2 - (space1 + 2));
				string listType = line.substr(space2 + 1);
				if(classType == 'i') { //check if list if integer list
					addList(listSLi, name, listType, 0, output);
				}
				else if(classType == 'd') { //check if list is double list
					addList(listSLd, name, listType, 0.0, output);
				}
				else { //list must be string list
					string dummy = "0";
					addList(listSLs, name, listType, dummy, output);
				}
			}
			else { //must be Push command
				string name = line.substr(space1 + 2, space2 - (space1 + 2));
				string value = line.substr(space2 + 1);
				if(classType == 'i') { //check if list is integer list
					pushValue(listSLi, name, atoi(value.c_str()), output);
				}
				else if(classType == 'd') { //check if list is double list
					pushValue(listSLd, name, atof(value.c_str()), output);
				}
				else { //list must be string list
					pushValue(listSLs, name, value, output);
				}
			}
		}
		input.close();
		output.close();
	}
	else { //Problem with input file
		cout <<"Error opening file." << endl;
	}
	input.close();
	output.close();
};