# Makefile for tuxpaint-config

# Tux Paint Configuration Tool - A GUI-based configurator for
#                              Tux Paint, a simple drawing program for children.

# Torsten Giebl <wizard@turricane.org>
# Jan Wynholds
# Bill Kendrick <bill@newbreedsoftware.com>
# Martin Fuhrer <mfuhrer@gmail.com>

# http://www.tuxpaint.org/

# November 12, 2002 - July 6, 2009
# $Id: Makefile,v 1.39 2009/07/06 16:21:09 wkendrick Exp $


VER_VERSION=0.0.13
VER_DATE=`date +"%Y-%m-%d"`


# Where to install things:

PREFIX=/usr/local


# Program:

BIN_PREFIX=$(PREFIX)/bin
EXE_EXT=


# Data:

DATA_PREFIX=$(PREFIX)/share/tuxpaint-config/


# Docs and man page:

DOC_PREFIX=$(PREFIX)/share/doc/tuxpaint-config/
MAN_PREFIX=$(PREFIX)/share/man/


# Tux Paint's 'System-wide' Config file:

ifeq ($(PREFIX),/usr)
  CONFDIR=/etc/tuxpaint
else
  CONFDIR=$(PREFIX)/etc/tuxpaint
endif


# Icons and launchers:

ICON_PREFIX=$(PREFIX)/share/pixmaps/
X11_ICON_PREFIX=$(PREFIX)/X11R6/include/X11/pixmaps/
GNOME_PREFIX=$(shell gnome-config --prefix 2> /dev/null)
KDE_PREFIX=$(shell kde-config --install apps --expandvars 2> /dev/null)
KDE_ICON_PREFIX=$(shell kde-config --install icon --expandvars 2> /dev/null)


# Locale files

LOCALE_PREFIX=$(PREFIX)/share/locale/
# LOCALE_PREFIX=/usr/share/locale/


# Built with sound by default  (override with "make nosound")

NOSOUNDFLAG=__SOUND


# Libraries, paths, and flags:

# FIXME: UTF-8 required for translations; we need to see if we can
# use fltk-utf8 (and fallback to regular fltk, if not).
# I did not have luck using fltk-utf8, even in English, though :(
# -bjk 2008.07.16
#FLTK_CFLAGS=`fltk-utf8-config --cxxflags`
#FLTK_LIBS=`fltk-utf8-config --ldflags`

FLTK_CFLAGS=`fltk-config --cxxflags`
FLTK_LIBS=`fltk-config --ldflags`

PAPER_LIB=-lpaper

# Default CFLAGS:
CFLAGS=-O2 -Wall

# The entire set of CFLAGS:
ALL_CFLAGS=$(CFLAGS) $(FLTK_CFLAGS) -DDATA_PREFIX=\"$(DATA_PREFIX)\" \
	-D$(NOSOUNDFLAG) -DDOC_PREFIX=\"$(DOC_PREFIX)\" \
	-DLOCALEDIR=\"$(LOCALE_PREFIX)\" -DCONFDIR=\"$(CONFDIR)\" \
	-DVER_VERSION=\"$(VER_VERSION)\" -DVER_DATE=\"$(VER_DATE)\"


# "make" with no arguments builds the program and man page from sources:

all:	tuxpaint-config translations
	@echo
	@echo "Done compiling."
	@echo "Now (probably as 'root' superuser), run 'make install'"
	@echo "to install Tux Paint Configuration Tool."
	@echo

releaseclean:
	@echo
	@echo "Cleaning release directory"
	@echo
	@rm -rf "build/tuxpaint-config-$(VER_VERSION)" "build/tuxpaint-config-$(VER_VERSION).tar.gz"
	@-if [ -d build ] ; then rmdir build ; fi

releasedir: build/tuxpaint-config-$(VER_VERSION)

