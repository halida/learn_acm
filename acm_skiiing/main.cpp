//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
// problem: http://acm.nyist.net/JudgeOnline/problem.php?pid=10
//----------------------------------------------------------
#include <iostream>
using namespace std;

#define MAX 105
int dp1[MAX][MAX];
int dp2[MAX][MAX];
int map[MAX][MAX];

void check(){
    int r, c;
    int i, j, p;
    int me;

    cin >> r >> c;
    // cout << "r: " << r << "c: " << c << endl;
    // get data
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            cin>>map[i][j];
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }

    // cout << "counting.." << endl;

    // loop check flow
    int (*dp)[MAX][MAX];
    int (*dp_old)[MAX][MAX];
    int (*dp_temp)[MAX][MAX];

    dp = &dp1;
    dp_old = &dp2;

    int o, n;
    for(p=0; p<r*c; p++){
        o = 0;

        //swap
        dp_temp = dp;
        dp = dp_old;
        dp_old = dp_temp;

        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                me = map[i][j];
                (*dp)[i][j] = (*dp_old)[i][j];

                if (i>0 and map[i-1][j]<me and (*dp)[i][j] <= (*dp_old)[i-1][j]){
                    (*dp)[i][j] = (*dp_old)[i-1][j] + 1;
                    o++;
                }
                if (i<r and map[i+1][j]<me and (*dp)[i][j] <= (*dp_old)[i+1][j]){
                    (*dp)[i][j] = (*dp_old)[i+1][j] + 1;
                    o++;
                }
                if (j>0 and map[i][j-1]<me and (*dp)[i][j] <= (*dp_old)[i][j-1]){
                    (*dp)[i][j] = (*dp_old)[i][j-1] + 1;
                    o++;
                }
                if (j<c and map[i][j+1]<me and (*dp)[i][j] <= (*dp_old)[i][j+1]){
                    (*dp)[i][j] = (*dp_old)[i][j+1] + 1;
                    o++;
                }
            }
        }
        if (o == 0) break;
    }

    //get max
    int ma, mv=-1;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if (mv < (*dp)[i][j]){
                ma = map[i][j];
                mv = (*dp)[i][j];
            }
        }
    }    
    cout<<ma<<endl;
}

int main(int argc, char *argv[])
{
    int n;

    cin >> n;

    while(n--){
        // cout << "get data" << endl;
        check();
    };
    return 0;
}
