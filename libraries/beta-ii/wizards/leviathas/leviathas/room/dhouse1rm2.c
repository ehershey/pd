#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^%^BOLD%^%^RED%^This room is fairly small.  The floor and walls are all made of plush, red, velvet sheets that "
           "make the room look like one big bed. %^RESET%^%^RED%^Dark red%^BOLD%^, corduroy pillows are in various places, edged with "
           "%^RESET%^%^BOLD%^silver%^RED%^, a popular material among vampires.  In the center of the room, there is a slightly elevated "
           "circle wrapped tightly in red leather.  Many red, silk sheets have been carefully laid over it.  Stairs on the west wall lead "
           "steeply up and out of the basement.");
   
    set_night_long("%^%^BOLD%^%^RED%^This room is fairly small.  The floor and walls are all made of plush, red, velvet sheets that "
           "make the room look like one big bed. %^RESET%^%^RED%^Dark red%^BOLD%^, corduroy pillows are in various places, edged with "
           "%^RESET%^%^BOLD%^silver%^RED%^, a popular material among vampires.  In the center of the room, there is a slightly elevated "
           "circle wrapped tightly in red leather. Many red, silk sheets have been carefully laid over it.  Stairs on the west wall lead "
           "steeply up and out of the basement.");
    
    set_items(([
        "sheets" : "The velvet or silk?",
        "pillows" : "Corduroy, the lined velvet material .",
        "velvet sheets" : "They make up the floor and walls, which are pretty much indiscernable, as if the room were a bowl.",
        "silk sheets" : "They have been placed ontop of the elevated circle in the center of the room.",
        "circle" : "Red leather has been stretched over this circle of a slightly elevated area in the bed.  It is covered with silk sheets.",
        "stairs" : "They lead steeply upward, blocking any view of the top floor.",
                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "upstairs" : ROOMS "dhouse1rm1.c",
        
                
    ]));

}

void reset() {
  ::reset();
    if(!present("bloodslave")) 
      new(MOB "bloodslave")->move(this_object());
}

