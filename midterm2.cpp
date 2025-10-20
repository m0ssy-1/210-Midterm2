#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> loadNames(const string& filename) {
    ifstream file(filename);
    vector<string> names;
    string name;
    while (getline(file, name)) {
        if (!name.empty())
        names.push_back(name);
    }
    return names;
}

string getRandomName(const vector<string>& names) {
    int index = rand() % names.size();
    return names[index];
}

int main() {
    srand(time(0)); //seeds RNG

    vector<string> names = loadNames("names.txt");

    DoublyLinkedList line;

    cout << "Store opens: " << endl;

    //add the 5 customers
    for (int i = 0; i < 5; ++i) {
        string customer = getRandomName(names);
        cout << customer << " something " << endl;
        line.push_back(customer);
    }

    cout << " something " << endl;
    line.print();

    return 0;
}