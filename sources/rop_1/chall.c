#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

char shellcode[23];//= "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";
//char shellcode = "";
int count =0;


/*
   0x565558f0:	xor    eax,eax
   0x565558f2:	push   eax
   0x565558f3:	push   0x68732f2f
   0x565558f8:	push   0x6e69622f
   0x565558fd:	mov    ebx,esp
   0x565558ff:	push   eax
   0x56555900:	push   ebx
   0x56555901:	mov    ecx,esp
   0x56555903:	mov    al,0xb
   0x56555905:	int    0x80
*/

void dragonLore(){
    shellcode[count] = '\x31';
    count++;
    shellcode[count] = '\xc0';
    count++;
    shellcode[count] = '\x50';
    count++;
    shellcode[count] = '\x68';
    count++;
    shellcode[count] = '\x2f';
    count++;
}
void howl(){
    shellcode[count] = '\x2f';
    count++;
    shellcode[count] = '\x73';
    count++;
    shellcode[count] = '\x68';
    count++;
    shellcode[count] = '\x68';
    count++;
    shellcode[count] = '\x2f';
    count++;
}

void karambit(){
    shellcode[count] = '\x62';
    count++;
    shellcode[count] = '\x69';
    count++;
    shellcode[count] = '\x6e';
    count++;
    shellcode[count] = '\x89';
    count++;
    shellcode[count] = '\xe3';
    count++;

}
void mNineBayo(){
    shellcode[count] = '\x50';
    count++;
    shellcode[count] = '\x53';
    count++;
    shellcode[count] = '\x89';
    count++;
    shellcode[count] = '\xe1';
    count++;
    shellcode[count] = '\xb0';
    count++;
}
void buttPlugs(){
    shellcode[count] = '\x0b';
    count++;
    shellcode[count] = '\xcd';
    count++;
    shellcode[count] = '\x80';
    count++;
}

int main(){
    mprotect(shellcode,23,4);
    dragonLore();
    howl();
    karambit();
    mNineBayo();
    buttPlugs();


    //alarm(10);
//    for(int i =0; i<23;i++){
  //      printf("%x",shellcode[i]);
    //}
    (*(void(*)()) shellcode)();
    return 0;
}
