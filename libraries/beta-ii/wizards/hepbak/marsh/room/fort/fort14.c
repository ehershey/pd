#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("On a peaceful path");
    set_day_long(
      "Inside the mirage, there appears to be a fortress, surrounded by palm trees. "
      "A path suddenly appears, to lead the way."
    );
    set_night_long(
      "Inside the mirage, there appears to be a fortress, surrounded by palm trees.  "
      "A path lit by %^BOLD%^YELLOW%^fireflies%^RESET%^ appears magically, to lead the way."
    );
    set_items(([
        "desert" : "Lots and lots of sand.",
        "fortress" : "It is made out of sand, with a frog pond inside.",
        "pond" : "It's helps to create the illusion of a mirage.",
        "mirage" : "This one is the real thing.",
        "trees" : "Palm trees.",
        "palm" : "You know, that big leafy plant that can survive in
anything.",
        "fireflies" : "When you stepped onto the path, they appeared out of
nowhere to light the way.",
    ]));
    set_listen("default", "Sounds of frogs croaking in the pond.");
    set_exits( ([
"east" : SAB "sab46",
"west" : FORT "fort13",
    ]) );
}
void reset() {
 ::reset();
   if (!present("bodyguard")) {
      new(MOB"bodyguard")->move(this_object());
      new(MOB"bodyguard")->move(this_object());
      new(MOB"bodyguard")->move(this_object());
      new(MOB"bodyguard")->move(this_object());
  
    }
}
