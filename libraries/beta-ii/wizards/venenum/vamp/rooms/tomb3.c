#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Entrance to the Mausoleum");
    set_long("This small chamber serves as a lead-in for a much larger one to the north. The walls here are block stone, the floor simply a carpet of roses and rose petals along the floor, although there appears to be hard stone underneath. This large tomb appears to be long deserted, except for the presence of the fresh roses.");
    set_smell("default", "The sweet smell of crushed roses is present here.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"flower", "flowers", "rose", "roses"}) : "There must be hundred and hundreds of these roses littering the stairway. They make decent or ascent difficult.",
	({"staircase"}) : "This staircase is almost completely covered with rose flowers and petals.",]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"up" : ROOMS"tomb2.c",
	"north" : ROOMS"tomb4.c",
      ]));
}
