// OBJECT
#include <std.h>
#include <waterworld.h>

inherit OBJECT;

int counter;
int controller=30;


void create()
{
    ::create();

    set_name("rose clam");
    set_id(({"rose clam","clam"}));
    set_long("This clam seems to have a rose growing right out of its shell.");
    set_weight(1);
    set_curr_value("copper",1);
    set_prevent_get("The clam wouldn't want to be disturbed.");
}
void init() {
    ::init();

    add_action("search", "dig");
}
void reset() {
    ::reset();
    counter=0;
}

int search(string str)
{
    if(!str) return 0;
    if(str != "sand") return 0;
    if(this_player()->query_disable()) return notify_fail("You are too busy to do that right now.\n");
    if (counter >=controller) return notify_fail("Clam Union local 3045 has issued a stop-work order do to your over-working the clams....\nThe Order will remain in affect until the next respawn.");

    PEARLS"PEARL_GAME.c"->execute_pearl_game(9995,this_player());
    this_player()->set_disable();
    counter +=1;
    return 1;
}
