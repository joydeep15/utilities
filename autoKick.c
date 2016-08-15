/*
Designed to work on CentOS systems
for other systems change the parsing on grep

Eg: ubuntu uses the form /dev/tty1
	whereas CentOS uses /dev/pts/1

	....you get the idea

the purpose of this program is to kick
all active ssh users whom you have permission to kick

assumes all ssh users are logged in under the name user

Joydeep Halder

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
sprintf(cmd," ps -aux | grep \"sshd: user\" | grep -v \"sshd: user@pts/%d\" | cut -c 10-15 > lol.txt",mytty);
	system(cmd);
	free(cmd);
	freopen("lol.txt","r",f1);	
	int i=0,el,list[40];		
	while(fscanf(f1,"%d\n",&el)!=EOF){
	list[i++]=el;
	}

	cmd = (char *) malloc(2000*sizeof(char));
	sprintf(cmd,"kill -9 ");
	
	int j;
	system("alias kill=kill");
	for(j=0;j<i-1;++j)
		sprintf(cmd+strlen(cmd),"%d ",list[j]);
	fclose(f1);
	
	system("rm -f lol.txt");
	printf("killing %d users\n",i);
	system(cmd);
	free(cmd);
	system("cp .bashrc ~/.bashrc");	
	system("source ~/.bashrc");
	printf("success....\n");
	

}
