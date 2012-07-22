inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",0);
  set("short","Dungeon");
  set("long","The hallway abruptly ends here.  Anyone who was clostraphobic wouldn't "
    "last very long in this tiny room.  There is a small cell to the north.  "
    "There is a small sign nailed to the door of this cell.  Apparently the problem "
    "prisoners get sent to this cell.");
  set_smell("default","The foul fumes singe your nose hairs.");
  set_listen("default","Loud ranting emanates from inside this cell.");
  set_items(([({"spiders","rats","rodents"}):"They're too fast for you to get a good look at them.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "ooze":"The pudrid, %^BOLD%^%^GREEN%^green%^RESET%^ ooze is quite disgusting.",
    "floor":"The floor is wet and slippery.",
    "sign":"UNDER NO CIRCUMSTANCES SHALL ANYONE ENTER WITHOUT PERMISSION OF THE KING"]));
  set_exits((["west":ROOMS "dungeon2.c","north":ROOMS "dungeon5.c"]));
}
