
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
     " There is a pile of stones against the northern wall. "
   );
   set_items( ([
     ({"stones","fragments","crystals"}): "Only reflective debris.",
     ({"rocky walls","walls","wall"}): "Well worn, very clean stone.",
     ({"flames","flame","torch","torches"}):
     "Simple wooden torches that burn with a %^MAGENTA%^violet flame%^RESET%^."
   ]) );
   set_search("stones", "There is nothing unusual about them, but they are neatly stacked.");
   set_exits( ([
     "down" : ROOMS"ba1",
     "southeast" : ROOMS"ca36",
   ]) );
}

void init() {
   ::init();
   add_action("move","move");
}

int move(string str) {
   if(str != "stones")
   { notify_fail("Move what?\n");  return 0; }
   write("You uncover a path leading north.\n");
   add_exit("/wizards/danovae/pro/aekari/room/ca38.c","north");
   return 1;
}
void reset() {
   ::reset();
   remove_exit("north");
   if(!present("guard"))
   new(NPC"ae_guard.c")->move(this_object());
   if(!present("guard 2"))
   new(NPC"ae_guard.c")->move(this_object());
}

