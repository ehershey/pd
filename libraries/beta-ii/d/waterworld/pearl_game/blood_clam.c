// OBJECT
#include <std.h>
#include <waterworld.h>

inherit OBJECT;

int counter;
int controller=20;

void create()
{
    ::create();

    set_name("Blood clam");
    set_id(({"blood clam","clam"}));
    set_long("You see this clam throbbing to the rhythm of a magical heartbeat.\nYou also notice that it is bleeding from a large gash on its side.");
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

int search(string str) {
    if(!str) return 0;
    if(str != "sand") return 0;
    if(this_player()->query_disable()) return notify_fail("You are too busy to do that right now.\n");

    if (counter >= controller) return notify_fail("The clam digs itself deeper into the sand so as not to be bothered.\n");
    PEARLS"PEARL_GAME.c"->execute_pearl_game(10000,this_player());
    this_player()->set_disable();
    counter +=1;
    return 1;
}