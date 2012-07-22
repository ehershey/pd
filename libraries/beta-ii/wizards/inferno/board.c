inherit "/std/bboard";

static string *boards = ({
"newbie",
"main_board",
"immortal",
"planning",
"arch",
"law",
"coding",
"ombud",
"kataan_board",
"rogue_board",
"monk_board",
"mage_board",
"cleric_board",
"monk_dark",
"monk_light",
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
"assassin",
"jester",
"theif",
"forge_ideas"
});
static int x;

void create() {
 ::create();
   set_name("forge");
   set_id( ({ "board", "forge", "iron board" }) );
   set_board_id("forge_ideas");
   set_max_posts(50);
//   set_location("/wizards/inferno/workroom");
   set_short("an iron board");
   set_long("The iron forge of Inferno. <next> to next board, and "
      "<back> will make this the iron forge again.");
}

int next() {
   int i;
   i = x - 1;
   if (i >= sizeof(boards)) x = 0;
   else x++;
   write("%^YELLOW%^You are now reading:%^RESET%^ "+boards[x]+".");
   tell_room(environment(this_object()),
      "%^YELLOW%^The board is now set to:%^RESET%^"+boards[x]+".");
   set_board_id(boards[x]);
   return 1;
}

int back() {
   write("%^YELLOW%^You are now reading:%^RESET%^ forge_ideas.");
   tell_room(environment(this_object()),
      "%^YELLOW%^The board is now set to:%^RESET%^ forge_ideas.");
   set_board_id("forge_ideas");
   return 1;
}

void init() {
 ::init();
   add_action("next", "next");
   add_action("back", "back");
}
