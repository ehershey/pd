#include <std.h>
#include <lost_caves.h>
inherit OBJECT;

void create() {
  ::create();

    set_name("shell piece");
    set_id( ({ "shell piece", "shell" }) );
    set_short("Shell piece");
    set_long("A small piece of shell from a large sea turtle. It is very hard and would make for a suitable shield if in the right hands.");
    set_weight(55+random(5));
    set_curr_value("gold", 1);
    set("shell_item",1);
    set_property("no steal", 1);
}


void init()
{
    ::init();

    add_action("give_shell", "give");
}

int give_shell(string str)
{
    object ob;
    if( str == "shell to garon" )
    {
        if( ob = present("garon", environment(this_player())) )
        {
            write("You give the shell to Garon.");
            say(this_player()->query_cap_name()+" gives a shell to Garon.",
                this_player());
            ob->force_me("say WOW! Such a tough shell, I'll bet I could make a mighty shield with this. Thank you!");
            write("Garon gives you some gold.");
            this_player()->add_money("gold",15000);
            call_out("shield_in_shop", 0);
            return 1;
        }
    }
    return 0;
}

void shield_in_shop()
{
    new(ARM"tortoise_shield.c")->move("/d/nopk/tirun/astorage.c");
    this_object()->remove();
}




