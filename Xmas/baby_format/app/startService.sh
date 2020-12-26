#!/bin/bash
chown pilot:pilot /app/baby_format
while true; do
	su pilot -c 'timeout -k 30s 1d socat TCP-LISTEN:7482,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./baby_format"'
done
