#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "An overpowering scent of blood resonates throughout the manor.");
set_listen("default", "Household screams of torture and pain fill your ears.");
set_short("Vastana Manor");
set_long("%^BOLD%^%^RED%^The Vastana Manor's main room is filled with busy drows practicing their skills to make their house the best in Zolenia.  Mothers torture the seed out of their male partners to create more children, and the Matron mother rules over all.  Multiple paths lead to different rooms in the house.");
set_items(([
({"paths", "path"}) : "Multiple paths lead to different rooms in the house.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
"drows" : "The Vastana drows are practicing their skills.",
"mothers" : "Mothers can be seen torturing their children.",
"children" : "The children of this house do not look very happy.",
]));
}
void reset() {
    ::reset();
    if(!present("vastanamother")){
        new(MOB"vastanamother")->move(this_object());
}
    if(!present("vastanamale")){
        new(MOB"vastanamale")->move(this_object());
}
    if(!present("vastanachild")){
        new(MOB"vastanachild")->move(this_object());
        new(MOB"vastanachild")->move(this_object());
        new(MOB"vastanachild")->move(this_object());
}
set_exits(([ "southeast" : ROOMS "vastana2.c",
"out" : ROOMS "46.c",
"southwest" : ROOMS "vastana3.c"]));
}
