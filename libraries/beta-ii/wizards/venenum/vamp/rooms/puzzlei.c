#include <std.h>
#include <venenum.h>
inherit ROOM;

int pushed=0;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This passage is crafted from dull grey stone blocks. Otherwise unremarkable, this place appears barren of any other features apart from a small inscription on the floor.");
    set_items(([
	({"inscription"}) : "%^BOLD%^%^WHITE%^Inside you is the potential for anything.%^RESET%^ \n \n Something else is scribed below. '%^BOLD%^Read all there is to know, seek the first, then %^RESET%^%^CYAN%^enter%^BOLD%^%^WHITE%^ it here. The key shall be revealed to you.%^RESET%^' There is a series of small stones here, each with a letter inscribed upon it.",
      ]));
    set_listen("default", "There are no audible noises here.");
    set_smell("default", "The slight scent of mildew is present here.");
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"puzzlef.c",
	"west" : ROOMS"puzzleh.c",
      ]));
}

void init() 

{
    ::init();
    add_action("enter", "enter");
}

int enter(str)

{
    if(!str) { return 0; }
    if(str == "fdtatymri") 
    {
	write("You enter: "+str+". The buttons glow brightly for a second, then a passage to the east slides open.");
	add_exit(ROOMS"puzzleZ.c","east");
	call_out("remove_exit_func",5);
	return 1;
    }
    else
    {
	write("You enter: "+str+", but nothing seems to happen.");
	return 1;
    }
}

int remove_exit_func()

{
    write("The passage closes without a sound.");
    this_object()->remove_exit("east");
    return 1;
}
