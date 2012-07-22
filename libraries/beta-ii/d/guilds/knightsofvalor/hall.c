#include <std.h>
#include <knightsofvalor.h>

inherit ROOM;
object board;

void create() {
    ::create();
    set_properties((["light":2, "indoors":1, "no scry":1]));
    set_name("Knights of Valor Hall");
    set_short("Knights of Valor Hall");
    set_long("The entrance leads into a large meeting hall for the Knights of Valor.  There is a board where Knights may communicate with each other, as well as various amenities such as tables and chairs for personal meetings.  Passages lead to various areas of the hall.");
    set_exits(([
        "door"         : KOVROOM"entrance.c",
"west" : KOVROOM"poolroom.c",
       "down"        : KOVROOM"treasury.c"
      ]));
          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board","Board of Valor","Knights of Valor Board"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"yun"}));
          board -> set_location("/d/guilds/knightsofvalor/hall.c");
          board -> set_short("%^BOLD%^%^WHITE%^Board of Valor%^RESET%^");
          board -> set_long("This is the Board of Valor, where the Knights of Valor may post to communicate with each other.");
           board->set_board_id("knights of valor board");
}
void init() {
    ::init();
    if(this_player()->is_player() && this_player()->query_guild() != "Knights of Valor" && !wizardp(this_player()))
        KOVOBJ"ejection"->eject(this_player());
}
