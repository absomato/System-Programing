#include<stdio.h>

int main(int argc,char* argv[]){
	FILE* fp;
	int c;
	//인수가 없을경우 표준입출력으로
	if(argc<2)
		fp=stdin;
	else fp=fopen(argv[1], "r");

	c=getc(fp);//파일로부터 문자 읽기
	while(c!= EOF){//파일의 끝에 다다를때 까지 문자를 출력하고 입력 반복
		putc(c, stdout);
		c=getc(fp);
	}
	fclose(fp);
	return 0;
}
