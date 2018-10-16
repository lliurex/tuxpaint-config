#include "defaults.h"
/*
struct {
  bool fullscreen=0;
  bool eightbysix=0;
  bool sound=1;
  bool fancycursors=1;
  bool grab=0;
  bool wheelmouse=1;
  bool outlines=0;
  bool simpleshapes=0;
  bool uppercase=0;
  bool noquit=0;
  bool stamps=1;
  bool stampcontrols=1;
  char lang[64]="\0";
  bool mirrorstamps=1;
  bool print=1;
  int printdelay=0;
  bool printcfg=1;
  char savedir[256]="\0";
  char datadir[256]="\0";
} options;
*/

void activate_buttons()
{
  BUTTON_apply->activate();
  BUTTON_reset->activate();
}

void DEF_videoandsound ()
{
    int diff = 0;

    // Video Defaults

    diff += CHECKBUTTON_fullscreen -> value (0);
    diff += CHECKBUTTON_native -> value (0);
    diff += CHOICE_windowwidth -> value (DEF_WINDOW_WIDTH);
    diff += CHOICE_windowheight -> value (DEF_WINDOW_HEIGHT);
    diff += CHECKBUTTON_rotate -> value(0);
    diff += CHECKBUTTON_screensaver -> value(0);

    // Sound Defaults
   
    diff += CHECKBUTTON_soundeffects -> value (1);

    // Colors

    diff += CHECKBUTTON_usecolorfile -> value (0);
    FILEINPUT_colorfile->value("");
    FILEINPUT_colorfile	-> deactivate ();
    BUTTON_browsecolorfile -> deactivate ();

    if (diff)
      activate_buttons();
}

bool CHKBUT_fulls_isdef ()
{
    if (CHECKBUTTON_fullscreen->value() == 0)
       return 1;
    else
       return 0;
}

void DEF_mouseandkeyboard ()
{
    int diff = 0;

    // Mouse Defaults

    diff += CHECKBUTTON_fancycursorshapes -> value (1);
    diff += CHECKBUTTON_hidecursor -> value (0);
    diff += CHECKBUTTON_grabmousepointer -> value (0);
    diff += CHECKBUTTON_mousewheelsupport -> value (1);
    diff += CHECKBUTTON_nobuttondistinction	-> value (0);
	
    // Keyboard Defaults
    
    diff += CHECKBUTTON_enablekbd -> value (1);

    if (diff)
      activate_buttons();
}

bool CHKBUT_fancycursors_isdef ()
{
    if (CHECKBUTTON_fancycursorshapes->value() == 1)
       return 1;
    else
       return 0;
}

bool CHKBUT_grabmouse_isdef ()
{
    if (CHECKBUTTON_grabmousepointer->value() == 0)
       return 1;
    else
       return 0;
}

bool CHKBUT_mousewheelsup_isdef ()
{
    if (CHECKBUTTON_mousewheelsupport->value() == 1)
       return 1;
    else
       return 0;
}

bool CHKBUT_enablekb_isdef ()
{
    if (CHECKBUTTON_enablekbd->value() == 1)
       return 1;
    else
       return 0;
}

void DEF_simplification ()
{
    int diff = 0;

    // Interface Simplification Defaults

    diff += CHECKBUTTON_disableshaperotation -> value (0);
    diff += CHECKBUTTON_simpleshapeoutlines -> value (0);
    diff += CHECKBUTTON_showuppercasetextonly	-> value (0);

    // Control Simplification Defaults
    
    diff += CHECKBUTTON_disablequitbutton	-> value (0);
    diff += CHECKBUTTON_disablestampstool	-> value (0);
    diff += CHECKBUTTON_disablestampcontrols -> value (0);

    diff += SLIDER_stampsize -> value(-1);

    if (diff)
      activate_buttons();
}

bool CHKBUT_norots_isdef ()
{
    if (CHECKBUTTON_disableshaperotation->value() == 0)
       return 1;
    else
       return 0;
}

bool CHKBUT_smploutlns_isdef ()
{
    if (CHECKBUTTON_simpleshapeoutlines->value() == 0)
       return 1;
    else
       return 0;
}

bool CHKBUT_showUConly_isdef ()
{
    if (CHECKBUTTON_showuppercasetextonly->value() == 0)
       return 1;
    else
       return 0;
}

