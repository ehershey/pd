#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path continues west and east. A little way off to the north there is a fairly large, freshly painted barn. Also to the north a small strem gently flows east. To the east the top of a large windmill can be seen. The stream to the north curves south and floods in the way of the path due east. There are a few flowers growing on the side of the road here.");
  set_night_long("The dark path continues west and east. A little way off to the north there is a fairly large, freshly painted barn. Also to the north a small stream gently flows east. To the east the large black hump of the top of a large windmill can be seen. The dark strem to the north curves south and floods in the way of the path due east. There are a few flowers growing on the side of the road here.");
  set_items(([
    "flower" : "How pretty!",
    "flowers" : "They are really pretty.",
    "path" : "A small dirt path to make walking easier. It goes west, east, and northeast.",
    "barn" : "A very large barn. It is north of your current location.",
    "stream" : "It is to the north of here. If flows east behind the barn."
   ]));
  set_exits(([
    "west" : ROOMS"farm8",
    "east" : ROOMS"farm12"
   ]));
}
void reset() {
  ::reset();
  if (!present("wife"))
    new(MOB "fwife.c")->move(this_object());
}
void init() {
  ::init();
  add_action("do_pick", "pick");
}
int do_pick(string str) {
  if(!str || str != "flower") return notify_fail("Pick what?\n");
  else {
    write("%^GREEN%^You pick a flower.%^RESET%^");
    tell_room(environment(this_player()), "%^GREEN%^"+this_player()->query_cap_name()+" picks a flower.", ({ this_player() }) );
    new(OBJ"flower.c")->move(this_player());
    return 1;
  }
}
