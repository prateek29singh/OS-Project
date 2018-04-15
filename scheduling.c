#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	char p[3];
	float at[3],at1[3];
	int bt[3];
	int i,j,ch,temp;
	int ct[3],t[3],s=0;
	printf("enter the process \n");
	for(i=0;i<3;i++)
	{
		scanf("%s",&p[i]);
	}
	printf("enter arrival time \n");
 	for(i=0;i<3;i++)
	{
			scanf("%f",&at[i]);
	}
	printf("enter burst time\n");
	for(i=0;i<3;i++)
	{
		scanf("%d",&bt[i]);
	}	
	printf("\n******* enter 1 to calculate average turnaround time using fcfs              *********");
	printf("\n******* enter 2 to calculate average turnaround time using sjf               *********");
	printf("\n******* enter 3 to calculate average turnaround time if the cpu is left idle *********\n");
	scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:at1[0]=at[0];
		       ct[0]=at1[0]+bt[0];
		       for(i=1;i<3;i++)
		       {
		       	 ct[i]=ct[i-1]+bt[i];
		       	 at1[i]=ct[i-1];
			   }
			   for(i=0;i<3;i++)
			   {
			   	t[i]=ct[i]-at1[i];
			   	s=s+t[i];
			   }
			   float tt=s/3.0;
			   printf("\nturn around time using fcfs is %f",tt);
			   break;
		case 2:for(i=0;i<3;i++)
		       {
		       	for(j=i+1;j<3;j++)
		       	{
		       	  if(bt[i]>bt[j])
					 {
					   temp=bt[j];
					   bt[j]=bt[i];
					   bt[i]=temp; 	
					 }	
				}
			   }
			   printf("\nnew burst time");
			   for(i=0;i<3;i++)
			   {
			   	printf("\n%d",bt[i]);
			   }
			   at1[0]=at[0];
		       ct[0]=at1[0]+bt[0];
		       for(i=1;i<3;i++)
		       {
		       	 ct[i]=ct[i-1]+bt[i];
		       	 at1[i]=ct[i-1];
			   }
			   for(i=0;i<3;i++)
			   {
			   	t[i]=ct[i]-at1[i];
			   	s=s+t[i];
			   }
			   float stt=s/3.0;
			   printf("\nturn around time using sjf is %f",stt);
			   break;
			   
		default:printf("\ninvalid choice");
		        break;			   
	}
	return 0;
}
