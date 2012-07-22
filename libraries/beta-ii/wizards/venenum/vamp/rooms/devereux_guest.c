#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Guest room");
    set_long("This neat room is a spare room for guests or visitors to the house, with a pair of neatly arranged beds and a large closet with many drawers for storing coats and items of clothing. A rack with several hooks upon it stands near the doorway, providing a means to hang one's coat for those cultured enough to do so. The floor here consists of polished and stained wooden beams laid together, displaying a level of craftsmanship rarely seen in a simple house. There is a single painting resting on the wall here.");
    set_smell("default", "The scent of fresh linin is clear here.");
    set_listen("default", "The house is quiet and peaceful.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"bed", "beds"}) : "This pair of single beds is clearly for visiting guests of the house. The sheets are neatly made and tucked.",
	({"closet"}) : "The closet is wide and deep, although completely empty.",
	({"rack"}) : "The rack is a tall brass affair with many hooks for hats and coats.",
	({"floor", "wood"}) : "The wood here is highly polished and crafted with great skill.",
	({"painting"}) : "This giant painting, nearly covering a whole wall, depicts a white dragon and a red dragon in a fond embrace, the red dragon laying over the white dragon, smiling fondly at her while she smiles back at him. It would look beautiful, except that it appears to have been angrily shredded almost to bits by some kind of huge claws.",
      ]));
    set_exits(([
	"east" : ROOMS"devereux3.c",
      ]));
}

