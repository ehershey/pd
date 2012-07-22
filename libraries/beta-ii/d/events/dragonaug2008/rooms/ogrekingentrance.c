#include <std.h>
#include <dragonevent.h>
inherit ROOM;

int do_peer(string);

void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("The Ogre King's Throne Room");
    set_long("%^BOLD%^%^BLACK%^This is the great chamber before the ogre king's throne room. The ogre king has set a great spell upon the area, causing reality to tear and tremble. As many people can face the ogre king as they wish, but to them, it will seem as if they are the only ones there, and so they must proceed unaided. Proceed with caution.");
    set_exits( ([
      "up" : DRAG_ROOMS "ogre95",
      "enter" : DRAG_ROOMS "ogreking1",
    ]) );
    add_pre_exit_function("enter", "enter_ogre_throne");
}

void init() {
  ::init();
  add_action("do_peer", "peer");
}

int do_peer(string str) {
  if(str == "enter") {
    write("You cannot see far into the ogre king's throne room.");
    return 1;
  }
  return 0;
}

void message_further(object ob) {
  if(!ob) return;
 if(!environment(ob) || !environment(ob)->is_instanced()) return;
  message("info", "The ogre king's guards will begin rushing in at larger and larger numbers as time wears on. It's up to you to decide if you want to wait to attack the king until you have killed all the guards, which may appear in numbers too large to handle, or if you want to attack the king the moment the opportunity presents itself, damn the guards.", ob);
}

int enter_ogre_throne() {
  if(!DRAG_D->query_data("denyOgreKingThroneEntrance")) {
    if(DRAG_D->query_data("canKillOgreKing")) {
      write("Expecting an attack, the ogre king has surrounded himself with a staggeringly large number of his best men, and has cast a spell upon the area. If you wish to kill the ogre king, you're going to have to whittle down their numbers before they have a chance to regroup.");
      call_out("message_further", 25, this_player());
    }
    else {
      write("The ogres rush to the defense of the throne room, which serves as a memory to their dead king.");
    }
    DRAG_D->player_entered_ogre_king_instance(this_player()->query_name());
    this_player()->dismount_all("You seem to have become separated from your riders.", "You seem to have become separated from your mount.");
    return 1;
  }
  else {
    this_player()->move_player(DRAG_ROOMS"ogrethronedestroyed", "into the rubble");
  }
  return 0;
}

void reset() {
  object ob;
  ::reset();
  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}
