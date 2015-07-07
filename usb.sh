#!/bin/sh
set -e
. ./build.sh

USB=/media/tor/PANDA # never leave this empty
echo $USB
cp sysroot/boot/turnip.kernel $USB/boot/turnip.kernel
cat > $USB/boot/grub/grub.cfg << EOF
menuentry "turnip" {
	multiboot /boot/turnip.kernel
}
EOF

