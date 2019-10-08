#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
        int fd, id;
            char c;
                struct student record;
                    if (argc < 2) {
                                fprintf(stderr, "file name : %s file\n", argv[0]);
                                        exit(1);
                                            }
                                                if ((fd = open(argv[1], O_RDONLY)) == -1) {
                                                            perror(argv[1]);
                           exit(2);
                  }
               do {
         printf("\nfile name is :");
                       if (scanf("%d", &id) == 1) {
                                    lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
                 if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)){
                     if(strchr(record.name,'*')!=NULL)printf("%d file is gone\n",id);
        else printf("name :%s\t id:%d\t score:%d\n", record.name, record.id, 
                                       record.score);}
               else printf("%d is gone\n", id);
                             } 
                     else printf("?낅젰 ?ㅻ쪟");
                       printf("re start?(Y/N) : ");
                                                                                                                      
           scanf(" %c",&c);
           } while (c=='Y');
             close(fd);
              exit(0);
}

