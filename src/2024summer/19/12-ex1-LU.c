
#include <float.h>
#include <stdio.h>
#include <math.h>
#define M 4


void pivot(double a[M][M], double b[M], double l[M][M], double u[M][M], int pos){
  double max = a[pos][pos];
  int max_pos = pos;
  for(int i = pos; i < M; i++){
    if(max < a[i][pos]){
      max = a[i][pos];
      max_pos = i;
    }
  }

  for(int i = pos; i < M; i++){
    double tmp_a = a[pos][i];
    double tmp_l = l[pos][i];
    double tmp_u = u[pos][i];
    a[pos][i] = a[max_pos][i];
    a[max_pos][i] = tmp_a;
    l[pos][i] = l[max_pos][i];
    l[max_pos][i] = tmp_l;
    u[pos][i] = u[max_pos][i];
    u[max_pos][i] = tmp_u;
  }
  double tmp_b = b[pos];
  b[pos] = b[max_pos];
  b[max_pos] = tmp_b;
}



int main(void){
  double a[M][M]; // 行列A
  double b[M];    // ベクトルB
  double c[M];    // ベクトルC
  double l[M][M]; // 行列L
  double u[M][M]; // 行列U
  double x[M];
  int i, j, k;
  FILE *fp;

  /* データ読み込み */
  fp = fopen("lu_data3.txt", "r");
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      fscanf(fp, "%lf", &a[i][j]);
    }
    fscanf(fp, "%lf", &b[i]);
  }
  fclose(fp);

  for(i=0;i<M;i++){    /* L行列, U行列を1と0で初期化 */
    for(j=0;j<M;j++){
      u[i][j] = 0;
      if(i==j)  l[i][j]=1;
      else      l[i][j]=0;
    }
  }
  /* LU分解 */
  for(i=0;i<M;i++){
    pivot(a, b, l, u, i);
    for(j=i;j<M;j++){  /* U行列の生成 */
      u[i][j]=a[i][j];
      for(k=0;k<i;k++){
        u[i][j] -= u[k][j]*l[i][k];
      }
    }

    for(j=i+1; j<M; j++){  /* L行列の生成 */
      l[j][i]=a[j][i];
      for(k=0;k<i;k++){
        l[j][i] -= u[k][i]*l[j][k];
      }
      l[j][i] /= u[i][i];
    }

  }

  /* 解を求める */
  for(i=0;i<M;i++){    /* C行列の生成 */
    c[i]=b[i];
    for(j=0;j<i;j++){
      c[i] -= l[i][j]*c[j];
    }
  }

  for(i=M-1; i>=0;i--){ /* X行列の生成 */
    x[i]=c[i];
    for(j=M-1;j>i;j--){
      x[i] -= u[i][j] * x[j];
    }
    x[i] /= u[i][i];
  }

  /* 結果の出力 */
  printf("入力行列A\n");
  for(i=0;i<M;i++){    /* 入力行列の出力  */
    for(j=0;j<M;j++){
      printf("%10.5lf", a[i][j]);
    }
    printf("%10.5lf\n", b[i]);
  }

  printf("\nL行列\n");
  for(i=0;i<M;i++){    /* L行列の出力  */
    for(j=0;j<M;j++){
      printf("%10.5lf", l[i][j]);
    }
    printf("\n");
  }

  printf("\nU行列\n");
  for(i=0;i<M;i++){    /* U行列の出力  */
    for(j=0;j<M;j++){
      printf("%10.5lf", u[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  for(i=0; i<M; i++){  /* 解 x の出力 */
    printf("x%d = %10.5lf\n", i, x[i]);
  }

}

/**
入力行列A
   5.00000   4.00000   1.00000   0.00000  16.00000
   3.00000   2.00000   1.00000   1.00000  12.00000
   0.00000   0.00000   3.00000   1.00000   2.00000
   2.00000   1.00000   2.00000   1.00000   9.00000

L行列
   1.00000   0.00000   0.00000   0.00000
   0.60000   1.00000   0.00000   0.00000
   0.00000  -0.00000   1.00000   0.00000
   0.40000   1.50000   0.33333   1.00000

U行列
   5.00000   4.00000   1.00000   0.00000
   0.00000  -0.40000   0.40000   1.00000
   0.00000   0.00000   3.00000   1.00000
   0.00000   0.00000   0.00000  -0.83333

x0 =    4.00000
x1 =   -1.00000
x2 =   -0.00000
x3 =    2.00000
**/

