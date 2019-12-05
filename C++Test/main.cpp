//
//  main.cpp
//  C++Test
//
//  Created by zhouchangxin on 2019/11/7.
//  Copyright © 2019 zhouchangxin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.1415926
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    cout<<"test1\r\n"<<endl;
    
    
    float h = 0.01;
    int L = 40/h;
    int Ap[2][2] = {0,1,-6,-7};
    int Bp[2][1] = {0,8};
    int Am[2][2] = {0,1,-10,-5};
    int Bm[2][1] = {0,2};
    int Sz[1][2] = {2,1};
    int n = 2,m = 1;
    int P[2][2] = {3,1,1,1};
    int R1=1,R2=1;
    float xp[2][1] = {0};
    float xm[2][1] = {0};
    float e[2][1] = {0};
    float F[1][2] = {0};
    float K = 0;
    float u = 0,yr = 0;
    double time = 0;
    float F0[1][2] = {0,0}, K0 = 0, yr0 =0, u0=0, e0[2][1]={0,0}, xp0[2][1]={0,0}, xm0[2][1]={0,0};
    float parae[2][1] = {0};
    
    for(int k=1;k<L;k++)
    {
        time = k*h;
        yr = 1*sin(0.01*PI*time) + 4*sin(0.2*PI*time) + sin(1*PI*time);
        xp[0][0]=xp0[0][0] + h*((Ap[0][0]*xp0[0][0]) + (Ap[0][1]*xp0[1][0]) + (Bp[0][0]*u0));
        xp[1][0]=xp0[1][0] + h*((Ap[1][0]*xp0[0][0]) + (Ap[1][1]*xp0[1][0]) + (Bp[1][0]*u0));//xp[2][1]
        
        xm[0][0]=xm0[0][0] + h*((Am[0][0]*xm0[0][0]) + (Am[0][1]*xm0[1][0]) + (Bm[0][0]*yr0));
        xm[1][0]=xm0[1][0] + h*((Am[1][0]*xm0[0][0]) + (Am[1][1]*xm0[1][0]) + (Bm[1][0]*yr0));//xm[2][1]
        
        e[0][0] = xm[0][0] - xp[0][0];
        e[1][0] = xm[1][0] - xp[1][0];
    
//        F[0][0] = F0[0][0] + h*R1*(Bm[0][0]*P[0][0] + Bm[1][0]*P[1][0]) * e0[0][0] * xp0[0][0];
//        F[0][1] = F0[0][1] + h*R1*(Bm[0][0]*P[0][1] + Bm[1][0]*P[1][1]) * e0[1][0] * xp0[1][0];//F[1][2]
        F[0][0] = F0[0][0] + h*R1*((Bm[0][0]*P[0][0] + Bm[1][0]*P[1][0]) * e0[0][0] + (Bm[0][0]*P[0][1] + Bm[1][0]*P[1][1]) * e0[1][0]) * xp0[0][0];
        F[0][1] = F0[0][1] + h*R1*((Bm[0][0]*P[0][0] + Bm[1][0]*P[1][0]) * e0[0][0] + (Bm[0][0]*P[0][1] + Bm[1][0]*P[1][1]) * e0[1][0]) * xp0[1][0];
        
        float x00 = Bm[0][0]*P[0][0] + Bm[1][0]*P[1][0];
        float x01 = Bm[0][0]*P[0][1] + Bm[1][0]*P[1][1];//Bm*P
        
        K = K0 + h*R2*(x00 * e0[0][0] + x01 * e0[1][0])*yr0;
        u = K*yr + F[0][0]*xp[0][0] + F[0][1]*xp[1][0];
        
//        cout<<xp[1][0]<<",";
        yr0 = yr;
        u0 = u;
        
        e0[0][0] = e[0][0];
        e0[1][0] = e[1][0];
        xp0[0][0] = xp[0][0];
        xp0[1][0] = xp[1][0];
        xm0[0][0] = xm[0][0];
        xm0[1][0] = xm[1][0];
        F0[0][0] = F[0][0];
        F0[0][1] = F[0][1];
        K0 = K;
    }
    return 0;
}
