
#include <std.h>
#include <aekari.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "cave" : 1,
     "indoors" : 1,
     "light" : 1
   ]) );
   set_short("Jagged Cavern");
   set_long(
     "It is apparent the %^CYAN%^rocky walls%^RESET%^ have been well kept in this small cave. There are fragments of %^BOLD%^%^CYAN%^crystal%^RESET%^ and %^GREEN%^glossy stone%^RESET%^ scattered across the floor. There are strange torches planted firmly in the walls, the interior becomes a little more suffocating from the %^MAGENTA%^purple glow%^RESET%^ of the flames."
     " There is a depression in one of the walls. "
   );
   set_items( ([
   "wall" : "It appears to be very fragile.",
     ({"stones","fragments","crystals"}): "Only reflective debris.",
     ({"rocky walls","walls"}): "Well worn, very clean stone.",
     ({"flames","flame","torch","torches"}):
     "Simple wooden torches that burn with a %^MAGENTA%^violet flame%^RESET%^."
   ]) );
   set_exits( ([
     "northwest" : ROOMS"ca44",
     "east" : ROOMS"ca46",
   ]) );
}

void init() {
   ::init();
   add_action("smash","smash");
   add_action("knock","knock");
}

int smash(string str) {
   if(str != "wall")
   { notify_fail("What?\n"); return 0; }
   write("The wall collapses as you strike it.\n");
   write("A passage is revealed to the southwest.\n");
   say(this_player()->query_cap_name() +
     " smashes a wall. \n");
   add_exit("/wizards/danovae/pro/aekari/room/ca51.c","southwest");
   return 1;
}

int knock(string str) {
   if(str != "wall")
   { notify_fail("What?\n"); return 0; }
   write("There is a hollow sound.\n");
   return 1;
}




