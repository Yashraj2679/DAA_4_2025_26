#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> attendance(N);
    for (int i = 0; i < N; i++) {
        cin >> attendance[i];
    }

    unordered_map<int, int> mp;
    int sum = 0;
    int maxLength = 0;

    mp[0] = -1;

    for (int i = 0; i < N; i++) {

        if (attendance[i] == 'P')
            sum += 1;
        else if (attendance[i] == 'A')
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            int length = i - mp[sum];
            maxLength = max(maxLength, length);
        } else {
            mp[sum] = i;
        }
    }

    cout << maxLength << endl;
    return 0;
}