bool CHKBUT_disablequit_isdef ()
{
    if (CHECKBUTTON_disablequitbutton->value() == 0)
       return 1;
    else
       return 0;
}

void DEF_locale ()
{
    int diff = 0;

    // Locale Defaults
	
    diff += CHOICE_language -> value (0);
    diff += CHECKBUTTON_mirrorstamps -> value (0);
    diff += CHECKBUTTON_loadsystemfonts	-> value (0);
    diff += CHECKBUTTON_alllocalefonts	-> value (0);

    if (diff)
      activate_buttons();
}

bool CHKBUT_mirstamps_isdef()
{
    if (CHECKBUTTON_mirrorstamps->value() == 0)
       return 1;
    else
       return 0;
}


void DEF_printing ()
{
    int diff = 0;

    // Printing Perm. Defaults

    diff += CHECKBUTTON_allowprinting -> value (1);
    diff += VALUEINPUT_printdelay	-> value (0);

    // Print Dialog

    diff += ROUNDBUTTON_printdialogmod -> value (1);
    diff += ROUNDBUTTON_printdialogalways -> value (0);
    diff += ROUNDBUTTON_printdialognever -> value (0);

    // Print Cmd. Defaults

    diff += CHECKBUTTON_usealtprintcmd -> value (0);
    TEXTINPUT_printcmd->value("");
    TEXTINPUT_printcmd -> deactivate ();

    // Print Dialog Cmd. Defaults

    diff += CHECKBUTTON_usealtprintdia -> value (0);
    TEXTINPUT_printdia->value("");
    TEXTINPUT_printdia -> deactivate ();

#if USE_PAPERSIZES
    diff += CHOICE_papersize -> value(0);
#endif

    if (diff)
      activate_buttons();
}

bool CHKBUT_allowprint_isdef()
{
    if (CHECKBUTTON_allowprinting->value() == 1)
       return 1;
    else
       return 0;
}

bool VALINP_printdel_isdef()
{
    if (VALUEINPUT_printdelay->value() == 0)
       return 1;
    else
       return 0;
}


void DEF_saving ()
{
    int diff = 0;

    // Saving Over Defaults

    diff += ROUNDBUTTON_askbeforeoverwriting -> value (1);
    diff += ROUNDBUTTON_alwaysoverwriteolderversion -> value (0);
    diff += ROUNDBUTTON_alwayssavenewpicture -> value (0);

    // Save Directory Defaults

    diff += CHECKBUTTON_usealternatesavedir -> value (0);
    FILEINPUT_alternatesavedir->value("");
    FILEINPUT_alternatesavedir -> deactivate ();
    BUTTON_browsealternatesavedir -> deactivate ();

    diff += CHECKBUTTON_startblank -> value(0);
    diff += CHECKBUTTON_disablesavebutton->value(0);
    diff += CHECKBUTTON_autosave -> value(0);

    if (diff)
      activate_buttons();
}


void DEF_data ()
{
    int diff = 0;

    // Data Directory Defaults

    diff += CHECKBUTTON_nolockfile -> value(0);

    diff += CHECKBUTTON_usealternatedatadir -> value (0);
    FILEINPUT_alternatedatadir->value("");
    FILEINPUT_alternatedatadir -> deactivate ();
    BUTTON_browsealternatedatadir -> deactivate ();

    if (diff)
      activate_buttons();
}

void DEF_accessibility()
{
    int diff = 0;
    diff += CHECKBUTTON_mouse_accessibility -> value(0);
    diff += CHECKBUTTON_keyboard_mouse -> value(0);
    diff += CHECKBUTTON_onscreen_keyboard -> value(0);
    diff += CHECKBUTTON_onscreen_keyboard_disable_change -> value(0);
    diff += CHOICE_onscreen_keyboard_layout -> value(0);

    if (diff)
      activate_buttons();
}

