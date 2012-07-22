
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("bunny");
  set_id( ({ "giant bunny", "black bunny", "hinkypunk", "hinkypunk the bunny",
    "winged cuteness", "floppy-eared bunny", "giant black bunny" }) );
  set_short("Hinkypunk the bunny");
  set_long(
    "A giant black floppy-eared bunny with wings. He has a really "
    "adorable cotton tail. His eyes are bright green."
  );
  set_gender("male");
  set_race("bunny");
  set_body_type("quadrupe");
  add_limb("tail", "", 20, 0, 0);
  add_limb("left wing", "", 50, 0, 0);
  add_limb("right wing", "", 50, 0, 0);
  set_emotes(3, ({
    "Hinkypunk meows.",
    "Hinkypunk grunts cutely.",
    "Hinkypunk flaps his wings.",
    "Hinkypunk frollics in the grass.",
    "Hinkypunk poos.",
  }), 0);

}

