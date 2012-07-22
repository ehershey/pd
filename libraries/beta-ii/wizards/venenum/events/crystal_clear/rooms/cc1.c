#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Halfling camp");
    set_long("This clearing in the woodlands has several burned out tents around, surrounding a long-dead campfire. This clearly functioned as a temporary camp for a scouting party, but has recently been burned to the ground. Several halfling bodies lay scattered about the ground, recently dead. To the side of the reminants of the largest tent are several backpacks of supplies, untouched by the flames. Fresh tracks and a trail of blood lead off to the south.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The stench of burned fabric obscures any other smell.");

    set_items(([
	({"body", "bodies"}) : "The bodies of six to seven halflings lay around here, warriors apparently, along with one cleric. Most of the bodies are in incomplete states of dress, often without armour or weapons. One corpse wears little more then a pair of pants. Clearly, the shortfolk were caught by surprise and slaughtered. In addition to this, the halflings appear completely outmatched by their opponants- not a single one of the weapons carried by the shortfolk is blooded.",
	({"tent", "tents"}) : "These tents are small, as though intended for a halfling or a human child. They have been burned to the ground.",
	({"backpack", "backpacks", "supplies"}) : "The backpack here are full to the brim with supplies. Clearly, robbery was not a motive here.",
	({"trail", "blood"}) : "The trail is not overly strong, although it appears to be a mixture of blood from two different races- the light red blood of halflings and an unknown, darker blood, almost black in colour and smelling strongly of mercury.",
	({"tracks", "track"}) : "The tracks are fresh and made by booted feet. Despite the number of boots, possibly up to six or seven, the tracks are surprisingly light and almost elvish in nature.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : ROOMS"cc2.c",
	"portal" : "/wizards/venenum/events/crystal_clear/void.c",
      ]));
}
