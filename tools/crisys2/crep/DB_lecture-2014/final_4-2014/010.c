void sort(ATTENDANCE item[MAX],int count)
{
 int a,b;
 ATTENDANCE t;
 for (a=1;a< count; a++)
   for(b=count-1;b>=a;b--){
 if (item[b-1].total<item[b].total){
  t=item[b-1];
  item[b-1]=item[b];item[b]=t;
 }
 }
}
