#include <std.h>
#include <gcity.h>
#include <mjungle.h>
inherit ROOM;
void create() {
  ::create();
set_short("%^YELLOW%^Dingo's supply room%^RESET%^");
set("long", "%^YELLOW%^Dingo stores weapons and such here.%^RESET%^");
    set_exits( 
(["south" : GCITY"gcity25.c"]) );
}
