#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 4, "night light" : 3, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 17, 0 }) ]));
  set_short("%^RED%^The plateau of the Red Dragon%^RESET%^");
  set_day_long("%^RED%^The plateau of the Red Dragon\n%^RESET%^A large plateau that extends over a cataclysmically deep chasm that runs north and south below. The plateau is a thick, sturdy structure consisting of baked red earth that is held up by a massive support structure to the southeast. The plateu is covered in scorch marks and deep superficial scars. The red dragons spar and practice their battle tactics on this, the highest point of the entire continent, before a breathtaking view; there are the peaks and valleys of the mountain below, a small mountain-top lake to the east, the ocean on all sides, and the sun which beats down upon the baked earth, seeming to imbue the earth with its power.");
  set_night_long("%^RED%^The plateau of the Red Dragon\n%^RESET%^A large plateau that extends over a cataclysmically deep chasm that runs north and south below. The plateau is a thick, sturdy structure consisting of baked red earth that is held up by a massive support structure to the southeast. The plateu is covered in scorch marks and deep superficial scars. The red dragons spar and practice their battle tactics on this, the highest point of the entire continent, before a breathtaking view; there are the peaks and valleys of the mountain below, a small mountain-top lake to the east, the ocean on all sides, and the cool yet strong moonlight, which illuminates the plateau and seems to gift it with the power of life and vitality.");
  set_exits( ([
    "southeast" : DRAG_ROOMS"dragnorth42.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  while(!present("dragon 4"))
    new(DRAG_MOBS"reddragon.c")->move(this_object());
}
