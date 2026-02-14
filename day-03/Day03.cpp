//
// Created by Masood on 12/03/2025.
//


#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long ans = 0;

    int N = 4;

    long long nAns = 0;



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

        long long best = -1;


        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                long long score = (bank[i] - '0') * 10 + (bank[j] - '0');
                best = max(best, score);
            }
        }


        ans += best;

    }





    cout << ans << "\n";
    cout<<nAns<<"\n";

}