build/tuxpaint-config-$(VER_VERSION):
	@echo
	@echo "Creating release directory"
	@echo
	@mkdir -p build/tuxpaint-config-$(VER_VERSION)
	@find . -follow \
		\( -wholename '*/CVS' -o -name .cvsignore -o -name 'build' -o -name '.#*' \) \
		-prune -o -type f -exec cp --parents -vdp \{\} build/tuxpaint-config-$(VER_VERSION)/ \;

release: releasedir
	@echo
	@echo "Creating release tarball"
	@echo
	@cd build ; \
		tar -czvf tuxpaint-config-$(VER_VERSION).tar.gz \
		tuxpaint-config-$(VER_VERSION)


win32:
	make \
		EXE_EXT=.exe \
		ICON_PREFIX=./ \
		X11_ICON_PREFIX=./ \
		CONFDIR=$(PREFIX)/etc/tuxpaint \
		ARCH_LINKS=$(shell if [ "x$$OSTYPE" == "xcygwin" ]; then echo -n "-lintl"; else echo -n "-lintl-8"; fi ) \
		ARCH_LIBS="obj/resource.o obj/win32utils.o" \
		PAPER_LIB= 

install-win32:
	@strip -s tuxpaint-config.exe
	make install \
		EXE_EXT=.exe \
		ICON_PREFIX=./ \
		X11_ICON_PREFIX=./ \
		CONFDIR=$(PREFIX)/etc/tuxpaint \
		ARCH_LINKS=$(shell if [ "x$$OSTYPE" == "xcygwin" ]; then echo -n "-lintl"; else echo -n "-lintl-8"; fi ) \
		ARCH_LIBS="obj/resource.o obj/win32utils.o"

# "make install" installs all of the various parts
# (depending on the *PREFIX variables at the top, you probably need
# to do this as superuser ("root"))

install:	install-bin install-data install-man install-doc \
		install-gnome install-kde install-kde-icons \
		install-icon install-gettext
	@echo
	@echo "All done! Now (preferably NOT as 'root' superuser),"
	@echo "you can type the command 'tuxpaint-config' to run the"
	@echo "configuration tool!"
	@echo
	@echo "Enjoy!"
	@echo


# "make clean" deletes the program, the compiled objects and the
# built man page (returns to factory archive, pretty much...)

