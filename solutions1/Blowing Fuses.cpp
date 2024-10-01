#include<bits/stdc++.h>
using namespace std;

int main(){

    int ndevices, nseq, curr;

    int i = 0;
    while((cin >> ndevices >> nseq >> curr) && (ndevices > 0)){
        i++;
        
        vector<int> device;


        for(int i = 0; i < ndevices; i++){
            int temp;
            cin >> temp;
            device.push_back(temp);
        }


        int maxcurr = 0, curre = 0;
        bool safe = true;

        for(int i = 0; i < nseq; i++){

            int temp;
            cin >> temp;

            if(safe){
                --temp;
                curre += device[temp];
                device[temp] *= -1;
                maxcurr = max(maxcurr, curre);

                if(maxcurr > curr) safe = false;    
            }
        }


        // if(i > 1) cout << '\n';

        if(safe){
            cout << "Sequence " << i << '\n';
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << maxcurr << " amperes.\n\n";
        }else{
            cout << "Sequence " << i <<'\n';
            cout << "Fuse was blown.\n\n";
        }


    }



}