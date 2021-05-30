#!/usr/bin/env bash
set -e

make
sudo kldload ./hello.ko
kldstat

sudo kldunload hello.ko
kldstat

