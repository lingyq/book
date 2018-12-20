#!/bin/sh
count=1;
for img in *.jpg *.png
do
new=image-$count.${img##*.}
echo "img=$img"
echo "new=$new"
mv "$img" "$new" 2> /dev/null
if [ $? -eq 0 ];
then
echo "Renameing $img to $new"
let count++
fi
done
