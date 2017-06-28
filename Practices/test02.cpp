//DP
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXM 100
#define MAXN 100

int r[MAXN][MAXM];
int max_ret[MAXN][MAXM];

//n compay, m money
void calc (int n, int m)
{
  int i,j,k,max,t;

  for(i=0 ; i<=m ; i++) {
    max_ret[0][i] = r[0][i];
  }

  for(i=1 ; i<n ; i++) {
    for(j=1 ; j<=m ; j++) {
        max = -1;
        for(k=0 ; k<=j ; k++) {
            t = max_ret[i-1][k] + r[i][j-k];
            if (t>max) max = t;
            cout<<t<< " ";
        }
        max_ret[i][j] = max;
        cout<<"m "<<max<<", ";
    }
    cout<<endl;
  }

}


int main(void)
{
  int n = 3, m = 4;
  int i;

  for(i=0 ; i<n ; i++)
    r[i][0] = 0;

  r[0][1] = 2; r[0][2] = 4; r[0][3] = 7; r[0][4] = 9;
  r[1][1] = 3; r[1][2] = 5; r[1][3] = 6; r[1][4] = 8;
  r[2][1] = 1; r[2][2] = 3; r[2][3] = 7; r[2][4] = 9;
  calc(3,4);

  cout<<"Max "<<max_ret[n-1][m]<<endl;

  return 0;
}
