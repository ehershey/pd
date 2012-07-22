#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Underneath the graveyard");
    set_long("This large, circular mausoleum sits underneath the graveyard. A long tunnel leads out towards the north, stretching out into the gloom. The walls are grey/black blocks of stone, bare of any describing features. A small spiral staircase is to the south, leading upwards. There is strange writing on the southeast corner of the wall.");
    set_smell("default", "The sweet smell of crushed roses is present here.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"flower", "flowers", "rose", "roses"}) : "There must be hundred and hundreds of these roses littering the stairway. They make decent or ascent difficult.",
	({"staircase"}) : "This staircase is almost completely covered with rose flowers and petals.",
	({"writing", "strange writing"}) : "The writing is strange and hard to make out, but is legible after a moment's study. It appears to be a new-ish addition to the tomb, as though it was not there when the tomb was created. It reads: '%^BOLD%^Warning to all; the creature buried herein lives but does not breathe, moves and does not rest, drinks but does not eat. Ware all who proceed into this mausoleum, lest your lifeblood be quaffed and you adopt the curse of blood.%^RESET%^' There is a bloody handprint at the end of the writing.",]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"tomb5.c",
	"south" : ROOMS"tomb3.c",
      ]));
}
