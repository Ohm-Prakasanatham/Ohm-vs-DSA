vector<int> largestPermutation(int k, vector<int> arr) {
    int n = arr.size();
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++)
        pos[arr[i]] = i;

    for (int i = 0; i < n && k > 0; i++) {
        int want = n - i;
        if (arr[i] == want) continue;

        int idx = pos[want];

        pos[arr[i]] = idx;
        swap(arr[i], arr[idx]);
        pos[want] = i;

        k--;
    }

    return arr;
}
