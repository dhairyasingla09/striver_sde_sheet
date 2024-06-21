// https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

#include<bits/stdc++.h>
using namespace std;

//Brute-Force
int maxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++){
        for (int j = i; j<n; j++){
            // subarray = arr[i.....j]
            int sum = 0;

            for (int k = i; k < j; k++){
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;

    // Time Complexity: O(N3), where N = size of the array.
    //Space Complexity : O(1) as we are not using any extra space.
}

//Better Approach
int maxSubarraySum2(int arr[], int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            // current subarray = arr[i.....j]

            // add the current element arr[j] to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
    // Time Complexity: O(N2), where N = size of the array.
    //Space Complexity : O(1) as we are not using any extra space.
}

int kadane(int arr[], int n){
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
        
        if(sum>maxi){
            maxi = sum;
        }

        if(sum<0){
            sum = 0;
        }
    }
    return maxi;

    // Time Complexity: O(N), where N = size of the array.
    //Space Complexity : O(1) as we are not using any extra space.
}

int main(){

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = kadane(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;

}
