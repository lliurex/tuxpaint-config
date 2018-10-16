#ifndef _DEFAULTS_H
#define _DEFAULTS_H


#include "tuxpaint-config2.h"


extern void DEF_videoandsound		();
extern void DEF_mouseandkeyboard	();
extern void DEF_simplification		();
extern void DEF_locale			();
extern void DEF_printing		();
extern void DEF_saving			();
extern void DEF_data			();
extern void DEF_accessibility		();
extern void DEF_joystick		();

extern bool CHKBUT_fulls_isdef          ();
extern bool RNDBUT_scrnsz_isdef         ();
extern bool CHKBUT_fancycursors_isdef   ();
extern bool CHKBUT_grabmouse_isdef      ();
extern bool CHKBUT_mousewheelsup_isdef  ();
extern bool CHKBUT_enablekb_isdef       ();
extern bool CHKBUT_norots_isdef         ();
extern bool CHKBUT_smploutlns_isdef     ();
extern bool CHKBUT_showUConly_isdef     ();
extern bool CHKBUT_disablequit_isdef    ();
extern bool CHKBUT_mirstamps_isdef      ();
extern bool CHKBUT_allowprint_isdef     ();
extern bool VALINP_printdel_isdef       ();
extern bool CHKBUT_altsavedir_isdef     ();
extern bool CHKBUT_altdatadir_isdef     ();

extern void CB_SetActualTabToDefaults	  ();
extern void CB_SetAllTabsToDefaults	    ();

#define DEF_WINDOW_WIDTH WW_800
#define DEF_WINDOW_HEIGHT WH_600

#endif

