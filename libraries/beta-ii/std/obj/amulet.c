// seeker 06/02/2000

#include <std.h>

inherit ARMOUR;

static void create()
{
 ::create();
 set_name("amulet");
 set_short("a crystal amulet");
 set_long("The crystaul amulet sparkles in the sunlight.");
 set_id( ({ "amulet", "crystal amulet", "a crystal amulet" }) );
 set_properties( ([ "no steal":1,
                    "magic item" : ({"..death..", "..protection..", "..life.." })
]) );
 set_limbs( ({ "head", "torso" }) );
 set_type("necklace");
 set_mass(2);
 set_value(10000);
}

void init()
{
 ::init();
 write("%^BOLD%^%^WHITE%^The amulet shines.");
}

void set_die()
{ 
 write("%^WHITE%^%^BOLD%^The crystal amulet shatters into many peices.");
 message("info", "%^YELLOW%^A blinding pillar of light shoots forth into the sky off in the distance.", users(), this_player());
 write("%^RED%^%^BOLD%^The grim reaper appears.");
 write("%^WHITE%^%^BOLD%^An archangel appears.");
new("/d/nopk/standard/obj/mon/reaper")->move(environment(this_player()));
 present("reaper", environment(this_player()))->set_kill(this_player());
new("/d/nopk/standard/obj/mon/angel")->move(environment(this_player()));
 this_player()->heal(100000);
 this_object()->remove();
}

int query_auto_load() { return 1; }
