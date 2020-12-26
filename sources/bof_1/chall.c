#include <stdio.h>
#include <stdlib.h>

void win(){
    system("/bin/sh");
    exit(0);
}


void vuln(){
    char arr[10];
    int passcode;
    gets(arr);
    if (passcode == 0xdeadbeef){
        win();
    }else{
        puts("nope");
    }
}

int main(){
    alarm(10);
    vuln();
    return 0;
}