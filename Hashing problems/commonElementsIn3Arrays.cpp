/*
Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.
Output:
For each testcase, print the common elements of array. If not possible then print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 107
1 <= Ai, Bi, Ci <= 1018

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements
*/

#include <bits/stdc++.h>
using namespace std;

void commonOf3(int *arr1,int *arr2,int *arr3,int arr1Size,int arr2Size,int arr3Size) {
    int i = 0,j = 0,k = 0;
    while (i < arr1Size && j < arr2Size && k < arr3Size) {
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i++] <<" ";
            j++,k++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr2[j] < arr3[k]) {
            j++;
        }
        else
            k++;
    }
}

//using hash map

void common3(int *ar1,int *ar2,int *ar3,int n1,int n2,int n3) {
    map <int,int> mp;
    for(int i = 0 ; i < n1 ; i++) {
        mp[ar1[i]] = i;
    }
    int j = 0, k = 0;
    while(j < n2 && k < n3) {
        if(mp.find(ar2[j]) != mp.end()) {
            cout << ar2[j] <<" ";
            j++;
        }
        if(mp.find(ar3[k]) != mp.end()) {
            k++;
        }
        j++;
        k++;
    }cout << endl;

    /*for(int i = 0 ; i < n2; i++) {
        if(mp.find(ar2[i]) != mp.end()) {
            cout << ar2[i] <<" ";
        }
        else
            mp.erase(ar2[i]);
    }
    for(int i = 0 ; i < n3; i++) {
        if(mp.find(ar3[i]) != mp.end()) {
            cout << ar3[i] <<" ";
        }
        else {
            mp.erase(ar3[i]);
        }
    }
    map <int,int> :: iterator it = mp.begin();
    for(; it != mp.end(); it++) {
        cout << it->first <<" " << it->second << endl;
    }*/
}

void in(int *arr,int n) {
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
}
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        int arr1[n1],arr2[n2],arr3[n3];
        in(arr1,n1);
        in(arr2,n2);
        in(arr3,n3);
        common3(arr1,arr2,arr3,n1,n2,n3);
        cout << endl;
    }
    return 0;
}
