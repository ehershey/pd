#define MESS "Syntax: <command [player] to [thing]>\n"
#define ILL  "You may not do that.\n"
#define ERR  "You do not have contol over that.\n"
#include <std.h>
inherit OBJECT;

static object *total=({ });
int add_subject(object ob);
int command(string str);
void remove_sub(object ob);

void create() {
 ::create();
   set_name("user_control");
   set_short("");
   set_long("You are under the influence (of other players).");
   set_weight(0);
   set_id(({ "user_control" }));
   set_value(0);
}

void init() {
 ::init();
   add_action("control", "infcom");
}

int add_subject(object ob) { total += ({ ob }); }

int control(string str) {
   string what, who;
   object you;
   int j, k=0;
   if (!str) return notify_fail(MESS);
   if (sscanf(str, "%s to %s", who, what) != 2) return notify_fail(MESS);
   you = present(who, environment(this_player()));
   if (!you) return notify_fail("They are not here.\n");
   j = sizeof(total);
   while (j--) { if (total[j] == you) k++; }
   if (!k) return notify_fail(ERR);
   // Check for illegal forces
   if (what == "suicide") {
      remove_sub(you);
      return notify_fail(ILL);
   }
   if (what == "quit") return notify_fail(ILL);
   write("%^YELLOW%^You command "+you->query_cap_name()+" to:%^RESET%^ "+what);
   tell_object(you, "%^YELLOW%^"+this_player()->query_cap_name()+
      " commands you to:%^RESET%^ "+what);
   if (you->force_me(what)) write(capitalize(you->query_subjective())+" does as commanded.");
   return 1;
}

void remove_sub(object ob) {
   object *new = ({ });
   int i;

   i = sizeof(total);
   while (i--)
      if (total[i] != ob) new += ({ total[i] });
   total = new;
}
