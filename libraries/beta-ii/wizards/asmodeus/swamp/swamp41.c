#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A small burial site");
set_day_long("This appears to be a small burial site.  The ground is extremely muddy as it has recently been dug up by someone.  Small headstones lie scattered through the area as do broken bones.");
set_night_long("This appears to be a small burial site.  The ground is extremely muddy as it has recently been dug up by someone.  Small headstones lie scattered through the area as do broken bones.");
set_property("swamp",1);
set_smell("default", "The stench of death fills the area.");
set_items(([
"mud" : "The ground is extremely slipperly.",
"jungle" : "The Merkkirri jungle lies to the north but looks impassible from here.",
"headstoens": "The headstones once marked the names of the dead.",
"bones": "The bones appear to be that of gnolls.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([

"south": SWAMP "swamp40.c",

])); 
}
void reset() {
::reset(); 

if (!present("necromancer")) {
new(MOB "necromancer")->move(this_object());
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
