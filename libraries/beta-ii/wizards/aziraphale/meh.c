//Aziraphale

#include <std.h>
inherit ROOM;

void create() 
{
    room::create();
    set_properties(([ "light" : 2, "indoors" : 1]));
    set_short("Hunt Bag Room");
    set_long("This is where bags are given out for the Scavenger Hunt.  To start the hunt, type %^CYAN%^<request bag>%^RESET%^.  Hunters can only play once, with their bag.");
    set_exits(([ 
	"out" :  "/wizards/aziraphale/workroom.c",
      ]));
}

void init()
{
    ::init();
    add_action("request", "request");
}

int request(string str)
{
    object ob, tp;

    if (!str || str !="bag")
    {
	write("You may only");
	return 1;
    }

    if (present("scavenger bag", this_player())) 
    {
	write("You may only have one bag for the Hunt.");
	return 1;
    }

    tp = this_player();
    ob = new(BAG);
    ob->set_id(({"bag", "scavenger bag"}));
    ob->set_name("Scavenger Bag");
    ob->set_short(""+tp->query_cap_name()+"'s Scavenger Bag");
    ob->set_mass(1);
    ob->set_long("Your own bag for the scavenger hunt. Return this to Daos when you are finished playing.");
    ob->set_value(0);
    ob->set_max_internal_encumbrance(1);
    ob->set_property("no steal", 1);
    ob->move(tp);
    write("You now have your own bag for the Scavenger Hunt.");
    message("info", ""+tp->query_cap_name()+" requests a bag for the Scavenger Hunt.", environment(tp), tp);
    return 1;
}
