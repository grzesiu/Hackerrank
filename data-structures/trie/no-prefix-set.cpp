#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

struct node {
    bool last;
    unordered_map<char, shared_ptr<node>> children;

    node(bool last) : last(last) {}

    bool is_last() {
        return children.empty();
    }

    bool has(char c) {
        return children.count(c) == 1;
    }
};

int main() {
    int n;
    string s;
    shared_ptr<node> curr, root = make_shared<node>(false);
    cin >> n;
    while (n--) {
        cin >> s;
        curr = root;
        for (int i = 0; i < s.size(); ++i) {
            if (!curr->last) {
                if (curr->has(s[i])) {
                    if (i != s.size() - 1) {
                        curr = curr->children.at(s[i]);
                        continue;
                    }
                } else {
                    curr->children[s[i]] = make_shared<node>(i == s.size() - 1);
                    curr = curr->children.at(s[i]);
                    continue;
                }
            }
            cout << "BAD SET" << endl << s << endl;
            return 0;
        }
    }
    cout << "GOOD SET" << endl;
    return 0;
}
