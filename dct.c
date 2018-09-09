#include <stdio.h>
#include <math.h>

#define SZ 10

int main(){
  int m,n,i,j,l,u,v;
  float k;
  float in[SZ][SZ],dct[SZ][SZ],idct[SZ][SZ];
  float csum = 0;
  printf("Enter the size of the blocks  - space separated\t");
  scanf("%d %d",&m,&n);

  if(m >= SZ || n >= SZ){
    printf("Out os bounds\n");
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
