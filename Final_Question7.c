#include<stdio.h> //Including standard input output header file
#include<conio.h> //Including console input output header file
#include<stdlib.h> //Including standard library for dynamic memory allocation
int main()
{
	int *class_process,number_of_process,i;
	float *response_time_process;
	printf("\n");
	printf("--------------------*Operating system simulation based project*-----------------\n");
	printf("\n");
	printf("Please enter the number of processes:- ");
	scanf("%d",&number_of_process);
	printf("\n");
	class_process = (int*)malloc(number_of_process * sizeof(int)); //Dynamic memory allocation
	response_time_process = (float*)malloc(number_of_process  * sizeof(float)); //Dynamic memory allocation
	if (class_process == NULL||response_time_process==NULL) //checking whether memory is allocated or not
	{ 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
	else
	{
		printf("\n");
		printf("-------------------*Please enter information about processes*-------------------\n");
		printf("\n");
		for(i=0;i<number_of_process;i++)
		{
			printf("Enter Response time of Process with ID P%d[*in seconds]: ",i);
			scanf("%f",&response_time_process[i]);
			if(response_time_process[i]<1)
			{
				class_process[i]=0;
			}
			else
			{
			class_process[i]=-1;
			}
		}
		printf("\n");
		printf("Process_Number\tResponse_Time\tClass\t\tPriority");
		printf("\n");
		for(i=0;i<number_of_process;i++)
		{
			printf("\nP%d\t\t%0.2fs\t",i,response_time_process[i]);
			if(class_process[i]==0)
			{
				printf("\tInteractive\tHigh");
			}
			else
			{
				printf("\tNon-Interactive\tLow");
			}
		}
	}
}

