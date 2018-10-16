#!/bin/sh

intltool-update --pot --gettext-package=tuxpaint-config
sed -e s/charset=CHARSET/charset=UTF-8/ tuxpaint-config.pot > temp.tmp && mv -f temp.tmp tuxpaint-config.pot
msguniq tuxpaint-config.pot > temp.tmp && mv -f temp.tmp tuxpaint-config.pot
for i in *.po ; do
  echo $i
  msgmerge --previous --update $i tuxpaint-config.pot
done
cd ..
intltool-merge -d -u po tuxpaint-config.desktop.in tuxpaint-config.desktop
cd po
