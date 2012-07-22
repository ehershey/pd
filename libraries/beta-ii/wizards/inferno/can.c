#include <std.h>
inherit OBJECT;
void this_name(string str); // =p
int myOpen(string str);

static int opened=0;
static string name;

void this_name(string str) { name = str; }

void create() {
 ::create();
   set_weight(1);
}

int myOpen(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   if (opened) {
      write("It is already open!");
      return 1;
   }
   write("You open the "+name+".");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         " opens "+name+".", ({ this_player() }));
   opened = 1;
   return 1;
}

int myDrink(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   if (!opened) {
      write("You must open it first!");
      return 1;
   }
   this_player()->add_quenched(40);
   this_player()->add_sp(20);
   this_player()->add_mp(30);
   this_player()->add_hp(40);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
        " drinks "+name+".", ({ this_player() }));
   write("You drink "+name+".");
   new("/wizards/inferno/emptycan")->move(this_player());
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("myOpen", "open");
   add_action("myDrink", "drink");
}
