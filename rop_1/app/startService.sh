#!/bin/bash
chown pilot:pilot /app/rop_1

su pilot -c 'socat TCP-LISTEN:7487,nodelay,reuseaddr,fork EXEC:"./rop_1"'

