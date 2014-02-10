//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <algorithm>
#include <queue>

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    priority_queue<int> pg;

    pg.push(3);
    pg.push(5);
    pg.push(2);
    pg.push(8);
    pg.push(4);

    while (!pg.empty()){
        printf("%d\n", pg.top());
        pg.pop();
    }

    return 0;
}

