#include <std.h>
#include <marsh.h>
inherit OCEAN;
void create() {
ocean::create();
   set_properties( ([ "light" : 1]) );
    set_property("indoors",1);
    set_short("Swamp waters");
    set_long(
      "%^BLUE%^ In the swampy-waters, swimming.  There's a whirlpool here."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
        "whirlpool" : "You see magical stardust swirling around.",
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"northeast" : WATER "ll14",
    ]) );
}
void init()
{
 ::init();
 add_action("enter", "enter");
}
int enter(string str)
{
 if (str!="whirlpool") return notify_fail("You cannot enter whirlpool!\n");
 if (this_player()->query_class()!="mage")
   {
    write("You cannot enter whirlpool.");
    return 1;
    }
 write("%^CYAN%^The whirlpool slows up and allows you to pass through.");
 this_player()->move_player(WATER "mahall", "through the whirlpool.");
return 1;
}
void reset() {
 ::reset();
   if (!present("eel")) {
      new(MOB"eel")->move(this_object());
      new(MOB"eel")->move(this_object());
      new(MOB"eel")->move(this_object());
      new(MOB"eel")->move(this_object());
 
    }
}
