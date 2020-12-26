#include <stdio.h>
#include <stdlib.h>


void vuln(){
    char name[20];
    puts("welcome back! What's your name again?");
    fgets(name,0x14,stdin);
    printf("ah yes ");
    printf(name);
    printf("it's nice to see you. ");
}

void vuln2(){
    char arr[100];
    puts("what would you like to drink?");  
    fgets(arr,0x100,stdin);
    puts("Great choice");

}

int main(){
    alarm(10);
    vuln();
    vuln2();
    return 0;
}