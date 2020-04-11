#include <string>
#include <vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

int answer;
vector<bool> used;
vector<string> tm;
set<vector<string>> st;

//글자수가 같고, *을 제외한 나머지 글자가 일치하면 true return
bool check(string user, string ban) {
    if (user.size() != ban.size())
        return false;
    for (int i = 0; i < user.length(); i++) {
        if (ban[i] != '*' && ban[i] != user[i])
            return false;
    }
    return true;
}

//결합 dfs 이용
void Set(int cnt, vector<string> user_id, vector<string>banned_id) {
    if (cnt == banned_id.size()) { //banned_id 갯수만큼 되면
        vector<string> tmp = tm; 
        sort(tmp.begin(), tmp.end());
        if (st.count(tmp) == 0) { //tmp가 set집합에 없을때
            st.insert(tmp); //넣어주고
            answer++;
        }
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if (!used[i] && check(user_id[i], banned_id[cnt])) { //user_id[i]를 이용하지 않았고, check함수 true면
            used[i]=true; //이용함
            tm.push_back(user_id[i]);   //tm에 넣어주고
            Set(cnt + 1, user_id, banned_id); //다시 cnt+1(이유 : 다른 banned_id와 일치하는 것을 찾아야해서) 해서 set 호출
            used[i] = false; //다시 false로 변경
            tm.pop_back(); //빼준다
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    answer = 0;
    used = vector<bool>(user_id.size(), false);
    Set(0, user_id, banned_id);

    return answer;
}

int main() {
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
    cout << solution(user_id, banned_id);
}