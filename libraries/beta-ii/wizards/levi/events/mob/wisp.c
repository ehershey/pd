#include <std.h>
#include <sp.h>
#include <daemons.h>
inherit MONSTER;
int test_heart;
void create()
{
 ::create();
 set_name("wisp");
 set_level(1);
 set_short("a violent wisp");
 set_long("This tiny little fairy-like creature zips this way and that.  It appears "
      "quite weak.  Why would the Summoner employ such a pathetic defense?");
 set_race("wisp");
 set_body_type("human");
 set("aggressive", 999);
 set_gender("neuter");
 set_id( ({ "wisp", "violent wisp"}) );
 set_heart_beat(1);
 set_patrol(35, ({ "west", "south", "south", "east", "east", "north", "north", "west", }) );
 set_hp(1000);
}
