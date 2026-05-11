ATTENDANCE sum(ATTENDANCE d[MAX],int size)
/*合計を計算する*/
{int  i,Alice,Bob,Carol,total;
ATTENDANCE avg;
/*各日付ごとの合計を計算*/
for (i=0;i<size;i++){
  d[i].total=d[i].Alice+d[i].Bob+d[i].Carol;
 }
