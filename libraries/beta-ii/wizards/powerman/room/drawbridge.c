#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The battlefields");
set_day_long("The chains holding down the drawbridge sways left and right in "
"the "
"light breeze. The opened drawbridge provides easy access to the castle. You see "
"some soldiers battling inside the castle. The moat is dry and littered with "
"corpses.");
set_night_long("The battle rages on even deep into the night. There are fires "
"from destruction everywhere. Sword sparks make the battlefield seem like the "
"dark clear sky. You can't help but feel that you are stepping on  "
"corpses on the ground. You are at the entrance to Macbeth's castle, "
"kept lit by large torches at both sides of the drawbridge. ");
set_items(([
"ground" : "Trampled and dirty.",
"castle"     : "Macbeth's castle, you sense evil inside.",
"drawbridge" : "A drawbridge.",
]));
set_smell("default","The Smell of blood and sweat is intense.");
set_listen("default","The battle roars on from within the castle.");
set_exits( ([ "north": "/wizards/powerman/room/fieldc5.c",
              "northwest" : "/wizards/powerman/room/fieldb5.c",
              "northeast" : "/wizards/powerman/room/fieldd5.c",
              //"drawbridge": "/wizards/powerman/room/drawbridge2.c",
]));
}

void reset()
{
 ::reset();
if(query_night() && !present("soldier"))
{
new("/wizards/powerman/arm/macsold")->move(this_object());
new("/wizards/powerman/arm/malsold")->move(this_object());
}
else
if(!present("soldier")) {
new("/wizards/powerman/arm/macsold")->move(this_object());
new("/wizards/powerman/arm/malsold")->move(this_object());
}
}
