#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> occurances('z' + 1, 0);
    map<int, int> freqs;
    map<int, int>::iterator it;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        occurances[s[i]]++;
    }


    for(int i = 'a'; i <= 'z'; i++)
    {
        if(occurances[i] != 0)
        {
            it = freqs.find(occurances[i]);
            if(it == freqs.end())
                freqs[occurances[i]] = 1;
            else
                freqs[occurances[i]]++;
        }
    }

    if(freqs.size() == 1)
    {
        cout << "YES";
    }
    else if(freqs.size() == 2)
    {
        it = freqs.begin();
        if(it->first == 1 && it->second == 1)
            cout << "YES";

        else if(next(it)->second == 1 && next(it)->first == it->first + 1)
            cout << "YES";
        else 
            cout << "NO";
    }
    else
    {
        cout << "NO";
    }

    cout << endl;


    return 0;
}
