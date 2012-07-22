#include <std.h>
#include <venenum.h>
inherit ROOM;

int taken = 0;

void create() {
    ::create();
    set_short("Inside the Mausoleum entrance");
    set_long("The carved stone stairway here is small and cramped, a thick layer of roses and rose petals scattered across the stone ground. The stairs decend counter-clockwise in tight arcs, probably to save space. Small carvings dot the walls of the staircase, sunk into the stone, almost all images of a beautiful woman with long hair in a variety of poses, always smiling at the viewer.");
    set_smell("default", "There is an overpowering smell of roses here.");
    set_listen("default", "As quiet as a grave.");
    set_properties(([
	"no_clean" : 1,
	"no clean" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_no_clean(1);

    set_items(([
	({"flower", "flowers", "rose", "roses"}) : "There must be hundred and hundreds of these roses littering the stairway. They make decent or ascent difficult.",
	({"staircase"}) : "This staircase is completely covered with rose flowers and petals.",
	({"woman", "images", "carvings"}) : "These carvings depict a nameless woman with long flowing hair. There are eight or nine in this section alone, placed in various positions up and down the wall. She appears to be dressed in a long flowing robe of some description, with her only other visible article of clothing a pair of leather sandles on her feet. Tiny gems have been set into the eyes of the largest carving, giving her eyes a bright shine.",
	({"eyes", "gems"}) : "These appear to be tiny sapphires, cut to shine, placed inside the eyes of the carving. The left eye appears to be slightly skewed in comparison to the right.",
	({"left eye"}) : "Upon closer inspection the left eye appears to be loose. It could possibly be pried off should you make an effort to.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"up" : ROOMS"tomb1.c",
	"down" : ROOMS"tomb3.c",
      ]));
}

void init() 

{
    ::init();
    add_action("pry_func", "pry");

}

int pry_func(str) {

    if (!str || str == "") {return 0;}
    if (str == "off left eye" && taken == 0)
    {
	write("You pry the gem from the eye of the carving.");
	new(ITEM"sapphire.c")->move(this_player());
	set_items(([
	    ({"flower", "flowers", "rose", "roses"}) : "There must be hundred and hundreds of these roses littering the stairway. They make decent or ascent difficult.",
	    ({"staircase"}) : "This staircase is completely covered with rose flowers and petals.",
	    ({"woman", "images", "carvings"}) : "These carvings depict a nameless woman with long flowing hair. There are eight or nine in this section alone, placed in various positions up and down the wall. She appears to be dressed in a long flowing robe of some description, with her only other visible article of clothing a pair of leather sandles on her feet. Tiny gems have been set into the eyes of the largest carving, giving her eyes a bright shine.",
	    ({"eyes", "gems"}) : "These appear to be tiny sapphires, cut to shine, placed inside the eyes of the carving. The left eye socket is empty and barren.",
	    ({"left eye"}) : "It would appear looters found this gem before you did.",
	  ]));
	taken = 1;
	return 1;
    }
    else { return 0;}

}
