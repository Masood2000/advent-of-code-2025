#include <bits/stdc++.h>
using namespace std;

vector<int> parentUF;

int findSet(int x) {
    if (parentUF[x] == x) return x;
    return parentUF[x] = findSet(parentUF[x]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) parentUF[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> X, Y, Z;
    long long x, y, z;
    char c1, c2;

    int N =1000;

    while (N) {
        cin >> x >> c1 >> y >> c2 >> z;
        X.push_back(x);
        Y.push_back(y);
        Z.push_back(z);
        N--;
    }

    int n = X.size();
    parentUF.resize(n);
    iota(parentUF.begin(), parentUF.end(), 0);

    // All distances (dist², i, j)
    vector<tuple<long long,int,int>> D;
    D.reserve((long long)n * (n - 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long dx = X[i] - X[j];
            long long dy = Y[i] - Y[j];
            long long dz = Z[i] - Z[j];
            long long dist = dx*dx + dy*dy + dz*dz;
            D.emplace_back(dist, i, j);
        }
    }

    sort(D.begin(), D.end());

    int connections = 0;

    for (int t = 0; t < (int)D.size(); t++) {
        auto [dist, i, j] = D[t];

        // At t == 1000 → component calculation
        if (t == 1000) {
            unordered_map<int, long long> SZ;

            for (int k = 0; k < n; k++)
                SZ[findSet(k)]++;

            vector<long long> sizes;
            for (auto &p : SZ) sizes.push_back(p.second);
            sort(sizes.begin(), sizes.end());

            if (sizes.size() >= 3) {
                long long result =
                    sizes[sizes.size()-1] *
                    sizes[sizes.size()-2] *
                    sizes[sizes.size()-3];
                cout << result << "\n";
            }
        }

        if (findSet(i) != findSet(j)) {
            connections++;

            if (connections == n - 1) {
                cout << X[i] * X[j] << "\n";
            }

            unionSet(i, j);
        }
    }

    return 0;
}
