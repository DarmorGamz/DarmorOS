#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

# After build create a .gitignore file so you can easily do commits.
cat > isodir/.gitignore << EOF
*
*/
!.gitignore
EOF

# Create grub.cfg that will be used when executing grub-mkrescue
cp sysroot/boot/darmoros.kernel isodir/boot/darmoros.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "darmoros" {
	multiboot /boot/darmoros.kernel
}
EOF
grub-mkrescue -o darmoros.iso isodir
