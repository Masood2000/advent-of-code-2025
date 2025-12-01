//
// Created by Masood on 12/01/2025.
//

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


//secret entrance
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 4545;

    vector<pair<string,int>> keys;

    for (int i = 0;i<N;i++)
    {
        string s;
        cin>>s;

        string key = s.substr(0,1);
        int value = stoi(s.substr(1,s.size()-1));

        keys.push_back(pair(key,value));

    }


    int countZeros = 0;

    int dialPos = 50;


    for (auto it: keys)
    {

        int dir =  (it.first == "L")?-1:1;

        for (int i=0;i<it.second;i++)
        {
            dialPos = (dialPos + dir)%100;

            if (dialPos == 0) countZeros++;
        }


    }


    cout<<countZeros;


    return 0;
}



