#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int q;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        map<vector<int>, int> descriptor_map;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                vector<int> descriptor(26, 0);
                for (int k = i; k < j; k++) {
                    descriptor[s[k] - 'a']++;
                }
                if (descriptor_map.count(descriptor) == 0) {
                    descriptor_map[descriptor] = 1;
                } else {
                    descriptor_map[descriptor]++;
                }
            }
        }
        int count = 0;
        for (auto& kv: descriptor_map) {
            count += kv.second * (kv.second - 1) / 2;
        }
        cout << count << endl;
    }
    return 0;
}
