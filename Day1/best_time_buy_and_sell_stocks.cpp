// https://takeuforward.org/data-structure/stock-buy-and-sell/

#include<bits/stdc++.h>
        using namespace std;

int maxProfit(vector<int> &arr){

    int maxPro = 0;
    int n = arr.size();
    int min = INT_MAX;

    for (int i = 0; i < n; i++){
        if(arr[i]>min){
            maxPro = max((arr[i] - min), maxPro);
        }
        else{
            min = arr[i];
        }
    }
    return maxPro;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

int main()
{
    vector<int> arr = {7, 6, 4, 3, 1};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
    return 0;
}
