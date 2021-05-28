// Greedy Algorithm :: Data Compression using huffman coding

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>


using namespace std;

// tree's node class to be used for the tree structure
class node {
public:
    char data;
    int freq;
    node *left;
    node *right;

    // construcotr
    node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};

// comparator function for the min heap :: make sure the heap' top is minimum element :: its a class object-> min heap's third parameter
class compare {
public:
    bool operator()(node *n1, node *n2) {
        return n1->freq > n2->freq;
    }
};

// function that cal and returns char and their freq using hashmap from a string
unordered_map<char, int> calFreq(char s[]) {
    unordered_map<char, int> freq;
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq.count(s[i]) == 0) {
            freq.insert(make_pair(s[i], 1));
        } else {
            freq[s[i]]++;
        }
    }
    return freq;
}

// function that builds a tree of class nodes given a heap made up of class nodes such that all the char are lead nodes. Basically makes the huffamn algo tree (optimal merge pattern)
node *buildTree(priority_queue<node *, vector<node *>, compare> heap) {
    node *top;
    // until the heap has only one element
    while (heap.size() != 1) {
        // extract the top 2 elements of the heap means the least 2 elements of the heap
        node *left = heap.top();
        heap.pop();
        node *right = heap.top();
        heap.pop();

        // make a top node that contains the sum of the both nodes and points to left and right node as children
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // push the info of top node into the heap
        heap.push(top);
    }
    return top;
}

// funciton to assign codes to all the chars of the string based upon the tree pattern. make all left edges 0 and right as 1. Then cal the variable codes.
void assignCodes(node *root, unordered_map<char, string> &ans, string temp) {
    // this function returns a hash map with each char and its variable hash code
    // recursive function

    // base case
    if (root == nullptr) {
        return;
    }
    // recursive cases -> Preorder type
    if (root->data != '$') {
        ans.insert(make_pair(root->data, temp));
    }
    // recur cases
    assignCodes(root->left, ans, temp + "0");
    assignCodes(root->right, ans, temp + "1");
}


// MAIN FUNCTION
unordered_map<char, string> huffmanCodes(char s[]) {
    // hashmap to store the frequency of the char in the string
    unordered_map<char, int> freq = calFreq(s);

    // insert elements of this hashmap into a min heap :: where each node stores both the char and its frequency
    priority_queue<node *, vector<node *>, compare> minHeap;
    for (auto itr : freq) {
        node *temp = new node(itr.first, itr.second);
        minHeap.push(temp);
    }
    // delete freq hash map
    freq.clear();

    // now we need to build the tree as we do in huffman coding algorithm i.e pop the 2 min freq, add them and make a node
    node *root = buildTree(minHeap);
    // now the tree has been formed and root contains the address to the tree. The heaps top element is also root!

    // now we need to mark the left edges as 0 and right as 1 and accordingly assign each char a variable code
    unordered_map<char, string> variableCodes;
    assignCodes(root, variableCodes, "");   // pass in the empty string


    // RESULT
    // convert the string into the variable bits
    for (int i = 0; s[i] != '\0'; i++) {
        cout << variableCodes[s[i]];
    }

    // return the codes as well
    return variableCodes;
}

int main() {
    // Strings entered
    cout << "Enter the string to be compressed" << endl;
    char str[100];
    cin >> str;

    // Result i.e. compressied strings in bit format already printed in this function, it also returns the codes
    unordered_map<char, string> codes = huffmanCodes(str);

    // print the variable codes
    cout << endl;
    cout << "The codes are:" << endl;
    for (auto itr:codes) {
        cout << itr.first << ":" << itr.second << endl;
    }

    return 0;
}