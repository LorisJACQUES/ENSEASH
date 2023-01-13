#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

#define Message_Welcome "\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit' \n"
#define Message_Goodbye "Bye bye ...\n"

#define Message_Prompt "enseash "
#define Message_Prompt2 " % "


#define Incorrect_Command  "Commande inconnue ...\n"
#define Exit "exit"



