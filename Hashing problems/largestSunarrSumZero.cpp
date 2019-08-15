/*
Given an array having both positive an negative integers. The task is to complete the function maxLen() which returns the length of maximum subarray
with 0 sum. The function takes two arguments an array A and n where n is the size of the array A.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consist of 2 lines.
 The first line of each test case contains a number denoting the size of the array A. Then in the next line are space separated values of the array A.

Output:
For each test case output will be the length of the largest subarray which has sum 0.

User Task:
Sinec this is a functional problem you don't have to worry about input, you just have to complete the function maxLen().

Constraints:
1 <= T <= 100
1 <= N <= 100
-1000 <= A[] <= 1000

Example:
Input
1
8
15 -2 2 -8 1 7 10 23

Output
5

Explanation
Testcase 1: In the above test case the largest subarray with sum 0 will be -2 2 -8 1 7
*/

#include <bits/stdc++.h>
using namespace std;

int LengthOfLargestSubarrWithSumZero(int *arr,int n) {

    unordered_map <int,int> mp;
    int sum = 0;
    int len = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += arr[i];
        if(arr[i] == 0 && len == 0)
            len = 1;
        if(sum == 0) {
            // cout << 0 <<" " << i << endl;
            len = i+1;
        }
        if(mp.find(sum) != mp.end()) {
            len = max(len,i-mp[sum]);
        }
        else {
            mp[sum] = i;
        }
    }
    return len;
}

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        cout << LengthOfLargestSubarrWithSumZero(arr,n) << endl;
    }
    return 0;
}
