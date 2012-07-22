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
set_long("Noise filters in from the intersection to the north. Every now "
         "and again a clearly audible word can be heard. Two buildings can "
         "be seen to the south. Past the buildings south, the city gates "
         "can be seen. Life in Rawlthford is very busy and frantically "
         "paced. A sudden rush of activity obscures the view of the city "
         "square.");
set_items(([ 
         "intersection" : "You spy a busy intersection just north of here." ,
         "streets" : " The streets are clean and free of debris." ,
         "buildings" : "Two buildings can be seen just south of here." ,
         "activity" : "A sudden, ordinary, spurt of activity obscures vision too far north." ,
         "gates" : "The large city gates, to the south, remain clearly visible." ,
         ]));
set_exits( ([
             "north" : ROOMS "power5_chem9.c",
             "south" : ROOMS "power3.c",
         ]) );
 
set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");

}
