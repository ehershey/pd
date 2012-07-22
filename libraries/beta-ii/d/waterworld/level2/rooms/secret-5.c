/// Rooms for Tirun's Barrier reef
///       written by Ironman

//
#include <std.h>
#include <waterworld.h>

inherit ROOM;

object board;
object tourtoise;
int score_check();
int wizard_info();
int list_prizes();

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear the sound of candles flickering softy.");
  set_listen("quessalaz","Quessalaz says in a soft voice,'I know a great deal about alot of legends. You should listen to some of them if you have the time.'");
  set_listen("quessalaz about legends","Quessalaz swims to rest on one of his podiums, smiles and says,'So which legend do you wish to know about?? I know about the following topics;"
   "\n\n     BLOOD pearl"
   "\n      Atlantis"
   "\n     Lord Poseidon"
   "\n\n Which one do you wish to listen to me about young one??");
  set_listen("quessalaz about BLOOD pearl","Quessalaz grins widely (I didn't even know a tortoise had lips no less could grin) and says, 'The BLOOD pearl is the rarest of the rare pearls. It's was allegedly created when an immortal cut themselves on the vat that Lord Poseidon was using to make the Pearls.'");
  set_listen("quessalaz about atlantis","Quessalaz sighs heavily and says,'That city is hidden someplace along the ocean floor. I know there is a history in a room hidden someplace to the east of my cavern if you wish to learn more.");
  set_listen("quessalaz about Lord Poseidon","Quessalaz swims over to his seagrass patch and starts munching as he says,'Lord Posiden is the ruler of Atlantis. He is a very benevolent leader with a short temper. Legend has it that General Kraken, Admiral Man-o-war and Posiden totally decimated the forces of Trydryill..... alone....'");
  set_listen("quessalaz about shots","Quessalaz snickers softly and says,'They are called Speedy Tourtoise young travellers.'"),
  set_listen("quessalaz about speedy tourtoise","Quessalaz winks at ya fondly and says,'That is one of my favorite drinks!! My friend Pelican Pete can mix ya up a few if you go ask him.'\n\n With that he goes and grabs a few shots from his stash and starts drinking them.\n\n");
  set_smell("default","It's been the home of a turtle for over 500 years.  It smells like a moldy old turtle....");
  set_smell("shots","Now THAT smells like some POTENT drinks!! Wonder where people can get some??");
  set_long(
   "This is the personal abode of Quessalaz, the record keeper of the Tirun Reef."
   " This room is competely underwater but nothing is behaving that way."
   " The walls are lined with books on nearly every topic imaginable."
   " There is an Acme brand 'shell buff-o-matic' set up in one corner."
   " Several large podiums are sitting in the middle of the room around a large table."
   " A large vat of seagrass lines the far wall of the cavern."
   " There area several fresh shots lined up on the table."
   " A large %^RED%^sign%^RESET%^ is staked into the ground at the entrance."
  );

  set_exits(([
    "out":ROOMS2"room-2b5.c"
   ]));
  set_items(([
    "books":"Despite being totally submerged in water, they're in immaculate condition.",
    "buff-o-matic":"The lable reads,'Use twice daily for that deep down turtle-fresh feeling all day long.' It looks to be in working order.",
    "podium":"These are Quessalaz's 'chairs'. He and his turtle friends simple lay their shells on them.",
    "shots":"It's a custom made drink for Quessalaz. Maybe you can listen to him about shots",
    "sign": (: wizard_info :),
    "prizes": (: list_prizes :),

    "seagrass":"That is Quessalaz's 'refrigerator' filed with grubs, worms, slugs and snails."
   ]));
  new(PEARLS"blood_clam.c")->move(this_object());

  // board id's

  board = new("std/bboard");
  board-> set_name("trivia board");
  board-> set_board_id("trivia board");
  board-> set_id(({"trivia board","board","trivia"}));
  board-> set_max_posts(100);
  board-> set_edit_ok(({"daos","whit","daboura","nesoo","ironman","durst"}));
  board-> set_location(ROOMS2"secret-5.c");
  board-> set_short("Quessalaz's Trivia Board");
  board-> set_long("\n\nQuessalaz's Trivia Board.\n\n");
}
// Mob regeneration
void reset() {
  ::reset();
  if(!present("monster",this_object())) {
    tourtoise=new(TRIVIA"quessalaz.c");
    tourtoise->move(this_object());

  }
}

