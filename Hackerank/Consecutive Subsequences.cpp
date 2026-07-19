#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {

        int N, K;
        cin >> N >> K;

        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long prefixSum = 0;
        long long count = 0;

        // Stores frequency of each remainder
        unordered_map<int, int> modCount;

        // Empty prefix sum has remainder 0
        modCount[0] = 1;

        for (int i = 0; i < N; i++) {

            // Update prefix sum
            prefixSum += arr[i];

            // Calculate remainder (handles negative numbers too)
            int mod = ((prefixSum % K) + K) % K;

            // Add number of previous prefix sums
            // having the same remainder
            count += modCount[mod];

            // Store current remainder
            modCount[mod]++;
        }

        cout << count << endl;
    }

    return 0;
}
