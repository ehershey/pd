#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;
object b;
void init() {
        ::init();
add_action("cmd_rules","read");
add_action("cmd_drop","drop");

}

void create() {
        ::create();

        set_short("%^RESET%^%^CYAN%^Ethereal Tower: Level 1%^RESET%^");
        set_long(
                "%^RESET%^%^CYAN%^Ethereal Tower: Level 1%^RESET%^\n%^BOLD%^%^WHITE%^Brilliant light emanates from an unknown source, "
                "illuminating the room with a holy glow. Archaically carved pilasters erect from the white marble floor, "
                "giving the locus a very sacred appearance. An old book lays open next to a scroll on a small altar, "
                "toward the back of the room. This is the hall of the Ethereal.%^RESET%^"
        );
        set_exits( ([
                "east" : ALL "meeting",
                "west" : ROOMS "1-3.c",
                "north" : ROOMS "1-4.c",
                "south" : ROOMS "1-5.c",
                "up" : ROOMS "2-1.c"
        ]) );


        set_items( ([
                "light" : "%^BOLD%^%^WHITE%^Brilliant light emanating into the room from an unknown source.%^RESET%^",
                "pilasters" : "%^BOLD%^%^WHITE%^Large pillars that seem to have no end.",
                "floor" : "%^BOLD%^%^WHITE%^A beautiful white marble floor.%^RESET%^",
                "book" : "%^RESET%^%^ORANGE%^The ancient book of rules. Perhaps it should be read.%^RESET%^"
        ]) );

        b=new(BBOARD);
        b->set_name("ethereal_board");
        b->set_id(({ "board", "ethereal scrolls" }));
        b->set_short("The Ethereal Scrolls");
        b->set_long("This is the Ethereal's bulletin board. Here members "
              "can post about anything they want, but please try to keep it guild related!\n");
        b->set_board_id("ethereal");
        b->set_edit_ok(GUILD_D->post_able("ethereal"));
        b->set_max_posts(99);
        b->set_location(ROOMS"1-1.c");
        set_smell("default", "The scent of aromatic blossoms intertwine with stench of blood.");
        set_listen("default", "Faint gaelic chanting drifts into the room from the marble halls.");

if (!present("pit")) {
        new(OBJ"pit")->move(this_object());
}


}
int cmd_drop(string str) {
    this_player()->force_me("put "+str+" in pit");
    return 1;
}
void reset() {
  ::reset;
  if (children(MOB"ww")==({}) || sizeof(children(MOB"ww"))<1)
     new(MOB "ww")->move(this_object());
}
