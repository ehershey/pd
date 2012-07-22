#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "This is called a sleeping room.  The Raknid's workers take "
      "turns sleeping to regain loss strength.  There is fresh straw "
      "laid out on the ground and fresh water in a bowl for washing up."
         
    );
    set_items(([
        "sleeping room" : "It is very quiet in here.",
        "room" : "It is very quiet in here.",
        "ground" : "The ground feels very soft.",
        "water" : "To bathe in before or after sleeping.",
        "bowl" : "Not very fancy, made out of wood.",
        "wood" : "It looks to be from the marsh lands.",
        "grass" : "It was taken fromt he mirage above the ground.",  
    ]));
    set_exits( ([
"southwest" : NEST "est16",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"rshovel")->move(this_object());
     if (!present("raknid")) 
    new(MOB"rpick")->move(this_object());
    }
}
