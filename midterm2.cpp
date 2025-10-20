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
        cout << "   " << customer << " joins the line" << endl;
        line.push_back(customer);
    }

    cout << "Resulting line: " << endl;
    line.print();
    cout << endl;

    auto maybeServeFront = [&] (DoublyLinkedList& line) {
        //roll RNG 1-100
        int prob = rand() % 100 + 1;
        //40% RNG
        if (prob <= 40) {
            string served = line.peek_front();
            if (!served.empty()) {
                cout<< "    " << served << " is served." << endl;
                line.pop_front();
            }
        }
    };

    auto maybeNewCustomer = [&] (DoublyLinkedList& line) {
        int prob = rand() % 100 + 1;
        if (prob <= 60) {
            string name = getRandomName(names);
            cout << "   " << name << " joins the line." << endl;
            line.push_back(name);
        }
    };



    for (int t = 2; t <= 20; ++t) {
        cout << "Time step #" << t << ":" << endl;
        maybeServeFront(line);
        cout << "Resulting line:" << endl;
        line.print();
        cout << endl;
    }

    return 0;
}