#include <bits/stdc++.h>
using namespace std;

vector<string> G;
int R, C;
int sr, sc;

map<pair<int,int>, long long> memo;

long long score(int r, int c) {
    auto key = make_pair(r, c);
    if (memo.count(key))
        return memo[key];

    if (r + 1 == R)
        return memo[key] = 1;

    if (G[r + 1][c] == '^')
        return memo[key] = score(r + 1, c - 1) + score(r + 1, c + 1);
    else
        return memo[key] = score(r + 1, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read all lines
    string line;
    int N = 142;

    while(N){

        getline(cin, line);
        G.push_back(line);
      N--;
    }


    R = G.size();
    C = G[0].size();

    // Find S
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (G[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }

    // Part 1: BFS
    long long p1 = 0;
    queue<pair<int,int>> q;
    set<pair<int,int>> seen;

    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (seen.count({r,c})) continue;
        seen.insert({r,c});

        if (r + 1 == R)
            continue;

        if (G[r + 1][c] == '^') {
            q.push({r + 1, c - 1});
            q.push({r + 1, c + 1});
            p1++;
        } else {
            q.push({r + 1, c});
        }
    }

    cout << p1 << "\n";

    // Part 2: DP recursive memoization
    long long p2 = score(sr, sc);
    cout << p2 << "\n";

    return 0;
}
