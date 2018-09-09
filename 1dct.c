#include <stdio.h>
#include <math.h>

#define SZ 10

int main(){
  int i,j,u,v,n;

  float dct[SZ],in[SZ],idct[SZ];

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf(" %f",&in[i]);
  float csum = 0;
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
