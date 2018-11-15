#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Cracker {
    private:
        const vector<string>& pass;
        const string& attempt;
        vector<int> visited_by;
    
        void crack_(int pos) {
            for (int i = 0; i < pass.size(); i++) {
                string s = pass[i];
                if (pos + s.length() <= attempt.length() &&
                        visited_by[pos + s.length() - 1] == -1 &&
                        attempt.substr(pos, s.length()) == s) {
                    visited_by[pos + s.length() - 1] = i;
                    crack_(pos + s.length());
                }
            }
        }

    public:
        Cracker(const vector<string>& pass, const string& attempt) : pass(pass), attempt(attempt) {
            visited_by.resize(attempt.length(), -1);
        }

        list<string> crack() {
            crack_(0);
            cout << flush;
            int i = visited_by.size() - 1;
            if (visited_by[i] == -1) {
                return {"WRONG", "PASSWORD"};
            } else {
                list<string> cracked;
                while (i > 0) {
                    string p = pass[visited_by[i]];
                    cracked.push_front(p);
                    i -= p.length();
                }
                return cracked;
            }
        }
};

int main() {
    int t, n;
    string attempt;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> pass(n);
        for (int i = 0; i < n; i++) {
            cin >> pass[i];
        }
        cin >> attempt;
        Cracker c(pass, attempt);
        list<string> cracked = c.crack();
        for (const auto &i : cracked) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

