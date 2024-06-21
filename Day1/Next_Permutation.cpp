// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A){
    int n = A.size();

    int ind = -1;
    for (int i = n - 2; i >= 0; i--){
        if(A[i]<A[i+1]){
            ind = i;//break point
            break;
        }
    }

    if(ind ==-1){
        reverse(A.begin(), A.end());
        return A;
    }

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin() + ind + 1, A.end());

    return A;

    //Time Complexity: O(3N)
    //Space Complexity: O(1)
}

int main(){
    int arr[] = {3, 2, 1};

    next_permutation(arr, arr + 3); // using in-built function of C++

    cout << arr[0] << " " << arr[1] << " " << arr[2];
    cout << endl;


    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: "<<endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;

    return 0;
}
