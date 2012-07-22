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
set_long("Activity is seeming, as with any city, to pick up nearer to the "
         "town square. Not so many children play here as the bustle is "
         "too frantic here to be safe for them. Residents can be heard "
         "chatting in their native tongues oblivious to the differences. "
         "The city gates are the only feature that can be seen past the "
         "intersection just to the south. Two buildings lay off the street"
         "just north of here. ");
set_items(([
       "activity" : "The bustling activity here is much too busy and unsafe for children to play often." ,
       "residents" : "Residents walk at brisk paces as they carry out their tasks." ,
       "square" : "The town square lies not >too< far north of here." ,
       "buildings" : "Two buildings lie of the street just north of here." ,
       "intersection" : "The intersection just south is also frantic with activity." ,
       "streets" : " The streets are clean and free of debris." ,
        ]));
set_exits( ([
             "north" : ROOMS "power7.c",
             "south" : ROOMS "power5_chem9.c",
         ]) );
set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");


}
