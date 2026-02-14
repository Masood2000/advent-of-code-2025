//
// Created by Masood on 12/03/2025.
//


#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, long long>> DP;

long long largestJoltage(const string &bank, int i, int used) {

    if (i == bank.size() && used == 12)
        return 0;

    if (i == bank.size())
        return -INT64_MAX;

    if (DP[i].count(used))
        return DP[i][used];

    long long ans = largestJoltage(bank, i + 1, used);

    if (used < 12) {
        long long multiplier = pow(10LL, 11 - used);
        long long digit = bank[i] - '0';
        ans = max(ans, multiplier * digit + largestJoltage(bank, i + 1, used + 1));
    }

    return DP[i][used] = ans;
}

long long largestJoltageB(const string &bank, int i, int used, long long current) {

    if (used == 12)
        return current;

    if (i == bank.size())
        return 0;

    long long best = 0;


    best = max(best, largestJoltageB(bank, i + 1, used, current));


    long long digit = bank[i] - '0';
    best = max(best, largestJoltageB(bank, i + 1, used + 1, current * 10 + digit));

    return best;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long ans = 0;

    int N = 200;


    vector<string> batteryBank;


    while (N)
    {
        string bank;
        getline(cin,bank);

        batteryBank.push_back(bank);

        N--;
    }


    for (auto bank:batteryBank)
    {

        DP.clear();
        ans += largestJoltage(bank, 0, 0);

    }

    cout << ans << "\n";
}
