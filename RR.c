//FCFS

#define s 100

void RR()
{
	int i,j,n,y,t;
	int ttime,index, tq;
	float avg_tat=0,avg_wt=0;
	Q *front=NULL,*rear=NULL, *ptr, *(list[s]), *tmp;

	clrscr();
	
	printf("5.Round Robin Scheduling\n");
	printf("************************\n");
	

/* Get Input*/

	while(1)
	{	printf("Enter number of processes:");
		if(scanf("%d",&n)&&n>0){break;}
		else{printf("\nInvalid Input\n");}
		Clear_stdin();
	}

	#undef s
	#define s n

	y=8;
	printf("\nProcess No.\tArrival Time\tBurst Time\n");
	printf("***********\t************\t**********\n");
	for(i=1;i<=n;i++,y++)
	{
		gotoxy(0,y);
		printf("  %d",i);
		ptr=(Q*)malloc(sizeof(Q));
		gotoxy(20,y);
		scanf("%d",&(ptr->at));
		gotoxy(35,y);
		scanf("%d",&(ptr->bt));
		
		ptr->pno=i;
		if(front==NULL)
		{
			front=rear=ptr;
			ttime=ptr->at;
		}
		else
		{
			rear->next=ptr;
			rear=ptr;
		}
		ptr->rbt=ptr->bt;
		ptr->next=NULL;
	}


	while(1)
	{	printf("Enter time quantum:");
		if(scanf("%d",&tq)&&n>0){break;}
		else{printf("\nInvalid Input\n");}
		Clear_stdin();
	}



/*Calculate Values*/

	index=-1;
	list[0]=NULL;
	
	for(i=0;i<=ttime;i++)
	{
		ptr=front;
		while(ptr!=NULL)
		{
			if(ptr->at==i)
			{
				if(index==-1)
				{
					ttime=ptr->at;
					ptr->wt=0;
				}
				ttime+=ptr->bt;
				list[++index]=ptr;
				ptr->tat=0;
			}
			ptr=ptr->next;
		}
		if(list[0]!=NULL)
		{
			if(list[0]->rbt!=0)
			{
				for(j=1;j<=index;j++)
				{
					(list[j]->wt)++;
					(list[j]->tat)++;	
				}
				(list[0]->tat)++;
				(list[0]->rbt)--;
				if(i%tq==0)
				{
					tmp=list[0];
					for(j=0;j<index;j++)
					{
						list[j]=list[j+1];
					}
					list[index]=tmp;
				}
			}
			else
			{
				list[0]=NULL;
				
				for(j=0;j<index;j++)
				{
					list[j]=list[j+1];
				}
				index--;

				for(j=1;j<=index;j++)
				{
					(list[j]->wt)++;
					(list[j]->tat)++;	
				}
				if(list[0]!=NULL)
				{
					(list[0]->tat)++;
					(list[0]->rbt)--;
				}
			}
		}
	}

/*Print Output Table*/

	Clear_stdin();
	clrscr();
	ptr=front;
	printf("\nProcess No.\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time");
	printf("\n***********\t************\t**********\t************\t****************\n");
	while(ptr!=NULL)
	{
		printf(" %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n",(ptr->pno),(ptr->at),(ptr->bt),(ptr->wt),(ptr->tat));
		avg_wt=avg_wt+(ptr->wt);
		avg_tat=avg_tat+(ptr->tat);
		ptr=ptr->next;
	}
	avg_wt=avg_wt/n;
	avg_tat=avg_tat/n;
	printf("\t\t\t\t\t\t------------\t----------------\n");
	printf("\t\t\t Average:\t\t  %.2f \t\t  %.2f",avg_wt,avg_tat);


/*Draw	Gaant Chart*/
	printf("\n\nGaant Chart:\n\n");

	index=-1;
	t==0;
	list[0]=NULL;
	
	printf(" [0]");
	
	for(i=0;i<=ttime;i++)
	{
		ptr=front;
		while(ptr!=NULL)
		{
			if(ptr->at==i)
			{
				ptr->rbt=ptr->bt;
				list[++index]=ptr;
			}
			ptr=ptr->next;
		}
		printf("--");
		if(list[0]!=NULL&&i==t+tq/2)
		{
			printf("P%d",list[0]->pno);
		}
		if(list[0]!=NULL)
		{

			if(list[0]->rbt!=0)
			{
				(list[0]->rbt)--;
				if(i%tq==0)
				{
					tmp=list[0];
					for(j=0;j<index;j++)
					{
						list[j]=list[j+1];
					}
					list[index]=tmp;
				}
			}
			else
			{
				list[0]=NULL;
				
				for(j=0;j<index;j++)
				{
					list[j]=list[j+1];
				}
				index--;

				if(list[0]!=NULL)
				{
					(list[0]->rbt)--;
				}
			}
		}
		
		if(i%tq==0&&i!=0)
		{	
			printf("[%d]",i);
			t=i;
		}
	}

	printf("[%d]",ttime);


	printf("\n\nPress any key to return to main menu...");
	getch();
}

#undef s
