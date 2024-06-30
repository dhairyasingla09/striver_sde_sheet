// https : // takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/

#include<bits/stdc++.h>
        using namespace std;


// Better Approach
int majorityElement(vector<int> v){
    int n = v.size();

    map<int, int> mp;
    for (int i = 0; i<n; i++){
        mp[v[i]]++;
    }

    for (auto it : mp){
        if (it.second > (n / 2)){
            return it.first;
        }
    }

    return -1;

    // Time Complexity: O(N*logN) + O(N)
    // Space Complexity:O(N)
}

int majElement(vector<int>v){
    int cnt = 0;
    int n = v.size();
    int ele;

    for (int i = 0; i < n; i++){
        if(cnt==0){
            cnt = 1;
            ele = v[i];
        }
        else if (ele == v[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
        int cnt1 = 0;

    for (int i = 0; i < n; i++){
        if (v[i] == ele)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return ele;


    return -1;

    // Time Complexity: O(N) + O(N), where N = size of the given array.
    // Space Complexity: O(1)
}

int main(){
    vector<int> v = {2, 3, 3};
    int ans = majElement(v);
    cout << ans << endl;

    return 0;
}
