// https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/

#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n){
    double ans = 1.0;
    for (int i = 0; i < n; i++){
        ans = ans * x;
    }
    return ans;

    // Time Complexity: O(N)
    // Space Complexity : O(1)
}

double O_myPow(double x, int n){
    double ans = 1.0;
    long long nn = n;

    if(nn<0)
        nn = -1 * nn;

    while(nn){
        if(nn%2==1){
            ans = ans * x;
            nn = nn - 1;
        }
        else{
            x = x * x;
            nn = nn / 2;
        }
    }

    if(n<0)
        ans = (double)(1.0) / (double)(ans);
    return ans;

    // Time Complexity: O(log n)
    // Space Complexity : O(1)
}

    int main(){

    cout << myPow(3, 10) << endl;
    return 0;
}
