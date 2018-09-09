#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
Sample i/o
Size of DCT	8
Enter the elements
1 2 3 4 5 6 7 8
DCT is
25.456 -12.885 -0.000 -1.347 0.000 -0.402 0.000 -0.101
IDCT is:
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 
**/



#define SZ 10

int main(){
  int i,j,u,v,n;

  float dct[SZ],in[SZ],idct[SZ];
  printf("Size of DCT\t");
  scanf("%d",&n);
  if( n < SZ )
    printf("Enter the elements\n");
  else{
    printf("Out of bounds\n");
    exit(1);
  }
  for(i = 0;i < n;i++)
    scanf(" %f",&in[i]);
  float csum = 0;
  printf("DCT is \n");
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++)
      csum += in[j]*cos((2*j+1)*M_PI*i/(2*n));
    dct[i] = i == 0 ? (csum/sqrt(2)) : csum;
    csum = 0;
    printf("%0.3f ",dct[i]);
}

printf("\nIDCT is:\n");
float k = 0;
for(i = 0;i < n;i++){
  for(j = 0;j < n;j++){
    k = dct[j]*cos((2*i+1)*M_PI*j/(2*n));
    csum += (j == 0) ? (k/sqrt(2)) : k;
  }
  idct[i] = csum*2/n;
  csum = 0;
  printf("%.1f ",idct[i]);
}
printf("\n");

return 0;
}