clean:
	@echo "Cleaning up the build directory ($(PWD))"
	@-rm -f tuxpaint-config tuxpaint-config.exe
	@-rm -f obj/*.o
	@#if [ -d obj ]; then rmdir obj; fi
	@-rm -f trans/*.mo
	@if [ -d trans ]; then rmdir trans; fi


# "make uninstall" should remove the various parts from their
# installation locations.  BE SURE the *PREFIX variables at the top
# are the same as they were when you installed, of course!!!

uninstall:
	-if [ "x$(GNOME_PREFIX)" != "x" ]; then \
	  rm $(GNOME_PREFIX)/share/applications/tuxpaint-config.desktop; \
	  rm $(GNOME_PREFIX)/share/pixmaps/tuxpaint-config.png; \
	fi
	-if [ "x$(KDE_PREFIX)" != "x" ]; then \
	  rm $(KDE_PREFIX)/Preferences/tuxpaint-config.desktop; \
	fi
	-rm $(ICON_PREFIX)tuxpaint-config.png
	-rm $(X11_ICON_PREFIX)tuxpaint-config.xpm
	-rm $(BIN_PREFIX)/tuxpaint-config
	-rm -r $(DATA_PREFIX)
	-rm -r $(DOC_PREFIX)
	-rm $(MAN_PREFIX)/man1/tuxpaint-config.1.gz


# Install a launcher icon in the Gnome menu, under "Graphhics"

install-gnome:
	@echo
	@echo "...Installing launcher icon into GNOME..."
	@if [ "x$(GNOME_PREFIX)" != "x" ]; then \
  	  install -d $(GNOME_PREFIX)/share/pixmaps; \
	  cp data/images/icon.png $(GNOME_PREFIX)/share/pixmaps/tuxpaint-config.png; \
	  chmod 644 $(GNOME_PREFIX)/share/pixmaps/tuxpaint-config.png; \
	  install -d $(GNOME_PREFIX)/share/applications; \
	  cp src/tuxpaint-config.desktop $(GNOME_PREFIX)/share/applications/; \
	  chmod 644 $(GNOME_PREFIX)/share/applications/tuxpaint-config.desktop; \
	fi


# Install a launcher icon in the KDE menu...

install-kde:
	@echo
	@echo "...Installing launcher icon into KDE..."
	@if [ "x$(KDE_PREFIX)" != "x" ]; then \
	  install -d $(KDE_PREFIX)/Preferences/; \
	  cp src/tuxpaint-config.desktop $(KDE_PREFIX)/Preferences/; \
	  chmod 644 $(KDE_PREFIX)/Preferences/tuxpaint-config.desktop; \
	fi


install-kde-icons:
	@echo "...Installing launcher icon graphics into KDE..."
	@if [ "x$(KDE_ICON_PREFIX)" != "x" ]; then \
	  cp data/images/icon48x48.png \
		$(KDE_ICON_PREFIX)/hicolor/48x48/apps/tuxpaint-config.png; \
	  cp data/images/icon32x32.png \
		$(KDE_ICON_PREFIX)/hicolor/32x32/apps/tuxpaint-config.png; \
	  cp data/images/icon16x16.png \
		$(KDE_ICON_PREFIX)/hicolor/16x16/apps/tuxpaint-config.png; \
	fi


# Install the PNG icon (for GNOME, KDE, etc.)
# and the 24-color 32x32 XPM (for other Window managers):

install-icon:
	@echo
	@echo "...Installing launcher icon graphics..."
	@install -d $(ICON_PREFIX)
	@cp data/images/icon.png $(ICON_PREFIX)tuxpaint-config.png
	@chmod 644 $(ICON_PREFIX)tuxpaint-config.png
	@install -d $(X11_ICON_PREFIX)
	@cp data/images/icon32x32.xpm $(X11_ICON_PREFIX)tuxpaint-config.xpm
	@chmod 644 $(X11_ICON_PREFIX)tuxpaint-config.xpm


# Install the program:

install-bin:
	@echo
	@echo "...Installing program itself..."
	@cp tuxpaint-config $(BIN_PREFIX)
	@chmod a+rx,g-w,o-w $(BIN_PREFIX)/tuxpaint-config$(EXE_EXT)


# Install the data (sound, graphics, fonts):

install-data:
	@echo
	@echo "...Installing data files..."
	@install -d $(DATA_PREFIX)
	@cp -R data/* $(DATA_PREFIX)
	@chmod -R a+rX,g-w,o-w $(DATA_PREFIX)


# Install the text documentation:

install-doc:
	@echo
	@echo "...Installing documentation..."
	@echo "(English)"
	@install -d $(DOC_PREFIX)
	@install -d $(DOC_PREFIX)/html
	@cp docs/AUTHORS.txt $(DOC_PREFIX)
	@cp docs/CHANGES.txt $(DOC_PREFIX)
	@cp docs/COPYING.txt $(DOC_PREFIX)
	@cp docs/README.txt $(DOC_PREFIX)
	@cp docs/html/README.html $(DOC_PREFIX)/html
	@cp docs/TODO.txt $(DOC_PREFIX)
	@echo "(...Setting permissions)"
	@chmod -R a+rx,g-w,o-w $(DOC_PREFIX)


# Install the man page:

install-man:
	@echo "...Installing man pages..."
	# man1 directory...
	@install -d $(MAN_PREFIX)/man1/
	# tuxpaint-config.1
	@cp src/tuxpaint-config.1 $(MAN_PREFIX)/man1/
	@gzip -9f $(MAN_PREFIX)/man1/tuxpaint-config.1
	@chmod a+rx,g-w,o-w $(MAN_PREFIX)/man1/tuxpaint-config.1.gz


# Build the program!

tuxpaint-config:	obj/tuxpaint-config.o obj/tuxpaint-config2.o	\
			obj/defaults.o $(ARCH_LIBS)
	@echo Linking
	$(CXX) $(ALL_CFLAGS) -o tuxpaint-config obj/tuxpaint-config.o 	\
			obj/tuxpaint-config2.o obj/defaults.o $(ARCH_LIBS) \
			$(FLTK_LIBS) $(ARCH_LINKS) $(PAPER_LIB)


# Build the object for the program!

obj/tuxpaint-config.o:	src/tuxpaint-config.cxx src/version.h src/about.h
	@echo Compiling tuxpaint-config.cxx
	$(CXX) $(ALL_CFLAGS) -c src/tuxpaint-config.cxx -o obj/tuxpaint-config.o

obj/tuxpaint-config2.o:	src/tuxpaint-config2.cxx src/version.h src/about.h
	@echo Compiling tuxpaint-config2.cxx
	$(CXX) $(ALL_CFLAGS) -c src/tuxpaint-config2.cxx -o obj/tuxpaint-config2.o

obj/defaults.o:	src/defaults.cxx
	@echo Compiling defaults.cxx
	$(CXX) $(ALL_CFLAGS) -c src/defaults.cxx -o obj/defaults.o

obj/win32utils.o: src/win32utils.cxx src/win32utils.h
	@echo Compiling win32utils.cxx
	$(CXX) $(ALL_CFLAGS) -c src/win32utils.cxx -o obj/win32utils.o

obj/resource.o:	visualc/resource.rc visualc/resource.h
	@echo
	@echo "...Compiling win32 resources..."
	@windres -i visualc/resource.rc -o obj/resource.o


# Translation stuff:

POFILES:=$(wildcard src/po/*.po)
MOFILES:=$(patsubst src/po/%.po,trans/%.mo,$(POFILES))
INSTALLED_MOFILES:=$(patsubst trans/%.mo,$(LOCALE_PREFIX)/%/LC_MESSAGES/tuxpaint-config.mo,$(MOFILES))

$(INSTALLED_MOFILES): $(LOCALE_PREFIX)/%/LC_MESSAGES/tuxpaint-config.mo: trans/%.mo
	install -D -m 644 $< $@

.PHONY: uninstall-i18n
uninstall-i18n:
	-rm $(LOCALE_PREFIX)/*/LC_MESSAGES/tuxpaint-config.mo


