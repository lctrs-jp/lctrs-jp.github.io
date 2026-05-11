#include<stdio.h>

int main(void)
{
  
  char str[256];
  int i; // 数えられる数
  int j; // 桁数を変える
  int k0=0, k1=0, k2=0,k3=0,k4=0,k5=0,k6=0,k7=0, k8=0, k9=0; //数を数える
  int l;
  
  printf ("数字列を入力して下さい: ") ;
  scanf ("%s", str);
  
  for (l = 0; l < 256; l++) {
    if (str[l] == '\0')
      break;
  }
  
  //for( l = 0; l < 256){
  //  putchar(str[l]) ;
  //}
  
  /* for( i = 0; i < 10; i++ ){
     k=0;
     for (j = 0; j < 256; j++){   
     if( str[j] == 'i')
     k = k + 1;
     else if ( str[j] == '\0')
     break;   
     }
     printf("%d は　%d個含まれています。\n", i, k);
     }*/
  
  
  for (j = 0; j < 256; j++){
    if( str[j] == '0')
      k0 = k0 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("0 は　%d個含まれています。\n", k0);
  
  
  
  for (j = 0; j < 256; j++){
    if( str[j] == '1')
      k1 = k1 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("1 は　%d個含まれています。\n" ,k1);
  
  
  
  for (j = 0; j < 256; j++){
    if( str[j] == '2')
      k2 = k2 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("2 は　%d個含まれています。\n", k2);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '3')
      k3 = k3 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("3 は　%d個含まれています。\n", k3);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '4')
      k4 = k4 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("4 は　%d個含まれています。\n", k4);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '5')
      k5 = k5 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("5 は　%d個含まれています。\n", k5);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '6')
      k6 = k6 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("6 は　%d個含まれています。\n", k6);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '7')
      k7 = k7 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("7 は　%d個含まれています。\n", k7);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '8')
      k8 = k8 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("8 は　%d個含まれています。\n", k8);
  
  for (j = 0; j < 256; j++){
    if( str[j] == '9')
      k9 = k9 + 1;
    else if ( str[j] == '\0')
      break;
  }
  printf("9 は　%d個含まれています。\n", k9);
  
  return 0;
}
