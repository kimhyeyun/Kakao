#include <string>
#include <vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

vector<string> sort(vector<string> a) {
    string v;
    for (int i = a.size()-1; i >0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j].size() > a[j+1].size()) {
                v = a[j];
                a[j] = a[j +1];
                a[j+1] = v;
            }

        }
    }
    return a;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp1;
    vector<string> a;
    string b;

    int o = 0;
    while (o != s.length()) {
        if (48<=s[o]&&s[o]<=57||s[o]==44) {
            b += s[o];
        }
        o++;
        if (s[o] == 125) {
            a.push_back(b);
            b = "";
            o += 2;
        }
    }
    a = sort(a);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != 44) {
                tmp1.push_back(int(a[i][j] - 48));
            }
            else{
                int x = 0;
                int sz = tmp1.size();
                for (int k = 0; k < sz; k++) {
                    x += (tmp1.back()*pow(10,k));
                    tmp1.pop_back();
                }
                if (find(answer.begin(), answer.end(), x) == answer.end())
                    answer.push_back(x);
            }
             
        }
        int x = 0;
        int sz = tmp1.size();
        for (int k = 0; k < sz; k++) {
            x = x + (tmp1.back() * pow(10, k));
            tmp1.pop_back();
        }
        if (find(answer.begin(), answer.end(), x) == answer.end())
            answer.push_back(x);
        
    }
    return answer;
}

int main() {
    string s = { " {{20,111},{111}}" };
    vector<int> a =  solution(s);
    cout << "[";

    for (int i = 0; i < a.size(); i++) {
        if (i == 0)
            cout << a[i];
        else
            cout << "," << a[i];
    }

    cout <<"]"<< endl;
    }