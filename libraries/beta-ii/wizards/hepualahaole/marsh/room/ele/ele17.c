#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
       "This is The heart of the graveyard. Bones are scattered "
      "everywhere and sickly elephants begging for death."
    );
    set_night_long(
      "There are sharp bones scattered everywhere.  This is the beginning "
      "There are sharp bones scattered everywhere.  This is the beginning "
      "be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"north" : ELE "ele22",
"northeast" : ELE "ele23",
"east" : ELE "ele18",
"south" : ELE "ele11",
"southeast" : ELE "ele12",
"west" : ELE "ele16",
"northwest" : ELE "ele21",
    ]) );
}
void reset() {
 ::reset();
   if (!present("melephant")) {
      new(MOB"melephant")->move(this_object());
  if (!present("felephant"))
     new(MOB"felephant")->move(this_object());
   }
}
