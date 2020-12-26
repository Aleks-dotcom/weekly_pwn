#!/bin/bash
chown pilot:pilot /app/bof_2
su pilot -c 'socat TCP-LISTEN:7479,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./bof_2"'
