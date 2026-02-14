#include <bits/stdc++.h>
using namespace std;


int mmax(int a,int b,int c)
{
    if (a>=b && a>=c ) return a;
    if (b>=a && b>=c ) return b;
    if (c>=a && c>=b ) return c;


    return a;

};


int sum(string a, string b, string c, string operation)
{
    int ans = 0;


    int m = mmax(stoi(a),stoi(b),stoi(c));

    int maxDig= std::to_string(m).size();

    cout<<maxDig<<endl;


    if (operation == "+")
    {
        while (a.size()<maxDig) a+='0';
        while (b.size()<maxDig) b+='0';
        while (c.size()<maxDig) c+='0';

    }
    else
    {
        //while (a.size()<maxDig) a='1'+a;
        //while (b.size()<maxDig) b='1'+b;
        //while (c.size()<maxDig) c='1'+c;
    }


    cout<<a<<" "<<b<<" "<<c<<endl;


    string aa = string(1, a[0]) + string(1, b[0]) + string(1, c[0]);
    string bb = string(1, a[1]) + string(1, b[1]) + string(1, c[1]);
    string cc = string(1, a[2]) + string(1, b[2]) + string(1, c[2]);

    cout<<aa<<" "<<bb<<" "<<cc<<" "<<endl;

    if (operation == "+")
        return stoi(aa)+stoi(bb)+stoi(cc);
    else
        return stoi(aa)*stoi(bb)*stoi(cc);

};


int main() {
    vector<string> G;
    string line;

int N = 4;




    // Read entire input from stdin
    while (N) {
        getline(cin, line);
        G.push_back(line);
        N--;
    }

    int R = G.size();
    int C = G[0].size();

    long long p1 = 0, p2 = 0;
    int start_c = 0;



    vector<vector<string>> numbers;       // Array to store numbers

    for (auto it:G)
    {
        stringstream ss(it);
        string temp;

        vector<string> nn;
        while (ss >> temp) {
            nn.push_back(temp); // Convert string to int and store
        }
        numbers.push_back(nn);

    }

    vector<string> compute;

    for (int i = 0;i<numbers.size();i++)
    {

        if (numbers[i][numbers.size()-1] == "+" || numbers[i][numbers.size()-1]=="*")
            continue;

        compute.push_back(numbers[i][numbers.size()-1]);


        cout<<endl;
    }


    for (auto it:compute)
    {
        cout<<it<<" "<<endl;
    }




    for (int cc = 0; cc <= C; ++cc) {
        bool is_blank = true;

        if (cc < C) {
            for (int r = 0; r < R; ++r) {
                if (G[r][cc] != ' ') {
                    is_blank = false;
                    break;
                }
            }
        }

        if (is_blank) {
            char op = G[R - 1][start_c];
            assert(op == '+' || op == '*');

            // Calculate p1
            long long p1_score = (op == '+') ? 0 : 1;
            for (int r = 0; r < R - 1; ++r) {
                long long p1_n = 0;
                for (int c = start_c; c < cc; ++c) {
                    if (G[r][c] != ' ') {
                        p1_n = p1_n * 10 + (G[r][c] - '0');
                    }
                }
                if (op == '*') {
                    p1_score *= p1_n;
                } else {
                    p1_score += p1_n;
                }
            }
            p1 += p1_score;

            // Calculate p2
            long long score = (op == '+') ? 0 : 1;
            for (int c = cc - 1; c >= start_c; --c) {
                long long n = 0;
                for (int r = 0; r < R - 1; ++r) {
                    if (G[r][c] != ' ') {
                        n = n * 10 + (G[r][c] - '0');
                    }
                }
                if (op == '+') {
                    score += n;
                } else {
                    score *= n;
                }
            }
            p2 += score;

            start_c = cc + 1;
        }
    }

    cout << p1 << endl;
    cout << p2 << endl;


    cout<<sum("123","45","6","*");

    return 0;
}

