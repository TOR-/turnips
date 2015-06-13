#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/turnip.kernel isodir/boot/turnip.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "turnip" {
	multiboot /boot/turnip.kernel
}
EOF
grub-mkrescue -o turnip.iso isodir
