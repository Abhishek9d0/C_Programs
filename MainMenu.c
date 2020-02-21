#include<stdio.h>
#include<stdlib.h>
#include"includes/sysfun.h"


struct LL{
	struct LL *next;
	int at,bt,tat,wt,pno,rbt,et,P;
};

typedef struct LL Q;

#include"includes/sort.h"

#include"SAC/FCFS.c"
#include"SAC/SJF_np.c"
#include"SAC/SJF_p.c"
#include"SAC/Priority.c"
#include"SAC/RR.c"

main()
{
	char choice;
	while(1)
	{
		clrscr();
		printf("\n*****************************************************************\n");
		printf("*\t\t Process Scheduling Algorithms \t\t\t*\n");
		printf("*\t\t-------------------------------\t\t\t*\n");
		printf("*\t1.\tFirst Come First Serve (FCFS)\t\t\t*\n");
		printf("*\t2.\tShortest Job First (SJF) non-preemptive\t\t*\n");
		printf("*\t3.\t(E)Shortest Job First (SJF) preemptive\t\t*\n");
		printf("*\t4.\tPriority Scheduling\t\t\t\t*\n");
		printf("*\t5.\tRound Robin Scheduling\t\t\t\t*\n");
		printf("*\t6.\t-Improved Round Robin Scheduling\t\t\t*\n");
		printf("*\t7.\t-Multi Level Feedback Queue Scheduling\t\t*\n");
		printf("*\t8.\t-Performance Comparision\t\t\t\t*\n");
		printf("*\t9.\tExit\t\t\t\t\t\t*\n");
		printf("*\t\t\t\t\t\t\t\t*\n");
		printf("*\t\t\tEnter Your Choice: \t\t\t*\n");
		printf("*****************************************************************\n");		
		gotoxy(43,15);
		choice=getche();
		gotoxy(0,17);
		switch(choice)
		{
			case '1':	FCFS();
					break;
			case '2':	SJF_np();
					break;
			case '3':	SJF_p();
					break;
			case '4':	Priority();
					break;
			case '5':	RR();
					break;
			case '6':
					break;
			case '7':
					break;
			case '8':
					break;
			case '9':	exit(0);
					break;
			default :	printf("\n\nInvalid Choice\nPress any key to return to main menu");
					getch();
					break;

		}
	}
}
