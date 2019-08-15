/*
Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.

Examples:

Input: A[] = {4, 1, 2, 1, 1, 2}, B[] = (3, 6, 3, 3)
Output: {1, 3}
Sum of elements in A[] = 11
Sum of elements in B[] = 15
To get same sum from both arrays, we
can swap following values:
1 from A[] and 3 from B[]

Input: A[] = {5, 7, 4, 6}, B[] = {1, 2, 3, 8}
Output: 6 2

*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n ,m;
        cin >> n >> m;
        int small = min(n,m);
        int big = max(n,m);
        int smallArr[small];
        int bigArr[big];
        int smallSum = 0;
        int bigSum = 0;
        unordered_map <int,int> mp;
        for(int i = 0 ; i < small; i++) {
            cin >> smallArr[i];
            smallSum += smallArr[i];
            mp[smallArr[i]] = i;
        }
        for(int i = 0 ; i < big; i++) {
            cin >> bigArr[i];
            bigSum += bigArr[i];
        }
        int flag = 0;
        int diff = (smallSum-bigSum)/2;
        for(int i = 0 ; i < big; i++) {
            if(mp.find(bigArr[i]+diff) != mp.end()) {
                cout << bigArr[i] <<" " << bigArr[i]+diff <<" ";
                flag = 1;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}
