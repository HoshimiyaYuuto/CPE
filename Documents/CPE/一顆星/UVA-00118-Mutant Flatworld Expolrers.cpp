#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct pos {
    int x;
    int y;
};
//左轉
void turnL(char &b) {
    if(b == 'E') b ='N';
    else if(b == 'W') b ='S';
    else if(b == 'S') b ='E';
    else b ='W';
}
//右轉
void turnR(char &b) {
    if(b == 'E') b ='S';
    else if(b == 'W') b ='N';
    else if(b == 'S') b ='W';
    else b ='E';
}
//向前走
void move(int &x, int &y, char b) {
    if(b == 'E') x++;
    else if(b == 'W') x--;
    else if(b == 'S') y--;
    else y++;
}

int main() {
    int M, N;
    vector<pos> no; //用來存警示點
    cin >> M >> N;  //座標右上界

    int X, Y, preX, preY; //X,Y:當下座標, preX, preY:指令前座標
    char bound; //方向
    string ins; //存指令集
    while(cin >> X >> Y >> bound) {
        cin.ignore();   //有個cin不會吃到的換行符號
        getline(cin, ins);  
        for(size_t i=0; i<ins.size(); i++) {    //依指令集進行動作
            preX=X; preY=Y; //更新指令前座標
            if(ins[i] == 'L') turnL(bound);
            else if(ins[i] == 'R') turnR(bound);
            else if(ins[i] == 'F') {
                move(X, Y, bound);
                for(size_t i=0; i<no.size(); i++) {         //檢查是否又在警示點掛掉，若是就讓他復活
                    if(no[i].x == preX && no[i].y == preY && ((X<0)||(X>M)||(Y<0)||(Y>N))) {
                        X=preX; Y=preY;
                    }
                }
            }    
            //cerr << X <<" "<< Y << " " << bound << endl;  (debug用，這題原本沒看清楚要設定警示點防止後面機器人在相同地方掛掉)
            if((X<0)||(X>M)||(Y<0)||(Y>N)) break;
        }
        if((X<0)||(X>M)||(Y<0)||(Y>N)) {
            cout << preX << ' ' << preY << ' ' << bound << ' ' <<"LOST" << endl;    //掛掉就輸出警示點並存入裝警示點的vector
            pos tmp;
            tmp.x=preX;
            tmp.y=preY;
            no.push_back(tmp);
        }    
        else cout << X << ' ' << Y << ' ' << bound << endl;
    }
}    