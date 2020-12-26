#!/bin/bash
chown pilot:pilot /app/baby_rop
while true; do
	su pilot -c 'timeout -k 30 1d socat TCP-LISTEN:7481,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./baby_rop"'
done
