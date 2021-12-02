#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string str, int left, int right) {
	while(left <= right) {
		if(str[left] == str[right]) {
			return isPalindrome(str, left+1, right-1);
		} else {
			cout << "false" << endl;
			return false;
		}
	}
	cout << "true" << endl;
	return true;
}

int main() {
    string str = "was it a cat i saw";

	//erase spaces
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

	int size = str.length();
	--size;

	cout << str << endl;

	cout << isPalindrome(str, 0, size) << endl;
	
    return 0;
}