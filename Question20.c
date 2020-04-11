#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
void *teacher_process();
void* student_process1();
void* student_process2();
void* student_process3();
int s_array[3][4]={0};
int choice1,choice2;
pthread_mutex_t m;
int main()
{
pthread_mutex_init(&m,NULL);
s_array[1][1]=1;
s_array[2][2]=1;
s_array[3][3]=1;
pthread_t thread_t,thread_s;
printf("Menu for resources\n 1.Please enter 'P' for pen \n 2.Please enter 'Q' for Question paper\n 3.Please enter 'X' for paper\n");
	while(true)
	{
		if(s_array[1][4]==1 && s_array[2][4]==1 && s_array[3][4]==1)
		{
			break;
		}
		else
		{
			pthread_create(&thread_t,NULL,teacher_process,NULL);
			pthread_join(thread_t,NULL);
			if(choice1==1 && choice2==3||choice2==1 && choice1==3 ||s_array[2][4]==0)
			{
				pthread_create(&thread_s,NULL,student_process2,NULL);
				pthread_join(thread_s,NULL);
			}
			else if(choice1==3 && choice2==2||choice2==3 && choice1==2 ||s_array[1][4]==0)
			{
				pthread_create(&thread_s,NULL,student_process1,NULL);
				pthread_join(thread_s,NULL);
			}
			else if(choice1==1 && choice2==2||choice2==2 && choice1==1 ||s_array[3][4]==0)
			{
				pthread_create(&thread_s,NULL,student_process3,NULL);
				pthread_join(thread_s,NULL);
			}
			else
			{
				printf("!!!!!!!!!!Error!!!!!!\n Please try again\n");
			/*	while(true)
				{
					pthread_create(&thread_t,NULL,teacher_process,NULL);
					pthread_join(thread_t,NULL);
					if(char1=='P' && char2=='Q'||char2=='P' && char1=='Q' ||s_array[2][4]==0)
					{
						pthread_create(&thread_s,NULL,student_process2,NULL);
						pthread_join(thread_s,NULL);
					}
					else if(char1=='Q' && char2=='X'||char2=='Q' && char1=='X' ||s_array[1][4]==0)
					{
						pthread_create(&thread_s,NULL,student_process1,NULL);
						pthread_join(thread_s,NULL);
					}
					else if(char1=='P' && char2=='X'||char2=='X' && char1=='P' ||s_array[3][4]==0)
					{
						pthread_create(&thread_s,NULL,student_process3,NULL);
						pthread_join(thread_s,NULL);
					}
				}
				*/	
			}
		}
	}
}
void* teacher_process()
{
	pthread_mutex_lock(&m);
	printf("Please enter first resource on the shared table:-");
	scanf("%d",&choice1);
	printf("Please enter Second resource on the shared table:-");
	scanf("%d",&choice2);
	pthread_mutex_unlock(&m);
}
void* student_process1()
{
	pthread_mutex_lock(&m);
	printf("Prefered choices:\n 1.Paper \n 2.Question Paper\n");
	s_array[1][4]=1;
	printf("Student-1 has completed the assignment successfully.\n");
	pthread_mutex_unlock(&m);
	printf("Student-1 has reported successfully\n");
} 
void* student_process2()
{
	pthread_mutex_lock(&m);
	printf("Prefered choices:\n 1.Pen \n 2.Question Paper\n");
	s_array[2][4]=1;
	printf("Student-2 has completed the assignment successfully.\n");
	pthread_mutex_unlock(&m);
	printf("Student-2 has reported successfully\n");
}
void* student_process3()
{
	pthread_mutex_lock(&m);
	printf("Prefered choices:\n 1.Paper \n 2.Pen\n");
	s_array[3][4]=1;
	printf("Student-3 has completed the assignment successfully.\n");
	pthread_mutex_unlock(&m);
	printf("Student-3 has reported successfully\n");
}
