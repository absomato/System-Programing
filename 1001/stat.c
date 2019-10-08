#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char*argv[]){

	struct stat buf;
	if(stat(argv[1], &buf) == -1)
	{

		perror("stat");
		return 1;
	}
	printf(" i-node number :%ld\n", (long)buf.st_ino);
	printf("Link count :%ld\n", (long)buf.st_nlink);
	printf("UID ;%ld  GID :%ld\n", (long)buf.st_uid,(long)buf.st_gid);
	printf("file size : %lld\n", (long long)buf.st_size);
	printf("Last stat change : %s", ctime(&buf.st_ctime));

