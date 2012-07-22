#include <std.h>
inherit ROOM;

string *allowed = ({"azire","venenum","noa", "ouka", "ouka"});

void create() {
    ::create();
    set_short("Venenum's Private Space");
    set_long("This small, quiet den appears to be the private space of Venenum, one of Quex'trilixil's sons. This private place is his and his alone (and for his good friends!), a quiet place for relaxation, reflection and sleep. It consists of a small, natural cavern, with a water-smoothed stone floor; something which is *very* comfortable for dragons but almost intolerable for anyone else. His den is covered in scratch marks from him sharpening his claws, and there is plenty of space here for two dragons to easily sprawl out comfortably. A string of flowering vines grow up part of one side of the den.");
    set_smell("default", "A soft, pleasant scent can be caught from the flowers.");
    set_listen("default", "The faint drip drip of water may be heard, but aside from that all is quiet.");
    set_properties(([
	"light" : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no_teleport" : 1,
	"no gate" : 1,
	"no_gate" : 1,
	"no magic" : 1,
	"no_magic" : 1,
	"no attack" : 1,
	"no_attack" : 1,
      ]));
    set_exits(([
	"out" : "/wizards/venenum/workroom.c",
      ]));
    set_heart_beat(1);
}

int receive_objects()
{


    object ob = previous_object();
    if(ob && userp(ob))
	if (member_array(ob->query_name(), allowed) == -1)
	{
	    write("This is Venenum's private space. You are bounced.");
	    return 0;
	}
	else
	{
	    if (ob->query_name() == "venenum")
	    {
		write("Welcome home, Venenum.");
	    }
	    else if (ob->query_name() == "azire")
	    {
		write("*snuggle* Of course you're welcome Azire... welcome to Ven's private area! ^_-");
	    }
	    else
	    {
		write("You are welcome in Venenum's private area.");
	    }
	    return 1;
	}
}

void heart_beat()
{
    object *inv = all_inventory(this_object());
    int x;

    for(x=0; x<sizeof(inv); x++)
    {
	if (inv[x]->is_living())
	{
	    if (member_array(inv[x]->query_name(), allowed) == -1) 
	    {
		write("You arn't ment to be here! You're bounced back to the teleport room.");
		inv[x]->move("/wizards/venenum/workroom");
	    }
	}
    }
}
