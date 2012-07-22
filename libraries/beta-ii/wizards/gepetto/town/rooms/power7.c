//Gepetto


#include <std.h>
#include <gepetto.h>

inherit ROOM;

void create() {
::create();
set_property ("plain", 1);
set_property ("outdoors" ,1);
set_property ("light", 2);
set_property ("night light", 1);

set_short("Power Lane");
set_long("The street here is straddled by two buildings. Nothing special, "
         "the buildings look to be dwellings of some sort. With the "
         "ethnicity so varied in this city, one really has no clue "
         "to whom the occupants may be. The city square can can be clearly"
         "seen, not far to the north and the gates of the city can just "
         "be made out far to the south.");
set_items(([
       "buildings" : "Buildings straddle the street here. You think that they are probably dwellings though fielding a guess as to whom the occupants are is incomprehensible." ,
       "gates" : "The gates of the city loom further to the south." ,
       "square" : "Action gives away the city square a bit north of here." ,
       "residents" : "Residents of all creeds and class mingle while going about their buisness." ,                                 
       "streets" : " The streets are clean and free of debris." ,
         ]));
set_exits( ([
             "north" : ROOMS "power8.c",
             "south" : ROOMS "power6.c",
             "east" : ROOMS "power_b4.c",
             "west" : ROOMS "power_b3.c",
        ]) );

set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");

}
