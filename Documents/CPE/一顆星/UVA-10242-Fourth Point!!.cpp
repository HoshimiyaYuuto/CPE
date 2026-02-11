//給定3個座標，求第4個
//測資給4個座標，依序看前兩個座標構成第一條邊，後兩座標構成第二條邊
//其中前兩座標與後兩座標內各取一個座標會是同個座標，需分4種情況討論
#include <iostream>
#include <iomanip>
using namespace std;
//座標
struct cor{
    double x;
    double y;
};

int main(){
    cor data[4];
    while(cin >> data[0].x >> data[0].y){   //先輸入確保還有測資
        cor p;
        for(int i=1;i<4;i++){               //輸入剩下的測資
            cin >> data[i].x >> data[i].y;
        }
        if(data[0].x==data[2].x && data[0].y==data[2].y){       //0號和2號座標相同
            p.x=data[3].x+data[1].x-data[0].x;
            p.y=data[3].y+data[1].y-data[0].y;
        }
        else if(data[1].x==data[2].x && data[1].y==data[2].y){  //1號和2號座標相同
            p.x=data[3].x+data[0].x-data[1].x;
            p.y=data[3].y+data[0].y-data[1].y;
        }  
        else if(data[0].x==data[3].x && data[0].y==data[3].y){  //0號和3號座標相同
            p.x=data[2].x+data[1].x-data[0].x;
            p.y=data[2].y+data[1].y-data[0].y;
        }
        else{                                                   //1號和3號座標相同
            p.x=data[2].x+data[0].x-data[1].x;
            p.y=data[2].y+data[0].y-data[1].y;
        }     
        cout << fixed << setprecision(3) << p.x << ' ' << p.y << endl;
    }
}