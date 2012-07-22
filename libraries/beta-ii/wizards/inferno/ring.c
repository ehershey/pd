#include <std.h>
inherit ARMOUR;

static string cname = "";

void create() {
 ::create();
   set_name("paradox_-ring-_paradox");
   set_id(({"ring", "paradox" }));
   set_short("a glistening silver ring");
   set_long("The ring is smooth and featureless, although it seems to "
     "feel of great worth. You gather from the strange discolorization "
     "of the metal, that it is not actually silver, rather some other "
     "curiously heavy metal.");
   set_weight(7);
   set_limbs(({"left hand", "right hand"}));
   set_type("ring");
   set_value(3500);
}

int query_auto_load() { return 1; }

string query_cap() { return cname; }

int name_change(string str) {
   if (!str) return 0;
   if (!this_object()->query_worn())
     return notify_fail("You must wear the ring first.\n");
   say(this_player()->query_cap_name()+" shifts and changes.", this_player());
   cname = capitalize(str);
   write("You assume the form of "+query_cap()+".");
   return 1;
}

int old_name() {
   if (!this_object()->query_worn() || !query_cap())
     return notify_fail("The ring is not in use.\n");
   cname = "";
   write("You revert to your old self.");
   say("The air shimmers and "+this_player()->query_cap_name()+" steps forth.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("name_change", "form");
   add_action("old_name", "revert");
}

