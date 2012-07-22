inherit "/std/bboard";

static string *boards = ({
"forge_ideas",
"quixxiol_board",
"roston_board",
"High_Mortal",
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
"fighter_board",
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
"spell_idea"
});
static int x;

void create() {
 ::create();
   set_name("spell");
   set_id( ({ "board", "spell", "spell board" }) );
   set_board_id("spell_idea");
    set_max_posts(200);
//   set_location("/wizards/stormbringer/workroom");
   set_short("Spell Board");
   set_long("The Spell Board. <next> to next board, and "
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
   write("%^YELLOW%^You are now reading:%^RESET%^ spell_idea.");
   tell_room(environment(this_object()),
      "%^YELLOW%^The board is now set to:%^RESET%^ spell_idea.");
   set_board_id("spell_idea");
   return 1;
}

void init() {
 ::init();
   add_action("next", "next");
   add_action("back", "back");
}

