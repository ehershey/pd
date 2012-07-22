//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The trees on either side have a break here allowing you to head back to the southwest or southeast, as well as north and south. Other than that the trees create effective walls with gaps of less than inch between them. As is common throughout the entire city, there is no roof, simply the leaves of the great trees and the open sky.");
     set_night_long("The trees on either side have a break here allowing you to head back to the southwest or southeast, as well as north and south. Other than that the trees create effective walls with gaps of less than inch between them. As is common throughout the entire city, there is no roof, simply the leaves of the great trees and the open sky filled with stars.");
     set_exits(([
                "north"         : ELFROOM"palacem5.c",
                "south"         : ELFROOM"palacem3.c",
		"southwest"	: ELFROOM"palacew2.c",
		"southeast"	: ELFROOM"palacee2.c",
                ]));
     set_items(([
        ]));
}
