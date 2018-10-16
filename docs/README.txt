                               Tux Paint Config.
                                 version 0.0.12

  Configuration tool for Tux Paint

                Copyright 2002-2008 by Bill Kendrick and others
                               New Breed Software

                           bill@newbreedsoftware.com
                            http://www.tuxpaint.org/

                       September 22, 2004 - July 14, 2008

     ----------------------------------------------------------------------

                                     About

     "Tux Paint Config." is a graphical configuration tool for "Tux Paint."
     It provides a point-and-click interface that allows parents and teachers
     to alter Tux Paint's behavior -- disable sound effects, run in
     full-screen mode, etc. - without needing to manipulate a text-based
     configuration file.

     ----------------------------------------------------------------------

                                    License

     Tux Paint Config. is an Open Source project, Free Software released
     under the GNU General Public License (GPL). It is free, and the
     'source code' behind the program is available. (This allows others to
     add features, fix bugs, and use parts of the program in their own GPL'd
     software.)

     See COPYING.txt for the full text of the GPL license.

     ----------------------------------------------------------------------

                              Other Documentation

     Other documentation included with Tux Paint Config. (in the "docs"
     folder/directory) include:
       * AUTHORS
         List of authors and contributors
       * CHANGES
         Summary of changed between releases
       * INSTALL
         Instructions on how to compile and install
       * COPYING
         Copying license (The GPL)
       * README
         (This file)
       * TODO
         A list of pending features or bugs needing fixed

     ----------------------------------------------------------------------

                            Using Tux Paint Config.

     Tux Paint Config.'s interface is divided into seven (7) tabs, each
     containing a different category of options that you can change in
     Tux Paint. (For full details on Tux Paint's options, we recommend
     reading Tux Paint's own documentation.)

     At the bottom of the screen are three buttons:

       * Defaults - This sets the options shown on the current tab to their
         default settings. (In other words, how Tux Paint would operate if
         you didn't make any changes to the options.)
       * Apply - This saves settings of all the options, on all the tabs, to
         your Tux Paint configuration file. (On Linux and Unix, this is
         "~/.tuxpaintrc". On Windows, this is "tuxpaint.cfg". On Mac OS X, it
         is " ~/Library/Application Support/TuxPaint/tuxpaint.cfg".)
       * Reset - This discards all unsaved changes on all the tabs. It loads
         whatever settings are currently stored in your Tux Paint
         configuration file.

     Also at the bottom are two additional options:

       * Settings for: - This lets you change which configuration file
         Tux Paitn Config. tries to save to when you click "Apply": either
         the Current User's, or All Users' (the system-wide config. file).
       * Use "All Users" Settings - Checking this option causes all
         configuration options in Tux Paint Config. to be greyed out. When
         you click "Apply", the current user's config. file will be deleted,
         causing them to use only the system-wide ("All users") config. file!

     The various tabs, and the options found within, are described below:

About

       This tab simply contains some information about Tux Paint Config.

Video & Sound

         * Fullscreen - This causes Tux Paint to (attempt to) run in
           fullscreen mode, rather than in a window on your desktop. It
           causes Tux Paint to display across your entire screen (or as much
           as it can, with a border around the outside), in essense turning
           your monitor into a Tux Paint-only display.
              * Native - This causes Tux Paint to run using your current
                desktop resolution when you run in fullscreen mode. Example:
                If you have Tux Paint set to run in a 800x600 window on your
                1280x800 laptop, but you have this option enabled, it will
                run at 1280x800 when you launch Tux Paint in fullscreen mode
                (rather than dropping your laptop's LCD display down to
                800x600, which might not look right).
         * Window Size - By default, Tux Paint creates a relatively small
           window (800 pixels across by 600 pixels high). Since many people
           prefer a larger drawing canvas, or have screens at different
           aspect ratios or larger sizes, Tux Paint can be told to create a
           larger window, instead. If running in fullscreen, this also
           determines the monitor resolution Tux Paint will try to switch
           into, unless the "Native" option is set.
         * Rotate Orientation - This option swaps the width and height values
           given in the "Window Size" setting, which can be useful for
           displays with portrait aspect ratios (e.g., a tablet PC in the
           tablet orientation, vs. the laptop orientation).
         * Allow Screensaver - By default, the underlying system that
           Tux Paint uses for graphics disables your screensaver. You can set
           this option to allow your screensaver to appear, even while
           Tux Paint is running.
         * Enable Sound Effects - By default, Tux Paint plays sounds for
           practically every action that takes place... drawing with the
           brush, displaying a pop-up dialog, painting a rainbow. By
           un-checking this option, you can turn sounds off.
         * Use Alternative Color Palette - This allows you to specify a file
           containing colors that Tux Paint should provide to the user. (See
           Tux Paint's documentation for details on the format.)

Mouse & Keyboard

         * Fancy Cursor Shapes - Normally, Tux Paint changes the shape of
           your mouse pointer when the mouse is inside the Tux Paint window.
           It turns into a large brush when painting, and a cross-hair when
           drawing lines, for example. However, the large brushes can cause
           problems on some systems, so you can disable this option if the
           brushes don't work right for you.
         * Hide Cursor - Completely hides the mouse pointer in Tux Paint.
           Useful when using a touchscreen (such as a tablet PC or handheld
           device), rather than a mouse or drawing tablet.
         * Enable Keyboard Shortcuts - Tux Paint supports some keyboard
           shortcuts ('accelerators'), like Control + S to Save and
           Control + Z to Undo. If your child hits the keyboard accidentally,
           you can disable these shortcuts to prevent them from being used
           accidentally.
         * Grab Mouse Pointer - If you'd rather not run Tux Paint in
           fullscreen mode, but you want to keep children from getting at
           your desktop files or other applications, you can have Tux Paint
           'grab' the mouse pointer, which prevents it from leaving the
           Tux Paint window.
         * Mouse Wheel Support - If your mouse has a scroll wheel, Tux Paint
           will let you use it to scroll up and down through the selection
           menu on the right (e.g., the brush or stamp collections). However,
           if your child still lacks dexterity with the mouse, they may hit
           the scroll wheel accidentally, and get frustrated. You can tell
           Tux Paint to ignore the mouse wheel, if that is the case.
         * No Button Distinction - Tux Paint notices if the user is
           accidentally clicking with the middle or right button on a mouse,
           and after a number of clicks, pops up a window explaining which
           button should be used. If this option is enabled, the pop-up does
           not appear, and the middle and right mouse button can be used
           (they act the same as the left button).

Simplification

       If your child is very young, or is handicapped, the 'Simplification'
       options can help make Tux Paint even easier to use.

         * Disable Shape Rotation - Tux Paint's 'Shape' tool works in three
           steps: (1) click where you want the center of your shape to be,
           (2) drag out from the center to determine the size of the shape,
           and (3) move the mouse to rotate the shape, and click once more to
           finalize it. The third step (rotation) can be tricky to get the
           hang of, and very young children are more interested in the shapes
           themselves, not the angles they can be drawn at. Hence, you can
           disable shape rotation by selecting this option.
         * Simple Stamp Outlines - If your computer is very slow, or you're
           using Tux Paint on a thin client (displaying over a network), you
           can simplify the outlines drawn around stamps to help speed up the
           display.
         * Show Uppercase Text Only - If your child is just learning to read,
           and hasn't yet mastered the lowercase alphabet, you can tell
           Tux Paint to display everything in uppercase. (LIKE THIS.)
         * Disable Quit Button - This greys out the 'Quit' button in
           Tux Paint. The Escape key and the close button in the window's
           toolbar still work (though the latter can be made inaccessible by
           running Tux Paint in fullscreen mode, or in mouse-grab mode.)
         * Disable Stamps Tool - This prevents Tux Paint from loading any
           stamps at start-up, this speeding up the load process and, of
           course, causing the 'Stamps' tool button to be greyed out.
         * Disable Stamp Controls - Tux Paint allows stamps to be shrunk and
           grown, and many stamps can be flipped and/or mirrored. These
           options add four buttons to the Stamp tool's selector, however,
           which can confuse the younger users. Disable those controls with
           this option.
         * Disable Magic Controls - Some of Tux Paint's Magic tools work as a
           painting tool, some apply their effect to the entire canvas, and
           some can do both. This option removes the button that selects
           which mode Magic tools run in. (If this option is set, tools will
           default to painting mode, unless they do not support it.)
         * Initial Stamp Size - This lets you set a default size for all
           Stamps in Tux Paint. Normally, it picks a size based on the
           stamp's size, your canvas size, and/or settings provided
           specifically for the stamp.

Languages

         * Language - Tux Paint has been translated into dozens of languages.
           While it can use your system's global language preference, you may
           prefer to run your desktop in one language, and have your children
           use Tux Paint in another. Select the language you want Tux Paint
           to run in from the pull-down menu. (Select "Use system's setting"
           to use your system's global language preference.)
         * Mirror Stamps - Some people are used to things going
           right-to-left, rather than left-to-right. (Hebrew is written
           right-to-left, for example.) Most stamps are oriented
           left-to-right, and many can be mirrored using the 'Mirror' stamp
           control. You can tell Tux Paint to mirror all such stamps, by
           default, when it starts up.
         * Load System Fonts - This causes Tux Paint to look around typical
           locations on your hard drive for fonts, and adds ones that seem
           useful to the fonts available in the "Text" tool.

Printing

         * Allow Printing - If you wish to disable the 'Print' button in
           Tux Paint, un-check this option.
         * Print Delay - If you wish to allow printing in Tux Paint, but
           limit it to, say, only once every 5 minutes, you can enter a delay
           value (in seconds). After printing, Tux Paint will wait that long
           before the 'Print' button works again.
         * Show Printer Dialog - Tux Paint can bring up a system printer
           dialog if the [Alt] key ([Option] on Macs) is held while the
           "Print" button is clicked. These options allow you to disable this
           feature (never show a dialog), or to always show a dialog, even
           when [Alt] isn't being held.
         * Use Alternative Print Command / Alternative Print Command -
           (Advanced! Unix/Linux only!) By default, Tux Paint under Linux and
           Unix uses the external program 'lpr' for printing pictures. You
           can specify a different command here. The command you specify must
           accept PostScript format on it's standard input (STDIN).
         * Use Alternative Print Dialog - (Advanced! Unix/Linux only!) By
           default, Tux Paint under Linux and Unix uses the extnernal program
           'kprinter' (KDE, the K Desktop Environment's printer tool). You
           can specify a different command here. The command you specify must
           accept PostScript format on it's standard input (STDIN).
         * Paper Size - This lets you choose the size of paper that you're
           using with Tux Paint. You can use your system's default, or
           override it with a specific paper size (e.g., "A4" or
           "US Letter").

Saving

  Save Over Earlier Work

         Tux Paint has one 'Save' command, which works with one click. If
         you're done drawing a picture, click 'Save' and it is saved, no
         questions asked!

         However, if you're re-saving a picture that you loaded using the
         'Open' command, Tux Paint needs to know whether you want to save
         over the original, or save a new image. (In most other programs,
         this would be 'Save' versus 'Save As...', respectively.)

         By default, Tux Paint will pop up a prompt asking whether to 'save
         over the older version of [the] picture.' Choosing 'Yes' will wipe
         out the old version, replacing it with the updated drawing. Choosing
         'No' will preserve the old version, and save a completely new file.

         To simplify the 'Save' process by never asking the 'save over?'
         question, you can tell Tux Paint what to do ahead of time:

           * Ask Before Overwriting - This is the default behavior, described
             above. (Ask whether to save over, or not.)
           * Always Overwrite Older Version - This will always wipe out the
             old version, replacing it with any updates to the drawing. (It's
             like 'Save' in other desktop applications.)
           * Always Save New Picture - This will never wipe out older work,
             this preserving every single change that's ever been saved.
             (It's like always using 'Save As...' in other desktop
             applications.) Warning: Using this option obviously creates the
             potential for many files being stored in Tux Paint! You may want
             to go in and manually remove files for your child. (Tux Paint's
             'Open' dialog uses thumbnails to show the saved pictures, and
             includes an 'Erase' button, so you can do this from within
             Tux Paint.)

  Start Blank

         This option tells Tux Paint to always start with a blank (white)
         drawing canvas, rather than re-loading the last-saved picture (its
         default behavior).

  Save Directory

         Since Tux Paint never asks where to save pictures (or what filename
         to use when creating the files), it keeps all of its pictures in its
         own special directory.

         If you wish to change where Tux Paint saves pictures (and, of
         course, where it looks for them when the 'Open' command is used),
         you can do so here.

         This can be useful in a school lab where all of the computers are
         shared by students, and students must log into a special network
         drive to save their files. You can tell Tux Paint to save on the
         mapped network drive, rather than on the local hard drive.

         See Tux Paint's own documentation for more on the subject.

  Disable 'Save' Button

         If you wish for Tux Paint to be used only as a 'scratch pad' for
         drawing, you may disable the 'Save' button. Obviously, this makes it
         impossible to save any drawings, so most people will have no use for
         this option.

  Auto-save on Quit

         This tells Tux Paint not to ask whether you wish to save the current
         picture (if unsaved) when you quit. It will assume you always do.
         (If it needs to ask about saving over an old copy, it will still do
         so.)

Data

         * Don't use lockfile - Normally, when Tux Paint is launched it
           creates a small data file called a 'lockfile.' If this file
           exists, and Tux Paint is launched again, the second copy will quit
           immediately. This was done to prevent multiple copies of Tux Paint
           from loading when children over-eagerly and/or impatiently click
           the launcher icon. However, if you're using Tux Paint on a
           networked filesystem, and all users share the same folder, this
           may prevent more than one computer from running Tux Paint. Enable
           this setting to ask Tux Paint to not use lockfiles, and ignore any
           that may be there.
         * Use Alternative Data Directory - Similar to "Use Alternative Save
           Directory," above, this option lets you specify a different
           location for Tux Paint to look for its data files: brushes,
           stamps, etc. (This can be good if you have school-specific data
           for Tux Paint stored on a network drive that you'd like all your
           students to use, rather than Tux Paint's default data files,
           located on the local hard disk.)

     ----------------------------------------------------------------------

                                More Information

     For more information, see the other documentation files that come with
     Tux Paint.

     If you need help, feel free to contact New Breed Software:

       http://www.newbreedsoftware.com/

     You may also wish to participate in the numerous Tux Paint mailing
     lists:

       http://www.tuxpaint.org/lists/
