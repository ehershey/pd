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
      "everywhere and sickly elephants are jumping off of cliffs to the south."
    );
    set_night_long(
      "There are sharp bones scattered everywhere.  This is the beginning "
      "of an Elephant's Graveyard.  It is a very drab and dreay place to "
      "be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"north" : ELE "ele18",
"northeast" : ELE "ele19",
"east" : ELE "ele13",
"south" : ELE "ele8",
"southwest" : ELE "ele7",
"northwest" : ELE "ele17",
"west" : ELE "ele11",
    ]) );
}
void reset() {
 ::reset();
   if (!present("melephant")) {
      new(MOB"melephant")->move(this_object());
   }
}
