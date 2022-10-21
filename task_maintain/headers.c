/*------------------------------includes--------------------------------------*/
#include "headers.h"
/*------------------------------functions definations-------------------------*/
/**
 *
 *@about void function to intialize shell
 *@param void 
 *@return void function 
 */
void intialize_shell(void) {
        printf("$Welcome to AhmedFandes shell..\n");
        sleep(1);
        printf("\n\n\n\n******************"
        "************************");
        printf("\n\n\n\t****FANDES SHELL****");
        printf("\n\n\t-HAVE A NICE TIME WITH OUR SHELL -");
         printf("\n\n\n\n*******************"
        "***********************");
        sleep(2);
        clear();
	

}

/*
 *@about int function to print factorial of a number
 *@param num 
 *@return res = result of factorial of a num
 * */
int fact(int num){
	int i, res=1;
	if( (num==0) || (num==1) )
	{
        	res=1;
	}
	else
	{
		for(i=num;i>1;i--)
		{
        		res=res*i;
		}
	}
	return res;

}
/**
 *@about void function to print fibonacci sequence
 *@param num 
 *@return void function 
 * */
void fib(int num){
	
	int i=0,t1=0,t2=1,NextTerm=0;
	printf("\nThe sequence is : ");
	for(i=0;i<=num;i++)
	{
		if(i==0)
		{
			printf("0,");
			continue;
		}
		if(i==1)
		{
			printf("1");
			continue;
		}
		NextTerm=t1+t2;
		t1=t2;
		t2=NextTerm;
		printf(",%d",NextTerm);
	}


}
/**
 *@about int function to get input from user and store it in a char array
 *@param str
 *@return 1 if string stored and success
 *	
 */
void getInput(char buf[100]){
	char *delim = " ";
        unsigned count = 0;
        char *token = strtok(buf,delim);
	while(token != NULL)
        {
		argv[count]=token;

		//printf("Token no. %d : %s \n", count,token);
                token = strtok(NULL,delim);
                count++;
        
	}
}
void echo(char buf[100]){
         char *token = strtok(buf, " ");
   // loop through the string to extract all other tokens
   token = strtok(NULL, " ");

	 while( token != NULL ) {
      printf( " %s", token ); //printing each token
      token = strtok(NULL, " ");
   }        
}

/**
 *@about void function to print current directory
 *@param void
 *@return void function 
 * */
void printDir(void){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDir: %s\n", cwd);
}
/**
 *
 *
 *
 * */
void ls(void){
	
            	if (fork() == 0) {

        		int status_code = execvp(command, arg1);

        		printf("ls -l has taken control of this child process. This won't execute unless it terminates abnormally!\n");

        		if (status_code == -1) {
            			printf("Terminated Incorrectly\n");
        		}
    		}	
    		else {
	    
    		}
    
    
    }
/**
 *
 *
 * */
void set(void){
	int i=0;
	for(i=0;i<15;i++){
		/*if( (variables[i]==NULL) || (values[i]==NULL)){
			break;
		}
		
		else{*/
		QueRetVal=QueueFront(variables,DATA_NOK);
		printf("local variables : %s =",QueRetVal);
		QueRetVal = QueueFront(values,DATA_NOK);
		printf(" %s\n",QueRetVal);
		continue;	
		//}
	}

}
/**
 *
 *
 *
 * */
/*int check_token(char buf[100]){
		
    char *token;                  
    token = strtok(buf,"=");
    while(token!=NULL){
        variables[v]=token;      
        token = strtok(NULL,"=");
        values[v]=token;
	v++;
    }
    
}*/
/**
 *
 *
 *
 * */
data_variables *CreateVariables(int MaxSize,Data_status *ret_status){
	data_variables *MyData;
	MyData= (*MyData)malloc(sizeof(*Mydata));
	if(NULL == MyData){
		*ret_status = DATA_NULL_POINTER;
		MyData= NULL;
	}
	else{
		MyData->QueueVariables = (void **)calloc(MaxSize,sizeof(void *));
		if(NULL ==MyData->QueueVariables){
			*ret_status =DATA_NOK;
			MyData=NULL;
		
		}
		else{
			MyData->count=0;
			MyData->front=-1;
			MyData->rear=-1;
			MyData->MaxSize=MaxSize;
			*ret_status = DATA_OK;




		}
	
	}
return MyData;
}           
/**
 *
 *
 *
 * */
Data_status EnqueueVariable(data_variables *obj,void *item){
	Data_status status =DATA_NOK;
	if( (NULL == obj)||(NULL== item) ){
		status=DATA_NULL_POINTER;
	
	}
	else {
		(obj->rear)++;
		if(obj->rear==obj->MaxSize){
			obj->rear=0;

		}
		else{
			obj->QueueVariables[obj->rear]= item;
			if(obj->count ==0){
				obj->front=0;
				obj->count=1;

			}
			else{
				(obj->count)++;
			
			}
			status = DATA_OK;
		}
			
	
	}

return status;

}

/**
 *
 *
 *
 * */
void *QueueFront(data_variables *obj,Data_status *ret_status){
	void *ReturnElement=NULL;
	if( (NULL == obj)||(NULL== ret_status) ){
		*ret_status=DATA_NULL_POINTER;
	}
	else{
		if(!obj->count){
			*ret_status=DATA_EMPTY;
			ReturnElement=NULL;
		}
		else{
			ReturnElement= obj->QueueVariables[obj->front];
			*ret_status=DATA_OK;
		}
	}
	return ReturnElement;
}


