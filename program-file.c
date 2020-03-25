 
//program to evaluate best process scheduling algorithm.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
int no_of_process;
int pr[20],pr2[20];
float sum_wt,avg_wt;
int fcfs(int btf[20],int prof[20]);
int sjf(int bts[20],int pros[20]);
int ps(int btp[20],int prop[20]);
int rr(int btr[20],int pror[20]);
int mq(int btm [20],int prom[20] );

int compare(int a,int b,int c,int d,int e)
{
    	if(a<<b && a<<c && a<<d && a<<e)
	return(a);

	else if(b<<a && b<<c && b<<d && b<<e)
	return(b);

	else if(c<<a && c<<b && c<<d && c<<e)
	return(c);

	else if(d<<a && d<<b && d<<c && d<<e)
	return(d);

	else if (e<<d && e<<b && e<<c && e<<a)
	return(e);
}

int main()
{
	int bt[20],wt[20],pro[20],btf[20],prof[20], bts[20], pros[20],btp[20],prop[20],btr[20],pror[20],btm [20],prom[20];
	printf("Enter no of processes:");	
	scanf("%d",&no_of_process);
	int i;
	float f,s,p,r,m,tom=0.00;
	char z;		

	for(i=1;i<=no_of_process;i++)
	{
		printf("\n Enter burst time of process P%d:",i);
		scanf("%d",&bt[i]);
	}
	printf("\n no of process:%d\n",no_of_process);

	for(i=1;i<=no_of_process;i++)
		pro[i]=i;

	printf("\nProcesses:\t\tBurst Time:");
	
	for(i=1;i<=no_of_process;i++)	
	{
		printf("\n P%d\t\t\t%d\n",i,bt[i]);
	}
	
	int choice,x,y, temp;
	
	printf("\n FIRST-COME-FIRST-SERVE SCHEDULING BEGINS:");	
	for(i=1;i<=no_of_process;i++)
	{
		prof[i]=pros[i]=prop[i]=pror[i]=prom[i]=pro[i];
		btf[i]=bts[i]=btp[i]=btr[i]=btm[i]=bt[i];
	}
	f=fcfs(btf,prof);//fcfs call
	s=sjf(bts,pros);//sjf call
	p=ps(btp,prop);//ps call
	m=mq(btm,prom);//mq call
	r=rr(btr,pror);	//rr call
	
	printf("   |============================|==================================|\n");
	printf("   |  	    ALGORITHM     	|      AVERAGE WAITING TIME (in ms)|\n");
	printf("   |============================|==================================|\n");
	printf("   |1.  FIRST-COME-FIRST-SERVE  |		%f			\n",f);
	printf("   |				|				 	 \n");
	printf("   |2.  SHORTEST-JOB-FIRST	|		%f		 	 \n",s);
	printf("   |				|				 	 \n");
	printf("   |3.  ROUND ROBIN		|		%f		 	 \n",r);
	printf("   |				|				 	 \n");
	printf("   |4.  PRIORITY SCHEDULING	|		%f		 	 \n",p);
	printf("   |				|				 	 \n");
	printf("   |5.  MULTILEVEL QUEUE 	|		%f			 \n",m);
	printf("   |____________________________|__________________________________\n");
 	tom=compare(f,s,p,r,m);
	printf("\n\nTHE BEST SCHEDULING ALGORITHM IS:");
	if(tom==r)
		printf("\n\t FIRST-COME-FIRST-SERVE!\n HAVING AVERAGE WAITING TIME:%f",f);
	else if(tom==f)		
		printf("\n\t SHORTEST-JOB-FIRST!\n HAVING AVERAGE WAITING TIME :%f",s);
        else if(tom==p)
                printf("\n\t PRIORITY SCHEDULING!\n HAVING AVERAGE WAITING TIME:%f",p);
        else if(tom==s)
            printf("\n \t ROUND ROBIN!\n HAVING AVERAGE WAITING TIME :%f",r);
        else if(tom==m)
            printf("\n\t MULTILEVEL QUEUE!\n HAVING AVERAGE WAITING TIME: %f",m);
        
        else
		 printf("\n Invalid output!!!!!");
fflush(0);

}//main

