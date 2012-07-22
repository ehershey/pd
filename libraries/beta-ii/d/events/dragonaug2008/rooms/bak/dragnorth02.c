#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "beach" : 1, "mountain" : 1, "coords" : ({ 136, 14, 0 }) ]));
  set_short("Dragon Lands North");
  set_day_long("The overgrown, uneven mountain path bounces off the mountain to the south and swerves to the east. Jagged mountain rocks and peaks jut out of the ground to the southwest and northeast. To the north the path begins to be covered in sand, and to the east it crawls further up the mountain.");
  set_night_long("The mountain path below snarls through the mountain, swerving around a large dark mountain peak and screaming up the mountain to the east. Vines and thorny underbrush litter the bumpy and uneven ground, scattering the moonlight. Sand litters the path below to the north, shivering and glinting in the night light.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth01.c",
    "east" : DRAG_ROOMS"dragnorth03.c",
             ]) );
  set_items( ([
    "beach" : "The path below drops off the mountain towards the north and picks up a cover of sand, becoming a full-blown beach.",
    "mountain" : "The mountain consists of many tall peaks, with tall ridges interconnecting them. It stands tall with the bulk of its mass towards the south and the southeast. Large peaks rise up in all directions and obscures most of your view of it.", 
    ({ "vines", "scrubs", "brambles", "branches", "overgrowth", "foliage" }) : "The ground is covered with them. It must have taken decades of untended growth for all of this to grow.",
    "path" : "A mountain path that appears to be extremely untended for. It climbs slows up the face of the mountain.",
    "sand" : "It covers the beach to the north.",
    "peak" : "A large mountain peak that rises out of the ground to the north, causing the path below to deviate from its path and swerve to the east, farther up the mountain.",
             ]) );
}
