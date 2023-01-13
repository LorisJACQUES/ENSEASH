#include "fonction.h"
#include "fonction.c"

int main()
{
    char buffer[50]={0};
	char Prompt_Status[50]={0};
	char Prompt_Time[50]={0};
    int x;
    int status;
    int duree;
    struct timespec clk_debut, clk_fin;
	
	Welcome_Shell();
    while(1)
    {
        Prompt(Prompt_Status,Prompt_Time);
        x = read(STDIN_FILENO, buffer, sizeof(buffer));
        
        clock_gettime(CLOCK_REALTIME, &clk_debut);
        buffer[x-1]='\0';
        
        
        char * argument_Liste[50] = {};
        char * argument = strtok(buffer," ");
        int i = 0;
        int fd;
        while (argument!=NULL){
			if(strcmp(">",argument)==0){
				char * fichier = strtok(NULL, " ");
				fd = open(fichier, O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO);
				dup2(fd, STDOUT_FILENO);
					
			}
			
			if(strcmp("<",argument)==0){
				char * fichier = strtok(NULL, " ");
				fd = open(fichier, O_RDONLY);
				dup2(fd, STDOUT_FILENO);
				
			}
			
			else{
				argument_Liste[i] = argument;
				i++;
				argument = strtok(NULL," ");
				}
			}
        
        if ((strcmp("exit",buffer) == 0) | (strcmp("", buffer) == 0)){
            Goodbye_Shell();
			}
        
        else{
            pid_t ret = fork();
            if (ret==0){
				execvp(buffer, argument_Liste);									
				exit(EXIT_FAILURE);
				}
				
			else{
				wait(&status);
				
				clock_gettime(CLOCK_REALTIME, &clk_fin);
				duree = (clk_fin.tv_sec - clk_debut.tv_sec)*1000+(clk_fin.tv_nsec - clk_debut.tv_nsec)/1000000;
				sprintf(Prompt_Time,"%dms]", duree);
				
				
				if (WIFEXITED(status)){
					sprintf(Prompt_Status, "[exit:%d|", WEXITSTATUS(status));
				}
				else if (WIFSIGNALED(status)){
					sprintf(Prompt_Status, "[sign:%d]", WTERMSIG(status));	
				}
			
			}
        }
    }

}

