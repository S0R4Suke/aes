#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
 
vector<vector<int>> Sbox = {
    {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
    {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
    {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
    {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
    {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
    {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
    {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
    {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
    {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
    {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
    {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
    {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
    {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
    {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
    {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
    {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16},
};

vector<vector<int>> InvSbox = {
    {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
    {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb},
    {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e},
    {0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25},
    {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92},
    {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84},
    {0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06},
    {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b},
    {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73},
    {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e},
    {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b},
    {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4},
    {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f},
    {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef},
    {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61},
    {0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d},
};

//サブ鍵生成
void RotWord(vector<vector<int>>& w){
    vector<int> tmp(4);
    for(int i=0;i<4;i++){
        tmp.at(i) = w.at(3).at(i);
    }

    for(int i=0;i<4;i++){
        w.at(3).at(i) = tmp.at((i+1)%4);
    }
    return;
}

void SubWord(vector<vector<int>>& w){
    int xnum,ynum = 0;
    for(int i=0;i<4;i++){
        xnum = w.at(3).at(i) / 16;
        ynum = w.at(3).at(i) % 16;
        w.at(3).at(i) = Sbox.at(xnum).at(ynum);
    }
    return;
}

void ShiftRows(vector<vector<int>>& s){
    vector<int> tmp(4);

    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            tmp.at(j) = s.at(j).at(i);
        }
        for(int j=0;j<4;j++){
            s.at(j).at(i) = tmp.at((i+j)%4);
        }
    }
    return;
}

void SubBytes(vector<vector<int>>& w){
    int xnum = 0,ynum = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            xnum = w.at(i).at(j) / 16;
            ynum = w.at(i).at(j) % 16;
            w.at(i).at(j) = Sbox.at(xnum).at(ynum);
        }
    }
    return;
}

int MixColumns_Shift(int tmp,int a){
    if(a == 2) {
        tmp = tmp * 2;
    }else if(a == 3){
        tmp = (tmp * 2) ^ (tmp * 1);
    }
    return tmp;
}

int OverflowCheck(int s) {
    for(int i=0x8000;i>0x100;i=i/2){
        if(s/i != 0){
            s = s ^ (i * 0b100011011 / 0b100000000);
        }
    }
    if(s > 0b11111111){
        s = s ^ 0x11b;
    }
    return s;
}

void MixColumns(vector<vector<int>>& s){
    vector<int> tmp(4);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tmp.at(j) = s.at(i).at(j);
        }
        s.at(i).at(0) = (MixColumns_Shift(tmp.at(0),2)) ^ (MixColumns_Shift(tmp.at(1), 3)) ^ (MixColumns_Shift(tmp.at(2), 1)) ^ (MixColumns_Shift(tmp.at(3), 1));
        s.at(i).at(1) = (MixColumns_Shift(tmp.at(0),1)) ^ (MixColumns_Shift(tmp.at(1), 2)) ^ (MixColumns_Shift(tmp.at(2), 3)) ^ (MixColumns_Shift(tmp.at(3), 1));
        s.at(i).at(2) = (MixColumns_Shift(tmp.at(0),1)) ^ (MixColumns_Shift(tmp.at(1), 1)) ^ (MixColumns_Shift(tmp.at(2), 2)) ^ (MixColumns_Shift(tmp.at(3), 3));
        s.at(i).at(3) = (MixColumns_Shift(tmp.at(0),3)) ^ (MixColumns_Shift(tmp.at(1), 1)) ^ (MixColumns_Shift(tmp.at(2), 1)) ^ (MixColumns_Shift(tmp.at(3), 2));
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s.at(j).at(i) = OverflowCheck(s.at(j).at(i));
        }
    }
    return;
}

//begin Dec

void InvShiftRows(vector<vector<int>>& s){
    vector<int> tmp(4);
    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            tmp.at(j) = s.at(j).at(i);
        }
        for(int j=0;j<4;j++){
            s.at(j).at(i) = tmp.at((j-i+4)%4);
        }
    }
    return;
}

void InvSubBytes(vector<vector<int>>& w){
    int xnum = 0,ynum = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            xnum = w.at(i).at(j) / 16;
            ynum = w.at(i).at(j) % 16;
            w.at(i).at(j) = InvSbox.at(xnum).at(ynum);
        }
    }
}

int InvMixColumns_Shift(int tmp,int a){
    if(a == 9){
        tmp = (tmp * 8) ^ (tmp * 1);
    }else if(a == 11){
        tmp = (tmp * 8) ^ (tmp * 2) ^ (tmp * 1);
    }else if(a == 13){
        tmp = (tmp * 8) ^ (tmp * 4) ^ (tmp * 1);
    }else if(a == 14){
        tmp = (tmp * 8) ^ (tmp * 4) ^ (tmp * 2);
    }
    return tmp;
}

void InvMixColumns(vector<vector<int>>& s){
    vector<int> tmp(4);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tmp.at(j) = s.at(i).at(j);
        }
        s.at(i).at(0) = (InvMixColumns_Shift(tmp.at(0),14)) ^ (InvMixColumns_Shift(tmp.at(1), 11)) ^ (InvMixColumns_Shift(tmp.at(2), 13)) ^ (InvMixColumns_Shift(tmp.at(3), 9));
        s.at(i).at(1) = (InvMixColumns_Shift(tmp.at(0),9)) ^ (InvMixColumns_Shift(tmp.at(1), 14)) ^ (InvMixColumns_Shift(tmp.at(2), 11)) ^ (InvMixColumns_Shift(tmp.at(3), 13));
        s.at(i).at(2) = (InvMixColumns_Shift(tmp.at(0),13)) ^ (InvMixColumns_Shift(tmp.at(1), 9)) ^ (InvMixColumns_Shift(tmp.at(2), 14)) ^ (InvMixColumns_Shift(tmp.at(3), 11));
        s.at(i).at(3) = (InvMixColumns_Shift(tmp.at(0),11)) ^ (InvMixColumns_Shift(tmp.at(1), 13)) ^ (InvMixColumns_Shift(tmp.at(2), 9)) ^ (InvMixColumns_Shift(tmp.at(3), 14));
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s.at(j).at(i) = OverflowCheck(s.at(j).at(i));
        }
    }
    return;
}

void print(vector<vector<int>>& s){
    cout << "debug:" << endl;
    for(int i=0;i<4;i++){
        cout << " ------------";
        for(int j=0;j<4;j++){
            if(j==0){
                cout << endl << "|";
            }
            if(s.at(j).at(i) < 16){
                cout << "0";
            }
            cout << hex << s.at(j).at(i) << "|";
        }
        cout << endl;
    }
    cout << " ------------" << endl;
    return;
}

int main(){
    vector<vector<vector<int>>> subkey(11,vector<vector<int>>(4,vector<int>(4,0)));
    subkey.at(0).at(0).at(0) = 0x2b;
    subkey.at(0).at(0).at(1) = 0x7e;
    subkey.at(0).at(0).at(2) = 0x15;
    subkey.at(0).at(0).at(3) = 0x16;
    subkey.at(0).at(1).at(0) = 0x28;
    subkey.at(0).at(1).at(1) = 0xae;
    subkey.at(0).at(1).at(2) = 0xd2;
    subkey.at(0).at(1).at(3) = 0xa6;
    subkey.at(0).at(2).at(0) = 0xab;
    subkey.at(0).at(2).at(1) = 0xf7;
    subkey.at(0).at(2).at(2) = 0x15;
    subkey.at(0).at(2).at(3) = 0x88;
    subkey.at(0).at(3).at(0) = 0x09;
    subkey.at(0).at(3).at(1) = 0xcf;
    subkey.at(0).at(3).at(2) = 0x4f;
    subkey.at(0).at(3).at(3) = 0x3c;
    // vector<vector<int>> w = {
    //     {0x2b,0x28,0xab,0x09},
    //     {0x7e,0xae,0xf7,0xcf},
    //     {0x15,0xd2,0x15,0x4f},
    //     {0x16,0xa6,0x88,0x3c},
    // };
    vector<vector<int>> w = {
        {0x2b,0x7e,0x15,0x16},
        {0x28,0xae,0xd2,0xa6},
        {0xab,0xf7,0x15,0x88},
        {0x09,0xcf,0x4f,0x3c},
    };

    vector<int> Rcon = {
        0x00, //0
        0x01, //x^0
        0x02, //x^1
        0x04, //x^2
        0x08, //x^3
        0x10, //x^4
        0x20, //x^5
        0x40, //x^6
        0x80, //x^7
        0x1b, //x^4+x^3+x^1+x^0
        0x36, //x^5+x^4+x^2+x^1
    };

    for(int i=1;i<=10;i++){
        RotWord(w);
        SubWord(w);
        w.at(3).at(0) = w.at(3).at(0) ^ Rcon.at(i);

        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                subkey.at(i).at(j).at(k) = subkey.at(i-1).at(j).at(k) ^ w.at(3).at(k);
                w.at(3).at(k) = subkey.at(i).at(j).at(k);       
            }
        }
    }

    for(int i=0;i<=10;i++){
        cout << "サブ鍵" << i << ":";
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(subkey.at(i).at(j).at(k) < 16){
                    cout << "0";
                }
                cout << hex << subkey.at(i).at(j).at(k);
            }
        }
        cout << endl;
    }
    // vector<vector<int>> s = {
    //     {0x32,0x88,0x31,0xe0},
    //     {0x43,0x5a,0x31,0x37},
    //     {0xf6,0x30,0x98,0x07},
    //     {0xa8,0x8d,0xa2,0x34},
    // };
    vector<vector<int>> s = {
        {0x32,0x43,0xf6,0xa8},
        {0x88,0x5a,0x30,0x8d},
        {0x31,0x31,0x98,0xa2},
        {0xe0,0x37,0x07,0x34},
    };

    cout << "平文:" << endl;
    for(int i=0;i<4;i++){
        cout << " ------------";
        for(int j=0;j<4;j++){
            if(j==0){
                cout << endl << "|";
            }
            if(s.at(j).at(i) < 16){
                cout << "0";
            }
            cout << hex << s.at(j).at(i) << "|";
        }
        cout << endl;
    }
    cout << " ------------" << endl;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s.at(i).at(j) = s.at(i).at(j) ^ subkey.at(0).at(i).at(j);
        }
    }

    for(int N=1;N<=10;N++){
        SubBytes(s);
        ShiftRows(s);
        if(N != 10){
            MixColumns(s);
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                s.at(i).at(j) = s.at(i).at(j) ^ subkey.at(N).at(i).at(j);
            }
        }
    }

    cout << "暗号化:" << endl;
    for(int i=0;i<4;i++){
        cout << " ------------";
        for(int j=0;j<4;j++){
            if(j==0){
                cout << endl << "|";
            }
            if(s.at(j).at(i) < 16){
                cout << "0";
            }
            cout << hex << s.at(j).at(i) << "|";
        }
        cout << endl;
    }
    cout << " ------------" << endl;

//復号
    for(int N=10;N>=1;N--){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                s.at(i).at(j) = s.at(i).at(j) ^ subkey.at(N).at(i).at(j);
            }
        }
        if(N != 10){
            InvMixColumns(s);
        }
        InvShiftRows(s);
        InvSubBytes(s);
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s.at(i).at(j) = s.at(i).at(j) ^ subkey.at(0).at(i).at(j);
        }
    }

    cout << "復号文:" << endl;
    for(int i=0;i<4;i++){
        cout << " ------------";
        for(int j=0;j<4;j++){
            if(j==0){
                cout << endl << "|";
            }
            if(s.at(j).at(i) < 16){
                cout << "0";
            }
            cout << hex << s.at(j).at(i) << "|";
        }
        cout << endl;
    }
    cout << " ------------" << endl;

    return 0;
}