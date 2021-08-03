// Leetcode: Employee Importance
// https://leetcode.com/problems/employee-importance/

#include<bits/stdc++.h>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

void dfs(vector<Employee *> &employees, int &ans, unordered_map<int, int> &index, int src) {
    // base case
    if (employees[src]->subordinates.empty()) {
        ans += employees[src]->importance;  // IMPORTANT -> need to add for the leaf nodes as well
        return;
    }
    // recursive cases
    ans += employees[src]->importance;

    // calls
    for (auto i : employees[src]->subordinates) {
        dfs(employees, ans, index, index[i]);
    }
}

int getImportance(vector<Employee *> employees, int id) {
    // get to the id and then just traverse over all the subordinates while adding the sum
    unordered_map<int, int> index;  // maps index with id
    for (int i = 0; i < employees.size(); i++) {
        index.insert(make_pair(employees[i]->id, i));
    }
    // apply DFS
    int ans = 0;
    dfs(employees, ans, index, index[id]);
    return ans;
}

int main() {
    vector<Employee *> e(3);
    Employee e1;
    Employee e2;
    Employee e3;
    e1.id = 1;
    e1.importance = 5;
    e1.subordinates = {2, 3};
    e2.id = 2;
    e2.importance = 3;
    e2.subordinates = {};
    e3.id = 3;
    e3.importance = 3;
    e3.subordinates = {};
    e[0] = &e1;
    e[1] = &e2;
    e[2] = &e3;
    cout << getImportance(e, 1);

    return 0;
}