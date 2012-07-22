#include <std.h>
#include <marsh.h>
inherit OCEAN;
void create() {
ocean::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Swamp waters");
    set_long(
      "%^BLUE%^ In the swampy-waters, swimming.  There's a whirlpool here."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
        "whirlpool" : "Just water going around counter clockwise.",
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"north" : WATER "level17",
    ]) );
}
void init() {
   ::init();
   add_action("enter","enter");
}
int enter(string str) {
   if(str != "whirlpool"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("As you approach the whirlpool, you start to get sucked in.\n");
   this_player()->move(WATER "lev17");
   tell_object(this_player(), "You get sucked in and pulled into the other side.\n");
   this_player()->add_hp(-30);
   return 1;
}
void reset() {
 ::reset();
   if (!present("shark")) {
      new(MOB"shark")->move(this_object());
      new(MOB"shark")->move(this_object());
      new(MOB"shark")->move(this_object());
   if (!present("eel"))
     new(MOB"eel")->move(this_object());
     new(MOB"eel")->move(this_object());
    if (!present("octopus"))
     new(MOB"octopus")->move(this_object());
    }
}
