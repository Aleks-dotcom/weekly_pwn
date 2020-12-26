#!/bin/bash
chown pilot:pilot /app/format_3
while true; do
	su pilot -c 'timeout -k 30s 1d socat TCP-LISTEN:7486,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./format_3"'
done
