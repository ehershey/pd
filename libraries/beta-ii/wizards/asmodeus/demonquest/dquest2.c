#include <gcity.h>
#include <mjungle.h>
#include <std.h>
#include <dquest.h>
inherit ROOM;

void init() {
  ::init();
add_action("read_tome", "read");
add_action("embrace_light", "embrace");
add_action("forsake_light", "forsake");
}

void create() {
::create();
set_short("A cave lit by several torches");
set_long("%^BOLD%^BLACK%^The tunnel takes you into a large cavern with a hole in the ceiling leading outside.  A bright %^RESET%^WHITE%^white%^BOLD%^BLACK%^ light streaks down from the sky above. Standing within the ray is a pedestal.  You notice the floor is carved with the same strange glowing runes as before.");
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"southeast": DQUEST "dquest1.c",
]));
set_items(([
"runes": "The runes are of various colors and of various shapes.  However in this room a %^BOLD%^BLUE%^blue %^RESET%^skull seems to flicker slightly.",
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
({"light", "beam", "ray"}) : "The ray of light streaks down from the heavens upon the pedistal.",
"walls": "The cave walls are rough and jagged yet the floor is strangely smooth.",
"floor": "The floor is covered with many strange runes.",
"pedestal": "The pedistal is made of white marble and holds a tome written in an ancient text.",
"tome": "As you look at the tome your mind is compelled to read it.",
]));
}

void reset() {
::reset();
if(!present("love")) {
new(DQUEST "love.c")->move(this_object());
}
}
int read_tome(string what) {
  if (what != "tome") return 0;
write("The tome reads: %^BOLD%^RED%^The path of the demon is a path that abandons the light.  The soul is forever lost and forever the possession of Asmodeus.  <%^WHITE%^embrace the light%^RESET%^BOLD%^RED%^> to save your soul or <%^BOLD%^BLACK%^forsake the light%^RESET%^BOLD%^RED%^> and prove your worth...%^RESET%^");
    return 1;
}
int embrace_light(string what) {
if(what != "the light") return 0;
this_player()->move_player(GCITY "gcity6.c", "into the light.");
    return 1;
}

int forsake_light(string what) {
if (what != "the light") return 0;
write("%^BOLD%^BLACK%^You abandon the %^RESET%^light%^BOLD%^BLACK%^ and allow yourself to be swallowed into darkness.%^RESET%^");
this_player()->move_player(DQUEST "dquest3.c", "repulses the light and is swallowed into darkness.");
this_player()->set_alignment(-25000);
     return 1;
}
