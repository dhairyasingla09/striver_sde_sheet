// https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/

#include<bits/stdc++.h>
using namespace std;

int recursive_countPaths(int i, int j, int n, int m){
    if(i==(n-1) && j==(m-1))
        return 1;
    if(i>=n || j>=m)
        return 0;
    else
        return recursive_countPaths(i + 1, j, n, m) + recursive_countPaths(i, j + 1, n, m);
}

int dp_countPaths(int i, int j, int n, int m, vector<vector<int>> dp){
    if((i==n-1) && (j==m-1))
        return 1;
    if(i>n || j>m)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    else
        return dp[i][j] = dp_countPaths(i + 1, j, n, m, dp) + dp_countPaths(i, j + 1, n, m, dp);

    //Time Complexity: O(NM)
    //Space Complexity: O(NM)
}

int uniquePaths(int m, int n){
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++){
        res = res * (N - r + 1) / i;
    }

    return res;

    // Time Complexity: O(m-1)/O(n-1)
    // Space Complexity: O(1)
}


int main(){


    return 0;
}