int fcfs(int btf[20],int prof[20])
{	
	int i, wtf[20];
	float sum_wt_fcfs,avg_wt_fcfs;
	printf("\nProcesses:\t\tWaiting Time");

	for(i=1;i<=no_of_process;i++)	
	{ 
		if(i==1)
		{
			wtf[1]=0;
		}
		else
		{
		 	wtf[i]=btf[i-1]+wtf[i-1];
		}

		printf("\n P%d\t\t\t%d\n",prof[i],wtf[i]);
		
		sum_wt=sum_wt+wtf[i];
	}

	avg_wt=sum_wt/no_of_process;
	avg_wt_fcfs=avg_wt;
	sum_wt_fcfs=sum_wt;
	avg_wt=sum_wt= 0;
	printf("\n sum=%fms and avg waiting time=%fms",sum_wt_fcfs,avg_wt_fcfs);
	printf("\n FCFS Ends.............\n\n");
	return(avg_wt_fcfs);
}// fcfs ends

int sjf(int bts[20],int pros[20])
{
	int i,x,y,temp,wts[20];
	float sum_wt_sjf,avg_wt_sjf;	
	//printf("\n Sorting in the increasing order of the burst times.... :");
	for(x=1;x<=no_of_process; x++)

		{

			for(y=1;y<no_of_process; y++)
			{
				if(bts[y]>bts[y+1])
				{
			
							temp = bts[y+1];// for burst time array
							bts[y+1] = bts[y];
							bts[y] = temp;
							temp = pros[y+1];//for process no. array
							pros[y+1] = pros[y];
							pros[y] = temp;

				}
			}
		}
	 	
	printf("\nProcesses:\t\tBurst Time:");

	for(i=1;i<=no_of_process;i++)	
	{
		printf("\n P%d\t\t\t%d\n",pros[i],bts[i]);

	}

	printf("\n performing sjf....",bts);

	printf("\nProcesses:\t\tWaiting Time");

	for(i=1;i<=no_of_process;i++)	
	{ 
		if(i==1)
		{
			wts[1]=0;
		}
		else
		{
		 	wts[i]=bts[i-1]+wts[i-1];
		}
		printf("\n P%d\t\t\t%d\n",pros[i],wts[i]);
		
		sum_wt=sum_wt+wts[i];
	}

	avg_wt=sum_wt/no_of_process;
	avg_wt_sjf=avg_wt;
	sum_wt_sjf=sum_wt;
	avg_wt=sum_wt= 0;
	printf("\n sum=%fms and avg waiting time=%fms",sum_wt_sjf,avg_wt_sjf);
	return (avg_wt_sjf);
}//sjf ends

int rr(int btr[20],int pror[20])
{	int i, tq,wtr[20];
	for(i=1;i<20;i++)
	{	wtr[i]=0;
	}
	float sum_wt_rr,avg_wt_rr;
	printf("\n ROUND ROBIN BEGINS..");

	printf("\n For ROUND-ROBIN SCHEDULING...Enter the time quantum:");

	scanf("%d",&tq);

	printf("\n Process:\t\t Time:");
	int j,ctr;		
int k;	
do{
			ctr=0,k=0;
			for(i=1;i<=no_of_process;i++)
			
			{
			
				if (btr[i]==0)	
			
				continue;
				

				else if(btr[i]>tq)
				{
	
					btr[i]=btr[i]-tq;
					for(k=1;k<=no_of_process;k++)
					{
						
						if(btr[k]==0)
						continue;
						else if(k==i)
						continue;
						else
							wtr[k]=wtr[k]+tq;
							//printf("\n%d",wtr[k]);
					}
					printf("\n P%d\t\t\t %d",pror[i],tq);
				}
				else if(btr[i]<=tq)
				{

					printf("\n P%d\t\t\t %d", pror[i], btr[i]);
					for(k=1;k<=no_of_process;k++)
					{
						
						if(btr[k]==0)
						continue;
						else if(k==i)
						continue;
						else
							wtr[k]=wtr[k]+btr[i];
					//	printf("\n%d",wtr[k]);
					}
					btr[i]=0;
					
				}//else if
		
			}//i for
		
		for(j=1;j<=no_of_process;j++)
		{
				if(btr[j]!=0)
				ctr++;
			
		}
			
		if(ctr==0)
		break;	
	}while(ctr!=0);

	printf("\nProcesses:\t\tWaiting Time");
	
	for(i=1;i<=no_of_process;i++)	
	{ 
		printf("\n P%d\t\t%d\n",pror[i],wtr[i]);
		
		sum_wt=sum_wt+wtr[i];
	}
	avg_wt=sum_wt/no_of_process;
	avg_wt_rr=avg_wt;
	sum_wt_rr=sum_wt;
	avg_wt=sum_wt= 0;
	printf("\n sum=%fms and avg waiting time=%fms",sum_wt_rr,avg_wt_rr);
	
	printf("\n end of ROUND ROBIN...........\n\n");
	return(avg_wt_rr);
}

