// https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

#include<bits/stdc++.h>
using namespace std;

int longestSuccessiveELements(vector<int> nums){
    int n = nums.size();
    if(n==0){
        return 0;
    }

    sort(nums.begin(), nums.end());

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++){
        if (nums[i] - 1 == lastSmaller){
            // a[i] is the next element of the
            // current sequence.
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller){
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

    // Time Complexity: O(NlogN) + O(N)
    // Space Complexity: O(1)
}

int optimalFunction(vector<int> nums){
    int n = nums.size();
    if(n==0)
        return 0;

    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++){
        st.insert(nums[i]);
    }

    for (auto itr:st){
        if(st.find(itr-1)==st.end()){
            int count = 1;
            int x = itr;
            while(st.find(x+1)!=st.end()){
                x = x + 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;

    //Time Complexity: O(3N)
    //Space Complexity: O(N)
}

int main(){


    return 0;
}
