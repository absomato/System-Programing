#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BS 512
int main(int argc, char *argv[])
{ 
	int fd1, n=0,cnt=0;
	char buf[BS];
	int a=0, b=0, c=0; //a 문자갯수 b 단어 갯수 c 줄수
	if (argc != 2) { 
		fprintf(stderr,"사용법: %s file1 file2\n",        
				argv[0]); 
		exit(1); 
	}
	if ((fd1 = open(argv[1], O_RDONLY)) ==-1) {
		perror(argv[1]);
		exit(2); 
	}

	while(1)
	{
		n=read(fd1,buf, 1);
		
		if(*buf == ' ' || *buf == '\n')  b++;
		if(*buf == '\n' ) c++;	
		a++;

		if(n<=0) break;
			
	}
	printf("글자 수 : %d\t 단어 수 : %d\t 줄 수 : %d \n", a-b, b-1, c-1);
	close(fd1);
	exit(0);
}
