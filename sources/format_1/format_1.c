#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln(){
    FILE *fp;
    int c;
    char arr[25];
    char name[20];
    fp = fopen("flag.txt","r");
    fgets(arr,25,fp);
    fclose(fp);
    puts("hello, what's your name?");
    fgets(name,20,stdin);
    printf("hello ");
    printf(name);
}




int main(){
    alarm(10);
    vuln();
    return 0;
}