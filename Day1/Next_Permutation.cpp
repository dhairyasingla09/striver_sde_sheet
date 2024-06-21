// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {3, 2, 1};

    next_permutation(arr, arr + 3); // using in-built function of C++

    cout << arr[0] << " " << arr[1] << " " << arr[2];

    return 0;
}
