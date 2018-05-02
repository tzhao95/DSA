// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2018

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  unsigned int val1;
  unsigned int val2;
  char val3;
  string val4;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->val1 >> pData->val2 >> pData->val3 >> pData->val4;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->val1 << " " 
	   << (*ipD)->val2 << " " 
	   << (*ipD)->val3 << " " 
	   << (*ipD)->val4 << endl;
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &, int field);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.  Executing sort..." << endl;

  int field = 0;
  cout << "Enter an integer from 1 - 4, representing field to sort: ";
  try {
    cin >> field;
    if (field < 1 || field > 4) {
      cerr << "Error: invalid field" << endl;
      exit(1);
    }
  }
  catch (...) {
    cerr << "Error: invalid field" << endl;
    exit(1);
  }
    
  clock_t t1 = clock();
  sortDataList(theList, field);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

//function to take everything in inputfile and put into array for sorting

//counter[126] = {0};
/*
void countSort(int arr[], int n, int exp) {
  int i
  for(i = 0; i < n; i++) {
    counter[arr[i]]++;
    //each index is an linked list. last link will now point to what was just checked
  }
}



int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void radixSort(unsigned *begin, unsigned *end) {
  unsigned *begin1 = new unsigned[end - begin];
  unsigned *end1 = begin1 + (end - begin);
  for(unsigned shift = 0; shift < 32; shift += 8) {
    size_t count[0x100] = {};
    for (unsigned *p = begin; p != end; p++) {
      count[(*p >> shift) & 0xFF]++;
    }
    unsigned *bucket[0x100], *q = begin1;
    for(int i = 0; i < 0x100; q += count[i++])
      bucket[i] = q;
    for(unsigned *p = begin; p != end; p++) 
      *bucket[(*p >> shift) & 0xFF]++ = *p;
    swap(begin, begin1);
    swap(end, end1);
  }
}

void insertionSort(list<Data *> &l, int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key; 
  }
}
*/
#include <array>

array<list<Data *>, 126> counter;

void countSort(list<Data *> &l, int n) {
  unsigned int i = 0;
  for (list<Data *>::iterator it = l.begin(); it != l.end(); i++) {
    counter[int((*it)->val3)].push_back(*it)
  }
  l.clear();
  for(i = 0; i < 126; i++) {
    for(list<Data *>::iterator it2 = counter[i].begin(); it2 != counter[i].end(); i++) {
      l.push_back(*it2);
    }
  }
}
/*
void insertionSort(list<Data *> &l, int n) {
  int i, key, j;
  for (list<Data *>::iterator i = l.begin(); i != l.end(); i++) {
    key = (*i).val1;
    j = i - 1;
    while ( j >= 0 && (*j).val1 > key) {

    }
  }
}
*/
bool myLessthen1(Data *pd1, Data *pd2) {
  if ((pd1->val1) < (pd2->val1)) {
    return true;
  }
  else {
    return false;
  }
}

bool myLessthen2(Data *pd1, Data *pd2) {
  if ((pd1->val2) < (pd2->val2)) {
    return true;
  }
  else {
    return false;
  }
}

bool myLessthen3(Data *pd1, Data *pd2) {
  if (int((pd1->val3)) < int((pd2->val3))) {
    return true;
  }
  else {
    return false;
  }
}

bool myLessthen4(Data *pd1, Data *pd2) {
  unsigned int i = 0;
  while((i < (pd1->val4).length()) && (i < (pd2->val4).length())) {
    if (int((pd1->val4)[i]) < int((pd2->val4)[i])) {
      return true;
    }
    else if (int((pd1->val4)[i]) > int((pd2->val4)[i])) {
      return false;
    }
    i++;
  }
  return ((pd1->val4).length() < (pd2->val4).length());
}
/*
bool myLessthen42(Data *pd1, Data*pd2) {
  //unsigned int i = 0;
  if (strncmp(pd1->val4, pd2->val4) < 0) {
    return true;
  }
  else if (strncmp(&(pd1->val4), &(pd2->val4)) > 0) {
    return false;
  }
}
*/
void sortDataList(list<Data *> &l, int field) {
  // Fill in this function
  if (field == 1) {
    l.sort(myLessthen1);
  }
  if(field == 2) {
    l.sort(myLessthen2);
  }
  if(field == 3) {
    l.sort(countSort);
  }
  if(field == 4) {
    l.sort(myLessthen4);
  }
}
