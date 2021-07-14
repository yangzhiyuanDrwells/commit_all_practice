/**************************************
*�ļ�˵��:process.c
*����:����Զ
*����ʱ��:2021��07��14�� ������ 07:28
*��������:GNU gdb (Ubuntu 8.1.1-0ubuntu1) 8.1.1
****************************************/

#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork(); // �����ӽ���

    if(pid == -1){
        perror("fork error");
        return -1;
    }
    else if(pid == 0){ //child
        printf("i am a child:my pid is %d,my father is %d\n",getpid(),getppid());
    }
    else{ // father
        printf("i am a father:my pid is %d\n",getpid());
        wait(NULL); // �ȴ��ӽ���
    }
    return 0;
}