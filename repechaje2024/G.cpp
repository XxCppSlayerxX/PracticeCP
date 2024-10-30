#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while(b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

const int MAX_PRIME = 1000000;
vector<int> primes;
vector<bool> is_prime(MAX_PRIME+1, true);

//nloglogn
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME; ++i) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int n;
    cin >> n;
    vector<ll> a(n);
    ll G = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        G = gcd(G, a[i]);
    }
    vector<ll> b(n);
    for(int i = 0; i < n; ++i) {
        b[i] = a[i] / G;
    }
    
    map<ll, int> prime_count;
    for(int i = 0; i < n; ++i) {
        ll num = b[i];
        set<ll> factors;
        for(int p : primes) {
            if((ll)p * p > num) break;
            if(num % p == 0) {
                factors.insert(p);
                while(num % p == 0) num /= p;
            }
        }
        if(num > 1) {
            // num is a large prime factor
            factors.insert(num);
        }
        for(ll p : factors) {
            if(prime_count[p]) {
                cout << "NO" << endl;
                return 0;
            }
            prime_count[p]++;
        }
    }
    cout << "YES" << endl;
    return 0;
}
