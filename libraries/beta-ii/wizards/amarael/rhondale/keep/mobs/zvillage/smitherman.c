#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

int once;
void create() {
   ::create();
     set_name("old adventurer");
     set_id( ({"man", "adventurer", "scholar", "smithxzor"}) );
     set_short("Old man");
     set_long("The old man appears to be the sole occupant of this house, and rather messy by the state of the place. He is constantly searching through the piles and piles of junk and muttering about a map");
     set_race("human");
     set_gender("male");
     set_body_type("human");
     set_level(70);
     once = 0;
}

void init() {
     object tp;
     tp = this_player();
   ::init();
     add_action("sayin", "say");
     add_action("givin", "give");
     if( present("lyfralace", this_player() ) && member_array("kratoan", this_player()->query_quests()) == -1 && once == 0) { call_out("do_say", 1, tp); once = 1; }
}

void catch_tell(string str) {
        string mappin, tpname;
        object ob;
        if(sscanf(str, "%s gives you a %s", tpname, mappin) == 2) {
          if(!(ob=present("mapxzor", this_object()))) return;
          command("say Thank you for returning this to me my friend.");
          command("say Perhaps... you would like to do something for me? Please say yes.");
          }
}

int sayin(string str) {
    object ob;
        if(member_array("kratoan", this_player()->query_quests()) != -1) return 0;
        if(strsrch(str, "yes") != -1) {
          if(!(ob=present("mapxzor", this_object()))) return;
          command("say Hah! Excellent. Now, listen carefully.");
          command("say This is a very special map indeed my friend. It shows a path I have found through this very forest that shall take you to a hidden place... The Kra'toan village.");
          command("say Shh Shh! Calm down. Take this map and follow it, when you reach the spot I have marked, kneel, and the way shall lie before you.");
          command("say Then I want you to retrieve something for me, something of power. An amulet it is, and undoubtedly well guarded. I don't care how you get it, just bring it to me.");
          message("info", "The old man unties the leather cord and hands you the map.", this_player(), );
          message("info", "The old man unties the leather cord from a map and hands it to "+this_player()->query_cap_name()+".", environment(this_object()), ({ this_object(), this_player() }));
          new(KEEPARMOUR"zvillage/realmap.c")->move(this_player());
          ob->remove();
          return 1;
          }
        return 0;
}

int givin(string str) {
    if(!present("lyfralace", this_player())) return 0;
    if(str != "amulet to man" && str != "lyfralace to man" && str != "leaf amulet to man") return 0;
    if(member_array("kratoan", this_player()->query_quests()) != -1) return 0;
    present("lyfralace", this_player())->move(this_object());
    message("info", "You give the Leaf Amulet to the man.", this_player(), );
    message("info", this_player()->query_cap_name()+" gives "+this_player()->query_possessive()+" Leaf Amulet to the man.", environment(this_object()), this_player() );
    command("Ah, finally I have it. Thankyou, "+capitalize(this_player()->query_name())+", for helping me with this. Here, your reward.");
    new(KEEPARMOUR"zvillage/questcoin.c")->move(this_player());
    message("info", "The man gives you a gold coin.", this_player(), );
    this_player()->set_manual_quest("kratoan");
    message("quest", "You feel experienced for your troubles.", this_player(), );
    return 1;
}

void do_say(object tp) {
     once = 0;
     command("look "+this_player()->query_name());
     if(tp->query_property("killersmark") == 1) {
       command("say You have it! Excellent! You... you had to kill them for it didn't you?");
       command("emote sighs heavily.");
       command("say That is unfortunate, but acceptable considering the rewards. Here, give it to me and I shall give you something in return.");
       return;
       }
     else {
       command("say Amazing, you have it! I can hardly believe they would just give it up... You didn't kill anyone for it did you?");
       command("emote waves his hand dismissively.");
       command("say Hah, of course not, why would I even think it. Remarkable it is though that you gained their trust. Here, give it to me and I shall give you something in return.");
       return;
       }
}
