#!/bin/bash

path=$(dirname $0)

# Require icotool from package icoutils
# Require convert from package ImageMagick
# Require inkscape
# Require optipng

for pic in $path/*.svg
do
  echo "converting $pic"
  inkscape --without-gui --export-png=$path/$(basename $pic .svg ).png --export-dpi=72 --export-background-opacity=0 --export-width=32 --export-height=32 $pic >/dev/null
done
optipng $path/*.png
./png2wx.pl -C $path/../icons.cpp -H $path/../icons.h -M ICONS_H $path/*.png
rm $path/*.png

