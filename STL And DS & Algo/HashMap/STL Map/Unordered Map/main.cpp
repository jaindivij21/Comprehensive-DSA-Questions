// C++ program to illustrate the unordered_map :: hash_function()
// All these methods use the same syntax under Map. The only difference is that they use binary trees as their underlying structure!

#include <bits/stdc++.h>

using namespace std;

int main() {

    // declaration
    unordered_map<string, int> sample;

    // inserts key and value pairs
    sample.insert({"Ankit", 1});
    sample.insert(make_pair("Divij", 2));
    sample["Rohan"] = 3;

    // use of hash_function
    unordered_map<string, string>::hasher fn = sample.hash_function();
    cout << fn("Divij") << endl;

    // Finding
    // If key not found in map iterator to end is returned
    string key = "Divij";
    if (sample.find(key) == sample.end())
        cout << key << " not found\n\n";
    else
        // If key found then iterator to that key is returned
        cout << "Found " << key << "\n\n";

    // Count Method :: Used to check if the key is present or not
    if (sample.count("Divij") == 1) {
        // returns 1 if the key is found and 0 if not
        cout << "Divij found" << endl;
    }

    // Erasing
    sample.erase("Divij");

    // Accessing (IMPORTANT)
    cout << sample.at("Divij") << endl; // If not found they key raises exception otherwise displays the value
    // however, if you use this following statement, if they key isn't found it creates that key value pair automatically
    cout << sample["Divij"];    // So try not to use this, rather use .at()


    // print the key and elements
    // Traversing an unordered map
    for (auto x : sample)
        cout << x.first << " " << x.second << endl;
    cout << "Key and Elements: ";
    for (auto it = sample.begin(); it != sample.end(); it++) {
        cout << "\n{" << it->first << ":"
             << it->second << "}, ";
    }
    return 0;
}
