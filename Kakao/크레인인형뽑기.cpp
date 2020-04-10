#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][moves[i] - 1]!=0) {
                if (!stk.empty() && board[j][moves[i] - 1] == stk.top()) {
                    board[j][moves[i] - 1] = 0;
                    stk.pop();
                    answer +=2;
                }
               /* else if(stk.empty()) {
                    stk.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }*/
                else{
                    stk.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }
                break;
            }
        }
    }


    return answer;
}



int main() {
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    int a = solution(board, moves);
    cout << a;
}