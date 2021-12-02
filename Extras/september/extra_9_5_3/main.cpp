#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
  Stack<int> s;
  cout << boolalpha; // formats output

  s.pop();


  cout << s.empty() << endl; // true
  s.push(2);
  cout << s.peek() << endl; // 2
  s.push(5);
  cout << s.peek() << endl; // 5
  cout << s.empty() << endl; // false
  s.pop();
  cout << s.peek() << endl; // 2
  s.pop();
  cout << s.empty() << endl; // true
}