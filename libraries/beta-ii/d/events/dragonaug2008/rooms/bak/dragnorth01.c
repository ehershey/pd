#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "night light" : 0, "no teleport" : 1, "beach" : 1, "mountain" : 1, "coords" : ({ 136, 14, 0 }) ]));
  set_short("Dragon Lands North");
  set_day_long("Two mountain fragments to the southwest and east lean overhead. Although the two fragments do not touch each other, the one on the east leans slightly over the one on the west, obscuring the majority of the light from above. A Few shafts of light pierce through the canopy of rocks and earth above and illuminate the area. The overgrown and uneven beach climbs slowly up the mountain to the south, which, unburdened by its sand, snakes through the mountain, leaving a path in its wake.");
  set_night_long("Two mountain fragments to the southwest and east lean overhead, casting a thick shadow over the area. Although the fragments do not physically connect with each other, the one on the east leans slightly over the one from the west, creating a canopy of darkness. A few shafts of moonlight pierce through the cloak of shadows above and leave patchy pools of light upon the vine and underbrush infested sand. The beach sneaks slowly up the mountain to the south, where it loses its cover of sand and streaks through the mountain, leaving a scar through the mountain just shallow enough to climb.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"beach.c",
    "south" : DRAG_ROOMS"dragnorth02.c"
             ]) );
  set_items( ([
    "beach" : "A sandy beach. It appears weathered and unused, there are bumps in the sand and brambles and branches scattered across it. In all honesty, towards the south it's beginning to look more like a path than a beach, as while it climbs the mountain it leaves the majority of its sand behind.",
    "scar" : "A steep path heading up through the heart of the mountain. It looks like it was carved out of the mountain by a long, sharp claw. Of course, no animal would have been large enough to accomplish that.",
    ({ "vines", "scrubs", "brambles", "branches", "overgrowth", "foliage" }) : "They litter the sandy ground.",
    "ocean" : "It lies to the northwest, past the beach. Its waves and peaks glisten softly in the light.",
    ({ "fragments", "fragment", "canopy", "rocks", "earth" }) : "Two large mountain pieces lean overhead. They do not form an all-encompasing barrier from above, but they do a good job of blocking out most of the sky.",
    ({ "light", "shafts", "moonlight" }) : "Some shafts of light pierce through the holes in the rock ledges above and help to illuminate the area.",
    "pools" : "The light collects in various patches on the floor.",
    "path" : "To the south, the beach loses the majority of its sand and becomes a full-blown path through the mountain.",
             ]) );
  set_listen("default", "It is mostly silent. You hear the low rustle of the beach to the northwest.");
}
