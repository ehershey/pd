#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a servant");
   set_id( ({ "servant" }) );
   set_name("servant");
   set_level(17);
   set_long("The servant walks about cleaning up things in general.");
   set_body_type("human");
   set_race("gnome");
   set_gender("male");
}
