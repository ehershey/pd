#include <std.h>
#include <roston.h>
inherit ROOM;

int stoneform = 0;
object vexgall;

void create() {
    ::create();
    set_short("Vexgall's Cloister");
    set_long("This short tunnel into the earth leads to the large statue of a half-dragon man, leaning empassively against the wall. Near the entrance of the tunnel is a small cluster of runes, carved in a circle. Many magical runes, written in the Dark Elven style, adorn this whole tunnel- as though it is designed to keep something contained... or intruders out.");
    set_smell("default", "There is only the scent of earth here.");
    set_listen("default", "There are no sounds here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"runes"}) : "These runes are clearly magical. Many appear to be activated. A large cluster of runes lies near the entrance.",
	({"cluster"}) : "This clusters of runes appears to be the trigger for some sort of event. There are many fingerprints all over their surface as though many people have been touching them.",
      ]));
    set_exits(([
	"east" : DROWROOM"room90.c",
      ]));
    vexgall=new(DROWOBJ"stone_statue");
    vexgall->move(this_object());
}

void init() 

{
    ::init();
    add_action("touch", "touch");
}

int touch(string str)
{
    if (str != "runes") {return 0;}
    if (stoneform == 0 && present("stone statue"))
    {
	write("You touch the runes carefully. The statue at the end of the tunnel melts into life.");
	message("room message", this_player()->query_cap_name()+" touches the runes carefully. The statue at the end of the tunnel melts into life.",this_object(),this_player());
	vexgall->remove();
	vexgall=new(DROWMOB"vexgall")->move(this_object());
	stoneform++;
	set_long("This short tunnel into the earth leads to a huge half-dragon male, clutching a massive axe. Near the entrance of the tunnel is a small cluster of runes, carved in a circle. Many magical runes, written in the Dark Elven style, adorn this whole tunnel- as though it is designed to keep something contained... or intruders out.");
	return 1;
    }
    if (stoneform == 1 && present("vexgall the caged"))
    {
	write("You touch the runes carefully. Vexgall the Caged becomes a statue again.");
	message("room message", this_player()->query_cap_name()+" touches the runes carefully. Vexgall the Caged becomes a statue again.",this_object(),this_player());
	vexgall->move("/d/nopk/standard/void.c");
	vexgall->remove_living();
	new(DROWOBJ"stone_statue")->move(this_object());
	set_long("This short tunnel into the earth leads to the large statue of a half-dragon man, leaning empassively against the wall. Near the entrance of the tunnel is a small cluster of runes, carved in a circle. Many magical runes, written in the Dark Elven style, adorn this whole tunnel- as though it is designed to keep something contained... or intruders out.");
	stoneform--;
	return 1;
    }
    else
    {
	write("Vexgall has found his peace at last, the runes do nothing now.");
	return 1;
    }
}

