#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    vector<vector<int>> SubBytes = {
        {0x20,  0x4d,  0x8f,  0x92},
        {0x53,  0x7f,  0xef,  0xf9},
        {0x3c,  0x20,  0x4d,  0xbc},
        {0x92,  0xfd,  0xfd,  0xfd},
    };
    cout << "SubBytes後：" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << hex << SubBytes.at(i).at(j) << " ";
            if(j==3){
                cout << endl;
            }
        }
    }

    vector<vector<int>> ShiftRows(4,vector<int>(4));
    int count=0;
    for(int i=0;i<4;i++){
        cout << count << endl;
        for(int j=0;j<4;j++){
            //cout << "debug:2" << endl;
            if((j+count)<4){
                //cout << "debug:3" << endl;
                ShiftRows.at(i).at(j+count) = SubBytes.at(i).at(j);
            }else{
                //cout << "debug:4" << endl;
                ShiftRows.at(i).at(j+count-4) = SubBytes.at(i).at(j);
            }
        }
        count++;
    }
    cout << "ShiftRows後" << endl;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << hex << ShiftRows.at(i).at(j) << " ";
            if(j==3){
                cout << endl;
            }
        }
    }
    cout << endl;
}