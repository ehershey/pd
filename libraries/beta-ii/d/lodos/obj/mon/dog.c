#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a little dog");
   set_id( ({ "little dog", "dog"}) );
   set_name("dog");
   set_level(12);
   set_long("A yellow colored dog.");
   set_body_type("quadrupe");
   set_race("dog");
   set_gender("male");
}
