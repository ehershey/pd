#include <lodos.h>
#include <std.h>
inherit OBJECT;

string check_long();
static int open=0, max=0;
void set_opened(int x);
int open(string str);
static string my_short = "%^RESET%^%^RED%^T%^ORANGE%^h%^RED%^e%^ORANGE%^ "
      "%^RED%^t%^ORANGE%^o%^RED%^m%^ORANGE%^e%^RED%^ %^ORANGE%^o%^RED%^f "
      "%^ORANGE%^f%^RED%^i%^ORANGE%^r%^RED%^e%^RESET%^";

void create() {
 ::create();
   set_name("tome");
   set_id( ({"tome"}) );
   set_short("%^RESET%^%^RED%^T%^ORANGE%^h%^RED%^e%^ORANGE%^ "
      "%^RED%^t%^ORANGE%^o%^RED%^m%^ORANGE%^e%^RED%^ %^ORANGE%^o%^RED%^f "
      "%^ORANGE%^f%^RED%^i%^ORANGE%^r%^RED%^e%^YELLOW%^ [Sealed]%^RESET%^");
   set_long("The cover of the tome portrays the Plane of Fire. It's "
      "pages are all golden and the book is labeled: The Tome of Fire. "
      +check_long());
   set_weight(3);
}

int open(string str) {
   if (!str || str != "tome") return 0;
  if (open) {
   write("It is already open.");
   return 1;
  }
   if (environment(this_player())->query_property("no attack") ||
       environment(this_player())->query_property("no magic")) {
     write("You cannot open the seal here.");
     return 1;
   }
  if (max >= 10) {
   write("%^ORANGE%^Flames shoot up into the air and fade away.");
   return 1;
  }
   tell_room(environment(this_player()),
     "%^YELLOW%^A magical serpent of flame lunges at you!", ({ }));
     if (children(MOB"serpent.c")==({})||
         sizeof(children(MOB"serpent.c"))==0)
            new(MOB"serpent")->move(environment(this_player()));
   max++;
   return 1;
}

void init() {
 ::init();
   add_action("open", "open");
}

void set_opened(int x) {
   open = x;
   if (x) set_short(my_short+" %^YELLOW%^[Sealed]%^RESET%^");
   else set_short(my_short+" %^YELLOW%^[Unsealed]%^RESET%^");
}

string check_long() {
   if (open) return "The tome has been pryed open, it's seal broken.";
   else return "The tome is closed by a magical seal of fire.";
}
