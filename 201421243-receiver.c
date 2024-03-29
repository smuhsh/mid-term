 /*201421243-receiver.c*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;

int main(void)
	int msqid = 0;
	 msg_t data;
	 if(-1 == (msqid == msgget((key_t)1234, IPC_CREAT | 0666))){
		 perror("msgget() error");
		 exit(1);
	 }
	 while(1){
		 // get the messages only type = 2
		 /*
			data.data_type = (ndx++ %3) + 1; //data_type = {1,2,3}
			data.data_num = ndx;
			sprintf(data.data_buff, "type = %ld, ndx = %d", data.data_type, ndx);
		  */
		 if(-1 == msgrcv(msqid, &data, sizeof(msg_t) - sizeof(long), 2, 0)){
			 perror("msgrcv() error");
			 exit(1);
		 }
		 printf("%d - %s \n", data.data_num, data.data_buff);
	 }
return(0);
}

