#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Merkkirri Jungle");
set_day_long("You are in the Merkkirri Jungle.  The swealtering heat and high humidity is beginning to tax your body.  You being to wonder if journeying through these parts is worth the hassle.  The bugs begin biting at your body causing itchy sores.");
set_night_long("You are in the Merkkirri Jungle.  The swealtering heat and high humidity is beginning to tax your body.  You being to wonder if journeying through these parts is worth the hassle.  The darkness around you is quite imposing.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"darkness" : "The massive trees and thick foliage keep the light of the moon and stars out of the jungle below.  It is quite dark.",
({"leaves", "trees", "foliage", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"north": MJUNGLE "mjungle5.c",
"south": MJUNGLE "mjungle3.c",
]));
}
