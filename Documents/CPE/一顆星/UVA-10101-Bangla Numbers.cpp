//奇怪的進位制轉換，此題應該有多種作法
//以下為我初見此題目的作法，須清楚數字單位與索引間的關係
//此題測資挺嚴格(?，且要注意輸出格式
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int c=1;    //Case索引   
    string str; //存輸入數字的字串
    string unit[4]={"shata", "hajar", "lakh", "kuti"};  //單位
    while(cin >> str){
        cout << "   " << c << ". " ;    //此題神奇的輸出格式
        c++;

        if(str=="0"){               //!重要!:此做法要特別處理0的輸出，否則會錯誤
            cout << '0' << endl;    //0要直接輸出0
            continue;
        }
        //此作法核心:從數字後面分段丟進vector內，再對應單位
        //我在此處是從後面往前看，一個數值和一個單位為一組
        vector<string> v;
        int index=0, i=str.size();  
        while(i>0){
            if(index%4==1 || i==1) {    //注意單位"shata"(或以我作法的視角看和"hajar"同組)的數字只能為一位數
                i--;    //先扣掉
                v.push_back(str.substr(i, 1));  //再擷取字串存進vector   
            }    
            else {      //其他都是兩位數
                i-=2;   //與上面同理
                v.push_back(str.substr(i, 2));
            }
            index++;
        }

        /*  debug用
        for(size_t i=0;i<v.size();i++){
            cerr << v[i] << ' ';
        }
        cerr << index << endl;
        */
        //找單位對應，特別注意輸出的值對應到的單位與上面的分組比起來會左移1
        while(--index>0){
            if(v[index]=="0" || v[index]=="00"){    //要排除數值為0的情況不做輸出
                if((index-1)%4==3) cout << "kuti" << ' ';   //但"kuti"為最大單位，會循環到，所以要特別在該輸出的時候輸出
                continue; 
            }
            else if (v[index][0]=='0') cout << v[index][1] << ' ';  //還要排除數值為二位數的前綴0不能輸出
            else cout << v[index] <<  ' ';  //其他數值才能正常輸出
            cout << unit[(index-1)%4] << ' ';   //輸出單位
        }
        if(v[0]!="00") {    //處理最後的數值
            if(v[0][0]=='0') cout << v[0][1];
            else cout << v[0];
        }    
        cout << endl;       
    }
}