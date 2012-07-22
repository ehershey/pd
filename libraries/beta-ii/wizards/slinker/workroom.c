#include <std.h>
#include <daemons.h>
inherit ROOM;
int findHall(string str);

int access = 1;
string *boards = ({
"slink_ideas",
"newbie",
"main_board",
"immortal",
"planning",
"arch",
"law",
"coding",
"ombud",
"forge_ideas",
"kataan_board",
"rogue_board",
"monk_board",
"mage_board",
"cleric_board",
"antipaladin",
"paladin",
"ranger",
"soldier",
"warrior",
"knight",
"conj",
"druid",
"necro",
"pyro",
"sorc",
"wizard",
"jester",
"theif",
"assassin",
"monk_dark",
"monk_light",
"spell",
"lodos_town",
"roston_board"
});
int x = 0;
object ob;

void create() {
 ::create();
   set_long("This is Slinker's workroom");
   set_short("Slinker's workroom");
   set_name("workroom");
   set_exits(([ "square" : "/d/standard/square.c"]));
   ob = new(BBOARD);
   ob->set_name("board");
   ob->set_location("/wizards/slinker/workroom");
   ob->set_id( ({ "board", "forge", "iron board" }) );
   ob->set_board_id("slink_ideas");
   ob->set_max_posts(100);
   ob->set_short("The Board");
   ob->set_long("The board");
}

int next() {
   int i, read, total, diff;

   diff = 0;
  while(!diff) {
   i = x + 1;
   if (i >= sizeof(boards)) {
     x = 0;
     write("You are now reading: slink_ideas%^ "
       "by default.");
     tell_room(environment(this_player()), "%^YELLOW%^The board is now set to: "
       "%^RESET%^slink_ideas%^YELLOW%^ by default.", ({ this_player() }));
     diff = BBOARD_D->get_num_read(boards[x], this_player()->query_name());
     diff -= BBOARD_D->get_num_posts(boards[x]);
     break;
   }
   else x++;
   if (!total = (int)BBOARD_D->get_num_posts(boards[x])) continue;
   read = (int)BBOARD_D->get_num_read(boards[x], this_player()->query_name());
   diff = total - read;
   if (read == total) continue;
   if (total == 0) continue;
  }
   write("%^YELLOW%^You are now reading:%^RESET%^ "+boards[x]+" ("+(string)diff+").");
   tell_room(environment(this_player()),
      "%^YELLOW%^The board is now set to: %^RESET%^"+boards[x]+".",
      ({ this_player() }));
   ob->set_board_id(boards[x]);
   return 1;
}

int back() {
   write("%^YELLOW%^You are now reading:%^RESET%^ slink_ideas.");
   tell_room(environment(this_object()),
      "%^YELLOW%^The board is now set to:%^RESET%^ slink_ideas.");
   ob->set_board_id("slink_ideas");
   x = 0;
   return 1;
}

void query_access() {
   if (!access) write("Dragon Lord Inferno only.");
   else write("All others allowed.");
}

int set_access(int i) {
   if (this_player()->query_name() != "slinker") {
      write("Access denied.");
      return 1;
   }
   access = i;
}

void reset() {
 ::reset();
   if (!present("guardian"))
   if(!present("keg"))
      new("/wizards/slinker/guard")->move(this_object());
      new("/wizards/inferno/item/keg.c")->move(this_object());
}
mixed init() {
  ::init();
    if(this_player()->query_name() != "inferno" && !access)
{
      write("Access denied.");
      this_player()->move("/d/standard/square");
      return 1;
  }
   add_action("toggle", "toggle");
   add_action("next", "next");
   add_action("back", "back");
   add_action("ready", "ready");
   add_action("findHall", "hall");
}
int findHall(string str) {
   if (!str) {
      write("Syntax: <hall [class_hall]> : class_hall must be in
sindarii");
      return 1;
   }
   this_player()->move_player("/d/standard/"+str+"_hall", str);
   return 1;
}
int ready() {
   if (this_player()->query_name() !="deathshroud") return 0;
   write("You are mystically readied.");
  if (!present("teleporter", this_player()))
   new("/wizards/slinker/teleporter")->move(this_player());
//   new("/wizards/inferno/widget")->move(this_player());
   return 1;
}

int toggle() {
   if (this_player()->query_name() != "slinker") {
      write("Access denied.");
      this_player()->move("/d/standard/square");
      return 1;
   }
   if (!access) {
      access = 1;
      write("All others now allowed.");
      return 1;
   }
   access = 0;
   write("Only Slinker allowed");
   return 1;
}
