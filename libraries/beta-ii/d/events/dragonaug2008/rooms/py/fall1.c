#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/fallbase";

void set_long(string str) {
  ::set_long(str+"%^RESET%^\n\n"+
    (query_night() ?
      ("/cmds/mortal/_look.c"->sky("moon")) :
      ("/cmds/mortal/_look.c"->sky("sun")) )
    );
}

void new_player(object ob) {
  set_long("Extremely high in the sky, to an extent that the ground far below is not visible.");
}

void init() {
  ::init();
  add_action("grab_branch", ({"get", "grab"}));
}

void heart_beat() {
  int i;
  ::heart_beat();
  if(!player()) return;

  //time triggers
  switch(beats()) {
    case 4:
      SAY("%^BOLD%^A puffy white cloud comes into view below you.");
      set_long("There is a puffy white cloud below.");
      break;
    case 6:
      if(random(1000) < 350) {
        SAY("You fall through the cloud, punching a small hole in it.");
        set_long("A cloud with a large hole in it drifts slowly by above.");
      }
      else {
        SAY("You fall quickly past the cloud.");
        set_long("A cloud drifts slowly by above.");
      }
      break;
    case 10:
      SAY("The cloud above fades out of view.");
      set_long("");
      break;
    case 15:
      SAY("The sky below you seems to darken as the ground far below slowly fades into view.");
      set_long("Far below, the sky turns a faint green color as the ground begins to fade into view.");
      break;
    case 17:
      SAY("As you continue to fall, the ground comes closer and closer, such that you can now see it clearly. It seems to be composed of a thick forest, which stretches out in every visible direction below as far as you can see.");
      set_long("A thick forest lays below you. It seems made of nearly every type of brush and foliage that there is.");
      break;
    case 21:
      SAY("As you fall closer and closer to the ground, one tree straight below you seems to be coming up at you much faster than all the surrounding trees.");
      set_long("There is a large forest below you that spans as far as you can see. One tree in particular directly below you seems to be much larger than the others.");
      break;
    case 25:
      SAY("You fall further towards the forest.\nSome branches on the large tree below you stick out towards you.");
      set_long("There is a large tree directly below you. Large branches on the side of the tree closest to you stick out into the air.");
      break;
    case 28:
      SAY("You fall past the tip of the tree. Large branches stick out from the tree, reaching towards you.");
      set_long("There is a large tree directly in front of you. Large branches stick out of the tree.");
      break;
    case 30:
      i = random(3)+1;
      SAY(capitalize(cardinal(i))+" of the branches on the tree scratch past you, %^BOLD%^%^RED%^gashing%^RESET%^ you deeply.");
      if(!harm_player(player(), (player()->query_max_hp()*0.12)*i)) return;
      break;
    case 33:
      SAY("You %^ORANGE%^slam%^RESET%^ into a large branch.");
      if(!harm_player(player(), player()->query_max_hp()*0.6)) return;
      SAY("You slide off the branch and continue your fall.");
      break;
    case 37:
      SAY("You are falling towards a large, pointed rock.");
      set_long("You are surrounded by large trees. There is a large, pointed rock below you.");
      break;
    case 38:
      SAY("You are %^RED%^IMPALED%^RESET%^ on the rock.");
      if(!harm_player(player(), player()->query_max_hp()*5)) return;
      player_death(player());
      break;
  }
}

int grab_branch(string str) {
  if(str != "branch" && str != "branches"
    && str != "tree") return 0;

  if(beats() < 24) {
    if(beats() < 21) return 0;
    write("That is too far below you for you to be able to reach it.");
    return 1;
  }
  if(beats() >= 30) {
    write("That is too far above you for you to be able to reach it.");
    return 1;
  }

  if(str == "tree") {
    write("You try to grab the base of the tree and get whacked by a branch.");
    harm_player(this_player(), this_player()->query_max_hp()*0.01);
    return 1;
  }

  write("You reach out and grab the branch. It bends with the force of your weight and launches you towards the center of the tree!");
  this_player()->move_player(DRAG_ROOMS"py/fall2", "into the tree");
  return 1;
}
