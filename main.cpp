#include <iostream>
#include <string>

#include "header.h"

using namespace std;

int main() {
  BSTMap<int, string> bst;

  cout << "bst before using get_or_insert():" << endl;
  bst.print();
  cout << endl;

  bst.get_or_insert(11) = "eleven";
  bst.get_or_insert(55) = "fifty five";
  bst.get_or_insert(99) = "ninety nine";

  cout << "bst before using get_or_insert() in a loop:" << endl;
  bst.print();
  cout << endl;

  for (const int x : {0, 11, 33, 55, 88, 99, 1000}) {
    cout << "bst.get_or_insert(" << x << ") == \"" << bst.get_or_insert(x) << '\"'<< endl;
  }
  cout << endl;

  cout << "bst after using get_or_insert() in a loop:" << endl;
  bst.print();

  return 0;
}