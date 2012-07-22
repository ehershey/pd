#include <locations.h>
#include <std.h>
inherit ROOM;

int counter;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "no gate" : 1, "no teleport" : 1, "no scry" : 1]) );
    set_short("Nightshade's room");
    set_long(
      "%^BLUE%^You have entered Nightshade's room.  There is very "
      "little floor space, as it is covered in junk and dirty "
      "clothes.  A large flag is hung on the wall over the closet, "
      "and his dresser is covered in various knicnacks.");
    set_items(([
        "room" : "This room is a mess!",
        "flag" : "There is a 13 starred flag hanging up here, covering the closet.",
        "closet" : "You look into the closet, and see a huge gaping hole!",
        "dresser" : "It's covered in useless trinkets."
    ]));
    set_smell("default", "Despite the dirty laundry, it smells pretty good in here.");
    set_listen("default", "Any footsteps are softened by the clothes beneath.");
    set_exits( ([ 
        "square" :  SQUARE_LOC,
        "hall"  :  "/d/nopk/standard/adv_inner",
        "stormy"  :  "/wizards/stormbringer/workroom"
    ]) );
  new("/wizards/nightshade/bed.c")->move(this_object());
  counter = 0;
    
}

void init() {
  ::init();
  add_action("lookie","look");
  add_action("enter_hole", "enter");
  add_action("do_eval", "nseval");
}

int lookie(string str) {
  if(!str) {

    return 0;
  }
  if(str != ("bed" || "at bed")) {
    return 0;
  }
  write("The bed is nice and broken in...  Nightshade must get a lot of action.");
  this_player()->force_me("blush");
  return 1;
}

int enter_hole(string str) {
  if(!str)
    return notify_fail("Enter what?\n");
  if(str != "hole")
    return notify_fail("You cannot enter that.\n");
  write("You enter the closet and drop down into the hole carefully.");
  say(this_player()->query_cap_name()+" walks over to the closet and climbs down a large hole.");
  if(!counter) {
    call_out("tell_story", 2, this_player());
    this_player()->move(new(ROOM));
    this_player()->set_paralyzed(19, "Shhh..  just sit back and watch the story!");
  }
  return 1;
}

void tell_story(object tp) {
  switch(counter) {
    case 0:
      message("info", "You reach the bottom of the hole, and find yourself in the bottom of a deep pit.  One wall seems to have a strange glow to it.  You decide to investigate further...\n", tp);
      call_out("tell_story", 3, tp);
      break;
    case 1:
      message("info", "As you approach the wall, you notice it %^BOLD%^shimmer%^RESET%^ and grow %^BOLD%^%^BLACK%^transparent%^RESET%^.\n", tp);
      call_out("tell_story", 3, tp);
      break;
    case 2:
      message("info", "Cautiously, you reach out and touch the wall.  The tingle of magical energies gives you goosebumps all the way up your arm.  Your hand passes easily though the wall, surprisingly.\n", tp);
      call_out("tell_story", 4, tp);
      break;
    case 3:
      message("info", "You take a deep breath and step forward into the wall, closing your eyes as the wash of magical energy passes over you.\n", tp);
      call_out("tell_story", 4, tp);
      break;
    case 4:
      message("info", "You slowly open your eyes and find yourself in a completely new place...\n", tp);
      call_out("tell_story", 3, tp);
      break;
    case 5:
      tp->move_player("/wizards/nightshade/cave");
      counter = -1;
      break;
    default:
      message("info", "doh..  nightshade screwed up.  get him to help.", tp);
      tp->set_paralyzed(1);
  }
  counter++;
}

int do_eval(string str)
{
    if( this_player()->query_name() != "nightshade" )
        return 0;

    return "/cmds/system/_eval.c"->cmd_eval(str);
}
