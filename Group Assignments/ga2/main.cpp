#include <iostream>
#include <fstream>

#include "ArgumentManager.h"
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

bool ValidateEquation(string eq) {
	bool isValid = true;

	Stack<string>* symbolStack = new Stack<string>();

	for (int i = 0; i < eq.length(); i++) {
		string c = eq.substr(i, 1);

		if (c == "(" || c == "[" || c == "{") {

			symbolStack->Push(c);
		}
		else if (c == ")") {
			if (symbolStack->Peek()->data != "(") {
				isValid = false;
			}
			else {
				symbolStack->Pop();
			}
		}
		else if (c == "]") {
			if (symbolStack->Peek()->data != "[") {
				isValid = false;
			}
			else {
				symbolStack->Pop();
			}
		}
		else if (c == "}") {
			if (symbolStack->Peek()->data != "{") {
				isValid = false;
			}
			else {
				symbolStack->Pop();
			}
		}
	}

	if (!symbolStack->Empty()) {
		isValid = false;
	}

	return isValid;
}

string ToPostFix(string eq) {
	string postEq = "";

	Stack<string>* operatorStack = new Stack<string>();

	for (int i = 0; i < eq.length(); i++) {
		string c = eq.substr(i, 1);

		if (isalnum(c.at(0))) {
			postEq += c;
			continue;
		}

		if (c == "(") {
			operatorStack->Push(c);
		}
		else if (c == ")") {
			while (!operatorStack->Empty() && operatorStack->Peek()->data != "(") {
				postEq += operatorStack->Pop()->data;
			}
			operatorStack->Pop();
		}
		else if (c == "+" || c == "-") {
			if (i - 1 != -1 && eq.at(i - 1) == '(') {
				postEq += "0";
			}
			while (!operatorStack->Empty() && operatorStack->Peek()->data != "(") {
				postEq += operatorStack->Pop()->data;
			}
			operatorStack->Push(c);
		}
	}

	while (!operatorStack->Empty()) {
		if (operatorStack->Peek()->data != "(") {
			postEq += operatorStack->Pop()->data;
		}
		else {
			operatorStack->Pop();
		}
	}

	return postEq;
}

string GroupingSymbolConversion(string eq) {
	string syms = "[]{}";

	for (int i = 0; i < 4; i++) {
		while (eq.find(syms[i]) != string::npos) {
			if (i % 2 == 0) {
				eq.replace(eq.find(syms[i]), 1, "(");
			}
			else {
				eq.replace(eq.find(syms[i]), 1, ")");
			}
		}
	}

	return eq;
}

bool ParseInput(const string filePath, const string outFilePath, LinkedList<string>* list) {
	ifstream file(filePath);
	ofstream outFile(outFilePath);

	string line = "";

	bool allValid = true;
	int equationCount = 0;
	while (getline(file, line)) {
		if (line.empty()) {
			continue;
		}
		equationCount++;

		if (!ValidateEquation(line)) {
			outFile << "Error at: " << equationCount << endl;
			allValid = false;
		}
		else {
			line = GroupingSymbolConversion(line);
			string post = ToPostFix(line);
			list->Add(post);
		}
	}

	outFile.flush();
	outFile.close();

	return allValid;
}

int PostFixEval(string eq) {
	Stack<int>* operandStack = new Stack<int>();

	for (int i = 0; i < eq.length(); i++) {
		string s = eq.substr(i, 1);

		if (isdigit(s.at(0))) {
			operandStack->Push(stoi(s));
		}
		else if (isalpha(s.at(0))) {
			operandStack->Push(s.at(0));
		}
		else if (s == "+") {
			int a, b;
			if (operandStack->Empty()) {
				a = 0;
			}
			else {
				a = operandStack->Pop()->data;
			}

			if (operandStack->Empty()) {
				b = 0;
			}
			else {
				b = operandStack->Pop()->data;
			}

			operandStack->Push(a + b);
		}
		else if (s == "-") {
			int a, b;
			if (operandStack->Empty()) {
				a = 0;
			}
			else {
				a = operandStack->Pop()->data;
			}

			if (operandStack->Empty()) {
				b = 0;
			}
			else {
				b = operandStack->Pop()->data;
			}

			operandStack->Push(b - a);
		}
	}

	return operandStack->Pop()->data;
}

int main(int argc, char* argv []) {
	ArgumentManager am(argc, argv);

	LinkedList<string>* list = new LinkedList<string>();
	LinkedList<int>* values = new LinkedList<int>();

	string outputFilePath = am.get("output");

	if (!ParseInput(am.get("input"), outputFilePath, list)) {
		return 1;
	}

	Node<string>* current = list->GetHead();
	while (current != nullptr) {
		int eqVal = PostFixEval(current->data);
		values->Add(eqVal);
		current = current->next;
	}

	int headVal = values->GetHead()->data;
	Node<int>* curr = values->GetHead()->next;
	while (curr->next != nullptr && headVal == curr->data) {
		curr = curr->next;
	}

	ofstream outFile(outputFilePath);
	if (headVal == curr->data) {
		outFile << "Yes" << endl;
	}
	else {
		outFile << "No" << endl;
	}

	return 0;
}