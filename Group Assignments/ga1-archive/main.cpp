#include <iostream>
#include <fstream>
#include <string>

#include "ArgumentManager.h"
#include "IDList.h"
#include "IDStack.h"

using namespace std;

// Put All ID's into a List
// Each ID Get Reversed with Stack
// List of Guilty & List of Innocents
// Sort the Lists
// Print the Lists

string FormatString(string str) {
	string output = "";

	for (int i = 0; i < str.length(); i++) {
		// infix to postfix
		// also removes '(' & ')'
		char c = str[i];

		if (c == '(') {
			int extraOpens = 0;
			int indexOfClose = -1;
			for (int j = i + 1; j < str.length(); j++) {
				if (str[j] == ')' && extraOpens == 0) {
					indexOfClose = j;
					break;
				}
				else if (str[j] == '(') {
					extraOpens++;
				}
				else if (str[j] == ')') {
					extraOpens--;
				}
			}
			int lengthBetweenParas = indexOfClose - i - 1;
			string toReverse = FormatString(str.substr(i + 1, lengthBetweenParas));

			for (int j = toReverse.length() - 1; j >= 0; j--) {
				output += toReverse[j];
			}
			str.replace(i, lengthBetweenParas + 2, "");
			i--;
		}
		else if (c != ')') {
			output += c;
		}
    }
	
    return output;
}

void ParseInput(IDStack* bar1, IDStack* bar2, const string filePath) {
	ifstream file(filePath);

	string line = "";

	bool isBar1Active = false;
	bool isBar2Active = false;
	while (getline(file, line)) {
		if (!line.empty()) {
			if (line == "Bar1") {
				isBar1Active = true;
				isBar2Active = false;
				continue;
			}
			else if (line == "Bar2") {
				isBar1Active = false;
				isBar2Active = true;
				continue;
			}

			if (isBar1Active) {
				bar1->Push(FormatString(line));
			}
			if (isBar2Active) {
				bar2->Push(FormatString(line));
			}
		}
	}


	file.close();
}

void PopulateLists(IDList* goodID, IDList* badID, IDStack* b1, IDStack* b2) {
	while (!b1->isEmpty()) {
		if (goodID->Contains(b1->Peek()->data) == -1) {
			goodID->Add(b1->Pop()->data);
		}
		else {
			goodID->Remove(goodID->Contains(b1->Peek()->data));
			badID->Add(b1->Pop()->data);
		}
	}
	// cout << endl;
	while (!b2->isEmpty()) {
		// cout << b2->Peek()->data << endl;
		if (goodID->Contains(b2->Peek()->data) == -1) {
			goodID->Add(b2->Pop()->data);
		}
		else {
			goodID->Remove(goodID->Contains(b2->Peek()->data));
			badID->Add(b2->Pop()->data);
		}
	}
}

string remZeros(string s) {
	//get size of string
	int slen = s.length();
	int i = 0;
	//keep looping while there are '0's
	//break when first index without '0' found
	while (s[i] == '0' && i < slen - 1) {
		i++;
	}
	//return temp string without leading '0's
	string temp = s.substr(i);

	return temp;
}

void swap(string* str1, string* str2) {
	//Keep record of original value of str1
	string tempStr;
	tempStr = *str1;
	*str1 = *str2;  //str1 value has been changed
	*str2 = tempStr;    //Fetch the original value of str1 and add to str2
}

void display(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

//take in the string arr and size of the string arr
void bubbleSort(string arr[], int n) {
	if (n <= 1)
		return;

	for (int i = 0; i < n - 1; i++) {
		//2 temp variables for comparing without having leading '0's
		string curStr = remZeros(arr[i]);
		string nextStr = remZeros(arr[i + 1]);

		//After removing leading '0's, if curStr larger than the nextStr, swap each other
		if (curStr.length() > nextStr.length()) {
			swap(&arr[i], &arr[i + 1]);
		}
		else if (curStr.length() == nextStr.length()) { //same length
			//get size of the strings
			int bothSize = curStr.length();
			int j = 0;
			//keep looping until first index j char reached that isn't equal to each other
			while (curStr[j] == nextStr[j] && j < bothSize - 1) {
				j++;
			}
			//set the chars of index j of each to string so stoi can be used
			string curChar(1, curStr[j]);
			string nextChar(1, nextStr[j]);

			//if int of curChar > int of nextChar -> swap each other
			if (stoi(curChar) > stoi(nextChar)) {
				swap(&arr[i], &arr[i + 1]);
			}
		}
	}

	bubbleSort(arr, n - 1);
}

IDList* ArrayToLL(string* arr, int size) {
	IDList* temp = new IDList();
	if (size == 0) {
		return temp;
	}

	for (int i = 0; i < size; i++) {
		temp->Add(arr[i]);
	}

	return temp;
}

void OutputLists(const string filePath, IDList* goodList, IDList* badList) {
	ofstream file(filePath);

	if (!badList->IsEmpty()) {
		file << "Guilty:\n" << badList->ToString();
	}
	if (!goodList->IsEmpty()) {
		file << "Innocent:\n" << goodList->ToString();
	}

	file.flush();
	file.close();
}

int main(int argc, char* argv[]) {
	ArgumentManager am(argc, argv);

	IDStack* bar1 = new IDStack();
	IDStack* bar2 = new IDStack();
	// ParseInput(bar1, bar2, am.get("input"));
    ParseInput(bar1, bar2, am.get("input"));

	IDList* innocentID = new IDList();
	IDList* guiltyID = new IDList();
	PopulateLists(innocentID, guiltyID, bar1, bar2);

	string* innocentArr = new string[innocentID->GetLength()];
	innocentID->makeArray(innocentArr);

	string* guiltyArr = new string[guiltyID->GetLength()];
	guiltyID->makeArray(guiltyArr);

	bubbleSort(innocentArr, innocentID->GetLength());
	bubbleSort(guiltyArr, guiltyID->GetLength());

    innocentID = ArrayToLL(innocentArr, innocentID->GetLength());
    guiltyID = ArrayToLL(guiltyArr, guiltyID->GetLength());

    // OutputLists(am.get("output"), innocentID, guiltyID);
    OutputLists(am.get("output"), innocentID, guiltyID);

	return 0;
}

// Steps (get string s):
// Remove leading zeros of 's'
// Return 's'

// Sort by string length

// Comparing s1, s2
// If there is two strings of same length
// Compare the first characters of the string
// Sort by the comparison