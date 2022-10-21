/**
 *
 *@ Ahmed Adel Wafdy
 *@email fandes99@gmail.com
 *@ creatin a shell with utilities
 * */
/*-------------------------includes----------------------------------*/
#include "headers.h"

/*-----------------------Data Types Declaration---------------------*/
int argc=0;
char buf[100];
int i;
int main(){
	intialize_shell();
	

	while(1){
        	printf("\nAhmedfandes shell>>> ");
		fgets(buf,100,stdin);
		int len =strlen(buf);
		buf[len-1]=0;
		getInput(buf);
		if(strcmp(argv[0],"exit")==0)
			{
				printf("Good bye :)\n$");
				break;     //breaking the shell
			}
		
		else if (strcmp(argv[0] ,"set")==0){
			set();
			printf("\n");
			continue;
		}
		else if (strcmp(argv[0] ,"ls")==0){				
			 for(i=1;i<20;i++){
				 if(argv[i]==NULL){
                                        ls();
					break;
                          	 }
				 else if(argv[i]!=NULL){
				 	arg1[i]=argv[i];
				 }
			 }	 

			
		}
		else if(strcmp(argv[0] ,"rand")==0)
			{
	
				printf("%d\n",rand());     //implement the rand function
				continue;
			}
		else if(strcmp(argv[0] ,"fact")==0)
			{
				printf("Enter a number: ");  //get input from the user 
				scanf("%d",&x);
				result=fact(x);
				printf("\nResult is: %d\n ",result); //implement factorial function
				continue;
			}
		else if(strcmp(argv[0] ,"fib")==0)
			{
				printf("Enter the number of terms : "); //get number of terms from user
				scanf("%d",&x);
				fib(x);                                  //implement fibonacci sequence
				printf("\n");
				continue;
			}	
		else if(strcmp(argv[0],"cp")==0)
			{
				
				int dest_fd = open(argv[2], O_CREAT | O_WRONLY ,0644);
				int src_fd = open(argv[1],O_RDONLY );
				int read_count;
				while( (read_count = read(src_fd, buf,100 )) >0 ){
                			write(dest_fd,buf,read_count);
						

				}
				close(src_fd);
				close(dest_fd);

			
			}
		 else if(strcmp(argv[0],"mv")==0)
                        {

                                int dest_fd = open(argv[2], O_CREAT | O_WRONLY ,0644);
                                int src_fd = open(argv[1],O_RDONLY );
                                int read_count;
                                while( (read_count = read(src_fd, buf,100 )) >0 ){
                                        write(dest_fd,buf,read_count);


                                }

                                close(src_fd);
                                close(dest_fd); 
				int rm = remove(argv[1]);
                        }
		else if(strcmp(argv[0],"echo")==0){
			for(i=1;i<20;i++){
				if(argv[i]==NULL){
					break;
				}
				
				printf("%s ",argv[i]);
			
			}
		
			}	

		else if(strcmp(argv[0] ,"pwd")==0)
			{
				printDir();
		
			}

		else
			{
				
				printf("You said: %s \n",buf);
		       		//print what user type
				for(counter=0;counter<=100;counter++){
					if(buf[counter]=="="){
						char *token;
    						token = strtok(buf,"=");
    						while(token!=NULL){
        					EnqueueVariable(variables,token);
        					token = strtok(NULL,"=");
        					EnqueueVariable(values,token);
    						}


						}
				}

					

				continue;
			}    

	}
	}		

