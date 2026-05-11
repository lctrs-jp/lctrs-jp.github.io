#include <stdio.h>

int main(int argc, char *argv[])
{
  
int x=0,y=0,z=0,w=0,u=0;

 if(argc==0){
  x=(argv[1][0]-64);
   printf("%d\n",x);
}  

else if(argc==1){
  x=1*(argv[1][1]-64);
  y=26*(argv[1][0]-64);
   printf("%d\n",x+y);
}  

else if(argc==2){
  x=1*(argv[1][2]-64);
  y=26*(argv[1][1]-64);
  z=26*26*(argv[1][0]-64);
  printf("%d\n",x+y+z);
} 

else if(argc==4){
  x=1*(argv[1][3]-64);
  y=26*(argv[1][2]-64);
  z=26*26*(argv[1][1]-64);
  w=26*26*26*(argv[1][0]-64);
 printf("%d\n",x+y+z+w);
}  

else if(argc==5){
  x=1*(argv[1][4]-64);
  y=26*(argv[1][3]-64);
  z=26*26*(argv[1][2]-64);
  w=26*26*26*(argv[1][1]-64);
  u=26*26*26*26*(argv[1][0]-64);
 printf("%d\n",x+y+z+w+u);
}  

 


  return 0;
}
