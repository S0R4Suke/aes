#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector<vector<int>> input = {
        {0x54,0x65,0x73,0x74},
        {0x50,0x6c,0x61,0x69},
        {0x6e,0x54,0x65,0x78},
        {0x74,0x21,0x21,0x21},
    };

    vector<vector<int>> cipher_key = {
        {0x2b,0x28,0xab,0x09},
        {0x7e,0xae,0xf7,0xcf},
        {0x15,0xd2,0x15,0x4f},
        {0x16,0xa6,0x88,0x33},
    };

    vector<vector<int>> state(4,vector<int>(4));

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            state.at(i).at(j) = (input.at(i).at(j) ^ cipher_key.at(i).at(j));
        }
    }

    for(int i=0;i<4;i++){
        cout << " ------------";
        for(int j=0;j<4;j++){
            if(j==0){
                cout << endl << "|";
            }
            cout << hex << state.at(i).at(j) << " ";
            if(j==3){
                cout << "|" << endl;
            }
        }
    }
    cout << " ------------" << endl;
    return 0;
}