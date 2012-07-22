#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : -2, "indoors" : 0]) );
set_property("plain",1);
    set_short("dark alley");
    set_long(
      "They alley comes to an end here.  To the north and the south are tall brick walls. "
      "Dark spots infest the area, leaving anything open to be hiding in there. "
    );
    set_items(([
        "walls" : "Large brick walls with graffiti covering them.",
        "dark spots" : "Darkness....",
        "spots" : "Darkness....",
	"graffiti" : "%^BOLD%^%^BLUE%^L%^BOLD%^%^RED%^i%^BOLD%^%^BLUE%^T%^BOLD%^%^RED%^t%^BOLD%^%^BLUE%^L%^BOLD%^%^RED%^e %^BOLD%^%^BLUE%^b%^BOLD%^%^RED%^A%^BOLD%^%^BLUE%^s%^BOLD%^%^RED%^T%^BOLD%^%^BLUE%^a%^BOLD%^%^RED%^R%^BOLD%^%^BLUE%^d%^BOLD%^%^RED%^ w%^BOLD%^%^BLUE%^U%^BOLD%^%^RED%^z %^BOLD%^%^BLUE%^h%^BOLD%^%^RED%^E%^BOLD%^%^BLUE%^r%^BOLD%^%^RED%^E%^BOLD%^%^BLUE%^!%^BOLD%^%^RED%^!",
    ]));
   set_listen("default", "Loud scratching and squeaking echoes throughout the alley way.");
   set_exits( ([ 
        "east" : ROOMS"room7.c",
    ]) );
}
void reset() {
::reset();
    if(!present("bastard.c"))
      new(MOB"bastard.c")->move(this_object());
}
