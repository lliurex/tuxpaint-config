#ifndef ABOUT_H
#define ABOUT_H

#include <libintl.h>
#ifndef gettext_noop
#define gettext_noop(String) String
#endif

static const char * about_text = gettext_noop(
          "Welcome to Tux Paint's graphical configuration tool, created by "
          "Torsten Giebl, Jan Wynholds, Bill Kendrick, and Martin Fuhrer.\n"
          "\n"
          "This tool allows you to alter Tux Paint's settings, such as "
          "full-screen mode, the interface's language, or options to simplify "
          "Tux Paint for younger children.\n"
          "\n"
          "These settings can be set for the current user only or for all users "
          "of your computer by making a selection in the 'Settings for' "
          "pull-down menu at the bottom.\n"
          "\n"
          "Use the tabs at the top to select the different setting categories, "
          "change the options you'd like to change, and click the 'Apply' "
          "button at the bottom to write out a new configuration file.\n"
          "\n"
          "The next time Tux Paint is launched, the new settings should take "
          "effect.");

#endif /* ABOUT_H */
