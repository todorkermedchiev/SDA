#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &arr) { // longest incresing subsequence
    int size = arr.size();
    vector<int> dp(size, 1);

    int ans = INT_MIN;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1); 
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans;

}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < arr.size(); ++i) {
        cin >> arr[i];
    }

    cout << "Ans: " << lis(arr);

    return 0;
}