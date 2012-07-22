#include <std.h>
#include <venenum.h>
inherit ROOM;

int pushed=0;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This tiny alcove, crafted from set stone blocks, is completely empty apart from a small stone statue of a cat which is firmly attached to the floor. The cat appears to be about to pounce on it's prey.");
    set_listen("default", "There are no audible noises here.");
    set_smell("default", "The slight scent of mildew is present here.");
    set_items(([
	({"paws", "cat's paws", "cats paws", "cat paws", "cat paw", "paw"}) : "The cat's paws have their claws extended.",
	({"eye", "eyes", "cats eyes", "cat's eyes", "cat eye", "cats eye", "cat's eye"}) : "The cat's left eye is empty and hollow, as though it once held some kind of jewel.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"west" : ROOMS"puzzlei.c",
      ]));
    new(ITEM"stone_cat.c")->move(this_object());
}

void init() 

{
    ::init();
    add_action("place", "place");
}

int place(str)

{
    if(!str) { return 0; }
    if(str == "stone in cat" || str == "stone in cat's eye" || str == "stone in cats eye" || str == "stone in eye" || str == "sapphire in cat" || str == "sapphire in cat's eye" || str == "sapphire in cats eye" || str == "sapphire in eye" || str == "gem in cat" || str == "gem in cat's eye" || str == "gem in cats eye" || str == "gem in eye")
    {
	if (present("eye_sapphire_looted", this_player()))
	{
	    write("You place the gem into the eye of the cat. It glows for a second then falls back out again, an emerald.");
	    present("eye_sapphire_looted", this_player())->remove();
	    new(ITEM"emerald.c")->move(this_object());
	    return 1;
	}
    }
}
