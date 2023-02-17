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
    unordered_map<string, int> m;
    
    string word;
    while (cin >> word) {
        m[word]++;
    }
    
    set<string> s;
    for (auto current : m) {
        if (current.second == 1) {
            s.insert(current.first);
        }
    }
    
    
    for (auto current : s) {
        cout << current << '\n';
    }
    
    return 0;
}
