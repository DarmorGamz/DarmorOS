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
cp sysroot/boot/darmoros.bin isodir/boot/darmoros.bin
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "darmoros (kernel)" {
    multiboot /boot/darmoros.kernel
}

menuentry "darmoros (bin)" {
    multiboot /boot/darmoros.bin
}
EOF

# Create the build directory if it doesn't exist.
mkdir -p build/

# Create .iso and .bin
grub-mkrescue -o build/darmoros.iso isodir
