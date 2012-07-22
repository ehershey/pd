#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Monastery");
  set_long(
   "%^BOLD%^Stone walls surround the hallway with candle "
   "holders adorning them. Stained glass windows allow "
   "colorful light to shine through. The hallway turns "
   "here. An old suit of knight's armour sits in the corner.%^RESET%^");
  set_items(([
    "walls" : "The stone walls are cold and gray. They've "
    "been pollished smooth, reflecting the "
    "light.",
    "suit" : "A suit of old, steel armour sits in the corner "
    "of the hallway. ",
    "armour" : "A suit of old, steel armour sits in the corner "
    "of the hallway. ",
    "holders" : "Golden candle holders line the walls.",
    "windows" : "Colorful windows decorate the monastery."
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "north" : ROOMS "mon26",
    "west" : ROOMS "mon28"]));
}
void reset() {
  ::reset();
  if(!present("healer")) new(MOB"healer.c")->move(this_object());
  if(!present("healer 2")) new(MOB"healer.c")->move(this_object());
}
