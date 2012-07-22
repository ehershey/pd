#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 4, "night light" : 3, "no teleport" : 1, "mountain" : 1  ]));
  set_short("%^RED%^The plateau of the Red Dragon%^RESET%^");
  set_day_long("%^RED%^The plateau of the Red Dragon\n%^RESET%^A large plateau that extends over a cataclysmically deep chasm that runs north and south below. The plateau is a thick, sturdy structure consisting of baked red earth that is held up by a massive support structure to the southeast. The plateu is covered in scorch marks and deep superficial scars. The red dragons spar and practice their battle tactics on this, the highest point of the entire continent, before a breathtaking view; there are the peaks and valleys of the mountain below, a small mountain-top lake to the east, the ocean on all sides, and the sun which beats down upon the baked earth, seeming to imbue the earth with its power.");
  set_night_long("%^RED%^The plateau of the Red Dragon\n%^RESET%^A large plateau that extends over a cataclysmically deep chasm that runs north and south below. The plateau is a thick, sturdy structure consisting of baked red earth that is held up by a massive support structure to the southeast. The plateu is covered in scorch marks and deep superficial scars. The red dragons spar and practice their battle tactics on this, the highest point of the entire continent, before a breathtaking view; there are the peaks and valleys of the mountain below, a small mountain-top lake to the east, the ocean on all sides, and the cool yet strong moonlight, which illuminates the plateau and seems to gift it with the power of life and vitality.");
  set_exits( ([
    "southeast" : DRAG_ROOMS"dragnorth42.c",
             ]) );
  set_items( ([
    "plateau" : "It appears to be the highest point of the mountain.",
    ({"chasm", "crevace", "canyon"}) : "The canyon below drops off for what seems to be an eternity. It seems strangely fitting that the plateau, the highest point in the mountain, should stand over the deepest crevace in the mountain.",
    ({ "structure", "support structure", "support" }) : "The support structure consists of a sort of inverted archway. The structure is connected to the side of the mountain in two locations to the southeast. It holds the plaeau up over the chasm by latching onto the large baked-earth slab from below, by its center of mass. A small ridge on the southeastern ledge of the plateau leads down off the plateau onto the support structure.",
    "ridge" : "A small ridge, relative to the massive size of the plateau, that leads off the plateau onto its support structure.",
    ({ "scorch", "scorches", "mark", "marks", "scars", "scorch marks", "superficial scars" }) : "Remnants from fierce battles and spars past. One seems to form a large shape on the ground.",
    "shape" : "The scorch marks are in the rough shape of a dragon, its tail pulled sideways and ready to strike.",
    ({"peaks", "valleys"}) : "They stand out clearly over the top of the mountain.",
    "ocean" : "Past the land and mountain below, you can see the ocean glistening softly over the horizon.",
             ]) );
}

void reset() {
  object ob;
  ::reset();
  while(!present("dragon 4"))
    new(DRAG_MOBS"reddragon.c")->move(this_object());

  if(0 && !present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}
