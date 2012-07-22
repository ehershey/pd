#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
int unicorn;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The swamp continues off to the east where the waters become
extremely deep.  A strong current pulls in that direction and out to the
ocean.");
set_night_long("The swamp continues off to the east where the waters become
extremely deep.  A strong current pulls in that direction and out to the
ocean.");
set_property("swamp",1);
set_listen("default", "The sounds of waves crashing can be heard to the east.");
set_smell("default", "The air smells of stale saltwater.");
set_items(([

"trees": "The trees dominate the landscape.",
"water" : "The water is waist high and cool. A heavy current pulls to the
east.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([

"west": SWAMP "swamp62.c",

])); 
}
void reset() {
::reset(); 
if (!find_living("unicorn") || !environment(find_living("unicorn")))
     {
       new(MOB "unicorn")->move(this_object());
    unicorn=1;
    }

ghast = random(100);
if ((ghast) > 96) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
