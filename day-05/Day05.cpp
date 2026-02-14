#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;

    int N = 1175;

    while (N)
    {
        getline(cin, line);
            lines.push_back(line);
        N--;

    }


    // Split into two parts at the blank line
    vector<string> rangeLines;
    vector<string> ingredientLines;

    bool foundBlank = false;
    for (auto &l : lines) {
        if (!foundBlank) {
            if (l.empty()) {
                foundBlank = true;
                continue;
            }
            rangeLines.push_back(l);
        } else {
            if (!l.empty())
                ingredientLines.push_back(l);
        }
    }

    // Parse ranges
    vector<pair<long long, long long>> R;
    for (auto &r : rangeLines) {
        size_t dash = r.find('-');
        long long s = stoll(r.substr(0, dash));
        long long e = stoll(r.substr(dash + 1));
        R.emplace_back(s, e);
    }

    // Sort ranges
    sort(R.begin(), R.end());

    long long p2 = 0;
    long long last = -1;

    for (auto &p : R) {
        long long s = p.first, e = p.second;

        if (last >= s) s = last + 1;

        //cout<<s<<"----"<<e<<endl;
        if (s <= e) p2 += (e - s + 1);
        //cout<<p2<<endl;

        last = max(last, e);
    }

    // Compute p1: number of ingredients inside any range
    long long p1 = 0;

    for (auto &l : ingredientLines) {
        long long x = stoll(l);
        for (auto &p : R) {
            if (p.first <= x && x <= p.second) {
                p1++;
                break;
            }
        }
    }

    cout << p1 << "\n" << p2 << "\n";
    return 0;
}
