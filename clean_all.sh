#!/bin/bash

#make clean
#make distclean

rm -f *.Debug
rm -f *.Release
rm -f *.json
rm -f *.pro.user
rm -f manifest.json

if [ -f Makefile ]; then
   make distclean
fi

rm -f -r debug
rm -f -r release

rm -f -r bin

rm -f Makefile

rm -f ui_*.h


#mv -f */*.deb ../