int score_check(string pname) {
  object turtle;
  int score;

  reset();
  if(tourtoise) {score=tourtoise->inquiry(pname); }

  return score;
}

int wizard_info() {
  object TP=this_player();

  if(!archp(TP)) {
    if(!wizardp(TP)) {
      message("info",
       "\n\n        This is the humble home of Quessalaz, the Tourtoise."
       "\n\n                       %^CYAN%^Welcome "+(TP->query_cap_name())+"%^RESET%^\n\n"
       "    There are %^ORANGE%^several%^RESET%^ prizes to be won from Quessalaz's trivia.\n"
       "   They are hidden throughout the barrier reef. However, they won't\n"
       "   be available in their hidding spots until you have answered enough\n"
       "   questions for Quessalaz.\n"
       "\n %^RED%^%^BOLD%^                  Take special notice "+(TP->query_cap_name())+"%^RESET%^\n\n"
       "    Quessalaz and all his prizes are a %^BLACK%^%^BOLD%^QUEST%^RESET%^ and as such\n"
       "   are under the protection of the quest-informantion rules!!\n"
       "       Discussing the questions and answers is permitted.\n"
       "       Discussing the prizes, their locations, trading/selling them\n"
       "   and any other information pertaining to them is protected!!\n\n"
       ,TP);
      return 1;
    }}

  message("info",
   "\n\nSeveral functions have been installed on Quessalaz to be used with call."
   "\n\n    %^YELLOW%^call quessalaz;check_up;<string with player's name>%^RESET%^"
   "\n\n          %^CYAN%^%^BOLD%^This function allows you to inspect the player's records with Quessalaz."
   "\n\n    %^YELLOW%^call quessalaz;give_credit;<string with player's name>%^RESET%^"
   "\n\n         %^CYAN%^%^BOLD%^This allows you to give credit to the player if you feel their answer was what Quessalaz was asking about..."
   "\n\n    %^YELLOW%^call quessalaz;remove_player;<string with player's name>%^RESET%^"
   "\n\n        %^CYAN%^%^BOLD%^This function allows you to destroy the records Quessalaz has about a player!!!"
   "%^RED%^%^BOLD%^Do NOT abuse this function. %^CYAN%^%^BOLD%^It is here primarily so Primal Darkness can clean-up a player's records when they suicide or get rid/banished from the realm."
   "\n\n    %^YELLOW%^call quessalaz;summary_report%^RESET%^"
   "\n\n        %^CYAN%^%^BOLD%^This function returns a report of ALL players that have records with Quessalaz."
   "\n\n %^RED%^%^BOLD%^NOTE --%^RESET%^  (1) Be sure to enclose the players name with quotes to make it a string..\n\n"
   "          (2) Type %^BLACK%^%^BOLD%^look prizes%^RESET%^ to get a listing of the prizes, locations and point-levels\n\n"
   ,TP);
  return 1;
}
int list_prizes() {
  object TP=this_player();
  string cap_tp=TP->query_cap_name();

  if(!archp(TP)) {
    if(!wizardp(TP)) {
      message("info",
       "\n\n There are several very powerful Atlantian Artifacts hidden through the Barrier Reef. However, the illusions that guard these prizes will not be lowered by Quessalaz until you have gained enough points with him...."
       ,TP);
      return 1;
    }}
  message("info",
   "\n\n                            %^GREEN%^%^BOLD%^Prize list%^RESET%^\n"
   "      %^RED%^PRIZE                   ROOM            QUESTIONS NEEDED\n"
   "--------------------------------------------------------------------%^RESET%^\n"
   "\n  Atlantian Ambrosia       secret-5.c                200\n"
   "  Coat-of-arms             secret-4.c                175\n" 
   "  Valor_gloves             secret-6b.c               150\n"
   "  Helm-of-honor            secret-3b.c               125\n" 
   "  Spirit Bracer            secret-6d.c               100\n"
   "  Soul Bracer              secret-8a.c                75\n"
   "  Bargaining gloves        secret-7a.c                50\n"
   "\n\n %^CYAN%^SPECIAL NOTICE --%^RESET%^ THe Atlantian ambrosia is a one time prize.\n\n"
   ,TP);
  return 1;
}
