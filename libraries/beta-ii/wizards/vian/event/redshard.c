#include <std.h>
inherit OBJECT;

void create()
{
 ::create();
 set_name("shard");
 set_short("a %^BOLD%^%^RED%^red %^RESET%^shard");
 set_long("A broken shard of some sort of magical cage, this shard is red.");
 set_id( ({ "shard", "red shard", "redshard" }) );
 set_mass(1);
 set_value(1);
}
