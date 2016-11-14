/*
Designed to work on CentOS systems
for other systems change the parsing on grep

Eg: ubuntu uses the form /dev/tty1
	whereas CentOS uses /dev/pts/1

	....you get the idea

the purpose of this program is to kick
all active ssh users whom you have permission to kick

assumes all ssh users are logged in under the name user

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(){

		
	system("touch lol.txt");
	system("tty > lol.txt");


	FILE *f1;
	f1=fopen("lol.txt","r+");
	int mytty;
	fscanf(f1,"/dev/pts/%d",&mytty);
	freopen("lol.txt","w",f1);
	//clear lol.txt		
	
	char *cmd = (char *) malloc(100*sizeof(char));	
	sprintf(cmd,"ps -aux | grep \"sshd: user\" | grep -v \"sshd: user@pts/%d\" | cut -c 10-15 > lol.txt",mytty);
	system(cmd);
	free(cmd);
	freopen("lol.txt","r",f1);
	int i=0,el;	
	system("alias kill=kill");
	system("echo \"Killing $(cat lol.txt|wc -l) users\"");
	cmd = (char *) malloc(20*sizeof(char));
	while(fscanf(f1,"%d\n",&el)!=EOF){
	sprintf(cmd,"kill -9 ");
	sprintf(cmd+strlen(cmd),"%d ",el);
	system(cmd);
	}
	fclose(f1);
	
	system("rm -f lol.txt");
	free(cmd);
	system("cp .bashrc ~/.bashrc");	
	system("source ~/.bashrc");
	printf("success....\n");
	

}