# Install the translated text:
# We can install *.mo files if they were already generated, or if it can be
# generated from the *.po files.  The *.mo files can be generated from the
# *.po files if we have the converter program, msgfmt, installed in the
# system.  So we test for both and install them if either case is found
# to be true.  If neither case is found to be true, we'll just install
# Tux Paint without the translation files.
.PHONY: install-gettext
ifeq "$(wildcard trans/*.mo)$(shell msgfmt -h)" ""
install-gettext:
	@echo
	@echo "--------------------------------------------------------------"
	@echo "Cannot install translation files because no translation files"
	@echo "were found (trans/*.mo) and the 'msgfmt' program is not installed."
	@echo "You will not be able to run Tux Paint in non-U.S. English modes."
	@echo "--------------------------------------------------------------"
else
install-gettext: $(INSTALLED_MOFILES)
endif


# Build the translation files for gettext

$(MOFILES): trans/%.mo: src/po/%.po
	msgfmt -o $@ $<

.PHONY: translations
ifeq "$(shell msgfmt -h)" ""
translations: trans
	@echo "--------------------------------------------------------------"
	@echo "Cannot find program 'msgfmt'!"
	@echo "No translation files will be prepared."
	@echo "Install gettext to run Tux Paint in non-U.S. English modes."
	@echo "--------------------------------------------------------------"
else
translations: trans $(MOFILES)
endif

trans:
	@echo
	@echo "...Preparing translation files..."
	@mkdir trans


# Make the "obj" directory to throw the object(s) into:

obj:
	@mkdir obj

