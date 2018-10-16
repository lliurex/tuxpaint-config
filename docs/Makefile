# Makefile for Tux Paint Config docs
# 
# Uses "links" to convert docs from HTML to plain text.
# (Normally only ran by the developers after updating the HTML, prior to
# release.)
#
# Bill Kendrick
# bill@newbreedsoftware.com
# 
# Sept. 9, 2006 - July 14, 2008
# $Id: Makefile,v 1.2 2008/07/14 20:50:50 wkendrick Exp $

#LINKS=links -dump -no-numbering -no-references
LINKS=links -dump

all:	README.txt

clean:
	-rm README.txt

README.txt:	html/README.html
	$(LINKS) $< > $@

