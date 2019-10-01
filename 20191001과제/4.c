#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BS 512
int main(int argc, char *argv[])
{ 
	int fd1, fd2, n=0,cnt=0;
	char buf[BS],buf2[BS];
	int a,b;
	if (argc != 3) { 
		fprintf(stderr,"사용법: %s file1 file2\n",        
				argv[0]); 
		exit(1); 
	}
	if ((fd1 = open(argv[1], O_RDONLY)) ==-1) {
		perror(argv[1]);
		exit(2); 
	}
	if ((fd2 =open(argv[2], O_RDONLY)) == -1) {
		perror(argv[2]);
		exit(3); 
	}
	while(1)
	{
		
		a=read(fd1,buf, 1);
		b=read(fd2,buf2,1);
		//printf("%d %d\n",a,b);
		/*if(a!=b){
			printf("사이즈가 다름\n");
			n=1;
			break;
		}*/
		if(*buf!=*buf2){
			n=1;
			printf("%d 위치에서 다름",cnt);
			break;	
		
		}
		else if(a<=0) break;
		//if(read(fd1,buf,BS)<=0)break;
		cnt++;
			
	}
	if(n==0)printf("같음");
	close(fd1);
	close(fd2);
	exit(0);
}
