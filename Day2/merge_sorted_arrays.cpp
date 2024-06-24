// https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/

#include <bits/stdc++.h>
using namespace std;

//Brute Force
void merge(long long arr1[], long long arr2[], int n, int m){

    long long arr3[n + m];
    
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m){
        if (arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++, index++;
        }
        else{
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n){
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m){
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n + m; i++){
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }

    // Time Complexity: O(n+m) + O(n+m)
    //Space Complexity: O(n+m) as we use an extra array of size n+m.
}

void optimal_merge(long long arr1[], long long arr2[], int n, int m){

    // Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m){
        if (arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else{
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
    //Space Complexity: O(1) as we are not using any extra space.
}

int main(){

    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;

    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }

    cout << "\n arr2[] = ";
    for (int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }

    cout << endl;
    return 0;
}
