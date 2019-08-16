/*
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not.
Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an
two integers m and n denoting the size of arr1 and arr2 respectively. The following two lines contains the space separated elements of arr1 and arr2 respectively.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an two integers m and n denoting the size of arr1 and arr2 respectively. The following two lines contains the space separated elements of arr1 and arr2 respectively.

Output:
Print "Yes"(without quotes) if arr2 is subset of arr1.
Print "No"(without quotes) if arr2 is not subset of arr1.

Constraints:
1 <= T <= 100
1 <= m,n <= 105
1 <= arr1[i], arr2[j] <= 105

Example:
Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No

Explanation:
Testcase 1: (11, 3, 7, 1) is a subset of first array.
*/

#include <bits/stdc++.h>
using namespace std;

bool isS2SubsetOfS1(int *a1,int *a2,int n,int m) {
    unordered_set <int> s;
    for(int i = 0 ; i < n; i++) {
        s.insert(a1[i]);
    }
    for(int i = 0 ; i < m; i++) {
        if(s.find(a2[i]) == s.end()) {
            return false;
        }
    }
    return true;
}
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int arr1[n],arr2[m];
        for(int i = 0 ; i < n; i++) {
            cin >> arr1[i];
        }
        for(int i = 0 ; i < m ; i++) {
            cin >> arr2[i];
        }
        if(isS2SubsetOfS1(arr1,arr2,n,m))  cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
