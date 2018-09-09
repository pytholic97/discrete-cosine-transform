#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
Sample i/o
Enter the size of the blocks  - space separated	8 8
Enter the pixels of the block
1 2 3 4 5 6 7 8
122 211 212 222 33 1 1 2
23 34 45 56 78 123 234 124
1 2 3 4 5 6 7 8
1 2 1 3 1 5 1 6
99 98 94 53 23 65 43 45
12 12 23 3 44 55 4 33
255 255 255 255 0 0 0 0
417.375 147.825 -6.920 -74.053 -35.125 46.320 -5.928 -37.537
-59.870 -122.926 -20.786 3.624 -13.902 1.003 -40.233 19.880
146.611 209.620 -24.599 -76.647 12.324 25.173 4.076 -40.020
-201.673 -54.942 6.287 48.045 14.717 -62.589 37.592 13.335
-139.375 72.039 7.494 -8.583 35.625 6.594 7.314 -10.906
-194.644 -234.358 22.885 105.082 4.748 -45.113 18.764 49.564
107.990 -75.261 58.326 36.124 -30.676 41.282 -12.401 16.145
-68.449 -188.450 12.533 62.491 -6.356 -3.853 -11.391 34.995
IDCT is:
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0
122.0 211.0 212.0 222.0 33.0 1.0 1.0 2.0
23.0 34.0 45.0 56.0 78.0 123.0 234.0 124.0
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0
1.0 2.0 1.0 3.0 1.0 5.0 1.0 6.0
99.0 98.0 94.0 53.0 23.0 65.0 43.0 45.0
12.0 12.0 23.0 3.0 44.0 55.0 4.0 33.0
255.0 255.0 255.0 255.0 0.0 -0.0 0.0 0.0
**/


#define SZ 10

int main(){
  int m,n,i,j,l,u,v;
  float k;
  float in[SZ][SZ],dct[SZ][SZ],idct[SZ][SZ];
  float csum = 0;
  printf("Enter the size of the blocks - space separated\t");
  scanf("%d %d",&m,&n);

  if(m >= SZ || n >= SZ){
    printf("Out of bounds\n");
    exit(1);
  }

  printf("Enter the pixels of the block\n");
  for(i = 0;i < m;i++)
    for(j = 0;j < n;j++)
      scanf(" %f",&in[i][j]);

  for(i = 0;i < m;i++){
    for(j = 0;j < n;j++){
      for(u = 0;u < m;u++)
        for(v = 0;v < n;v++)
          csum += in[u][v]*cos((2*u+1)*i*M_PI/(2*m))*cos((2*v+1)*j*M_PI/(2*n));
      if(!i && !j) k = 0.5;
      else if((!i && j) || (i && !j)) k = 1/sqrt(2);
      else k = 1;
      dct[i][j] = 2*csum*k/n;
      printf("%.3f ",dct[i][j]);
      csum = 0;
    }
    printf("\n");
  }

  printf("IDCT is:\n");
  csum = 0;
  for(i = 0;i < m;i++){
    for(j = 0;j < n;j++){
      for(u = 0;u < m;u++)
        for(v = 0;v < n;v++){
          if(!u && !v) k = 0.5;
          else if((!u && v) || (u && !v)) k = 1/sqrt(2);
          else k = 1;
          csum += k*dct[u][v]*cos((2*i+1)*M_PI*u/(2*m))*cos((2*j+1)*M_PI*v/(2*n));
        }
      idct[i][j] = csum*2/n;
      csum = 0;
      printf("%0.1f ",idct[i][j]);
    }
    printf("\n");
  }

return 0;
}
