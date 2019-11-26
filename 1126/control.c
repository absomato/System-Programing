#include<signal.h>
#include<stdio.h>
int main(){
    int pid1,pid2;
    pid1 = fork();
    if(pid1 == 0){
        while(1){
            sleep(1);
            printf("프로세스 [1] 실행 \n");
        }
    }
    pid2 = fork();
    if(pid2 == 0){
        while(1){
            sleep(1);
            printf("프로세스 [2] 실행\n");
        }
    }
    sleep(2);
    kill(pid1,SIGSTOP);
    sleep(2);
    kill(pid1,SIGSTOP);
    sleep(2);
    kill(pid1,SIGSTOP);
    sleep(2);
    kill(pid1,SIGSTOP);
    sleep(2);
    kill(pid1,SIGSTOP);
    kill(pid2,SIGKILL);
}
