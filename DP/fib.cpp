#include <bits/stdc++.h>
using namespace std;

int fib(int n, unordered_map<int, int>& memo){
	if(memo.find(n) != memo.end()){
		return memo[n];
	}

	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
	return memo[n];
}

int main(){
	int n; cin >> n;
	unordered_map<int, int> memo = {{1, 1}, {2, 1}};
	cout << fib(n, memo) << endl;
	return 0;
}