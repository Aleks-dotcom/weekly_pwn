#include <stdio.h>
#include <stdlib.h>

void win(){
    system("/bin/sh");
    exit(0);
}


void vuln(){
    char arr[100];
    int passcode;
    puts("please tell me a joke...");  
    fgets(arr,0x100,stdin);
    if (passcode == 0xdeadc0de){
        puts('try harder this time');
    }else{
        puts("AHAHAHAHAHAHA, good joke");
    }
}

int main(){
    alarm(10);
    vuln();
    return 0;
}