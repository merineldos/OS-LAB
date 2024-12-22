
#include<stdio.h>
#include<stdlib.h>
int counter[]={0,0,0};
int frames[]={-1,-1,-1};
int fr=3;
int i,j;
int pf=0;   //page faults
void display()
{
    for(j=0;j<fr;j++)
    {
        if (frames[j]!=-1)
        {
            printf("%d ",frames[j]);
        }
        else
        {
            printf("- ");

        }

    }
    printf("\n");
    
}
int findLRU()
{
    int frame=0;
     int max=counter[0];
    for(j=0;j<fr;j++)
    {
       
        if(counter[j]>max)
        {
            max=counter[j];
            frame=j;
            
        }

    }
    return frame;

}
int lru(int pages[],int n)
{
display();
int found;
for(i=0;i<n;i++)
{
    found=0; //not found outside the loop
    for(j=0;j<fr;j++)
    {
      if (pages[i]==frames[j])
      {
        found=1;
    
        break;



      }
    }
    int lruframe;
    if (found==0)
    {
        lruframe=findLRU();
        frames[lruframe]=pages[i];
        pf++;

    }

    for(j=0;j<fr;j++)
    {
        counter[j]++;
    }

    
    //counter[lruframe]=0;

    for(j=0;j<fr;j++)
    {
        if (pages[i]==frames[j])
        {
            counter[j]=0;
        }
    }
           
        
 display();

}
return pf;

}

void main()
{
int pages[]={3,1,8,1,6,2,6};    
int n=7;
printf("%d", lru(pages,n));
}