int ps(int btp[20],int prop[20])
{	

	int i,x,y, temp,wtp[20];
	
	float sum_wt_ps,avg_wt_ps;
	printf("\n Enter Priority of the given processes:(1 to %d)",no_of_process);
	for(i=1;i<=no_of_process;i++)
	{
		printf("\n P%d(%d) : ",prop[i],btp[i]);
		scanf("%d", &pr[i]);
		if(pr[i]>no_of_process)
		{	
			printf("\n invalid input");
			break;
		}
		pr2[i]=pr[i];
	}
	
	//printf("\n Sorting in the increasing order of the priorities.... :");
	for(x=1;x<=no_of_process; x++)

		{

			for(y=1;y<no_of_process; y++)
			{
				if(pr[y]>pr[y+1])
				{
							temp = pr[y+1];//for priority array
							pr[y+1] = pr[y];
							pr[y] = temp;
							temp = btp[y+1];// for burst time array
							btp[y+1] = btp[y];
							btp[y] = temp;
							temp = prop[y+1];//for process no. array
							prop[y+1] = prop[y];
							prop[y] = temp;
							

				}
			}
		}
	 	
	printf("\nPriority:\t\tProcess:\t\tBurst Time:");

	for(i=1;i<=no_of_process;i++)	
	{
		printf("\n %d\t\t\tP%d\t\t\t\t%d\n",pr[i],prop[i],btp[i]);

	}

	printf("\n performing priority scheduling....",btp);

	printf("\nPriority:\t\tProcess:\t\tWaiting Time");

	for(i=1;i<=no_of_process;i++)	
	{ 
		if(i==1)
		{
			wtp[1]=0;
		}
		else
		{
		 	wtp[i]=btp[i-1]+wtp[i-1];
		}
		printf("\n %d\t\t\tP%d\t\t\t%d\n",pr[i],prop[i],wtp[i]);
		
		sum_wt=sum_wt+wtp[i];
	}

	avg_wt=sum_wt/no_of_process;
	avg_wt_ps=avg_wt;
	sum_wt_ps=sum_wt;
	avg_wt=sum_wt= 0;
	avg_wt_ps++;
	printf("\n sum=%fms and avg waiting time=%fms",sum_wt_ps,avg_wt_ps);
	return(avg_wt_ps);
}

int mq(int btm [20],int prom[20])
{
	int x,y,temp,i,wtm[20],p;
	float sum_wt_mq,avg_wt_mq;
	p=(no_of_process)/2;
	printf("\n Multilevel queue:");
	
		for(x=1;x<=no_of_process; x++)

		{

			for(y=1;y<no_of_process; y++)
			{
				if(pr2[y]>pr2[y+1])
				{
							temp = pr2[y+1];//for priority array
							pr2[y+1] = pr2[y];
							pr2[y] = temp;
							temp = btm[y+1];// for burst time array
							btm[y+1] = btm[y];
							btm[y] = temp;
							temp = prom[y+1];//for process no. array
							prom[y+1] = prom[y];
							prom[y] = temp;
							

				}//if
			}//y for
		}//x for
		
		for(i=1;i<=no_of_process;i++)
		{
			if(pr2[i]<pr2[p])
			{
				printf("\n P%d is in high level priority queue..",prom[i]);
			}
			else
			printf("\n P%d is in lower level priority queue..",prom[i]);
		}
	printf("\nProcesses:\t\tWaiting Time");
	for(i=1;i<=no_of_process;i++)	
	{ 
		if(i==1)
		{
			wtm[1]=0;
		}
		else
		{
		 	wtm[i]=btm[i-1]+wtm[i-1];
		}
		printf("\n P%d\t\t%d\n",prom[i],wtm[i]);
		
		sum_wt=sum_wt+wtm[i];
	}
	avg_wt=sum_wt/no_of_process;
	avg_wt_mq=avg_wt;
	sum_wt_mq=sum_wt;
	avg_wt=sum_wt= 0;
	printf("\n sum=%fms and avg waiting time=%fms",sum_wt_mq,avg_wt_mq);
	return(avg_wt_mq);
}
