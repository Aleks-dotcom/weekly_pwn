#include <stdio.h>
#include <stdlib.h>


void vuln(){
    char input[100];

    while (1){
        fgets(input,0x64,stdin);
        printf(input);
    }
}


int main(){
    alarm(10);
    vuln();
    return 0;
}