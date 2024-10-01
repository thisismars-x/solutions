#include<bits/stdc++.h>
using namespace std;

struct contestant{
    int id, time, solved;
    vector<int> submissions;
    bitset<10> is_solved;

    contestant(int i): id(i), time(0), solved(0), submissions(vector<int>(10)){}

    inline bool operator<(contestant& other){
        if(solved == other.solved){
            if(time == other.time) return id < other.id;
            return time < other.time;
        }

        return solved > other.solved;
    }

};

int main(){
    int t0; cin >> t0;
    cin.ignore(); cin.ignore();

    while(t0--){
        string submission;
        vector<contestant> data;
        bitset<101> participation;

        for(int i = 0; i < 101; i++) data.push_back(contestant(i));
        while(getline(cin, submission) and submission.length() != 0){
            int id, time;
            char status;
            int problem;

            istringstream in(submission);
            in >> id >> problem >> time >> status;
            participation[id] = 1;

            if(!data[id].is_solved[problem]){
                if(status == 'C'){
                    ++data[id].solved;
                    data[id].is_solved[problem] = 1;
                    data[id].time += time + data[id].submissions[problem] * 20;
                }

                else if(status == 'I'){
                    ++data[id].submissions[problem];
                }
            }
        }

        vector<contestant> board;
        for(int i = 0; i < 101; i++){
            if(participation[i]) board.push_back(data[i]);
        }

        sort(board.begin(), board.end());

        for(int i = 0; i < board.size(); i++)
            cout << board[i].id << " "
                << board[i].solved << " "
                << board[i].time << '\n';
        
        if(t0) cout << '\n';
    }
}