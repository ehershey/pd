#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 14, 0 })]));
    set_short("Dragon Lands North");
    set_long("The mountain ridge runs east-west, skirting deep valleys to the south and to the north. The valley to the north runs deep and wide, the view of the bottom of it is obscured by a large rock which juts out from the mountainside below. The crevice to the south drops off gently into rolling rocks and dirt. The path is clean and clear from bumps and obstacles, in stark contrast to the valley to the north below which is covered in vines and other loose brush.");
    set_exits( ([
	"west" : DRAG_ROOMS"dragnorth05.c",
	"east" : DRAG_ROOMS"dragnorth07.c",
      ]) );
    set_items( ([
	"path" : "It would be foolish to say that the path is well-travelled, but it is definitely well-worn. It appears to have been prematurely trampled into place by something, or some things, of great mass.",
      ]) );
}
