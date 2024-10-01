#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }
int visited[26];

void solve() {
    int n, m;

    while (cin >> n) {
        vector<string> connections;
        map<char, int> mp;
        cin >> m;

        memset(visited, 0, sizeof(visited));

        string awake, temp;
        cin >> awake;
        int x = 0;

        for (int i = 0; i < 3; i++)
            if (mp.find(awake[i]) == mp.end()) mp[awake[i]] = x++;

        for (int i = 0; i < m; i++) {
            cin >> temp;
            connections.push_back(temp);

            for (int j = 0; j < 2; j++) {
                if (mp.find(temp[j]) == mp.end()) mp[temp[j]] = x++;
            }
        }

        if (n > mp.size()) {
            cout << "THIS BRAIN NEVER WAKES UP\n";
            continue;
        }

        for (int i = 0; i < 3; i++) visited[mp[awake[i]]] = 1;
        int cnt = 3, ret = 0;

        while (cnt < n) {
            vector<int> mark;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                int t1 = it->second;
                if (visited[t1]) continue;

                int tcnt = 0;
                for (int i = 0; i < connections.size(); i++) {
                    if (mp[connections[i][0]] == t1 && visited[mp[connections[i][1]]])
                        tcnt++;
                    else if (mp[connections[i][1]] == t1 && visited[mp[connections[i][0]]])
                        tcnt++;
                }

                if (tcnt >= 3) mark.push_back(t1);
            }

            cnt += mark.size();
            if (mark.empty()) break;
            for (int i = 0; i < mark.size(); i++) visited[mark[i]] = 1;

            ret++;
        }

        if (cnt < n)
            cout << "THIS BRAIN NEVER WAKES UP";
        else
            cout << "WAKE UP IN, " << ret << ", YEARS";

        cout << '\n';
    }
}

MAIN
