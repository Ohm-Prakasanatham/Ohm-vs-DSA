void topView(Node *root) {
    if (root == NULL)
        return;

    map<int, int> top;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (top.count(hd) == 0)
            top[hd] = curr->data;

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    for (auto x : top)
        cout << x.second << " ";
}
