#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, k, e;
    cin >> n >> k >> e;

    vector<bool> a(n, false);

    for (int i = e; i < e + k; ++i)
    {
        a[i] = true;
    }

    // for(int i = 0; i < n; ++i){
    //     cout << a[i] << " ";
    // }

    int A = 0;
    int b = 0;
    bool first = true;
    for (int i = 0; i < n; ++i)
    {
        if (!first && a[i] == false)
        {
            b++;
        }

        if (a[i] == false && first)
        {
            A++;
        }
        else
        {
            first = false;
            continue;
        }
    }
    int bigger = 0;
    //cout << A << " " << b;
    if (A <= b)
    {
        for (int i = e + k; i < n; ++i)
        {
            if(A == b || (k  == n - i && i == e + k)){
                b++;
                continue;
            }
            a[i] = true;
            bigger++;
        } // right completed
        int pTiles = bigger - 1;
        int i = 0;
        while (i < e && pTiles > 0)
        {
            int tiles = pTiles;
            if (tiles == k)
            {
                pTiles--;
                continue;
            }
            if (i + tiles <= e)
            {
                while (tiles && i < e)
                {
                    a[i] = true;
                    i++;
                    tiles--;
                }
            }
            pTiles--;
        }
    }
    else
    {
        for (int i = 0; i < e; ++i)
        {
            if(i == 0 && k == A){
                continue;
            }
            a[i] = true;
            bigger++;
        } // left completed
        int pTiles = bigger - 1;
        int i = e + k;
        while (i < n && pTiles > 0)
        {
            int tiles = pTiles;
            if (tiles == k)
            {
                pTiles--;
                continue;
            }
            if (i + tiles <= n)
            {
                while (tiles && i < n)
                {
                    a[i] = true;
                    i++;
                    tiles--;
                }
                pTiles--;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == false)
        {
            res++;
        }
        //cout << a[i] << " ";
    }

    cout << res << endl;

    return 0;
}
