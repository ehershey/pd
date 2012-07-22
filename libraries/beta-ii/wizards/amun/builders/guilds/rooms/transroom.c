#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("On the main deck of a boat");
    set_long("%^RESET%^%^ORANGE%^This boat is small but large enough for a few people to board. It has a long sail that captures more wind so it can go faster. On the top deck, there is a long bench for travelers to sit on and gaze across the waters.%^RESET%^");
    set_smell("default", "The strong smell of seawater encompasses the area.");
    set_listen("default", "Waves can be heard hitting the side of the boat.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"no magic" : 1,
	"indoors" : 1,
	"outdoors" : 0,
	"no kill" : 1,
	"no attack" : 1,
	"no bump" : 1,
	"no steal" : 1
      ]));
}

int start_fmv(string str)
{
    write("The sails begin to catch the wind as the sails are raised.");
    destination = str;
    switch (destination) {
    case "town":
	time = 9;
	call_out("town1", time);
	break;
    case "merkkirri":
	time = 9;
	call_out("merkkirri1", time);
	break;
    case "rhondale":
	time = 10;
	call_out("rhondale1", time);
	break;
    case "purgatory":
	time = 10;
	call_out("purgatory1", time);
	break;
    case "inferi":
	time = 17;
	call_out("inferi1", time);
	break;
    case "dunsinane":
	time = 9;
	call_out("dunsinane1", time);
	break;
    }


}
int town1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("town2", time);
}

int town2()
{
    write("%^BOLD%^%^CYAN%^Dolphins swim along side of the boat as it moves towards the Guild Town.%^RESET%^");
    call_out("town3", time);
}

int town3()
{
    write("%^BOLD%^%^CYAN%^The dolphins jump into the depths of the ocean as the Town comes into view.%^RESET%^");
    call_out("town4", time);
}

int town4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"docks.c");
    return 1;
}

int merkkirri1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("merkkirri2", time);
}

int merkkirri2()
{
    write("%^BOLD%^%^CYAN%^The sky above begins to blacken as if a rain is about to come. The Captain of the boat makes a sharp turn to the south causing things to fall out of place.%^RESET%^");
    call_out("merkkirri3", time);
}

int merkkirri3()
{
    write("%^BOLD%^%^CYAN%^Rain begins to beat down hard on the main deck as Merkkirri Island comes into view.%^RESET%^");
    call_out("merkkirri4", time);
}

int merkkirri4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"merk_holding.c");
    return 1;
}

int rhondale1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("rhondale2", time);
}

int rhondale2()
{
    write("%^BOLD%^%^CYAN%^A large figure can be seen moving just below the boat. The Captain lifts the sails higher in hopes of passing whatever is causing this darkened shadow beneath the surface.%^RESET%^");
    call_out("rhondale3", time);
}

int rhondale3()
{
    write("%^BOLD%^%^CYAN%^The boat begins to slow down as the city of Rhondale comes into view.%^RESET%^");
    call_out("rhondale4", time);
}

int rhondale4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"rhon_holding.c");
    return 1;
}

int purgatory1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("purgatory2", time);
}

int purgatory2()
{
    write("%^BOLD%^%^CYAN%^Dark misty fog covers the area, leaving it almost impossible to see anything infront or around the boat.%^RESET%^");
    call_out("purgatory3", time);
}

int purgatory3()
{
    write("%^BOLD%^%^CYAN%^A gust of wind shifts the fog around to where the blackened city of Purgatory can barely be seen.%^RESET%^");
    call_out("purgatory4", time);
}

int purgatory4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"purg_holding.c");
    return 1;
}

int inferi1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("inferi2", time);
}

int inferi2()
{
    write("%^BOLD%^%^CYAN%^Peering off the side of the boat, dead bodies can be seen floating just beneath the surface of the water.%^RESET%^");
    call_out("inferi3", time);
}

int inferi3()
{
    write("%^BOLD%^%^CYAN%^The Captain raises the sails attempting to go faster as hands can been seen climbing up the sides of the boat. Luckily, Inferi Island is just up ahead.%^RESET%^");
    call_out("inferi4", time);
}

int inferi4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"inferi_holding.c");
    return 1;
}
int dunsinane1()
{
    write("%^BOLD%^%^CYAN%^The waves slap against the side of the boat, causing it to rock back and forth.%^RESET%^");
    call_out("dunsinane2", time);
}

int dunsinane2()
{
    write("%^BOLD%^%^CYAN%^Battleships can be seen encompassing the area, as if being sent out on missions. In fear of being spotted, the Captain raises the sails in attempts to move faster.%^RESET%^");
    call_out("dunsinane3", time);
}

int dunsinane3()
{
    write("%^BOLD%^%^CYAN%^Just as the boat is spotted by the battleships, the island of Dunsinane comes into view.%^RESET%^");
    call_out("dunsinane4", time);
}

int dunsinane4()
{
    write("%^BOLD%^%^CYAN%^The boat pulls into the dock station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"bf_holding.c");
    return 1;
}
