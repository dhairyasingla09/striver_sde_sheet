// https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v){

    vector<int> ans;
    int n = v.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++){
        mp[v[i]]++;
    }

    int mini = int(n / 3) + 1;

    for(auto itr:mp){
        if(itr.second>=mini){
            ans.push_back(itr.first);
        }
    }

    return ans;
}

vector<int> OptimalApproach(vector<int> v){

    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN;      // element 1
    int el2 = INT_MIN;      // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    return ls;

    // Time Complexity: O(N) + O(N)
    // Space Complexity: O(1)
}


int main(){
    vector<int> v = {11, 33, 33, 11, 33, 11};
    vector<int> ans=majorityElement(v);

    for(auto itr:ans){
        cout << itr << " ";
    }
    return 0;
}