void DEF_joystick ()
{
    int diff = 0;

    if (SPINNER_joystick_dev -> value() != 0)
      {
        SPINNER_joystick_dev -> value(0);
	diff += 1;
      }
    if (SPINNER_joystick_slowness -> value() != 15)
      {
	SPINNER_joystick_slowness -> value(15);
	diff += 1;
      }
    if (SPINNER_joystick_threshold -> value() != 3200)
      {
	SPINNER_joystick_threshold -> value(3200);
	diff += 1;
      }
    if (SPINNER_joystick_maxsteps -> value() != 7)
      {
	SPINNER_joystick_maxsteps -> value(7);
	diff += 1;
      }
    if (SPINNER_joystick_hat_slowness -> value() != 15)
      {
	SPINNER_joystick_hat_slowness -> value(15);
	diff += 1;
      }
    if (SPINNER_joystick_hat_timeout -> value() != 1000)
      {
	SPINNER_joystick_hat_timeout -> value(1000);
	diff += 1;
      }
    if (CHECKBUTTON_joystick_buttons_ignore -> value() != 0)
      {
	CHECKBUTTON_joystick_buttons_ignore -> value(0);
	diff += 1;
      }
    if(strlen(TEXTINPUT_joystick_buttons_ignore->value()) > 0)
      {
	TEXTINPUT_joystick_buttons_ignore->value("");
	diff += 1;
      }
    TEXTINPUT_joystick_buttons_ignore->deactivate();
    if (SPINNER_joystick_btn_brush -> value() != 255)
      {
	SPINNER_joystick_btn_brush -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_label -> value() != 255)
      {
	SPINNER_joystick_btn_label -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_new -> value() != 255)
      {
	SPINNER_joystick_btn_new -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_print -> value() != 255)
      {
	SPINNER_joystick_btn_print -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_shapes -> value() != 255)
      {
	SPINNER_joystick_btn_shapes -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_undo -> value() != 255)
      {
	SPINNER_joystick_btn_undo -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_eraser -> value() != 255)
      {
	SPINNER_joystick_btn_eraser -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_lines -> value() != 255)
      {
	SPINNER_joystick_btn_lines -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_open -> value() != 255)
      {
	SPINNER_joystick_btn_open -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_redo -> value() != 255)
      {
	SPINNER_joystick_btn_redo -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_stamp -> value() != 255)
      {
	SPINNER_joystick_btn_stamp -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_escape -> value() != 255)
      {
	SPINNER_joystick_btn_escape -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_magic -> value() != 255)
      {
	SPINNER_joystick_btn_magic -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_pgsetup -> value() != 255)
      {
	SPINNER_joystick_btn_pgsetup -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_save -> value() != 255)
      {
	SPINNER_joystick_btn_save -> value(255);
	diff += 1;
      }
    if (SPINNER_joystick_btn_text -> value() != 255)
      {
	SPINNER_joystick_btn_text -> value(255);
	diff += 1;
      }

    if (diff)
      activate_buttons();
}

bool RNDBUT_askoverwrite_isdef()
{
    if (ROUNDBUTTON_askbeforeoverwriting->value() == 1)
       return 1;
    else
       return 0;
}

bool CHKBUT_altsavedir_isdef()
{
    if (CHECKBUTTON_usealternatesavedir->value() == 0)
       return 1;
    else
       return 0;
}


bool CHKBUT_altdatadir_isdef()
{
    if (CHECKBUTTON_usealternatedatadir->value() == 0)
       return 1;
    else
       return 0;
}


void CB_SetActualTabToDefaults ()
{
    if ( TABE_videoandsound	-> visible () )
    {
        DEF_videoandsound	();
        return;
    }
    
    if ( TABE_mouseandkeyboard	-> visible () )
    {
        DEF_mouseandkeyboard	();
        return;
    }

    if ( TABE_simplification	-> visible () )
    {
        DEF_simplification	();
        return;
    }

    if ( TABE_locale		-> visible () )
    {
        DEF_locale		();
        return;
    }
    
    if ( TABE_printing -> visible () )
    {
        DEF_printing		();
        return;
    }
    
    if ( TABE_saving -> visible () )
    {
        DEF_saving		();
        return;
    }
    
    if ( TABE_data -> visible () )
    {
        DEF_data		();
        return;
    }
    if ( TABE_accessibility -> visible () )
    {
        DEF_accessibility		();
        return;
    }
    if ( TABE_joystick -> visible () )
    {
        DEF_joystick		();
        return;
    }
}

void CB_SetAllTabsToDefaults ()
{
    DEF_videoandsound();
    DEF_mouseandkeyboard();
    DEF_simplification();
    DEF_locale();
    DEF_printing();
    DEF_saving();
    DEF_data();
    DEF_accessibility();
    DEF_joystick();
}
