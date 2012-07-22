#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain": 1  ]));
  set_short("Dragon Lands North");
  set_day_long("As the path heads southeast, it begins to ride higher up on the mountain, sliding up the side of the mountain ridge on the south. The valley below that path had previously been following drops off to the east into a tremendous crevace. Loose brush and thorny underbrush litter the side of the mountain and the mountain path.");
  set_night_long("As the path heads southeast, it begins to ride higher up on the mountain, sliding up the side of the mountain ridge to the south and climbing out of the dark valley in between the two mountain ridges to the north. The night light casts a cool glow on the side of the mountain and the loose brush scattered across it. The valley below slips quickly into a dark abyss to the east.");
  set_exits( ([
    "west" : DRAG_ROOMS"dragnorth02.c",
    "southeast" : DRAG_ROOMS"dragnorth04.c",
   ]) );
  set_items( ([
    ({ "vines", "scrubs", "brambles", "branches", "overgrowth", "foliage" }) : "They litter the mountain path below, impeding progress.",
    "mountain" : "The mountain consists of many tall peaks, with tall ridges interconnecting them. It stands tall with the bulk of its mass towards the south and the southeast. Large peaks rise up in all directions and obscures most of your view of it.", 
    "path" : "A mountain path that appears to be extremely untended for. It climbs slows up the face of the mountain. The path is currently within a deep mountain valley, but to the southeast it climbs up on the side of a mountain peak, climbing up the side of it.",
    "valley" : "The mountain path below rides in a deep mountain valley which drops off into a large canyon to the east.",
    "abyss" : "It is too dark to see into.",
   ]) );
}
