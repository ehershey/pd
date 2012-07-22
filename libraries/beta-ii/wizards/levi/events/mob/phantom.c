#include <std.h>
#include <sp.h>
#include <daemons.h>
inherit MONSTER;
int test_heart;
void create()
{
 ::create();
 set_name("spirit");
 set_level(20);
 set_short("Phantom Slave");
 set_long("The Phantom Slave has been brought to this world by the combined talents of "
        "The Summoner and his partner, Geshama.  Once a ghost, it has been given a "
        "corporeal form.  It is quite tall and pale and has eerily idealized features. ");
 set_race("ghost");
 set_body_type("human");
 set("aggressive", 999);
 set_class("mage");
 set_subclass("wizard");
 set_gender("neuter");
 set_spell_chance(100);
 set_spells( ({"missile", "annihilate"}) );
 set_skill("magic attack", 100);
 set_id( ({ "ghost", "phantom", "slave", "phantom slave" }) );
 set_heart_beat(1);
 set_patrol(9, ({ "west", "south", "south", "east", "east", "north", "north",
"west", }) );
 set_emotes(3,({
   "The Phantom opens its gaping mouth to scream but only a moan is barely audible.",
}),0);
 set_hp(30000);
}
