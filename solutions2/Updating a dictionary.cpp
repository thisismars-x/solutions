#include <bits/stdc++.h>
using namespace std;

map<string, string> make_ordering(string& in) {
    in = in.substr(1, in.size() - 2); 
    regex pattern(R"((\w+):([0-9]+))"); 
    smatch match;

    map<string, string> ordering;
    while (regex_search(in, match, pattern)) {
        ordering[match[1]] = (match[2]);  
        in = match.suffix().str();  
    }

    return ordering;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    while (n--) {
        map<string, string> map1, map2;
        set<string> added_to_map2, removed_from_map1, updated;

        string temp;
        
        getline(cin, temp);
        map1 = make_ordering(temp);
        getline(cin, temp);
        map2 = make_ordering(temp);

        for (auto &i : map2) {
            if (!map1.count(i.first)) {
                added_to_map2.insert(i.first);  
            } else if (map1[i.first] != i.second) {
                updated.insert(i.first); 
            }
        }

        for (auto &i : map1) {
            if (!map2.count(i.first)) {
                removed_from_map1.insert(i.first); 
            }
        }

        if (!added_to_map2.empty()) {
            cout << "+";
            for (auto it = added_to_map2.begin(); it != added_to_map2.end(); ++it) {
                if (it != added_to_map2.begin()) cout << ",";
                cout << *it;
            }
            cout << endl;
        }

        if (!removed_from_map1.empty()) {
            cout << "-";
            for (auto it = removed_from_map1.begin(); it != removed_from_map1.end(); ++it) {
                if (it != removed_from_map1.begin()) cout << ",";
                cout << *it;
            }
            cout << endl;
        }

        if (!updated.empty()) {
            cout << "*";
            for (auto it = updated.begin(); it != updated.end(); ++it) {
                if (it != updated.begin()) cout << ",";
                cout << *it;
            }
            cout << endl;
        }

        if (added_to_map2.empty() && removed_from_map1.empty() && updated.empty()) {
            cout << "No changes" << endl;
        }

        cout << endl;
    }

    return 0;
}
