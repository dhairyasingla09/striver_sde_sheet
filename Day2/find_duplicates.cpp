// https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/

#include<bits/stdc++.h>
using namespace std;

//sorting array
int findDuplicate(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++){
        if (arr[i] == arr[i + 1]){
            return arr[i];
        }
    }

    // Time Complexity: O(Nlogn + N)
    // Space Complexity: O(1)
}

//using hashmap
int findDuplicate(vector<int> &arr){
    int n = arr.size();
    int freq[n + 1] = {0};
    for (int i = 0; i < n; i++){
        if (freq[arr[i]] == 0){
            freq[arr[i]] += 1;
        }
        else{
            return arr[i];
        }
    }
    return 0;

    // Time Complexity: O(N)
    // Space Complexity: O(N)
}

int main(){
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
    return 0;
}
