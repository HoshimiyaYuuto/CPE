//算2011年日期對應到週幾
#include <iostream>
#include <string>
using namespace std;

//用來算天數總和
int dCnt(int month, int date){
    const int days[]={31,28,31,30,31,30,31,31,30,31,30,31}; //月份天數
    int sum=0;  
    for(int i=1;i<month;i++){   //先算月份的天數總和
        sum+=days[i-1];
    }
    sum+=date;  //加上日期的天數總和
    return sum;
}

//判斷週幾並輸出
void cWeekdays(int sum){
    const string weekdays[]={"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"}; //由測資可推得，1/1為Saturday，起始點設成Friday
    int index=sum%7;    
    cout << weekdays[index] << endl;
}

int main(){
    int cases;
    if(!(cin >> cases)) return 0;
    while(cases--){
        int month, date;
        cin >> month >> date;
        int sumDate=dCnt(month, date);
        cWeekdays(sumDate);
    }
}