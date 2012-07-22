#include <std.h>
inherit ROOM;

void create() {
object board;
room::create();
     add_pre_exit_function("infernow","go_stairs");
     add_pre_exit_function("acheron","go_stairs");
     add_pre_exit_function("square","go_stairs");
     add_pre_exit_function("hall","go_stairs");
     add_pre_exit_function("darksoul","go_stairs");
     add_pre_exit_function("unholy","go_stairs");
     add_pre_exit_function("forsaken","go_stairs");
     add_pre_exit_function("illuminati","go_stairs");
     add_pre_exit_function("AoD","go_stairs");
     add_pre_exit_function("blackforce","go_stairs");
     add_pre_exit_function("chosen","go_stairs");
     add_pre_exit_function("arena","go_stairs");
     add_pre_exit_function("lodos","go_stairs");
     add_pre_exit_function("tenebrae","go_stairs");
     add_pre_exit_function("roston","go_stairs");
     add_pre_exit_function("drows","go_stairs");
     add_pre_exit_function("merkcamp","go_stairs");
     add_pre_exit_function("gcity","go_stairs");
     add_pre_exit_function("purgatory","go_stairs");
     add_pre_exit_function("helgrath","go_stairs");
   set_properties( ([ "light" : 2, 
                      "indoors" : 1,
                      "no teleport" : 1,
                      "no snoop" : 1]) );
    set_short("Principal`s office");
    set_long("%^BOLD%^%^RED%^The Principal`s Office\n"
"%^BOLD%^%^BLACK%^You have entered Wraith`s office. A rather large desk made "
"%^BOLD%^%^BLACK%^from one humoungous tree sits in the middle of the room. "
"%^BOLD%^%^BLACK%^Trophies from Wraith`s most recent decisions hang on the "
"%^BOLD%^%^BLACK%^wall."
    );

    set_smell("default", "An odd smell of burning water is in the air.");
    set_listen("default", "A whimpering sound floats around.");
    set_exits( ([ 
        "helgrath" : "/d/helgrath/rooms/wilndursquare",
        "purgatory" : "/d/purgatory/room/purgatorysquare",
        "infernow" : "/wizards/inferno/workroom",
        "square" :  "/d/tirun/square",
        "acheron" : "/d/guilds/acheron/hall",
        "hall"  :  "/d/standard/adv_inner",
        "darksoul" : "/d/guilds/darksoul/hall",
        "unholy" : "/d/guilds/unholy/hall",
        "scorpio" : "/d/guilds/scorpio/hall",
        "forsaken" : "/d/guilds/forsaken/hall", 
        "illuminati" : "/d/guilds/illuminati/hall", 
        "AoD" : "/d/guilds/AoD/hall",
        "DW"  : "/d/guilds/dw/hall",
        "chosen" : "/d/guilds/chosen/hall", 
        "arena" : "/d/arena/bet",
        "lodos" : "/d/lodos/square",
        "tenebrae" : "/d/shadow/rooms/tene10",
        "roston" : "/d/roston/rooms/roston",
        "drows" : "/d/roston/drow/room/room4",
        "merkcamp" : "/d/merkkerri/jungle/merkkirri/mjungle13",
        "gcity" : "/d/merkkerri/jungle/gcity/gcity6"]) );
    set_items(([ "desk" : "Papers and reports on unruly people are piled high on this desk." ]));
board = new("/std/bboard");
board->set_board_id("The_principals_board");
board->set_id(({"board", "principals board"}));
board->set_name("The Principals Board");
board->set_short("The Principals Board");
board->set_long("This board was made to post mud ideas by trusted players and imms.");
board->set_location("/wizards/wraith/workroom.c");
board->set_edit_ok(({"wraith"}));
board->set_max_posts(200);
board->set_board_name("Principal's board");

}
int go_stairs() {
  if(!wizardp(this_player())) return 0;
 return 1;}
void reset() {
 ::reset();
   if (!present("box"))
      new("/wizards/seeker/box")->move(this_object());
   if (!present("picture"))
      new("/wizards/wraith/picture")->move(this_object());
//   if (!present("list"))
//      new("/std/obj/player_list")->move(this_object());

  }

void init() {
    ::init();
    add_action("look_wall", "look");
}

int look_wall(string str) {
    if(!str) {
        notify_fail("look at what?\n");
        return 0;

    }
    if(str != "wall") {
        notify_fail("You can't see that!\n");
        return 0;
    }
    
   write(@ENDTEXT

%^BOLD%^%^WHITE%^                               ,-.
%^BOLD%^%^WHITE%^          ___,---.__          /'|`\          __,---,___
%^BOLD%^%^WHITE%^       ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
%^BOLD%^%^WHITE%^     ,'        |           ~'\     /`~           |        `.
%^BOLD%^%^WHITE%^    /      ___//              `. ,'          ,  , \___      \
%^BOLD%^%^WHITE%^   |    ,-'   `-.__   _         |        ,    __,-'   `-.    |
%^BOLD%^%^WHITE%^   |   /          /\%^BOLD%^%^RED%^_ %^RESET%^ `   %^RESET%^.    |    ,      %^BOLD%^%^RED%^_%^RESET%^/%^RESET%^\         %^BOLD%^%^RED%^ \   |
%^BOLD%^%^WHITE%^   \  |          %^RESET%^ \ %^BOLD%^%^RED%^\`-.___ %^RESET%^\   |   /%^BOLD%^%^RED%^ ___,-'/ %^RESET%^/          %^BOLD%^%^RED%^ |  /
%^BOLD%^%^WHITE%^   %^BOLD%^%^RED%^ \  \ %^RESET%^          | %^BOLD%^%^RED%^`._   `\%^RESET%^\  |  /%^BOLD%^%^RED%^/'   _,' %^RESET%^|         %^BOLD%^%^RED%^  /  /
%^BOLD%^%^WHITE%^    %^BOLD%^%^RED%^  `-.\%^RESET%^         /'  _ %^BOLD%^%^RED%^`---'%^RESET%^' , . `%^BOLD%^%^RED%^`---' %^RESET%^_  `\        %^BOLD%^%^RED%^ /,-'
%^BOLD%^%^WHITE%^     %^BOLD%^%^RED%^    ``%^RESET%^       /     \    ,='/ \`=.    /     \       ''
%^BOLD%^%^WHITE%^                |__   /|\_,--.,-.--,--._/|\   __|
%^BOLD%^%^WHITE%^                /  `./  \\`\ |  |  | /,//' \,'  \
%^BOLD%^%^WHITE%^               /   /     ||--+--|--+-/-|     \   \
%^BOLD%^%^WHITE%^              |   |     /'\_\_\ | /_/_/`\     |   |
%^BOLD%^%^WHITE%^               \   \__, \_     `~'     _/ .__/   /
%^BOLD%^%^WHITE%^                `-._,-'   `-._______,-'   `-._,-'
ENDTEXT);


   return 1;
}

