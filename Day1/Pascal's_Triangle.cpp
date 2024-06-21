// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

      //1
     //1 1
    //1 2 1
   //1 3 3 1
  //1 4 6 4 1
//1 5 10 10 5 1

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
int ncr(int r, int c){
    int n = r - 1;
    int m = c - 1;

    int res = 1;
    for (int i = 0; i < m; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;

    //Time Complexity: O(column)
    //Space Complexity: O(1)
}

//Variation 2 : Given the row number r.Print the rth row of Pascal’s triangle.
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for (int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;

    // Time Complexity: O(N)
    // Space Complexity : O(1)
}

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
vector<vector<int>>pascalTriangle(int n){
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int n = 5;
    int r = 5;
    int c = 3;

    //cout << ncr(r, c) << endl;

    // vector<int> row=generateRow(r);
    // for (auto itr:row){
    //     cout << itr << " ";
    // }
    // cout << endl;

    // vector<vector<int>> Triangle = pascalTriangle(n);
    // for(auto it:Triangle){
    //     for(auto itr:it){
    //         cout << itr << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
