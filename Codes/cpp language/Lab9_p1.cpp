#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> V(N), W(N);
        
        for (int i = 0; i < N; i++) cin >> V[i];
        for (int i = 0; i < N; i++) cin >> W[i];
        
        sort(V.begin(), V.end());          
        sort(W.begin(), W.end(), greater<long long>());  
        
        long long minDotProduct = 0;
        for (int i = 0; i < N; i++) {
            minDotProduct += V[i] * W[i];
        }
        
        cout << minDotProduct << endl;
    }
    return 0;
}
