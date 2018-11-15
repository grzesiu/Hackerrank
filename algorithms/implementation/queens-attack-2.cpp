#include <iostream>
using namespace std;

int main()
{
    int n, k, rq, cq, ri, ci;

    cin >> n >> k >> rq >> cq;

    int d[] = {min(rq, cq) - 1, rq - 1, min(rq - 1, n - cq),
        cq - 1, 0, n - cq,
        min(n - rq, cq - 1), n - rq, n - max(rq, cq)};

    for(int i = 0; i < k; i++)
    {
        cin >> ri >> ci;
        
        if(rq - ri == cq - ci)
        {
            if(rq - ri > 0)
            {
                if(rq - ri - 1 < d[0])
                    d[0] = rq - ri - 1;
            }
            else
            {
                if(ri - rq - 1 < d[8])
                    d[8] = ri - rq - 1;
            }
        }
        else if(cq == ci)
        {
            if(rq - ri > 0)
            {
                if(rq - ri - 1 < d[1])
                    d[1] = rq - ri - 1;
            }
            else
            {
                if(ri - rq - 1 < d[7])
                    d[7] = ri - rq - 1;
            }
        }
        else if(rq - ri == ci - cq)
        {
            if(rq - ri > 0)
            {
                if(rq - ri - 1 < d[2])
                    d[2] = rq - ri - 1;
            }
            else
            {
                if(ri - rq - 1 < d[6])
                    d[6] = ri - rq - 1;
            }
        }
        else if(rq == ri)
        {
            if(cq - ci > 0)
            {
                if(cq - ci - 1 < d[3])
                    d[3] = cq - ci - 1;
            }
            else
            {
                if(ci - cq - 1 < d[5])
                    d[5] = ci - cq - 1;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 9; i++)
        sum += d[i];

    cout << sum << endl;


    return 0;
}
