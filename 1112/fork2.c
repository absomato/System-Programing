#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int pid;
    pid = fork();
    if(pid==0){
        printf("[chile]: hello, world pid = %d\n",getpid());
    }
    else {
        printf("[parent] : hello,world pid = %d\n",getpid());
    }
}
