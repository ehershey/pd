#include <std.h>
#include <venenum.h>
#include <daemons.h>
inherit ROOM;

int opened = 0;
int hours;
int minutes;
string timestring;

void create() {
    ::create();
    set_short("Hidden Study");
    set_long("This appears to be a comfortable room, spacious and carpeted in expensive Rostian carpet. A large oak desk sits to one side, with an equally large oaken chair resting beside it. Several books are laid open upon the desk, with notes scribbled in the margins. A large grandfather clock sits to one side, apparently still functional. A full-length mirror rests against the south wall, providing a mirror of almost the entire room.");
    set_smell("default", "The soft scent of expensive oils is here.");
    set_listen("default", "The only sound comes from the ticking clock.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"carpet", "carpets"}) : "These dwarven-styled carpets are popular with the older generation and suit this place well. They consist of flat colour, occasionally sprinkled with faint swirling patterns.",
	({"desk", "oak desk"}) : "This desk is large for a human, with many drawers and plenty of working space. The legs have been carved and styled to be curved like waves, adding a further edge of class to this already expensive-looking desk.",
	({"books", "book"}) : "These books appear to be written by adventurers past and present describing the life of the road, various monster descriptions and fighting techniques.",
	({"notes"}) : "The notes relate mostly to adapting the techniques described in the books to fighting undead or some other powerful monster.",
	({"clock", "grandfather clock"}) : time_fun(),
	({"mirror"}) : "The mirror stands at about two and a half meters, .",
      ]));
    set_exits(([
	//        "east" : ROOMS"secret3.c",
      ]));
    set_heart_beat(1);
}

int time_fun()
{
    return timestring;
}

void heart_beat() 
{
    string realmins;

    minutes = EVENTS_D->query_minutes(time());
    hours = EVENTS_D->query_hour(time());  

    if (minutes < 10)
    {
	realmins = "0"+ minutes;
    }
    else
    {
	realmins = minutes;
    }

    timestring = "This massive clock sits on the floor, reaching almost up to the ceiling. It consists of  a tall body, containing the swinging pendulums. The main part of the clock is, however, the round dial (or face) which tells the time. The clock requires winding every few days and is currently about half wound. The time on it's face is: "+hours+":"+realmins+".";

    set_items(([
	({"carpet", "carpets"}) : "These dwarven-styled carpets are popular with the older generation and suit this place well. They consist of flat colour, occasionally sprinkled with faint swirling patterns.",
	({"desk", "oak desk"}) : "This desk is large for a human, with many drawers and plenty of working space. The legs have been carved and styled to be curved like waves, adding a further edge of class to this already expensive-looking desk.",
	({"books", "book"}) : "These books appear to be written by adventurers past and present describing the life of the road, various monster descriptions and fighting techniques.",
	({"notes"}) : "The notes relate mostly to adapting the techniques described in the books to fighting undead or some other powerful monster.",
	({"clock", "grandfather clock"}) : time_fun(),
	({"mirror"}) : "The mirror stands at about two and a half meters, .",
      ]));

}


void init() 

{
    ::init();
    add_action("open", "open");
}

int open(string str)
{
    if (str != "clock") {return 0;}
    if (opened == 0)
    {
	write("You open the door of the clock.");
	opened++;
	return 1;
    }
    else
    {
	write("It's already open.");
	return 1;
    }
}
