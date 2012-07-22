#include <std.h>
inherit OBJECT;

string query_type() { return "food"; }

void
create()
{
    ::create();
    set_value(1);
    set_weight(1);
    set_short("Turkey drumstick");
    set_long("A giant drumstick!");
    set_name("drumstick");
    set_id(({"drumstick", "turkey drumstick"}));
}

void
init()
{
    ::init();
    add_action("cmd_eat", "eat");
}

int
cmd_eat(string what)
{
   if (!id(what))
       return 0;

   if (environment(this_object()) != this_player())
       return notify_fail("Get the drumstick first.");

   if (!this_player()->add_stuffed(this_player()->query_level()))
       return notify_fail("You are too full to eat the drumstick!");

   this_player()->heal((this_player()->query_level())/5);

   write("WOW! what a meal!");
   say(this_player()->query_cap_name()+" eats a GIANT drumstick!");
   this_object()->remove();
   return 1;
}
