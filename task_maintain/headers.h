/* -------------------- includes------------------------ */
	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include<sys/wait.h>
	#include<readline/readline.h>
	#include<readline/history.h>
/*-----------------------------macro functions declaration------------------------------*/
#define clear() printf("\033[H\033[J")
/* ------------------------------Data Types Declaration ------------------------------- */
        int x,result;
	char buf[100];
       	int read_count;
	char *argv[]={ NULL };
    	char* command = "ls";
    	char *arg1[]={"ls",NULL};
	typedef struct{
		void **QueueVariables;
		int MaxSize;
		int count;
		int front;
		int rear;
	}data_variables;
        void *QueRetVal;
	typedef enum{
		DATA_NOK=0,
		DATA_OK,
		DATA_FULL,
		DATA_EMPTY,
		DATA_NULL_POINTER
	}Data_status;
	data_variables *variables,*values;
	variables=CreateVariables(100,DATA_NOK);
        values= CreateVariables(100,DATA_NOK);

/*------------------------------functions declaration-------------------------*/	

	void intialize_shell(void);
	int fact(int num);
	void fib(int num);
	void getInput(char buf[100]);
	void printDir(void);
	void echo(char buf[100]);
	void ls(void);
	int check_token(char buf[100]);
	void set(void);
	data_variables *CreateVariables(int MaxSize,Data_status *ret_status);
	Data_status EnqueueVariable(data_variables *obj,void *item);
	void *QueueFront(data_variables *obj,Data_status *ret_status);
