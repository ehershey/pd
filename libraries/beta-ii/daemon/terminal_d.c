//      /obj/daemon/terminal_d.c
//      from the Nightmare Mudlib
//      Contains all the terminal information used to initialize
//      a player's terminal settings
//      created by Pinkfish@Discworld
//      rewritten for the Nightmare Mudlib by Descartes of Borg 930903

#define ANSI(p) sprintf("%c["+(p)+"m", 27)
#define ESC(p) sprintf("%c"+(p), 27)

static mapping term_info;
string *colours;
void create() {
    colours = ({ "RESET","BOLD","FLASH","BLACK","RED","BLUE","CYAN",
                 "MAGENTA","ORANGE","YELLOW","GREEN","WHITE","BLACK",
                 "B_RED","B_ORANGE","B_YELLOW","B_BLACK","B_CYAN",
                 "B_WHITE","B_GREEN","B_MAGENTA","STATUS","WINDOW",
                 "INITTERM","ENDTERM" });
    term_info = ([  
       "unknown":
      ([ "RESET": "", "BOLD": "", "FLASH":"", "BLACK":"", "RED":"", "BLUE":"",
      "CYAN":"", "MAGENTA":"", "ORANGE":"", "YELLOW":"", "GREEN":"",
      "WHITE":"", "BLACK":"", "B_RED":"", "B_ORANGE":"", "B_YELLOW":"",
      "B_BLACK":"", "B_CYAN":"","B_WHITE":"", "B_GREEN":"",
      "B_MAGENTA":"", "STATUS":"", "WINDOW":"", "INITTERM": "","ENDTERM":""]),

       "wrap":
      ([ "RESET": "%^RESET%^", "BOLD": "%^BOLD%^", "FLASH":"%^FLASH%^", "BLACK":"%^BLACK%^", "RED":"%^RED%^", "BLUE":"%^BLUE%^",
      "CYAN":"%^CYAN%^", "MAGENTA":"%^MAGENTA%^", "ORANGE":"%^ORANGE%^", "YELLOW":"%^YELLOW%^", "GREEN":"%^GREEN%^",
      "WHITE":"%^WHITE%^", "B_RED":"%^B_RED%^", "B_ORANGE":"%^B_ORANGE%^", "B_YELLOW":"%^B_YELLOW%^",
      "B_BLACK":"%^B_BLACK%^", "B_CYAN":"%^B_CYAN%^","B_WHITE":"%^B_WHITE%^", "B_GREEN":"%^B_GREEN%^",
      "B_MAGENTA":"%^B_MAGENTA%^", "STATUS":"%^STATUS%^", "WINDOW":"%^WINDOW%^", "INITTERM": "%^INITTERM%^","ENDTERM":"%^ENDTERM%^"]),

      "ansi": ([ "RESET":ANSI("0;37;40"), "BOLD":ANSI(1), "FLASH":ANSI(5),
      "BLACK":ANSI(30), "RED":ANSI(31), "GREEN":ANSI(32), "ORANGE":ANSI(33),
      "YELLOW":ANSI(1)+ANSI(33), "BLUE": ANSI(34), "CYAN":ANSI(36),
      "MAGENTA":ANSI(35), "BLACK":ANSI(30), "WHITE": ANSI(37),
      "B_RED":ANSI(41), "B_GREEN":ANSI(42), "B_ORANGE":ANSI(43),
      "B_YELLOW":ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
      "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
      "B_MAGENTA":ANSI(45), "STATUS":"", "WINDOW":"", "INITTERM":"",
      "ENDTERM":"" ]),
      "freedom": ([ "RESET": ESC("G0"), "BOLD":ESC("G@"), "FLASH":ESC("G2"),
      "BLACK":"", "RED":"", "GREEN":"", "ORANGE":"", "YELLOW":"", "BLUE":"",
      "CYAN":"", "MAGENTA":"", "BLACK":"", "WHITE":"", "B_RED":ESC("GD"),
      "B_GREEN": ESC("GD"), "B_ORANGE":ESC("G4"), "B_YELLOW":ESC("G4"),
      "B_BLUE":ESC("G4"), "B_CYAN":ESC("GD"), "B_BLACK": ESC("GD"),
      "B_WHITE":ESC("G4"), "B_MAGENTA":("G4"), "STATUS":"", "WINDOW":"",
      "INITTERM":"", "ENDTERM":"" ]),
      "ansi-status": ([ "RESET": ANSI("0;37;40"), "BOLD":ANSI(1),
      "FLASH":ANSI(5), "BLACK":ANSI(30), "RED":ANSI(31),
      "GREEN":ANSI(32), "ORANGE":ANSI(33), "YELLOW":ANSI(1)+ANSI(33), "BLUE":ANSI(34),
      "CYAN": ANSI(36), "MAGENTA": ANSI(35), "BLACK":ANSI(30),
      "WHITE":ANSI(37), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
      "B_ORANGE":ANSI(43), "B_YELLOW": ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
      "B_CYAN": ANSI(46), "B_BLACK":ANSI(40), "B_WHITE":ANSI(47),
      "B_MAGENTA":ANSI(45), "STATUS":ESC("[23;24r")+ESC(8), 
      "WINDOW":ESC(7)+ESC("[0;22r")+ESC("[22H\n"),
      "INITTERM":ESC("[H")+ESC("[J")+ESC("[23;24r")+ESC("23H\n"),
      "ENDTERM":ESC("[0r")+ESC("[H")+ESC("[J") ]),
      "xterm": ([ "RESET": ESC(">")+ESC("[1;3;4;5;61")+ESC("[?7h")+ESC("[m"),
      "BOLD": ESC("[7m"), "FLASH":ESC("[5m$<2>"), "BLACK":ANSI(30),
      "RED":ANSI(31), "GREEN":ANSI(32), "ORANGE":ANSI(33), "YELLOW":ANSI(33),
      "BLUE":ANSI(34), "CYAN":ANSI(36), "MAGENTA":ANSI(35),"BLACK":ANSI(34),
      "WHITE":ANSI(38), "B_RED":ANSI(41), "B_GREEN":ANSI(42), 
      "B_ORANGE":ANSI(43), "B_YELLOW":ANSI(43), "B_BLUE":ANSI(44), 
      "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
      "B_MAGENTA": ANSI(45), "STATUS":"", "WINDOW":"", "INITTERM":"",
      "ENDTERM":"" ]),
    ]);
   term_info["html"] = term_info["unknown"] +
        ([ "RED"  : "<FONT COLOR=\"#FF0000\">",
         "GREEN" : "<FONT COLOR=\"#00FF00\">",
         "BLUE"  : "<FONT COLOR=\"#0000FF\">",
         "YELLOW" : "<FONT COLOR=\"#FFFF00\">",
         "CYAN" : "<FONT COLOR=\"#00A0DD\">",
         "MAGENTA" : "<FONT COLOR=\"#C50067\">",
         "WHITE" : "<FONT COLOR=\"#FFFFFF\">",
         "RESET": "</FONT>",
         "BR" : "<BR>", "P" : "<P>", "/P" : "</P>", ">" : ">",
         "HREF" : "<A HREF=", "NAME" : "<A NAME=", "/A" : "</A>",
         "I" : "<I>", "/I" : "</I>", "PRE" : "</PRE>", "/PRE" : "</PRE>",
         "STRONG" : "<STRONG>", "/STRONG" : "</STRONG>",               
         "TABLE" : "<TABLE>", "/TABLE" : "</TABLE>", "TR" : "<TR>",
         "/TR" : "</TR>", "TD" : "<TD>" , "/TD" : "</TD>" ]);         
}

mapping query_term_info(string type) {
    return (term_info[type] ? term_info[type] : term_info["unknown"]);
}

string *query_terms() { return keys(term_info); }

int query_term_support(string str) {
    return (term_info[str] ? 1 : 0);
}

string no_colours(string str) {
   if (!str) return "";
//   return terminal_colour( str, term_info["ascii"]);
    return implode( explode(str, "%^") - colours, "");
// can't use this way, the driver always inserts a code for RESET (for line wrapping)
//   return terminal_colour( str, term_info["unknown"]);

}
string html_it(string str) {
   return terminal_colour(str, term_info["html"]);
}

