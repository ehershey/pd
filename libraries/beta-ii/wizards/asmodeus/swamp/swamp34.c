#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;

void init() {
::init();
add_action("questo", "say");
add_action("questorama", "invoke");
}

void create() {
::create();
set_short("The dwelling of Yyz");
set_long("%^BLUE%^This dwelling is quite small and is overgrown by thick thorn-covered vines.  The air is exceptionally cold here and the whole area smells and feels of death.  Thousands of tiny bugs crawl along the dwelling walls.");
set_property("swamp",1);
set_items(([
"vines" : "The vines are quite strong and covered in nasty thorns.",
"bugs" : "Spiders, termites, ants, gnats and the like.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"out": SWAMP "swamp33.c",


])); 
}

int questo(string what) {
if (what != "lich quest") return 0;
if (what == "lich quest") {
find_living("Yyz")->force_me("say Find the beast known as Tiamat...");
find_living("Yyz")->force_me("say Then return to me and invoke the name of Death.");
find_living("Yyz")->force_me("say But remember...  Death hath no remorse...");

return 1;
}
}

int questorama(string what) {
if (what != "thaalzi al adom") return 0;
if (what == "thaalzi al adom") {
if (this_player()->query_class() != "mage") return 0;
if (this_player()->query_race() == "demon") return 0;
if (this_player()->query_race() == "archangel") return 0;
if (this_player()->query_race() == "lich") return 0;
if (this_player()->query_level() < 40) return 0;
find_living("Yyz")->force_me("say Thaalzi al adom mirthua mak si a al puul al don!");
this_player()->set_level(1);
this_player()->set_race("lich");
this_player()->new_body();
write(this_player()->query_cap_name()+" has become one of the undead.");
find_living("Yyz")->force_me("speak From this death there is no return...");
return 1;
}
}


void reset() {
::reset();

if (!present("Yyz")) {
new(MOB "yyz")->move(this_object());
}

ghast = random(100);


}
