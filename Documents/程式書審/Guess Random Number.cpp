#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main() {
	srand((unsigned)time(NULL));     //亂數種子
    int digit;
	cout << "來玩猜數字:)" << endl;
	cout << "先輸入你想猜的位數, 每回合輸入你猜的數字~"<< endl;  //規則介紹
	cout << "電腦會回應你A和B的數量, A代表數字和位置都正確, B代表數字正確但位置錯誤" << endl;
	cout << "如果放棄了就輸入-1, 我會告訴你正確答案哦~" << endl;
	cout << "你現在想猜幾位數呢? (最少2位數, 最多10位數)" << endl;
	while (cin >> digit && digit<2 || digit>10) {   //檢測位數是否符合規範
		cout << "位數不符合限制哦!" << endl;
	}
	int ran[10], guess[10], number, turn = 0, count;  
	bool end = false;  //迴圈檢測終止用
	ran[0] = rand() % 9 + 1;
	for (int i = 1; i < digit; i++) {
		ran[i] = rand() % 10;          //生成亂數
	}
	while (end == false) {
		turn++;  //計算回合數
		cout << "ROUND " << turn << "  請輸入一組" << digit << "位數:";
		while (cin >> number && (number != -1 && number < pow(10, digit - 1) || number>pow(10, digit)-1)) {
			cout << "不符合規範哦:( 請重新輸入一組" << digit << "位數" << endl;  //檢測猜的數是否符合規範
		}
		if (number == -1) {     //若放棄會直接顯示答案並終止遊戲
			cout << "正確答案為: ";
			for (int i = 0; i < digit; i++) {
				cout << ran[i];
			}
			cout << endl;
			break;
		}
		count = pow(10, digit - 1);  //計算用參數
		for (int j = 0; j < digit; j++) {
			guess[j] = number / count % 10;  //將猜的數字以陣列方式儲存，以方便比對
			count /= 10;
		}
		int A = 0, B = 0;
		for (int j = 0; j < digit; j++) {  //計算A和B之數量
			if (ran[j] == guess[j]) {
				A++;
				continue;
			}
			for (int k = 0; k < digit; k++) {
				if (ran[j] == guess[k] && j != k) {
					B++;
					break;
				}
			}
		}
		if (A == digit) {  //輸出每回合的結果, 猜中即終止遊戲
			cout << "恭喜你猜中了:D , 你花了" << turn << "次猜中正解";
			end = true;
		}
		else if (A == 0 && B == 0) {
			cout << "槓龜 再接再厲";
		}
		else {
			cout << A << "A" << B << "B";
		}
		cout << endl;
	}
}