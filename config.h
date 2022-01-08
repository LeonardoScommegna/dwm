/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "alacritty"
#define TERMCLASS "Alacritty"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=11", "fontawesome:size=13", "JoyPixels:pixelsize=13:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=11";

// static const char col_gray1[]       = "#222222";
// static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#005577";
// static const char col_urgborder[]   = "#ff0000";
// 
// 
// static const char *colors[][3]      = {
// 	/*               fg         bg         border   */
// 	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
// 	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// 	[SchemeTitle]  = { col_gray4, col_cyan,  col_cyan },
// 	[SchemeUrg]  = { col_urgborder, col_urgborder, col_urgborder },
// };

//static const char col_surface[] = "#121212";
//static const char col_primary[] = "#1F1B24";

static const char col_surface[]       = "#222222";
static const char col_primary[]       = "#444444";

//static const char col_surface[] = "#212121";
//static const char col_primary[] = "#2e2e2e";
//static const char col_sec[] = "#BB86FC";
static const char col_sec[] = "#FFFFFF";
static const char col_other[] = "#03DAC5";
static const char col_urg[] = "#D08770";


    // influenza quello che non viene selezionato
    // arg 1: testo della tab fuori dal quadratino non selezionato
    // arg 2: colore della barra in generale
    // arg 3: colore contorno window non selezionate
	//[SchemeNorm] = { col_gray4, col_gray4, col_gray4 },

    // influenza il contorno del quadratino selezionato e il controrno della window
    // arg 1: testo dentro il quadratino
    // arg 2: colore quadratino selazionato
    // arg 3: colore contorno current window
	//[SchemeSel]  = { col_gray4, col_gray4, col_gray4 },

    // arg 1: testo nella barra centrale
    // arg 2: colore barra centrale quando si apre qualcosa
    // arg 3: ??
	// [SchemeTitle]  = { col_gray4, col_gray4, col_urgborder },

static const char *colors[][3]      = {
	[SchemeNorm] = { col_sec, col_surface, col_other },
	[SchemeSel]  = { col_sec, col_primary , col_sec },
	[SchemeTitle] = { col_sec, col_surface, col_other },
	[SchemeUrg]  = { col_urg, col_surface, col_other },
};


// /* nord theme */
// static const char norm_fg[] = "#88C0D0";
// static const char norm_bg[] = "#2E3440";
// static const char norm_border[] = "#4C566A";
// 
// static const char bar_border[] = "#4C566A";
// 
// static const char sel_fg[] = "#D08770";
// static const char sel_bg[] = "#4C566A";
// static const char sel_border[] = "#8FBCBB";
// 
// static const char urg_fg[] = "#8FBCBB";
// static const char urg_bg[] = "#88C0D0";
// static const char urg_border[] = "#88C0D0";
// 
// static const char title_fg[] = "#88C0D0";
// static const char title_bg[] = "#88C0D0";
// static const char title_border[] = "#88C0D0";
// 
// static const char *colors[][3]      = {
// 
//     //                  fg           bg         border                         
//     [SchemeNorm]    = { norm_fg,  norm_bg,   norm_border  },  // unfocused wins
//     [SchemeSel]     = { sel_fg,   sel_bg,    sel_border   },  // the focused win
//     [SchemeUrg]     = { urg_fg,   urg_bg,    urg_border   },  // urgent 
//     [SchemeTitle]   = { sel_fg,   norm_bg,   norm_border   },  // the status bar
// };


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
 	{ NULL,       NULL,       "Event Tester",    0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

#define STATUSBAR "dwmblocks"

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_surface, "-nf", col_sec, "-sb", col_primary, "-sf", col_sec, NULL };
static const char *termcmd[]  = { TERMINAL , NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_x,      setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_z,      setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_x,      setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_z,      setgaps,        {.i = GAP_TOGGLE} },
	{ MODKEY,			            XK_minus,  spawn,		   SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		        XK_minus,  spawn,		   SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			            XK_equal,  spawn,		   SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		        XK_equal,  spawn,		   SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		        XK_m,	   spawn,		   SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_BackSpace, quit,        {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

