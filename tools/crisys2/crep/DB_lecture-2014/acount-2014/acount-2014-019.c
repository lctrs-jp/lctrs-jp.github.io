#include <stdio.h>

int main()
{
  int p, q, r, s, t, coa=0, cob=0, coc=0, cod=0, coe=0, cof=0, cog=0, coh=0;
  int u, coi=0, coj=0, cok=0, col=0, com=0, con=0, coo=0, cop=0, coq=0;
  int cor=0, cos=0, cot=0, cou=0, cov=0, cow=0, cox=0, coy=0, coz=0;
  char mozi[100];

  printf("文字列を入力してください(長さ100以下):");
  gets(mozi);

  for( p = 0; p < 100; p++){
    if(mozi[p] < 91 && mozi[p] > 64)
      mozi[p] = mozi[p] + 32;
    else
      mozi[p] = mozi[p];
  }


  for( q =0; mozi[q] > 96 && mozi[q] <123 && mozi[q] !='\0'; q++){
    switch(mozi[q]){
    case'a':
      coa++;
      break;
    case'b':
      cob++;
      break;
    case'c':
      coc++;
      break;
    case'd':
      cod++;
      break;
    case'e':
      coe++;
      break;
    case'f':
      cof++;
      break;
    case'g':
      cog++;
      break;
    case'h':
      coh++;
      break;
    case'i':
      coi++;
      break;
    case'j':
      coj++;
      break;
    case'k':
      cok++;
      break;
    case'l':
      col++;
      break;
    case'm':
      com++;
      break;
    case'n':
      con++;
      break;
    case'o':
      coo++;
      break;
    case'p':
      cop++;
      break;
    case'q':
      coq++;
      break;
    case'r':
      cor++;
      break;
    case's':
      cos++;
      break;
    case't':
      cot++;
      break;
    case'u':
      cou++;
      break;
    case'v':
      cov++;
      break;
    case'w':
      cow++;
      break;
    case'x':
      cox++;
      break;
    case'y':
      coy++;
      break;
    case'z':
      coz++;
      break;

    }
  }

  
   return 0;
}
