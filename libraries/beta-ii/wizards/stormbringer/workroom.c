#include <locations.h>
#include <locations.h>
#include <std.h>
#include <daemons.h>
inherit ROOM;
 
int cmd_start(string str);
 
object ob;
void init()
{
    ::init();
    add_action("cmd_start", "start");
}
void create() {
 ::create();
    set_properties( ([ "light" : 3]) );
    set_properties( ([ "no gate" : 1]) );
    set_short("High above the realms. Stormbringers place.");
    set_long(
    "%^CYAN%^The sun shines high above this place. Lazy white clouds float "
    "%^CYAN%^by on their journey to wherever it is that clouds go. Far "
    "%^CYAN%^below, a town can be seen, though it is much to far to tell "
    "%^CYAN%^what town. This must be the home of Stormbringer, only he "
    "%^CYAN%^would feel at home this far above the world where storms rule "
    "%^CYAN%^the air.%^RESET%^"
    );
    set_night_long(
    "%^BOLD%^%^BLUE%^The sister moons loom large in the sky. Millions of stars can " 
    "%^BOLD%^%^BLUE%^be seen this high above the world. Far below, the lights of a "
    "%^BOLD%^%^BLUE%^town can be seen, though it is much to far to tell what town. "
    "%^BOLD%^%^BLUE%^This must be the home of Stormbringer, only he would feel at "
    "%^BOLD%^%^BLUE%^home this far above the world where storms rule the air.%^RESET%^"
    );
    set_name("Storm Room");
    set_smell("default", "Ozone fills your nostrals.");
    set_listen("default", "The silence of solitude.");
    set_exits( ([ 
         "eventroom" :  "/wizards/stormbringer/room/eventroom.c",
         "down" :  SQUARE_LOC,
         "pub" :  "/d/nopk/tirun/pubstart",
         "range"  :  "/wizards/stormbringer/room/newhouse.c",
        "hall"  :  "/d/nopk/standard/adv_inner",
         "seekerw"  :  "/wizards/seeker/workroom",
         "whitw"  :  "/wizards/whit/workroom",
         "wraithw"  :  "/wizards/wraith/workroom",
         "infernow"  :  "/wizards/inferno/workroom",
         "danovaew"  :  "/wizards/danovae/workroom",
         "nightshadew"  :  "/wizards/nightshade/workroom",
         "guildmeet"  :  "/d/guilds/meeting",
    ]) );
    ob = new(BBOARD);
    ob->set_name("spell");
    ob->set_location("/wizards/stormbringer/workroom");
    ob->set_id( ({ "board", "spell", "spell board" }) );
    ob->set_board_id("spell_idea");
    ob->set_max_posts(99);
    ob->set_short("Spell Board");
    ob->set_long("The Spell Board.");
   }
void reset() {
 ::reset();
   if (!present("box"))
      new("/wizards/stormbringer/box")->move(this_object());
  if (!present("portal"))
      new("/wizards/stormbringer/portal")->move(this_object());
  }
int cmd_start(string str)
{
    if (!str || str=="") 
    {
        notify_fail("Start where?\n");
        return 0;
    }
    if (str!="here")
    {
        notify_fail("You cannot start there.\n");
        return 0;
    }
    this_player()->set_primary_start("/wizards/stormbringer/workroom");
    write("You are now set to start here.");
    return 1;
}
