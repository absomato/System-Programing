nclude <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
int main(int argc, char *argv[]){
        int fd, id;
            char c,s='*';
                struct student record;
                    if (argc < 2) {
                                fprintf(stderr, "?ъ슜踰?: %s file\n", argv[0]);
                                        exit(1);
                                            }
                                                if ((fd = open(argv[1], O_RDWR)) == -1) {
                                                            perror(argv[1]);
                                                                    exit(2);
                                                                        }
                                                                            do {
                                                                                        printf("??젣???숈깮???숇쾲 ?낅젰: ");
                                                                                                if (scanf("%d", &id) == 1) {
                                                                                                                lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
                                                                                                                            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
                                                                                                                                                printf("?숇쾲:%8d\t ?대쫫:%4s\t ?먯닔:%4d???숈깮????젣?섏뿀?듬땲??\n",
                                                                                                                                                                        record.id, record.name, record.score);
                                                                                                                                                                lseek(fd, (long) -sizeof(record), SEEK_CUR);
                                                                                                                                                                                write(fd, (char *)&s, sizeof(s));
                                                                                                                                                                                            }}
                                                                                                                                                                                                    else printf("?덉퐫??%d ?놁쓬\n", id);
                                                                                                                                                                                                            printf("怨꾩냽?섍쿋?듬땲源?(Y/N)");
                                                                                                                                                                                                                    scanf(" %c",&c);
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                            while (c == 'Y');
                                                                                                                                                                                                                                close(fd);
                                                                                                                                                                                                                                    exit(0);
}
