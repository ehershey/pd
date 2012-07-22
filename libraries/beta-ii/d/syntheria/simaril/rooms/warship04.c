#include <std.h>
#include <simaril.h>

inherit ROOM;

int pl_crate(string str);

void create()
{
    ::create();
        set_name("syntherian warship");
        set_short("Syntherian Warship");
        set_long("An array of various tools line the hull of the ship. Each one looks a hundred years old and is terribly worn. "
                 "Below the hanging instruments are boxes of varying size and shape. Some are old and splintered while others appear to be built from fresh wood. "
                 "It appears this section of the ship is rarely visited. The place seems to be in a in a general state of disarray with everything placed randomly around. "
                 "Only small streams of light seep into this part of ship from the sleeping quarters. Random shadows dance around each other in strange patterns, hiding many things in their darkness. "
                );  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "town"        : 1,
        "indoors"         : 1,
 
        ]) );
        set_items(([
                "tools"         :       "Quite a collection of tools, everything from axes to wrenches.",
                "boxes"         :       "Obviously used for long term storage as they are all nailed tightly shut.",
                "hull"          :       "The inner side of the hull of the ship, it is made of solid wood.",
                "shadows"       :       "Strange dark forms created by the varied items near by. Who knows what secrets they hide behind their veil.",         
            ]));
            set_listen("default", "The room is silent.");
            set_smell("default", "The smell of burning oil fills the air.");
                set_exits(([
                        "north"         : ROOMS"warship03.c",
        ]));
        set_search("tools",   "There does not appear to be anything of use among these relics of the past.");
        set_search("boxes",   "The nails holding the boxes shut are too large to be pried away.");
        set_search("shadows", "After looking carefully, and allowing your eyes to adjust to the light, you spot what looks like part of a door behind a stack of boxes.");
        set_search("door",    "The door is mostly hidden by shadows and stacked boxes. Pulling on the boxes might move them.");
} 


void init() {
        ::init();
                add_action("pl_crate", "pull");
}


int pl_crate(string str)
{
        if(!str)
                return notify_fail("Pull what?\n");
        if(str != "boxes")
                return notify_fail("You can not pull that!\n");
 
                message("info", "You pull on the bottem box as hard as you can without success. The boxes are too heavy to be moved.", this_player());    

        return 1;
}

 
void reset() {
   ::reset();

}
