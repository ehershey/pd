#include <std.h>
#include <arund.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
    ::create();
        set_name("arund mine");
        set_short("Arund Mine");
        set_long("The cave's ceiling opens here, revealing the sky above. "
                    "A constant breeze of fresh air rushes in from above. "
                    "Dangling from a rope that leads up is a large wooden bucket. "
                    "Resting up against the wall of the cave is a ladder that leads up through the opening. "
                    "The floor of the cave is rough and uneven, and chunks of broken stone are everywhere. "
                    );

        set_properties( ([
        "light"       : 2,
        "night light" : 0, 
        "indoors"      : 1,
        ]) );
        set_items(([
        "opening"   :   "A large hole in the ceiling of the cave with a ladder leading up through it.",
        "floor"     :   "The floor is littered with stones and small piles of dirt.",
        "dirt"      :   "Simple small piles of dirt.",
        "rope"      :   "Definitely a very sturdy rope, and tied to its end is a large wooden bucket.",
        "bucket"    :   "A simple square wooden bucket hanging over the hole from a rope. It is very dirty and worn.",
        "ladder"    :   "A hastily constructed ladder made from wood. It appears to lead down into the hole."
            ]));
        set_listen("default", "A strong breeze comes in from above.");
        set_smell("default", "A number of horrible odors have combined into one terrible one.");
                
        set_exits(([
                    //"west"         : "/d/shadow/rooms/thirtythree.c",
                    "ladder"       : ROOMS"arund001.c",
            ]));
}
 
void reset() {
   ::reset();
   /*
        if (!present("bilino", this_object()))
            new(MOB"bilino.c")->move(this_object());
            */
}
      
void init() {
        ::init();
                add_action("searching", "search");
}

int searching(string str)
{
        if(!str) return notify_fail("Search what?\n");        

        if(str == "bucket")
        {
                message("info", "Nothing of any use is found."
                        , this_player());
                        return 1;
        }

        if(str == "dirt")
        {
                message("info", "You sift through the piles of dirt and find nothing."
                        , this_player());
                        return 1;
        }
}
