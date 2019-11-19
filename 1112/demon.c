#include<stdio.h>
#include<stdlib.h>
#include<svs/types.h>
#include<fcntl.h>
int main(){
    pid_t pid;
    if((pid=fork())<0)exit(0);
    else if(pid!=0)
        exit(0);

    signal(SIGHUP,SIG
