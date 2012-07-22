#include <std.h>
#include <venenum.h>
inherit ROOM;

int locked=1;
int open=0;

void create() {
    ::create();
    set_short("Graveyard");
    set_day_long("It would appear that someone has gone to a large amount of trouble to errect a very large, cylindrical marble tomb here. It stands over four metres tall and two and a half wide, with a small door so that mourners can enter and lay flowers.");
    set_night_long("It would appear that someone has gone to a large amount of trouble to errect a very large, cylindrical marble tomb here. It stands over four metres tall and two and a half wide, with a small door so that mourners can enter and lay flowers. There is something odd about this tomb when it's seen at night.");
    set_smell("default", "The strong smell of roses wafts from the tomb.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"tomb"}) : "This huge cylinder looks like it cost millions of gold pieces to create. Created from sanded marble blocks, it is covered from head to foot in elegant carvings of a woman in flowing robes, smiling and holding a new born child. In some of the images she is depicted as having the wings of an angel.",
	({"door"}) : "This door has a large lock.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : ROOMS"grave2.c",
	"tomb" : ROOMS"tomb1.c",
      ]));

    add_invis_exit("tomb"); 

    set_pre_exit_functions( ({"tomb"}), ({"check_tomb"}) );


}

int check_tomb()

{
    if (open == 0) { return notify_fail("The tomb is closed."); }
    if (locked == 1) { return notify_fail("The tomb is locked."); }
    return 1;

}

void init() 

{
    ::init();
    add_action("open", "open");
    add_action("lockpick", "lockpick");
}

int open(str)

{
    if(!str) { return notify_fail("Open what?"); }
    if(str == "tomb") {
	if (locked == 1) { return notify_fail("The tomb is locked.");}
	else { 
	    message(0, "The door of the tomb slides open silently.", this_object()); 
	    open = 1;
	    remove_invis_exit("tomb"); }
    }
}

int unlock()

{
    if (locked == 1) 
    { 
	message("info", "The tomb's lock opens with a click.", this_object());
	locked = 0;
	remove_invis_exit("tomb"); 
	call_out("lock", 10);
	return 1;
    }
}

int lockpick()

{
    if (this_player()->query_race() == "dragon" || this_player()->query_race() == "weimic") return notify_fail("A flash of light zaps your claws as you get close to the lock.");
    else if (this_player()->query_race() == "bastet") return notify_fail("A flash of light zaps your paws as you get close to the lock.");
    else return notify_fail("A flash of light zap's your hands as you get close to the lock.");
}


void reset()
{
    locked = 1;
    open = 0;
}

int lock()

{
    if (locked == 0)
    { 
	message("info", "The tomb's lock closes with a click.", this_object());
	locked = 1;
	add_invis_exit("tomb"); 
	return 1;
    }
}
