#include<stdio.h>
int n,i;
typedef struct 
{
    int pid,at,bt,tat,ct,wt;
    
}process;
void findCT(process p[])
{
    p[0].ct=p[0].bt;
    for(i=1;i<n;i++)   // start from one
    {
       p[i].ct=p[i-1].ct+p[i].bt;
    }
   

}
void findTAT(process p[])
{
    for(i=0;i<n;i++)
    {
       p[i].tat=p[i].ct-p[i].at;
    }

}

void findWT(process p[])
{
    for(i=0;i<n;i++)
    {
       p[i].wt=p[i].tat-p[i].bt;
    }

}
void findavgtime(process p[])   //use p[]
{
  findCT(p);  
  findTAT(p);
  findWT(p);

  float total_tat=0;
  float total_wt=0;
  float avg_tat;
  float avg_wt;
  for(i=0;i<n;i++)
    {
       total_tat=total_tat+p[i].tat;
       total_wt=total_wt+p[i].wt;
       
    }
    avg_tat=total_tat/n;
    avg_wt=total_wt/n;
  printf("PID\tAT\tBT\tCT\tTAT\tWT");
  printf("\n");
  for(i=0;i<n;i++)
    {
       printf("%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
       printf("\n");
    }


}
void main()
{
    n=5;
    process p[]={{1,0,8},{2,1,1},{3,2,3},{4,3,2},{5,4,6}};
    findavgtime(p);  // dont use p[]
}