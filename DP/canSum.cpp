#include <bits/stdc++.h>
using namespace std;

bool canSum(int target, vector<int>& numbers, unordered_map<int, bool> map){
    if(map.find(target) != map.end()){
            return map[target];
        }
    if(target == 0){
        return true;
    }
    if(target < 0){
        return false;
    }

    for(int& num : numbers){
        int nextNode = target - num;
        if(canSum(nextNode, numbers, map)){
            map[target] = true;
            return true;
        }
    }
    map[target] = false;
    return false;
}

int main(){
    int n;
    vector<int> a;
    unordered_map<int, bool> map;



}