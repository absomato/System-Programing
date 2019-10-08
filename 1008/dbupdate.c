#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* ?숇쾲???낅젰諛쏆븘 ?대떦 ?숈깮 ?덉퐫?쒕? ?섏젙?쒕떎. */
int main(int argc, char *argv[])
{
        int fd, id;
            char c;
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
                                                                                        printf("?섏젙???숈깮???숇쾲 ?낅젰: ");
                                                                                                if (scanf("%d", &id) == 1) {
                                                                                                                lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
                                                                                                                            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
                                                                                                                                                printf("?숇쾲:%8d\t ?대쫫:%4s\t ?먯닔:%4d\n",
                                                                                                                                                                        record.id, record.name, record.score);
                                                                                                                                                                printf("?덈줈???먯닔: ");
                                                                                                                                                                                scanf("%d", &record.score);
                                                                                                                                                                                                lseek(fd, (long) -sizeof(record), SEEK_CUR);
                                                                                                                                                                                                                write(fd, (char *) &record, sizeof(record));
                                                                                                                                                                                                                            } else printf("?덉퐫??%d ?놁쓬\n", id);
                                                                                                                                                                                                                                    } else printf("?낅젰?ㅻ쪟\n");
                                                                                                                                                                                                                                            printf("怨꾩냽?섍쿋?듬땲源?(Y/N)");
                                                                                                                                                                                                                                                    scanf(" %c",&c);
                                                                                                                                                                                                                                                        } while (c == 'Y');
                                                                                                                                                                                                                                                                close(fd);
                                                                                                                                                                                                                                                                        exit(0);
}

