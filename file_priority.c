

#include<stdio.h>
int n,i,j;
typedef struct 
{
    int pid,at,bt,pr,tat,ct,wt;    //add priority
    
}process;
void sortPR(process p[])
{
    process temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (p[j].pr>p[j+1].pr)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }

        }
    }
}
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
    process p1[]={{1,0,4,1},{2,1,3,2},{3,3,2,3},{4,5,1,4},{5,6,4,5}}; //add priority
    sortPR(p1); 
    int total_bt=0;
    int j =0;
    int i=0;
    int currenttime=0;
    process p[]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

     for(i=0;i<n;i++)
    {
       total_bt=total_bt+p1[i].bt;
       
       
    }
    while (currenttime<=total_bt)  //use equal to
    {
        for(i=0;i<n;i++)
        {
        if (currenttime>=p1[i].at && p1[i].at!=-1)
        {
            p[j]=p1[i];
            j++;
            p1[i].at=-1;
            break;
        }
        }
        currenttime+=p[j-1].bt;   //j already incremented so j-1
    }  
    



    findavgtime(p);  // dont use p[]
}