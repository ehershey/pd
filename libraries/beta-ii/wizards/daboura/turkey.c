#include <std.h>

inherit MONSTER;
int cmd_tackle();

void create() {
 ::create();
   set_short("A GIANT Turkey");
   set_id( ({ "a giant turkey", "giant turkey", "turkey" }) );
   set_name("turkey");
   set_level(1);
   set_long("A large turkey, wow.... it looks good! Perhaps if you tackle him, you can get his drumstick!");
   set_body_type("fowl");
   set_race("turkey");
   set_gender("male");
}

void init()
{
    ::init();
    add_action("cmd_tackle", "tackle");
    
}

int cmd_tackle(string str)
{
    if (!str || str=="") 
    {
        notify_fail("tackle what?\n");
        return 0;
    }

    if (str != "giant turkey")
    {
        notify_fail("tackle what?\n");
        return 0;
    }
    if(this_player()->query_disable()) return 1;
    write("You TACKLE the giant turkey!");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " TACKLES the giant turkey!\n", ({this_player()}));

    new("/wizards/daboura/drumstick.c")->move(this_object());
    command("give drumstick to " + this_player()->query_name());
    this_player()->set_disable();
    return 1;

    
    
}
