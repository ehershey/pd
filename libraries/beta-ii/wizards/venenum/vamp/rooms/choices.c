#include <std.h>
#include <venenum.h>
inherit ROOM;

string *names = ({"mrpoopypants", "bob"});

void create() {
    ::create();
    set_short("A dark and musty mausoleum");
    set_long("The darkness fades out to bright, blinding light. The passage leads out to the east, decending somewhat. There is strangely no way back to the south. There is a finely chiseled engraving on the wall here.");
    set_smell("default", "The sweet smell of crushed roses and earth is present here.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"engraving", "engravings", "finely chiseled engravings"}) : "The engravings form words: '%^BOLD%^Bandit, theif, or worthy venturer? Who can tell but fate; answer these questions and journey onwards, or fail and discover your true fate.%^RESET%^'",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"east" : ROOMS"choices1.c",
      ]));
    set_pre_exit_functions( ({"east"}), ({"check_or_add_name"}) );
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}

int check_or_add_name()
{

    if(member_array(this_player()->query_name(), names) == -1)
    {
	names += ({this_player()->query_name()});
	return 1;
    }
    else
    {
	this_player()->move(ROOMS"failed.c");
	this_player()->force_me("look");
	return 0;
    }

}
