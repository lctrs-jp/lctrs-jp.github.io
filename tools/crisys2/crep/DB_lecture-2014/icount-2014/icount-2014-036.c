#include <stdio.h>
#include <string.h>

int main()
{
  int a,ia,ib,ic,id,ie,ig,ih,ii,ij,ik,j;
  char style[100];
  int count;
  printf("数字列を入力してください。(長さ100以下)\n");
  
  fgets(style,100,stdin);
  
  j=strlen(style);
  ia=0;
    for(a=0;a<j;a++){
      if(style[a]=='1')
      ia=ia+1;
    }
  printf("1 は%d 個含まれています。\n",ia);

  ib=0;
    for(a=0;a<j;a++){
      if(style[a]=='2')
      ib=ib+1;
    }
  printf("2 は%d 個含まれています。\n",ib);

  ic=0;
    for(a=0;a<j;a++){
      if(style[a]=='3')
      ic=ic+1;
    }
  printf("3 は%d 個含まれています。\n",ic);


  id=0;
    for(a=0;a<j;a++){
      if(style[a]=='4')
      id=id+1;
    }
  printf("4 は%d 個含まれています。\n",id);

  ie=0;
    for(a=0;a<j;a++){
      if(style[a]=='5')
      ie=ie+1;
    }
  printf("5 は%d 個含まれています。\n",ie);

  ig=0;
    for(a=0;a<j;a++){
      if(style[a]=='6')
      ig=ig+1;
    }
  printf("6 は%d 個含まれています。\n",ig);

  ih=0;
    for(a=0;a<j;a++){
      if(style[a]=='7')
      ih=ih+1;
    }
  printf("7 は%d 個含まれています。\n",ih);

  ii=0;
    for(a=0;a<j;a++){
      if(style[a]=='8')
      ii=ii+1;
    }
  printf("8 は%d 個含まれています。\n",ii);

  ij=0;
    for(a=0;a<j;a++){
      if(style[a]=='9')
      ij=ij+1;
    }
  printf("9 は%d 個含まれています。\n",ij);

  ik=0;
    for(a=0;a<j;a++){
      if(style[a]=='0')
      ik=ik+1;
    }
  printf("0 は%d 個含まれています。\n",ik);

    return 0;
}
