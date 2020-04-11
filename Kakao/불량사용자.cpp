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

//���ڼ��� ����, *�� ������ ������ ���ڰ� ��ġ�ϸ� true return
bool check(string user, string ban) {
    if (user.size() != ban.size())
        return false;
    for (int i = 0; i < user.length(); i++) {
        if (ban[i] != '*' && ban[i] != user[i])
            return false;
    }
    return true;
}

//���� dfs �̿�
void Set(int cnt, vector<string> user_id, vector<string>banned_id) {
    if (cnt == banned_id.size()) { //banned_id ������ŭ �Ǹ�
        vector<string> tmp = tm; 
        sort(tmp.begin(), tmp.end());
        if (st.count(tmp) == 0) { //tmp�� set���տ� ������
            st.insert(tmp); //�־��ְ�
            answer++;
        }
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if (!used[i] && check(user_id[i], banned_id[cnt])) { //user_id[i]�� �̿����� �ʾҰ�, check�Լ� true��
            used[i]=true; //�̿���
            tm.push_back(user_id[i]);   //tm�� �־��ְ�
            Set(cnt + 1, user_id, banned_id); //�ٽ� cnt+1(���� : �ٸ� banned_id�� ��ġ�ϴ� ���� ã�ƾ��ؼ�) �ؼ� set ȣ��
            used[i] = false; //�ٽ� false�� ����
            tm.pop_back(); //���ش�
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