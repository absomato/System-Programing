#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BS 1
int main(int argc, char *argv[]){ 
    int fd1, fd2, n=0;
         char buf[BS],buf2[BS];
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
          while(read(fd1,buf,BS)>0){
                if(read(fd2,buf2,BS)!=read(fd1,buf,BS)){
                 n=1;
                  printf("다름\n");
                break;
         }
              else if(strcmp(buf,buf2)!=0){
                   printf("%d\n",strcmp(buf,buf));
                   n=1;
                     printf("다름 ");         
               printf("위치출력 :\n\n");
                 }
                     
        }
          if(n==0)printf("같음");
             close(fd1);
               close(fd2);
              exit(0);
}
