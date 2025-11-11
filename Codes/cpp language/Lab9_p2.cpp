#include <iostream>
#include <cstdlib>  // for abs()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long a[100000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > m) {
        cout << 0;
        return 0;
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = (ans * (abs(a[i] - a[j]) % m)) % m;
            if (ans == 0) {
                cout << 0;
                return 0;
            }
        }
    }

    cout << ans;
    return 0;
}