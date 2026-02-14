//
// Created by Masood on 12/02/2025.
//

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool invalid(long long x) {

    string s = to_string(x);
    int n = s.size();

    int limit = n+1;

    for (int k = 2; k < limit; k++) {
        if (n % k == 0) {
            bool inVal = true;
            int size = n / k;

            for (int i = 0; i < n; i += size) {
                if (s.substr(i, size) != s.substr(0, size)) {
                    inVal = false;
                    break;
                }
            }

            if (inVal)
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string input, temp;

    int i = 2;
    while (i) {
        getline(cin, temp);
        if (!input.empty()) input += "\n";
        input += temp;
        i--;
    }

    long long ans = 0;

    stringstream ss(input);
    string r;

    while (getline(ss, r, ',')) {
        size_t dash = r.find('-');


        long long first = stoll(r.substr(0, dash));
        long long last  = stoll(r.substr(dash + 1));

        for (long long x = first; x <= last; x++) {

            if (invalid(x))  ans += x;
        }
    }

    cout <<ans << "\n";
    return 0;
}