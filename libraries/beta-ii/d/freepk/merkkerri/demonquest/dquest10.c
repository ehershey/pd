#include <std.h>
#include <dquest.h>
#include <daemons.h>
#include <locations.h>
inherit ROOM;
void init() {
    ::init();
    add_action("pray_asmodeus", "pray");
    add_action("surrender_soul", "surrender");
    add_action("salvation", "ask");
}
void create() {
    ::create();
    set_short("A cave lit by several torches");
    set_long("%^BOLD%^%^BLACK%^You stand before a strange altar of black stone.  An oozing black liquid boils slowly within it.  It is here that followers of Asmodeus come to pray to the Lord of Demons.%^RESET%^");
    set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
    set_exits(([
      ]));
    set_items(([
        "altar": "The alter is unlike anything you have ever seen.  It almost seems to pulsate with a life of its own.",
        "liquid": "The liquid seems to be alive.  It reacts to your movement.",
        "torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
        "walls": "The cave walls are rough and jagged yet the floor is strangely smooth.",
      ]));
}
void reset() {
    ::reset();
    if(present("avatar")) present("avatar")->remove();
}
int pray_asmodeus(string what) {
    if (what!="to asmodeus")return 0;
    write("%^BOLD%^%^RED%^You pray to the Lord of Demons...  and he appears before you.%^RESET%^");
    if(!present("avatar")) {
        new(DQUEST "avatar.c")->move(this_object());
    }
    return 1;
}
int surrender_soul(string what) {
    string primary;
    if(what !="soul")return 0;
    if (this_player()->query_race()=="demon") {
        write("%^BOLD%^%^RED%^Do not mock ME demon.  Never forget who owns your soul...");
        return 1;
    }
    primary = IDENTITY_D->search_primary(this_player());
    if (primary && IDENTITY_D->query_setting(primary, "noquestrace")) {
      write("You may never become a quest race.");
      this_player()->move(SQUARE_LOC, "square");
      return 1;
    }
    if (this_player()->query_alignment() < -1000)
        if (this_player()->query_level() > 49)  {
            if (sizeof(this_player()->query_kills()) < 300) {
              write("%^BOLD%^%^RED%^YOU HAVE NOT SPILLED ENOUGH BLOOD YET!%^RESET%^");
              return 1;
            }
            write("%^BOLD%^%^RED%^You choose to surrender your soul to Asmodeus...%^RESET%^"
              "\n\n%^BOLD%^%^BLACK%^The flames of the Abyss burn upon your body causing you to scream in pain!\nWings rip through your back with a terrible bonecrushing sound!\nHorns emerge from your temples shreading the flesh around them!\nYour skin melts into a blackened leather shell of your former self!\n\n%^BOLD%^%^RED%^You have become a demon.%^RESET%^\n\n"
            );
            this_player()->add_exp(-(this_player()->query_exp()));;
            this_player()->set_stats("strength",(int)this_player()->query_base_stats("strength")*2/3);
            this_player()->set_stats("constitution",(int)this_player()->query_base_stats("constitution")*2/3);
            this_player()->set_stats("dexterity",(int)this_player()->query_base_stats("dexterity")*2/3);
            this_player()->set_stats("charisma",(int)this_player()->query_base_stats("charisma")/4);
            this_player()->set_stats("intelligence",(int)this_player()->query_base_stats("intelligence")/3);
            this_player()->set_stats("wisdom",(int)this_player()->query_base_stats("wisdom")/3);
            foreach (string st in this_player()->query_all_stats())
              if (this_player()->query_base_stats(st) < 1) this_player()->set_stats(st, 1);
            this_player()->set_level(1);
            this_player()->set_race("demon");
            this_player()->new_body();
              this_player()->clear_remort_sub_data(this_player()->query_subclass());
            this_player()->set_class("child");
            this_player()->set_subclass("none");
            this_player()->init_skills("child");
            this_player()->fix_vital_bonus();
            this_player()->set_mini_quest("demon", 1000, "You have completed your quest in becomming a demon.\n");
            new(DQUEST "amulet.c")->move(this_player());
            this_player()->set_primary_start(DQUEST "dquest115.c");
            write("%^RED%^%^BOLD%^You are now an evil force of this world.");
            write("%^BLUE%^%^BOLD%^ ***You are being forced to quit, please re-login***");
            this_player()->force_me("save");
            this_player()->force_me("quit");
            return 1;
        }
    if (this_player()->query_alignment() > -1000 ||
        this_player()->query_level() < 50)  {
        write("%^BOLD%^%^RED%^FOOL!  I have no use for you!%^RESET%^");
        this_player()->move_player(DQUEST "dquest5.c");
    }
    return 1;
}
