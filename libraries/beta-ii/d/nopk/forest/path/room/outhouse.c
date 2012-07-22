#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("An old outhouse");
    set_long(
      "This is an outhouse. There is a bench with a toilet seat on "
      "it and a pile paper which rests on the bench. A "
      "plate consisting of food is sitting on the bench as well. The wo"
      "od used to make this outhouse is obviously old and rotting."
    );
    set_items(([
   "plate" : "A plate houses fried onions, beans, and liver. Yup, that'd "
             "just about do it.",
   "bench" : "On the bench sits a toilet, toilet paper, and a plate of food.",
   "toilet paper" : "A roll of toilet paper sits on the bench.",
   "toilet" : "You are afraid to get too close to look.",
   "wood" : "The wood is rotting, quite possibly from the obscene gasses this "
	      "room has seen.",
    ]));
    set_exits( ([ 
        "out"  : "/d/nopk/forest/path/room/backyard"
    ]) );
}

void reset() {
    if(!present("man"))
        new("/d/nopk/forest/path/mob/potman.c")->move(this_object());

}
