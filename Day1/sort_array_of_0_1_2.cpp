// https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/

#include<bits/stdc++.h>
        using namespace std;

// Dutch National FLag Algorithm
void sortArray(vector<int> &arr, int n){
    int low=0;
    int mid =0;
    int high = n - 1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

int main(){

    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
