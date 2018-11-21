#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

struct node {
    int count = 1;
    unordered_map<char, shared_ptr<node>> children;

    bool has(char c) {
        return children.count(c) == 1;
    }
};


void add(shared_ptr<node> root, string s) {
    shared_ptr<node> curr = root;
    for (const char &c : s) {
        if (curr->has(c)) {
            curr = curr->children.at(c);
            ++curr->count;
        } else {
            curr->children[c] = make_shared<node>();
            curr = curr->children.at(c);
        }
    }
}

int find(shared_ptr<node> root, string s) {
    shared_ptr<node> curr = root;
    for (const char &c : s) {
        if (curr->has(c)) {
            curr = curr->children.at(c);
        } else {
            return 0;
        }
    }
    return curr->count;
}

int main() {
    int n;
    string operation, s;
    shared_ptr<node> root = make_shared<node>();
    cin >> n;
    while (n--) {
        cin >> operation >> s;
        if (operation == "add") {
            add(root, s);
        } else {
            cout << find(root, s) << endl;
        }
    }
    return 0;
}
