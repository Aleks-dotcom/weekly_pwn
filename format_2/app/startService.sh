#!/bin/bash
chown pilot:pilot /app/format_2
su pilot -c 'socat TCP-LISTEN:7482,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./format_2"'
