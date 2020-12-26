#include <stdio.h>
#include <stdlib.h>

void win(int a, int b){
    puts("you made it to win land, no free handouts this time, try harder");
    if (a == 0xdeadbeef){
        puts("one down, one to go!");
        if (b == 0x1337c0de){
            puts("2/2 bro good job");
            system("/bin/sh");
            exit(0);
        }
    }
}


void vuln(){
    char arr[75];
    int passcode;
    puts("will need more than a simple joke this time...");  
    fgets(arr,0x100,stdin);
    if (passcode == 0xdeadc0de){
        puts("damn, this is bof_1, still far behind, go to work :)");
    }else{
        puts("will this work?");
    }
}

int main(){
    alarm(10);
    vuln();
    return 0;
}
