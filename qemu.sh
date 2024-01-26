#!/bin/sh
set -e
. ./iso.sh

# qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom darmoros.iso
qemu-system-i386 -cdrom ./build/darmoros.iso
