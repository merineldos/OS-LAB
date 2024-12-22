#include<stdio.h>
#include<stdlib.h>
int n=5;

int calcseektime(int request[])
{
    int total=0,seektime;
    int current=50;
    for(int i=0;i<n;i++)
    {
        seektime=abs(current-request[i]);
        current=request[i];
        printf("%d-->",request[i]);
        total=total+seektime;
    }
    return total;
}
void main()
{
int request[]={70,20,90,40,130};
printf("/n");
printf("%d",calcseektime(request));

}