#include <bits/stdc++.h>
using namespace std;

void findLCS(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "LCS Length = " << dp[n][m] << endl;
    cout << "LCS Sequence = ";
    for (int x : lcs) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 2, 4, 1, 2};
    vector<int> B = {2, 4, 3, 1, 2, 1};

    findLCS(A, B);

    return 0;
}
