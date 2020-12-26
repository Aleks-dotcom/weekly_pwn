#!/bin/bash
chown pilot:pilot /app/format_1
su pilot -c 'socat TCP-LISTEN:7481,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./format_1"'
