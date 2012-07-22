// - seeker rules, inferno is a moron!!! -

#include <std.h>
inherit OBJECT;

string dest;

void set_destination(string str)
{
 dest = str;
}
void create() {
 ::create();
   set_id( ({"portal"}) );
   set_name("portal");
   set_short("A glowing portal");
   set_long("The portal swirls with magical colours.");
      
}

void set_colour() {
   if (dest == "/d/standard/dragon_hall" ||
       dest ==  "/d/standard/dragon_hall.c")
       set_short("a portal glowing dark green");
   if (dest == "/d/standard/assassin_hall" ||
       dest == "/d/standard/assassin_hall.c")
       set_short("a portal glowing dark red");
}

int rmPortal()
{
 message("info","The portal suddenly disappears.\n", environment(this_object()));
 this_object()->remove();
 if (this_object()) destruct(this_object());
 return 1;
}
int init()
{
 ::init();
 add_action("enter", "enter");
 call_out("rmPortal", 10);

}
int enter(string str)
{
 if (!str || present(str, environment(this_player())) != this_object())
   {
      return notify_fail("Enter what?\n");
   }
 write("You enter the portal and land in a place totally different than before.");
 this_player()->move_player(dest, "into the portal");
// this_player()->force_me("look");
 return 1;
}
int get() { return 0; }
