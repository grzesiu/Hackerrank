#include <climits>
#include <iostream>

using namespace std;

int main() {
    int min = INT_MAX, mini, first = -1, freqs[26];
    for (int i = 0; i < 26; i++) {
        cin >> freqs[i];
        if (freqs[i] != 0 && first == -1) {
            first = i;
        }
        if (freqs[i] < min && freqs[i] != 0) {
            min = freqs[i];
            mini = i;
        }
    }

    if (mini != first) {
        printf("%c", mini + 'a');
        freqs[mini]--;
        while (first < 26) {
            while (freqs[first]) {
                printf("%c", first + 'a');
                freqs[first]--;
            }
            first++;
        }
    } else {
        if (freqs[mini] == 1) {
            printf("%c", mini + 'a');
            freqs[mini]--;
        } else {
            printf("%c%c", mini + 'a', mini + 'a');
            freqs[mini] -= 2;
        }

        first++;
        while (first < 26) {
            if(freqs[first]) { 
                printf("%c", first + 'a');
                freqs[first]--;
                if(freqs[mini]) {
                    printf("%c", mini + 'a');
                    freqs[mini]--;
                }
            } else {
                first++;
            }
        }
        while (freqs[mini]) {
            printf("%c", mini + 'a');
            freqs[mini]--;
        }
    }
    return 0;
}
