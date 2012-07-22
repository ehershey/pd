#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Into the forest");
    set_long(
      "%^GREEN%^T%^BOLD%^he forest is mainly composed of "
      "evergreen trees and willows.  There is little or "
      "no vegetation here that wont last through winter.",);
 
    set_items(([
        "forest" : "The shadows are leaping all round now, "
             "it looks like they're about to attack something.",
        "evergreen trees" : "They are massive and old looking. ",
        "willows" : "The willows seem to cry somehow.",
        "shadows" : "These shadows don't seem too friendly.",
        ]));
    
    set_exits( (["west" : ROOMS "trm3.c",
                 "east"  : ROOMS "tfrm2.c", ]) );
    
}
