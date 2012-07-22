#include <std.h>
#include <roston.h>
inherit ROOM;

string look_tree();
static int flower = 0;

string look_tree() {
   string str;
   str = "It is the most beautiful tree you have ever seen.";
   if (!flower) return str;
   else str += " A single red rose grows at the base of it.";
   return str;
}

void create() {
  ::create();         

set_name("garden");
set_properties((["light":2, "night light":3]));
set_short("The prince's garden");
set_long("You are standing in the Prince's garden. "
         "Many different types of flowers, bushes, trees, "
         "and shrubs have been carefully planted here. The "
         "beauty of this place is overwhelming. Even the "
         "dirt is a deep black in color.");
set_items((["flowers" : "There are many colorfull flowers all over. ",
            "trees"   : "There are many trees, but a single white ash stands out "
                        "from the rest.",
            ({ "ash", "tree" })    : (: look_tree() :),
            "bushes"  : "Green shrubs of every shape and size.",
            "shrubs"  : "They are marvelously carved.",
            "snow"    : "Deep white snow.",
            "dirt"    : "The dirt here is a dark black, great for growing "
                        "plants."])); 
set_exits( ([ "north" : ROOMS"roston20"]));
   flower = 1;
}                                                                 

void reset() {
 ::reset();
   flower = 1;
}

int pick(string str) {
   if (!str || !flower) return 0;
   if (str != "rose" && str != "flower") return 0;
   write("You pick the rose from beneath the tree. The rose glows in your "
     "hands.");
   new("/wizards/wiz/item/rose")->move(this_player());
   flower = 0;
   return 1;
}

void init() {
 ::init();
   add_action("pick", "pick");
}

