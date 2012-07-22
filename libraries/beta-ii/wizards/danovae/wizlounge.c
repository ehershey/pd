#include <std.h>
inherit ROOM;


void create() {
   ::create();
   set_properties( ([ "light":2, "indoors":1 ]) );
   set_short("The Immortal's Break Room");
   set_long(
     "%^BOLD%^%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n"
     "Immortal Break Room \n"
     "%^BOLD%^%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^"
   );

   set_exits( ([
     "danovae" : "/wizards/danovae/workroom.c",
   ]) );
}
