#include <std.h>

inherit ARMOUR;

int last_damage;
object owner;
static void create()
{
 ::create();
 set_name("ring");
 set_short("Mirror Ring");
 set_long("This ring seems to made of gold, where a diamond or "
  "jewel would normaly be mounted is a very shiney mirror.");
 set_id( ({ "ring", "mirror ring", "mirrorring" }) );
 set_properties( ([ "no steal":1,
                    "magic item" : ({"..death..", "..protection..",
"..life.."
})
]) );
 set_limbs( ({ "right hand",}) );
 set_type("mirror ring");
 set_mass(2);
 set_value(10000);
}
int query_auto_load() {return 1;}
int query_heart(){ return query_heart_beat(); }
void init()
{
 ::init();
if (!environment(environment(this_object()))) return;
 last_damage = this_player()->query_hp();
if (environment(this_object())) write("%^BOLD%^%^WHITE%^The ring reflects the surroundings.");
set_heart_beat(1);
owner = environment(this_object()); 
}

void heart_beat()
{
 if ((last_damage-owner->query_hp()) > 500)
   {
    message("info", "The ring reflects the damage then explodes.", owner);
    owner->query_current_attacker()->add_hp(-300);
    this_object()->remove();
   } 
}
  

