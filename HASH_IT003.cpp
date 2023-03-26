#include <bits/stdc++.h>
#define M 10000
#define strlength 100
using namespace std;

int modpower2[101];

void setpower(){
    modpower2[0] = 1 % M;
    for(int i = 1; i< 101; i++)
        modpower2[i] = (modpower2[i - 1]*2) % M;
}

int hashbinastring(const string& a){
    int index = 0;
    int si = a.size();

    for(int i = si - 1; i > -1; i--){
        if(a[i] == '1')
            index = (index + modpower2[si - 1 - i]) % M;
    }

    return (index + a.size()) % M;
}

int main(){
    setpower();
    string key;
    while(true){
        cout << "Enter a key (binary string no longer than 100 bits) or 'q' to quit: ";
        cin >> key;
        if(key[0] == 'q' && key.size() == 1)
            break;
        else{
            int i;
            for(i = 0; i < key.size(); i++){
                if(key[i] != '0' && key[i] != '1'){
                    cout << "Invalid\n";
                    break;
                }
                    
            }
            if(i == key.size())
                cout << "Index for the key is: " << hashbinastring(key) << "\n";
        }
            
    }
}
       