//
// Created by pcp on 11/28/2025.
//

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1000;

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<int> a,b;

    for (int i =0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }


    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    map<int,int> freq;
    for (int x:b)
    {
        freq[x]++;
    }
    long long  sum = 0;

  for (int x:a) sum += (long long ) x * freq[x];

    cout<<endl<<sum<<endl;

    return 0;
}