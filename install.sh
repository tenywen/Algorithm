#/bin/sh
if [ ! -d lib ] ; then
    mkdir lib 
fi
make
mv *.a lib/
make clean
