#!/bin/bash
echo "Type folder name :"
read name
touch $name".txt"
find $name -type f | sed /.c$/\!d > $name".txt"
touch "Makefile"
cp "Makefile" "Makefile.backup.obj"
make -C ~/create_obj/
~/create_obj/create_obj $name".txt" >> "Makefile"
rm $name".txt"
