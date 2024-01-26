#!/bin/sh
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done

# After build create a .gitignore file so you can easily do commits.
cat > sysroot/.gitignore << EOF
*
*/
!.gitignore
EOF
