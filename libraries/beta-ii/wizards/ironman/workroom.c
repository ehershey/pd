
#include <std.h>
inherit ROOM;

object board;
int my_test();

int BOOO();

void create() {
    ::create();

    set_properties( ([ "light" : 2, "indoors" : 1]) );

    set_smell("default", "You smell the strange combination of burning cinders and animal fur");

    set_smell("boo",(: BOOO :));
    set_smell("boo2",(: "BOOO" :));
    set_short("Ironman's Chemistry set");

    set_long("This is the personal lab of the absent-minded professor, Ironman.  You can tell he's been focusing on his latest creations cause parts of creatures and half-build equipment litter every part of the room...");

    set_items(([
	"parts" : "severed body parts of some unfortunate creature that Ironman has dis-assembled (or blown apart) to study it's inner workings.",
	"equipment" : "The building blocks of equipment. Some are armour. Others are weapons. Still others are items and supplies. \n Totally scattered to the four winds without rhyme or reason."
	,
	"armour" : "This is half-assembled breastplates and cloaks"
	,
	"weapons" : "Now here are some off-the wall weapons. They're made to resemble animal parts."
      ]));
    set_exits( ([ 
        "tirun" : "/d/nopk/tirun/pubstart.c",
        "builders" : "/d/nopk/tirun/gcroom.c",
        "test" : (: my_test :),
        "stormy" : "/wizards/stormbringer/workroom.c",
	"wiz" : "/d/nopk/standard/adv_inner"
      ]) );
    /// Board settings
    board = new("std/bboard");
    board -> set_name("Ironman's Notepad");
    board -> set_id(({"board","Ironman's notepad","notepad"}));
    board -> set_max_posts(1000);
    board -> set_edit_ok(({"ironman","scrappy","cortoth"}));
    board -> set_location("/wizards/ironman/workroom.c");
    board -> set_short("Ironman's Notepad");
    board -> set_long("Ironman's Design notepad. This board is set in his workshop to allow free access to ideas and methods. If i'm not on leave me a note here.\n\nSigned Ironman\n\n");
    board->set_board_id("ironman's notepad");
}

int my_test() {
     if(this_player()->query_name()=="ironman") {
         this_player()->move("/d/nopk/tirun/gcroom.c");
         return 1; }
       else return 0; }
