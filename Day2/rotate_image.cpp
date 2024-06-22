// https://takeuforward.org/data-structure/rotate-image-by-90-degree/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
vector<vector<int>> rotate(vector<vector<int>> & matrix){

    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    return rotated;

    //Time Complexity: O(N*N)
    //Space Complexity: O(N*N)
}

void optimal_rotate(vector<vector<int>> &matrix){
    int n = matrix.size();

    //Transposing
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reversing the Row
    for (int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // Time Complexity: O(N*N)
    // Space Complexity: O(1)
}

int main(){

    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> rotated = rotate(arr);
    // cout << "Rotated Image" << endl;

    // for (int i = 0; i < rotated.size(); i++){
    //     for (int j = 0; j < rotated[0].size(); j++){
    //         cout << rotated[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    optimal_rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
