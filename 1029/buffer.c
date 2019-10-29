#include<stdio.h>
void main(){
    int i,n,m,j;
    char c;
    
    printf("반복 횟수 입력 : ");
    scanf("%d",&n);
    for(j=1;j<=n;j++){
    printf("반복할 문자와 반복할 수 입력 : ");
    getchar();
    scanf("%c %d",&c,&m);
    for(i=1;i<=m;i++){
        printf("%c",c);
    
    }
    printf("\n");
}
}
