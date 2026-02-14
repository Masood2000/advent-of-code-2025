//
// Created by Masood on 12/04/2025.
//

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> G;


    int N = 140;


    while (N)
    {
        string line;
        getline(cin,line);

        G.push_back(line);

        N--;
    }



    int R = G.size();
    if (R == 0) return 0;
    int C = G[0].size();

    long long p1 = 0, p2 = 0;
    bool first = true;

    while (true) {
        bool changed = false;


        vector<string> newG = G;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {

                int nbr = 0;
                for (int dr : {-1, 0, 1}) {
                    for (int dc : {-1, 0, 1}) {
                        int rr = r + dr, cc = c + dc;
                        if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                            if (G[rr][cc] == '@')
                                nbr++;
                        }
                    }
                }

                if (G[r][c] == '@' && nbr < 5) {
                    p1++;
                    changed = true;

                    if (!first) {
                        p2++;
                        newG[r][c] = '.';
                    }
                }
            }
        }

        if (first) {
            cout << p1 << "\n";
            first = false;
        }

        if (!changed) break;

        G = std::move(newG);
    }

    cout << p2 << "\n";

    return 0;
}
