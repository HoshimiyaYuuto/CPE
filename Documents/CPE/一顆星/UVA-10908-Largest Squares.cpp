//!!!!程式答案錯誤就檢查自己哪邊變數打錯或越界存取!!!
#include <iostream>
using namespace std;

int main() {
    int T;
    if(!(cin >> T)) {
        return 0;
    }
    while(T--){ //T:測資數
        int M, N, Q, r ,c;  //M*N的矩陣, Q個測試點, (r,c)為點在矩陣的位置
        char mat[100][100];
        if(!(cin >> M >> N >> Q)) {
            return 0;
        }
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cin >> mat[i][j];
            }
        }
        cout << M << ' ' << N << ' ' << Q << endl;

        while(Q--) {
            cin >> r >> c;
            int in=1, ans=1;    //in:檢查周圍元素用的索引, ans:最大的正方形邊長
            bool end=false;
            while(!end) {       //沒終止就繼續找下層
                end=false;      //重設終止布林變數
                for(int i=-in; i<=in; i++) {
                    if(end) break;
                    for(int j=-in; j<=in; j++) {    //打成i<=in過，其他程式也注意迴圈內條件有沒有打錯變數
                        if(r+i<0 || r+i>M-1 || c+j<0 || c-j>N-1 || mat[r+i][c+j] != mat[r][c]) { //打成r+i>N-1過，其他程式也注意判斷式條件有沒有打錯變數
                            end=true;               //有不同或越界就停止比對
                            break;
                        }    
                    }
                }
                if(!end) {      //沒終止代表可以繼續比到下層
                    ans += 2;
                    in++;
                }    
            }
            cout << ans << endl;     
        }
    }    
}