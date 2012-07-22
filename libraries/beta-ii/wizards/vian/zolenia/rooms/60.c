#include <std.h>
#include <zolenia.h>
inherit ROOM;
int zolking;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "The palace smells of clean stone.");
set_listen("default", "The palace is kept very quiet.");
set_short("Zolenia Palace");
set_long("%^BOLD%^%^BLACK%^This appears to be the end room of the palace, very quiet and still.  There is a large onyx throne sitting in the center of the back wall, made of shimmering onyx.  There are small pools of blood around the room.  The ground is made of polished onyx, containing a pathway leading toward the Valsharess and her throne, or back toward the city.");
set_items(([
({"ground", "blood", "pools", "pools of blood", "path"}) : "The ground contains a pathway which is made of polished onyx, leading back toward the city.  Small pools of crimson red blood are scattered throughout the room.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"walls", "wall"}) : "The walls in this room are adorned with precious and semiprecious gemstones.",
({"throne"}) : "The throne is very large and made of marbled onyx.",
]));
}
void reset() {
    ::reset();
    if(!present("valsharess")){
        new(MOB"valsharess")->move(this_object());
}
    if(!present("throne")){
        new(OBJ"throne")->move(this_object());
}
set_exits(([ "south" : ROOMS "59.c",
"southeast" : ROOMS "59e.c",
"southwest" : ROOMS "59w.c"]));
}
void init() {
  ::init();
  add_action("become_king","sit");
}
int become_king(string str) {
  if(!str) {
    notify_fail("Sit where?\n");
    return 0;
  }
  if((str != "on throne") && (str != "throne"))
    return notify_fail("Dont sit on that!\n");
  else {
    if(!present("valsharess")){
      if(this_player()->query("zolking")!=1){
        object ob, tp;
        tp = this_player();
        ob = present("rubyencrustedhelm", tp);
        if (ob && ob->query_worn()) {
          users()->set("zolking",0);
          this_player()->set("zolking",1);
          if(this_player()->query_gender() == "female") {
              write("You declare yourself Queen of Zolenia!");
              message("info",this_player()->query_cap_name()+" has become queen of Zolenia!",users(), this_player());
          }
          else {
              write("You declare yourself King of Zolenia!");
              message("info",this_player()->query_cap_name()+" has become king of Zolenia!",users(), this_player());
          }
          if(present("mage"))
          present("mage")->force_me("emote reads from an ancient scroll.");
          if(present("mage"))
          present("mage")->force_me("say The ancient scrolls say 'He who
becomes King has the key to unlock the hidden power of darkness!'");
          write("Your throne feels fairly comfortable.");
          }
        else {
          write("Your throne feels fairly comfortable.");
          }
        }
      else {
        write("Your throne feels fairly comfortable.");
        }
      }
    else {
      write("The Valsharess is sitting there, you fool!");
      }
    
  }
   return 1;
}
