//     /d/standard/booth.c
//     from the Nightmare mudlib
//     voting booth
//     created by Gregon@Nightmare Jan 1994

#include <daemons.h>
#include <security.h>
#include <std.h>
#include <tirun.h>
#include <voting.h>
inherit ROOM;

int a,b;
static int tmp_clear;
mapping vote;

void create() {
    ::create();
    set("short", "Primal Darkness referendum room");
    set_property("light", 2);
    set_property("indoors", 1);
    set("long",
      "This is the referendum room of Primal Darkness.  Players come here to vote "
      "on issues that the wizards desire input on.  The current voting "
      "question is posted on the wall <read question> will display it."); 
    set_exits( (["down" : "/d/nopk/tirun/pubstart"]) );
    vote=([]);
    seteuid(UID_VOTESAVE);
    restore_object(DIR_VOTES+"/question");
    seteuid(getuid());
}
void init() {
    ::init();
    add_action("vote", "vote");
    add_action("read", "read");
    add_action("abstain", "abstain");
    if(wizardp(this_player())) add_action("check", "check");
    if(archp(this_player())) add_action("clear", "clear");    
}

int vote(string str) {
    string me;

    me=(string)this_player()->query_name();
    if(str!="a" && str!="b") {
        notify_fail("You may only vote for a or b.\n");
        return 0;
    }
    if(this_player()->query_level() < 5 && !wizardp(this_player())) {
        write("You are too small of an adventurer to partake in such events.");
        return 1;
    }
    if(MULTI_D->non_voter(me)) {
        write("You are listed as a second character.  You may not vote.");
        return 1;
    }
    if(vote[me]) {
        write("You have already voted.");
        return 1;
    }
    if(str=="a") {
        vote[me]="a";
        a++;
        write("Vote counted.  Thank you.");
        seteuid(UID_VOTESAVE);
        save_object(DIR_VOTES+"/question");
        seteuid(geteuid());
        return 1;
    }
    if(str=="b") {
        vote[me]="b";
        b++;
        write("Vote counted.  Thank you.");
        seteuid(UID_VOTESAVE);
        save_object(DIR_VOTES+"/question");
        seteuid(geteuid());
        return 1;
    }

}

int read(string str) {
    if(!str || str != "question") return 0;
    write("The current voting question is this:\n\n"
    "Would you like to see a \"High Council\" in which players\n"
    "would discuss mud related matters as a council with voting\n"
    "powers on such items as some law and PR."
    "\n\na) Yes\nb) No\n"
      "\nTo vote for one of these choices, type <vote a> or <vote b>.  Of "
      "course you may only vote once, and seconds are not allowed to vote.  "
      "You may also <abstain> your vote if you change your mind."
    );
    return 1;
}

int check(){
    write("A: "+a+"\nB: "+b);
    return 1;
}

int clear() {
    if(!tmp_clear) {
        write("Type clear again to clear the votes.");
        tmp_clear=1;
        return 1;
    }
    vote=([]);
    a=0;
    b=0;
    write("Vote counted.  Thank you.");
    seteuid(UID_VOTESAVE);
    save_object(DIR_VOTES+"/question");
    seteuid(geteuid());
    write("Vote system cleared.");
    return 1;
}

int abstain(string s) {
   if(s != "vote") return notify_fail("Abstain what?\n");
   if(!vote[this_player()->query_name()]) return notify_fail("You have not yet
voted.\n");
   switch(vote[this_player()->query_name()]) {
      case "a":
        a--;
        break;
      case "b":
        b--;
        break;
      default:
        write("Unknown execution.\n");
        return 1;
        break;
   }
   map_delete(vote, this_player()->query_name());
   write("You vote has been removed.\n");
   return 1;
}
