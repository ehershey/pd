#include <std.h>
#include <blueserver.h>
inherit ROOM;
void create() {
room ::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Cavern of Blue Waters");
    set_day_long(
   "Standing in front of a magnificent cave that is encrusted "
   "with sapphire crystals around the mouth. Each blue stone "
   "shines brilliantly as it sparkles under the sun's warm "
   "rays. A large fountain can be seen of to one side of the "
   "entrance."
    );
    set_night_long(
   "Standing in front of a magnificent cave that is encrusted "
   "with sapphire crystals around the mouth. Each blue stone "
   "shines brilliantly as it sparkles under the moon's "
   "rays. A large fountain can be seen of to one side of the "
   "entrance."
    );
    set_items(([
        "cave" : "It seems to be the home of some large animal, "
             "but feels inviting nonetheless.",
        "sapphires" : "Gigantic, brilliant blue stones and crystals "
                         "outline the entrance to the cave. Their deep, "
     
       "shifting blues remind you of going to the water's "
             "edge on a warm sunny day.",
    "opening" : "It is very large, big enough for a large creature.",
    "stone" : "Brilliant blue sapphires cut into diamonds that "
            "reflect the light.",
     "crystals" : "Brilliant blue sapphires cut into diamonds that "
             "reflect the light.",
    ]));
    set_smell("default", "It smells like wet soil after a day's rain.");
    set_listen("default", "Sounds of creatures splashing in a distance");
    set_exits( ([
"east" : BLUE "a24",
"southeast" : BLUE "a10",
"northwest" : FOR "a52",
    ]) );
}
void reset() {
 ::reset();
   if (!present("fountain", this_object()))
     new( ITEMS "fountain.c" )->move(this_object());
}
