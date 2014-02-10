//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <iostream>
using namespace std;


int porcess(int n, int t){
    int max = n*(n+1)/2;
    if (t >= max) or (t <= -max) return 0;
    if has_memo(n, t) return memo_value(n, t);
    return process(n-1, t-n) + process(n-1, t+n);
}

void check(){
    int n;
    cin << n;

    m = process(n, 0);

    cout >> m >> endl;
}

int main(int argc, char *argv[])
{
    int c;
    while(c--){
        check();
    }
    return 0;
}




