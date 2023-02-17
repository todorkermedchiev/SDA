#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(char root, unordered_map<char, vector<char>> &adjacencyList, unordered_set<char> &visited, vector<char> &result) {
    if (visited.find(root) != visited.end()) {
        return;
    }

    visited.insert(root);
    for (int i = 0; i < adjacencyList[root].size(); ++i) {
        dfs(adjacencyList[root][i], adjacencyList, visited, result);
    }

    result.push_back(root);
}

vector<char> topologiacalSort(unordered_map<char, vector<char>> &adjacencyList, unordered_set<char> &visited) {
    vector<char> result;

    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        dfs(it->first, adjacencyList, visited, result);
    }

    return result;
}

int main() {
    int wordsCount;
    cin >> wordsCount;
    
    unordered_map<char, vector<char>> adjacencyList;
    
    string first, second;
    cin >> first;
    for (int i = 0; i < wordsCount - 1; ++i) {
        cin >> second;
        for (int j = 0; j < first.length() && j < second.length(); ++j) {
            if (first[j] != second[j]) {
                adjacencyList[first[j]].push_back(second[j]);
                break;
            }
        }
        
        first = second;
    }

    unordered_set<char> visited;
    vector<char> result = topologiacalSort(adjacencyList, visited);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}