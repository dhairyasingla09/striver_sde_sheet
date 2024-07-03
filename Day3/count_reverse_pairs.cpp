// https://takeuforward.org/data-structure/count-reverse-pairs/

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> arr){
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > 2*arr[j]){
                count++;
            }
        }
    }

    return count;

    // Time Complexity: O(N^2)
    // Space Complexity: O(1) 
}

int main(){

    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = countPairs(a);
    cout << "The number of reverse pair is: "<< cnt << endl;
    return 0;
}
