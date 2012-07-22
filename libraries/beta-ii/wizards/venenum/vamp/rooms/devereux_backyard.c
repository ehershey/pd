#include <std.h>
#include <venenum.h>
inherit VAULT;

int closed=1;

void create() {
    ::create();
    set_short("Backyard");
    set_long("The rear garden of this house is smaller the then the front garden by a significant margin, but is still spacious compared to many houses in this district. Many weeping willow trees grow tall here, providing a shield from the neighbor's prying eyes. A small birdbath stands to the back of the garden, providing a perch for visiting birds. Several large lounging chairs are scattered about the backyard for the aid of entertaining guests. The grass on the lawn is thick and lush but well kept. A large pair of double doors, closed together and parallel to the ground, lead down to the basement. To the south, another door leads back into the house.");
    set_smell("default", "The air smells fresh here and slightly of flowers.");
    set_listen("default", "This backyard area is relaxing and quiet.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"tree", "trees", "weeping willow", "willow trees", "weeping willow trees"}) : "These huge trees have been here for a great deal of time. Their upper branches have grown together, wound around each other like the knots of some crazed swashbucker.",
	({"birdbath"}) : "This solid stone birdbath is full of water.",
	({"chair", "chairs"}) : "The chairs are crafted from woven shafts of an unknown wood, lacqured to prevent them from spoiling in the weather.",
	({"grass", "lawn"}) : "The lawn is thick and lush with soft grass and neatly trimmed edges.",
	({"door"}) : "This door leads back into the house. Crafted of solid oak it is heavy to move.",
	({"doors"}) : "These doors lead down to the basement or room under the house. They could probably be opened without too much effort.",
      ]));
    set_exits(([
	"south" : ROOMS"devereux_study.c",
      ]));
}

void init() 

{
    ::init();
    add_action("open", "open");
    add_action("close", "close");
}

int open(str)

{
    if(str != "doors") 
    {
	return 0;
    }

    if (closed)
    {
	write("You open the large doors.");
	message("dooropen", this_player()->query_cap_name()+" opens the large doors to the basement.", this_object(), this_player());
	add_exit(ROOMS"devereux_basement1.c","enter"); 
	call_out("close",20);
	return 1;
    }

}

int close()

{
    message("doorclose", "The doors to the basement swings shut without a sound.", this_object());
    closed = 1;
    remove_exit("enter");
}
