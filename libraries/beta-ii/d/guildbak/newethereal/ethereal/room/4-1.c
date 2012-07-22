#include <guild.h>
#include <ether.h>
inherit ETHERSTD;

void create() {
    object ob;
    ::create();
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "scrolls" }) );
    ob->set_board_id("leader");
    ob->set_max_posts(99);
    ob->set_edit_ok(({ "kumi","evolution","endbringer" }));
    ob->set_location(ROOMS"4-1.c");
    ob->set("short", "Ethereal Leader's Scrolls");
    ob->set("long", "These arcane scrolls are for the leaders of Ethereal to write about guild issues.");
    set_property("no steal", 1);
    set_short("Ethereal Level 4");
    set_day_long(
      "%^BOLD%^%^MAGENTA%^Ethereal Tower: Level 4\n%^RESET%^%^MAGENTA%^"
      "Glorious rays of sunlight shine down onto the room through the glass ceiling,"
      " illuminating the room with light."
      " A large stone altar stands in the center of the room with arcane scrolls atop it."
      " Three pedestals stand next to each door, with a miniature marble statue of each Ethereal leader.%^RESET%^"
    );
    set_night_long(
      "%^BOLD%^%^MAGENTA%^Ethereal Tower: Level 4\n%^RESET%^%^MAGENTA%^"
      "Luminescent moonbeams and starlights shine down onto the room through the glass ceiling,"
      " illuminating the room with light."
      " A large stone altar stands in the center of the room with arcane scrolls atop it."
      " Three pedestals stand next to each door, with a miniature marble statue of each Ethereal leader.%^RESET%^"
    );
    set_items(([
	"altar" : "A large stone altar which holds the leader's scrolls.",
	"pedestals" : "Three pedestals with miniature statues on them.",
	"pedestal" : "A pedestal with a miniature statue on it.",
	"statues" : "%^BOLD%^Three statues of the Ethereal Leaders: %^RESET%^Kumi%^BOLD%^, %^RESET%^Evolution%^BOLD%^ & %^RESET%^Endbringer%^BOLD%^.%^RESET%^",
      ]) );
    set_smell("default", "The scent of aromatic blossoms waft in the air, bringing peace to the room.");
    set_listen("default", "Faint gaelic chanting drifts through the marble halls.");
    set_exits( ([
	"north" : ROOMS "4-2.c", "south" : ROOMS "4-3.c" , "east" : ROOMS"4-4.c" , "down" : ROOMS "3-1.c", "up" : ALL"meeting"
      ]) );
    remove_exit("up");

}
