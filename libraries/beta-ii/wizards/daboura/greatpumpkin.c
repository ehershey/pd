#include <std.h>

inherit MONSTER;
int cmd_tricktreat();

void create() {
 ::create();
   set_short("The Great Pumpkin");
   set_id( ({ "the great pumpkin", "great pumpkin", "pumpkin" }) );
   set_name("pumpkin");
   set_level(50);
   set_long("The great pumpkin who appears during halloween to give candy to
people!");
   set_body_type("human");
   set_race("pumpkin");
   set_gender("male");
}

void init()
{
    ::init();
    add_action("cmd_tricktreat", "trick");
    
}

int cmd_tricktreat(string str)
{
    if (!str || str=="") 
    {
        notify_fail("trick what?\n");
        return 0;
    }

    if (str != "or treat")
    {
        notify_fail("trick what?\n");
        return 0;
    }
    write("You scream TRICK OR TREAT! at the great pumpkin.");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " yells TRICK OR TREAT!\n", ({this_player()}));

    new("/wizards/daboura/candy.c")->move(this_object());
    command("give candy to " + this_player()->query_name());
    return 1;
;
    
    
}
