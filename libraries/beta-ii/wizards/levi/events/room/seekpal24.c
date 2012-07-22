#include <std.h>
#include <sp.h>
inherit ROOM;

void create() 
{
::create();
    set_short("The Priest School");
    set_long("A few mahogany desks face the north where a table and several old books can be seen.  "
	"The walls have many writings on them making this place look like a place of learning.  The "
	"floor is worn from much use. " );
    
    set_items(([
          "floor" : "The floor is black and shiny.  It is very worn.",
	  "walls" : "They are plain walls with writings scratched into them",
	  "light" : "Lanterns offer a comforting blue light.",
	  "writings" : "There are several in a language known only to The Avatar's followers.",
	  	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "seekpal23.c",
		
        
       ]));
       
}

void reset() {
  ::reset();
    if(!present("highpriest")) 
      new(MOB "highpriest")->move(this_object());

    if(!present("spriestess")) 
      new(MOB "spriestess")->move(this_object());

    if(!present("spriestess")) 
      new(MOB "spriestess")->move(this_object());

    if(!present("spriestess")) 
      new(MOB "spriestess")->move(this_object());

    if(!present("spriestess")) 
      new(MOB "spriestess")->move(this_object());
    
    if(!present("spriestess")) 
      new(MOB "spriestess")->move(this_object());
}




