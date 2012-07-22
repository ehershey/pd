
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
   );
   set_items( ([
     ({"stones","fragments","crystals"}): "Only reflective debris.",
     ({"rocky walls","walls","wall"}): "Well worn, very clean stone.",
     ({"flames","flame","torch","torches"}):
     "Simple wooden torches that burn with a %^MAGENTA%^violet flame%^RESET%^."
   ]) );
   set_exits( ([
     "north" : ROOMS"ca9",
     "northwest" : ROOMS"ca8",
     "west" : ROOMS"ca10",
     "south" : ROOMS"ca13",
     "southeast" : ROOMS"ca14",
     "east" : ROOMS"ca12",
   ]) );
}

void reset() {
   ::reset();
   if(!present("red guard"))
   new(NPC"ae_magi1.c")->move(this_object());
   if(!present("yellow guard"))
   new(NPC"ae_magi2.c")->move(this_object());
   if(!present("blue guard"))
   new(NPC"ae_magi3.c")->move(this_object());
   return 0;
}


