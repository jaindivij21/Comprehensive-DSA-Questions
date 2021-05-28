// TRIE DATA STRUCTURE :: PREFIX TREE
// Tree like information retrieval data structure
// Time Complexity is  O(N) where n is the length of the word. Tries are generally used to store strings

#include<iostream>
#include<unordered_map>

using namespace std;

// class for the node that makes up the trie
class node {
public:
    // we require a hashmap because we aren't certain as to how many nodes can start from a particular node
    // so it stores the characters of string and address to the it's node
    char data;
    unordered_map<char, node *> h;
    bool isTerminal;

    node(char d) {
        data = d;
        isTerminal = false;
    }
};

// trie class
class trie {
    node *root;
public:
    trie() {
        // when you initialize a root, make a node with data /0
        root = new node('/0');
    }

    // insertion into the trie
    void addWord(const char *word) {
        // parameter is a string or array of char; so given its starting address
        node *temp = root;

        // iterate through the word
        for (int i = 0; word[i] != '\0'; i++) {
            char ch = word[i];
            if (temp->h.count(ch) == 0) {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            } else {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }

    // Lookup
    bool search(const char *word) {
        // the node temp points to the initial root of the tree
        node *temp = root;

        // start looking forthe char of the words in the tree and at last check if the last char is a terminal node
        for (int i = 0; word[i] != '\0'; i++) {
            char ch = word[i];
            if (temp->h.count(ch) == 1) {
                // if the temp's hash map has the address of the words character
                temp = temp->h[ch];
            } else {
                // if at any point of time the address of the word isn't found means the word doesn't exist
                return false;
            }
        }
        // after the loop is exited we need to make sure that the the node we are on is terminal
        if (temp->isTerminal) {
            return true;
        } else {
            return false;
        }
    }
};


int main() {
    // array of words
    char word[10][100] = {"apple", "ape", "code", "coding blocks", "no", "divij"};
    trie t;

    // insert these words into trie
    for (auto & i : word) {
        t.addWord(i);
    }

    // search for a word
    char str[100];
    cin.getline(str, 100);

    if (t.search(str)) {
        cout << "The word " << str << " was found" << endl;
    } else {
        cout << "The word wasn't found" << endl;
    }


    return 0;
}
