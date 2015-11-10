/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 12时06分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int rec1 = (C - A) * (D - B);
    int rec2 = (G - E) * (H - F);
    int width, height;
    if(E >= C || G <= A)
        width = 0;
    else if(E >= A) {
        if(G >= C)
            width = C - E;
        else
            width = G - E;
    }
    else if(E < A) {
        if(G >= C)
            width = C - A;
        else
            width = G - A;
    }
    if(F >= D || H <= B)
        height = 0;
    else if(F >= B) {
        if(H >= D)
            height = D - F;
        else
            height = H - F;
    }
    else if(F < B) {
        if(H >= D) 
            height = D - B;
        else
            height = H - B;
    }
    int area = rec1 + rec2 - width * height;
}

int main() {
    return 0;
}
