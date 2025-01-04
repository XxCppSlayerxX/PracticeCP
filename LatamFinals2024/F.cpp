#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    float k, n;
    cin >> k >> n;

    if (!(ceil(n / 3) <= k && ceil(n / 2) >= k))
    {
        cout << '*' << endl;
        return 0;
    }

    bool equis = true;
    while (n > 0 && k > 0){
        while (n > 2 && k > 0 && !((ceil((n - 1) / 3) <= (k - 1) && ceil((n - 1) / 2) >= (k - 1)))){
            cout << "-X-";
            n -= 3;
            k--;
            equis = true;
        }
        if(n <= 0){
            break;
        }
        if (equis)
            {
                cout << "X";
                equis = false;
                k--;
            }
            else
            {
                cout << "-";
                equis = true;
            }
        n--;
    }
    if(n){
        cout << "-";
    }
    cout << endl;

    return 0;
}