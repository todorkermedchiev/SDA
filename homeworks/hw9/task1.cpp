#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main() {
    unordered_map<string, set<string>> m;

    int queriesCount;
    cin >> queriesCount;

    string currentFolder = "/";

    string query;
    for (int i = 0; i < queriesCount; ++i) {
        cin >> query;

        if (query == "mkdir") {
            string name;
            cin >> name;

            if (m[currentFolder].count(name) == 0) {
                m[currentFolder].insert(name);
            }
            else {
                cout << "Directory already exists\n";
            }
        }
        else if (query == "cd") {
            string name;
            cin >> name;

            if (name == "..") {
                if (currentFolder == "/") {
                    cout << "No such directory\n";
                }
                else {
                    do {
                        currentFolder.pop_back();
                    }
                    while (currentFolder.back() != '/');
                }
            }
            else {
                if (m[currentFolder].count(name) == 1) {
                    currentFolder += name + "/";
                }
                else {
                    cout << "No such directory\n";
                }
            }
        }
        else if (query == "ls") {
            set<string> toPrint = m[currentFolder];
            for (auto it = toPrint.begin(); it != toPrint.end(); it++) {
                cout << *it << ' ';
            }
            cout << '\n';
        }
        else if (query == "pwd") {
            cout << currentFolder << '\n';
        }
    }


    return 0;
}