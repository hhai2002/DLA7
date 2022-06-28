/*
//////////////////////////////////////////////////
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='


     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     No errors			         No bugs
//////////////////////////////////////////////////
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>

//#include <iostream>
//#include <string>
//#include <limits>
//#include <cmath>
//#include <random>
//#include <chrono>
//#include <iomanip>
//#include <ios>
//#include <cassert>

double ** sor(double ** c_matrix, int row, int col, int n, double w){
    int adjacent[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    double *** C = (double***)calloc(n+1,sizeof(double**));
    C[0] = c_matrix;
    for(int i=1;i<=n;++i){
        C[i] = (double**)calloc(row,sizeof(double*));
        for(int j=0;j<row;++j){
            C[i][j] = (double*)calloc(col,sizeof(double));
        }
    }
    for(int rep = 1; rep<= n; ++rep){
        for (int i = 0;i<row;++i){
            for(int j=0;j<col;++j){
                double result = 0.0;
                result += C[rep-1][i+1][j] + C[rep-1][i][j+1];
                for(int k=2;k<=3;++k){
                    int r = i + adjacent[k][0];
                    int c = j +adjacent[k][1];
                    if(r >=0 && r< row&& c >=0 && c<col){
                        result += C[rep][r][c];
                    }
                }
                result *= w / 4.0;
                result += C[rep-1][i][j] * (1.0 - w);
                C[rep][i][j] = result;
            }
        }
    }
    return C[n];
}


int main(){
    double ** c_matrix = (double**)calloc(4,sizeof(double*));
    for(int i=0;i<4;++i){
        c_matrix[i] = (double*)calloc(4,sizeof(double));
    }
    c_matrix[0][0] = 1.0;
    c_matrix = sor(c_matrix,4,4,5,1.5);
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            printf("%.8lf\t",c_matrix[i][j]);
        }
        printf("\n");
    }
}
