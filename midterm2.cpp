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

int main() {
    srand(time(0)); //seeds RNG

    vector<string> names = loadNames("names.txt");

    cout << "Total Names: " << names.size() << endl;
    cout << "Test name: " << names[rand() % names.size()] << endl;

    return 0;
}