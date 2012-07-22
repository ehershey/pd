#include <std.h>
#include <voting.h>
#include <daemons.h>
#include <radyne.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 1);
    set_property("no castle", 1);
    set_property("indoors", 1);
    set("short", "Voting hall of the fighters");
    set("long", (: this_object(), "new_long" :));
    set_items(
        (["list" : "During election time, it lists all candidates."]) );
    set_exits( 
              (["west" : ROOMS"fighter_hall"]) );
}
void init() {
  ::init();
    if((int)this_player()->query_level() < 2) return;
    add_action("vote", "vote");
    add_action("read", "read");
    add_action("enter", "enter");
}
int vote(string str) {
    int x;
    if(!VOTING_D->election_day()) {
        notify_fail("You will have to wait until "+NEXT_ELECTION+".\n");
        return 0;
    }
    x = (int)VOTING_D->register_vote((string)this_player()->query_name(),
      str, (string)this_player()->query_class());
    switch(x) {
      case VOTE_OK:
        write("Your vote has been registered.");
        say(this_player()->query_cap_name()+" registers "+
            this_player()->query_possessive()+" vote.");
        break;
      case VOTE_ERROR:
        write("Bad entry.  Try again.");
        break;
      case NOT_RUNNING:
        write("That person is not running.  Vote for someone else.");
        break;
      case ALREADY_VOTED:
        write("You have already voted twice!");
        break;
      case BAD_VOTE:
        write("You can only vote for a candidate once.");
        break;
      default: write("Bad entry: "+ x+".");
    }
    return 1;
}
int enter(string str) {
    int x;
    if(!str || str != "race") return 0;
    if(!VOTING_D->election_day()) {
        notify_fail("It is not yet time to enter the next election.\n");
        return 0;
    }
    x = (int)VOTING_D->register_candidate(
        (string)this_player()->query_name(), (string)this_player()->query_class()
    );
    switch(x) {
        case VOTE_ERROR: write("Bad entry.\n Try again."); break;
        case ALREADY_RUNNING: write("You are already running!"); break;
        case VOTE_OK:
            write("You enter the race.");
            say(this_player()->query_cap_name()+" enters the race.", 
                this_player());
            break;
        default: write("Bad entry. Try again."); 
    }
    return 1;
}
int read(string str) {
    string *who;
    int i;
    if(!str || (str != "list" && str != "candidates") ) return 0;
    if(!VOTING_D->election_day()) {
        notify_fail("It is not currently time for elections.\nNext election time: "+NEXT_ELECTION+".\n");
        return 0;
    }
    who = (string *)VOTING_D->query_candidates((string)this_player()->query_class());
        write("You may vote for any two of the following candidates:\n");
    for(i=0; i<sizeof(who); i++) {
        if(who[i]) write(capitalize(who[i])+"\n");
    }
    write("<vote [name]> votes\n");
    write("<enter race> enters yourself into the race\n");
    return 1;
}
string new_long() {
    if(VOTING_D->election_day()) 
      return "This is the voting chamber of the Hall of Fighters.  "
      "Fighters come here during this election time to vote on their "
      "class leadership.  A current list of candidates is posted on the wall.";
    else return "This is the voting chamber of the Hall of Fighters.  "
      "Fighters will gather here for the next election: " NEXT_ELECTION ".";
}
