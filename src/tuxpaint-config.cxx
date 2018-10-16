/*
  tuxpaint-config.c

  Tux Paint Configuration Tool - A GUI configuration editor for Tux Paint,
                                 a simpel drawing program for children.

  Copyright (c) 2002-2008
  
  Torsten Giebl <wizard@turricane.org>
  Jan Wynholds
  Bill Kendrick <bill@newbreedsoftware.com>

  http://www.tuxpaint.org/
  
  November 12, 2002 - July 14, 2008
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>

#include <libintl.h>
#ifndef gettext_noop
#define gettext_noop(String) String
#endif

#if !defined (__WIN32__) && !defined(__APPLE__) && !defined(__BEOS__)
#include <paper.h>
#endif

#include "version.h"
#include "about.h"


#ifdef WIN32
#define LOCALEDIR "locale"
#endif

#include <errno.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#if !defined(Fl_H)
#error "---------------------------------------------------"
#error "If you installed FLTK from a package, be sure to get"
#error "the development package, as well!"
#error "(e.g., 'libfltk1-dev.rpm')"
#error "---------------------------------------------------"
#endif

#include "tuxpaint-config2.h"

/* Local function prototypes: */

void setup(int argc, char * argv[]);
int mainloop(int argc, char * argv[]);


int main(int argc, char * argv[])
{
  int res;

  setup(argc, argv);

  res = mainloop(argc, argv);

#if !defined (__WIN32__) && !defined(__APPLE__) && !defined(__BEOS__)
  paperdone();
#endif

  return res;
}


int mainloop(int argc, char * argv[])
{
    Fl::scheme ("none");	
    Show_TPC_Window ();

    return Fl::run ();
}


void setup(int argc, char * argv[])
{
  int i;
  int show_usage;
  int exit_val;
    
#if !defined (__WIN32__) && !defined(__APPLE__) && !defined(__BEOS__)
  const struct paper * ppr;
  int max_papersizes;
#endif
    
  show_usage = 0;
  exit_val = 0;

  for (i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--help") == 0)
    {
      unsigned int x, j, len;
      char buf[80];

      buf[0] = '\0';
      len = 0;
      x = 0;

      for (j = 0; j <= strlen(about_text); j++)
      {
        buf[len++] = about_text[j];

        if (about_text[j] == ' ' || about_text[j] == '\0')
        {
          if (x + len > 78)
          {
            printf("\n");
            x = 0;
          }

          buf[len] = '\0';
          printf("%s", buf);
          x += len;

          len = 0;
        }
      }

      printf("\n\n");

      exit(0);
    }
    else if (strcmp(argv[i], "--usage") == 0)
    {
      show_usage = 1;
      exit_val = 0;
    }
    else if (strcmp(argv[i], "--copying") == 0)
    {
      /* FIXME: Copying! */
      printf("\nTux Paint Config. version " VER_VERSION ", " VER_DATE "\n\n");

      printf("This program is free software; you can redistribute it\n"
	     "and/or modify it under the terms of the GNU General Public\n"
	     "License as published by the Free Software Foundation;\n"
	     "either version 2 of the License, or (at your option) any\n"
	     "later version.\n"
	     "\n"
	     "This program is distributed in the hope that it will be\n"
	     "useful and entertaining, but WITHOUT ANY WARRANTY; without\n"
	     "even the implied warranty of MERCHANTABILITY or FITNESS\n"
	     "FOR A PARTICULAR PURPOSE.  See the GNU General Public\n"
	     "License for more details.\n"
	     "\n"
	     "You should have received a copy of the GNU General Public\n"
	     "License along with this program; if not, write to the Free\n"
	     "Software Foundation, Inc., 59 Temple Place, Suite 330,\n"
	     "Boston, MA  02111-1307  USA\n\n");
	exit(0);  
    }
    else if (strcmp(argv[i], "--version") == 0)
    {
      printf("Tux Paint Config. version " VER_VERSION ", " VER_DATE "\n");
      exit(0);
    }
    else
    {
      show_usage = 1;
      exit_val = 1;
    }
  }

  if (show_usage)
  {
    printf("Usage: %s [--version | --copying | --usage | --help]\n",
           argv[0]);

    /* Kluge to get around OS X sending arguments to apps; jdrake 2004-10-02 */
#ifndef __APPLE__
    exit(exit_val);
#endif
  }


  setlocale(LC_ALL,"");

  bindtextdomain("tuxpaint-config", LOCALEDIR);
  /* Old version of glibc does not have bind_textdomain_codeset() */
#if defined __WIN32 || __GLIBC__ && __GLIBC__ == 2 && __GLIBC_MINOR__ >=2 || __GLIBC__ > 2 || __APPLE__
  bind_textdomain_codeset("tuxpaint-config", "UTF-8");
#endif
  textdomain("tuxpaint-config");


  /* Get available paper sizes: */

#if !defined (__WIN32__) && !defined(__APPLE__) && !defined(__BEOS__)
  paperinit();

  max_papersizes = 5;
  papersizes = (char * *) malloc(sizeof (char * *) * max_papersizes);

  papersizes[0] = strdup(gettext("(Use system's default)"));
  num_papersizes = 1;
  ppr = paperfirst();
  
  do
  {
    if (ppr != NULL)
    {
      if (num_papersizes >= max_papersizes)
      {
        max_papersizes += 5;
        papersizes = (char * *) realloc(papersizes, sizeof(char * *) * max_papersizes);
      }

      papersizes[num_papersizes++] = strdup(papername(ppr));
    }

    ppr = papernext(ppr);
  }
  while (ppr != NULL);

#endif
}
