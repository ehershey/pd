#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : -1, "no teleport" : 1, "mountain" : 1, "indoors" : 1 ]));
  set_short("%^BLACK%^%^BOLD%^Realm of the Black Dragon%^RESET%^");
  set_long("%^BLACK%^%^BOLD%^Realm of the Black Dragon%^RESET%^\n"
    +"Deep in a dark crevace, no natural light pervades this place. The area is illuminated by a soft, dark light, which seems to emanate from a strange large rock embedded in the middle of the ground. Jagged overhangs above stretch over and block out the sky. There is a dark path that leads up the side of the mountain to the east back onto the mountain top. The moist, dark rock walls of the mountain peaks and ridges close in from all directions, breeding a foreboding and uninviting, yet strangely nurturing feeling.");
  set_exits( ([
    "east" : DRAG_ROOMS"dragnorth38.c",
             ]) );
  set_items( ([
    "crevace" : "You are at the bottom of it.",
    "light" : "A soft, dark light, provided by a large rock embedded at the bottom of the crevace.",
    ({ "rock", "large rock" }) : "The rock luminesces a soft, dark light, bathing you in darkness. There is a shadow floating just above the rock's surface.",
    "shadow" : "It is in the shape of a dragon with its head raised back.",
    ({ "darkness", "dark light", "feeling" }) : "The enveloping darkness feels almost comfortable, as if it were a wary mother seeking to cover you from the world within its deep cloak.",
    ({ "walls", "rock walls", "wall" }) : "Rocky mountain walls surround the area on all sides. They appear to be slightly moistened. A dark path cuts steeply into the mountain side to the west, allowing passage out of the crevace.",
    ({ "mountain", "mountain top" }) : "The jagged overhangs above block out your view of it.",
    ({ "overhang", "overhangs", "jagged overhangs", "jags" }) : "Large pieces of rock and other mountain-side material which extend outward from the canyon walls high above, blocking out the sky.",
             ]) );
}

void reset() {
  object ob;
  ::reset();
  while(!present("dragon 4"))
    new(DRAG_MOBS"blackdragon.c")->move(this_object());
  load_object(DRAG_MOBS+"dragonmage")->move(this_object());

  /*
  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
  */
}
