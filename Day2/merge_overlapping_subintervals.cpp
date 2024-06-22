 // https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &sub){
    int n = sub.size();
    sort(sub.begin(), sub.end()); //Important

    vector<vector<int>> ans;
    ans.push_back(sub[0]);
    for (int i = 1; i < n; i++){
        if (sub[i][0] <= sub[i - 1][1]){
            ans[i - 1][1] = sub[i][1];
        }
        else{
            ans.push_back(sub[i]);
        }
    }
    return ans;

    // Time Complexity: O(N*logN) + O(2*N)
    //Space Complexity: O(N)
}

//Optimised
void Optimised_mergeOverlappingIntervals(vector<vector<int>> &sub){
    int n = sub.size();
    sort(sub.begin(), sub.end()); // Important

    for (int i = 1; i < n; i++){
        if (sub[i][0] <= sub[i - 1][1]){
            sub[i - 1][1] = sub[i][1];
            sub.erase(sub.begin()+i);
            i--;
            n--;
        }
    }
    // Time Complexity: O(N*logN) + O(N)
    // Space Complexity: O(1)
}

int main(){

    vector<vector<int>> ques = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
    Optimised_mergeOverlappingIntervals(ques);

    for(auto itr:ques){
        cout << itr[0] << " " << itr[1] << endl;
    }

    return 0;
}
