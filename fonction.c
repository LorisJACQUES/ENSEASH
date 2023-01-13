#include "fonction.h"


void Welcome_Shell(){
	write (STDOUT_FILENO, Message_Welcome, sizeof(Message_Welcome)-1);
	}

void Goodbye_Shell(){
	write(STDOUT_FILENO, Message_Goodbye, sizeof(Message_Goodbye)-1);
    exit(0);
	}

void Prompt(char * Prompt_Status, char * Prompt_Time){
    write(STDOUT_FILENO, Message_Prompt, sizeof(Message_Prompt)-1);
    write(STDOUT_FILENO, Prompt_Status, sizeof(Prompt_Status));
    write(STDOUT_FILENO, Prompt_Time, sizeof(Prompt_Time));
    write(STDOUT_FILENO, Message_Prompt2, sizeof(Message_Prompt2)-1);
	}

/*char Read_Buffer(){
	read(STDIN_FILENO, buffer, sizeof(buffer));
	}*/
