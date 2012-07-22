#include <std.h>
#include <arund.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
    ::create();
        set_name("arund mine");
        set_short("Arund Mine");
        set_long("Deep within the forest a large hole seems to have been dug in the ground. "
                    "Virtually every plant and blade of grass has been trampled flat against the ground. "
                    "Several small piles of dirt have been pushed up against a few trees a few feet away from the hole. "
                    "Just beyond the tree line dozens of wooden planks have been stacked in a neat fashion. "
                    "Just to the North of the hole sits a wooden and metal contraption that extend up and over the hole. "
                    );

        set_properties( ([
        "light"       : 2,
        "night light" : 0, 
        "forest"        : 1,
        ]) );
        set_items(([
        "hole"      :   "It is not a natural formation, clearly it has been dug up by someone or something.",
        "ground"    :   "Hundreds of small footprints lead in all directions, leaving trails of dirt everywhere.",
        "dirt"      :   "Apparently the dirt has come from the hole and been piled up against a few trees.",
        "planks"    :   "They look perfectly cut, and have been stacked very neatly. These kind of planks would be perfect for building something.",
        "contraption":  "It looks to have been built hastily. There are crooked nails that have not been pounded in all the way and the wood used to make it looks old. A thick rope hangs from the end of the contraption and hangs down into the hole. Near the base a hand crank has been attached.",
        "rope"      :   "Definitely a very sturdy rope, and tied to its end is a large wooden bucket.",
        "bucket"    :   "A simple square wooden bucket hanging over the hole from a rope. It is very dirty and worn.",
        "crank"     :   "Some sort of metal crank attatched to a pully. Perhaps it could be turned to move the bucket.",
        "ladder"    :   "A hastily constructed ladder made from wood. It appears to lead down into the hole."
            ]));
        set_listen("default", "A soft wind rustles the leaves of the forest.");
        set_smell("default", "The pungent odor of rotting plants eminates from the hole.");
                
        set_exits(([
                    "west"         : "/d/shadow/rooms/thirtythree.c",
                    "ladder"       : ROOMS"arund002.c",
            ]));
        set_invis_exits( ({"ladder"}) );

}
 
void reset() {
   ::reset();
        if (!present("bilino", this_object()))
            new(MOB"bilino.c")->move(this_object());
}
      
void init() {
        ::init();
                add_action("searching", "search");
}

int searching(string str)
{
        if(!str) return notify_fail("Search what?\n");
        
        if(str == "planks")
        { 
                message("info",
                        "They are stacked too tightly to have anythign hidden within.", this_player());
                return 1;
        }
        if(str == "bucket")
        {
                message("info", "Nothing of any use is found."
                        , this_player());
                        return 1;
        }
        if(str == "hole")
        {
                message("info", "A small wooden ladder leaning up against the hole leads down into the darkness."
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
