#include <std.h>
#include <lodos.h>
inherit MOUNT;
static int oi;

void create() {
 ::create();
   set_short("a happy deer");
   set_id(({ "deer", "happy deer" }));
   set_name("deer");
   set_level(18);
   set_long("A happy little forest animal whom has wandered from its home. "
     "A puffy white striped tail adorns it's brown coat.");
   set_body_type("quadrupe");
   set_race("deer");
   set_gender("female");
}
