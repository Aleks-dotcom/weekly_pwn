#!/bin/bash
chown pilot:pilot /app/bof_3
su pilot -c 'socat TCP-LISTEN:7480,nodelay,reuseaddr,fork EXEC:"stdbuf -i0 -o0 -e0 ./bof_3"'
