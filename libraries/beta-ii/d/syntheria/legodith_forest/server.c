#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALSERVER;

void create() {
    ::create();
        set_how_long(6);
        set_day_sentances( ({
            "The trees are thick and tall, they block most of the sunlight from reaching the forest floor.",
            "Small patches of grass cover the ground, each patch looks under grown from the lack of sunlight.",
            "A slight breeze blows through here, making it difficult to hear anything over the rustling of the leaves.",
            "A patch of ferns grow here, they sway slowly in the breeze.",
            "The ground is very dry and hard, the trees must soak up most of the rain before it can reach the ground.",
            "Moss grows on several fallen trees, it is thick and a very dark shade of green.",
            "Large mushrooms grow up the side of a large tree here, both the trees and the mushrooms look to be very old.",
            "Large vines hang down from the trees, it may be possible to climb them if there are bigger ones.",
            "Many small birds can be seen flying from tree to tree, keeping an eye out for something to eat.",
            "Rays of light bounce off of plants on the forest floor, making for strange patterns of light everywhere.",
        }) );


        set_night_sentances( ({
            "The forest is very dark at night, dancing shadows can be seen in all directions.",
            "A cold breeze blows through the forest, a dark omen indeed.",
            "The faint outline of mushrooms can be seen on a tree nearby, they appear to be rather large mushrooms.",
            "Many small ferns grow here, the reflect what small amount of light is being cast on them.",

            "The ghostly image of shadows dance in wind, they look to be vines swaying back and forth.",
            "Large trees reach into the night sky, blocking out any stars that might be out.",
            "The ground is very hard and dry, very little water must reach the forest floor.",
            "Animals can be heard in all directions, searching for food most likely."
        }) );
        set_item_list( ([
            "trees" : "Huge trees that reach into the sky.",
            "vines" : "Long mostly thin vines that hang down from the trees above.",
            "ferns" : "Small ferns that cover the forest floor.",
            "grass" : "The grass is very short, and seems to be turning brown.",
            "moss"  : "Furry green moss grows everywhere.",
        ]) );
        set_smell("The smell of decaying plant matter fills the air.");
        set_listen("Many dozens of bird's mating calls can be heard from all directions.");
        set_reset_list( ({
            MOB"bear_cub", MOB"black_ant", MOB"coyote", MOB"forest_pixie", MOB"giant_dragonfly",
            MOB"king_snake", MOB"large_raccoon", MOB"satyr", MOB"spriggan", MOB"trent",
            MOB"wild_gnome", MOB"young_wolf",
        }) );
        set_properties( ([ 
            "light" : 2,
            "night light" : 1,
            "forest" : 1
        ]) );
        set_short("Legodith Forest"); 
}
