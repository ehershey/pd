inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Throne Room");
  set("long","The throne room is bustling with activity in preparation "
    "of the wedding between the Prince and Princess that is about to take "
    "place.  The lords are all gathered here and chat amongst themselves "
    "happily, while the servants run from guest to guest, making sure everyone "
    "has a wonderful time.");
  set_smell("default","The smell of a great feast permeates the air.");
  set_listen("default","The sound of people talking and making merry surrounds you.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the chandeleir in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps.",
    "throne":"This throne is reserved for the King of Tenebrae only.\nIt is just begging to be sat on, though.",
    "scratches":"At the base of the throne, you find the words 'Power of darkness, come consume me'"]));
  set_exits((["west":ROOMS "palace14.c"]));
}

void reset() {
  ::reset();
  if(!present("king")) {
    new(MOB "king")->move(this_object());
  }
  if(!present("queen")) {
    new(MOB "queen")->move(this_object());
  }
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());
    new(MOB "pknight")->move(this_object());
  }
  if(!present("dog")) {
    new(MOB "dog")->move(this_object());
  }
  if(!present("guest")) {
    new(MOB "guest")->move(this_object());
    new(MOB "guest")->move(this_object());
    new(MOB "guest")->move(this_object());
    new(MOB "guest")->move(this_object());
  }
  if(!present("servant")) {
    new(MOB "mservant")->move(this_object());
    new(MOB "mservant")->move(this_object());
    new(MOB "fservant")->move(this_object());
    new(MOB "fservant")->move(this_object());
  }
  if(!present("jester")) {
    new(MOB "jester")->move(this_object());
  }
  if(!present("mage")) {
    new(MOB "mage")->move(this_object());
  }
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
    if(!present("king")){
      if(this_player()->query("teneking")!=1){
        object ob, tp;
        tp = this_player();
        ob = present("crown", tp);
        if (ob && ob->query_worn()) {
          users()->set("teneking",0);
          this_player()->set("teneking",1);
          if(this_player()->query_gender() == "female") {
              write("You declare yourself Queen of Tenebrae!");
              message("info",this_player()->query_cap_name()+" has become queen of Tenebrae!",users(), this_player());
          }
          else {
              write("You declare yourself King of Tenebrae!");
              message("info",this_player()->query_cap_name()+" has become king of Tenebrae!",users(), this_player());
          }
          if(present("mage"))
          present("mage")->force_me("emote reads from an ancient scroll.");
          if(present("mage"))
          present("mage")->force_me("say The ancient scrolls say 'He who becomes King has the key to unlock the hidden power of darkness!'");
          write("About this time, you notice some small scratches at the base of the throne.");
          }
        else {
          write("You sit on the throne, but feel that something is missing...");
          }
        }
      else {
        write("You sit contentedly on your throne.");
        }
      }
    else {
      write("The king is sitting there, you fool!");
      }
    
  }
   return 1;
}
