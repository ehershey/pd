#include <std.h>
inherit OBJECT;

static object ob;
static int lit, smoked;

string query_short() {
   if (!ob) return ::query_short()+" (empty)";
   if (lit) return ::query_short()+" (lit)";
   return ::query_short()+" (packed)";
}

void create() {
 ::create();
   set_properties(([ "pipe" : 1 ]));
}

int smoke(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   if (!ob) return notify_fail("There is nothing in it.\n");
   if (!lit) return notify_fail("It is not lit.\n");
   if (this_player()->query_disable()) return notify_fail(
     "You are busy.\n");
   write("You smoke some "+ob->query_short()+" from the pipe.");
   say(this_player()->query_cap_name()+" smokes some "+ob->query_short()
     +" from a pipe.", this_player());
   ob->smoke_me(this_player());
   if (!smoked) smoked = 1;
   else smoked++;
   if (smoked >= 3) {
     ob->remove();
     lit = 0;
     smoked = 0;
   }
   this_player()->set_disable(1);
   return 1;
}

int pack(string str) {
   string what;
   object that;

   if (!str) return 0;
   if (!sscanf(str, "pipe with %s", what))
   if (!sscanf(str, "%s into pipe", what)) return notify_fail(
     "Pack what into what?\n");
   if (!(that = present(what, this_player()))) return 0;
   if (!that->can_smoke()) return notify_fail("You cannot put that into the pipe.\n");
   if (ob) return notify_fail("The pipe is already packed.\n");
   write("You pack some "+that->query_short()+" into the pipe.");
   say(this_player()->query_cap_name()+" packs a pipe full of "
     +that->query_short()+".", this_player());
   ob = that;
   that->move("/d/standard/temporary");
   return 1;
}

int light(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   if (lit) return notify_fail("It is already so.\n");
   if (!ob) return notify_fail("There is nothing in the pipe.\n");
   write("You light the pipe.");
   say(this_player()->query_cap_name()+" lights a pipe.", this_player());
   lit = 1;
   return 1;
}

void init() {
 ::init();
   add_action("pack", "pack");
   add_action("light", "light");
   add_action("smoke", "smoke");
}
