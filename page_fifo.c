#include<stdio.h>
#include<stdlib.h>
int fr=3;
int frame[]={-1,-1,-1};

int pg=7;
int hit=0;
int i,j;
int rear=-1;
void display()
{
    for(j=0;j<fr;j++)
    {
        if (frame[j]!=-1)
        {
            printf("%d ",frame[j]);
        }
        else
        {
            printf("- ");

        }

    }
    printf("\n");
    
}
int fifo(int page[])
{
    display();
    int pf=0;
    int found=-1;
    for(i=0;i<pg;i++)
    {
     for(j=0;j<fr;j++)
     {
        if (page[i]==frame[j])
        {
             found=1;
             hit++;
             break;
        }
        else
        {
            found=-1;
            pf++;
        }
        
    }
    if (found==-1)
        {
            if (rear<fr-1)
            {
                rear++;
            }
            else
            {
             rear=0;
            }
            frame[rear]=page[i];
     }
     display();

}
return pg;
}

void main()
{
   
    int page[]={4,3,1,8,1,2,6};
    printf("page faults : %d",fifo(page));

}