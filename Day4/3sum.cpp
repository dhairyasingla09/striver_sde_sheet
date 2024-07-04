// https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int target){
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            for (int k = j + 1; k < nums.size(); k++){
                if (nums[i] + nums[j] + nums[k] == target){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;

    // Time Complexity: O(N^3 * log(no. of unique triplets))
    // Space Complexity : O(2 * no.of the unique triplets)
    }
}

vector<vector<int>> triplet(int n, vector<int> arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++){
        // remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0){
                j++;
            }
            else if (sum > 0){
                k--;
            }
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;

    // Time Complexity: O(NlogN)+O(N2), where N = size of the array
    // Space Complexity: O(1)
}

int main(){

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
