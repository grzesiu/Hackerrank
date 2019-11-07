#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    unordered_map<int, int> counts, freqs;
    scanf("%d", &t);
    while (t--) {
        int query, x;
        scanf("%d %d", &query, &x);
        switch (query) {
            case 1 : if (counts[x] > 0) {
                         freqs[counts[x]]--;
                     }
                     counts[x]++;
                     freqs[counts[x]]++;
                     break;
            case 2 : if (counts[x] > 0) {
                         freqs[counts[x]]--;
                         counts[x]--;
                         freqs[counts[x]]++;
                     }
                     break;
            case 3 : printf("%d\n", ((freqs[x] > 0) ? 1 : 0));
                     break;
        }
    }
    return 0;
}

