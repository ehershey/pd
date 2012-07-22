
#include <std.h>
#include <security.h>
#include <dirs.h>
#include <tirun.h>

inherit ROOM;

int query_voted(string ip);
void add_voted_ip(string ip);
void add_current_vote(string word, int amt);
int cmd_vote(string str);
int cmd_query(string str);
int cmd_clear(string str);
void saveme();
void restoreme();

string *voted_ips;
mapping current_votes;

// first choice worth 2 points, second choice worth 1 point
static int *VOTE_POINTS = ({ 2, 1 });

string CURRENT_ISSUE = @END
Please vote for the order in which to have subclasses worked on.
You may also vote for 'dragon' or 'vampire'.
You get two votes, the primary vote will receive 2 points and the secondary
vote will receive 1 point. The end results will be tallied based on points.

Examples:
<vote druid dragon> Will vote for druids as your primary and dragons second.
<vote wizard> Will vote for wizards as your primary and give no secondary.

Please note that you get to vote once per *player*, NOT per character.
END;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "no attack" : 1, "no steal" : 1 ]) );
  set_short("Voting room");
  set_long(
    "This austere room is lined with booths along both sides. A dark rug "
    "runs up the middle of the floor. Between voting booths, there are some "
    "plain wooden chairs for waiting. Lamps on the walls are lit for "
    "nighttime gatherings.\n"
    "A small posting on the wall explains the current issues."
  );
  set_items( ([
    "booths" : "Wooden booths with tall walls and curtains.",
    "rug" : "The rug is dark brown and runs the length of the room.",
    "chairs" : "They have been sanded and stained a light brown, but there "
      "is nothing remarkable about them.",
    "lamps" : "The lamps are lit to provide light when people must "
      "come vote at night.",
    "posting" : (: this_object()->query_read("posting") :),
  ]) );
  set_read( ({ "default", "post", "posting" }), CURRENT_ISSUE );
  set_exits( ([
    "down" : ROOMS+"pubstart",
  ]) );
  restoreme();
}

void init() {
  ::init();
  add_action("cmd_vote", "vote");
  if (wizardp(this_player()))
    add_action("cmd_query", ({ "check", "query" }) );
  if (archp(this_player()))
    add_action("cmd_clear", ({ "clear", "erase" }) );
}

int cmd_vote(string str) {
  object tp = this_player();
  string *words;

  return notify_fail("Voting has ended.");

  if (!str)
    return notify_fail("Vote for what?");

  if (query_voted(query_ip_number(tp)))
    return notify_fail("A vote from your IP has already been registered.");

  add_voted_ip(query_ip_number(tp));

  words = explode(lower_case(str), " ");

  for (int i = 0; i < sizeof(words); i++) {
    int amt;
    if (i >= sizeof(VOTE_POINTS)) break;
    if (member_array(words[i], words) != i) continue;
    amt = VOTE_POINTS[i];
    add_current_vote(words[i], amt);
    message("info", "Vote registered for "+words[i]+
      (sizeof(VOTE_POINTS) > 1 ? ": "+amt+" points" : "")+ ".", tp);
  }

  saveme();

  return 1;
}

int query_voted(string ip) {
  if (voted_ips && sizeof(voted_ips) && member_array(ip, voted_ips) != -1)
    return 1;
  return 0;
}

void add_voted_ip(string ip) {
  if (!voted_ips) voted_ips = ({});
  voted_ips |= ({ ip });
}

void add_current_vote(string word, int amt) {
  if (!current_votes) current_votes = ([]);
  if (!current_votes[word]) current_votes[word] = 0;
  current_votes[word] += amt;
  if (current_votes[word] == 0) map_delete(current_votes, word);
}

int cmd_query(string str) {
  object tp = this_player();

  if (!str)
    return notify_fail("Syntax: <query ips> <query votes> <query all>");

  if (str == "ips" || str == "all") {
    if (!voted_ips || !sizeof(voted_ips))
      message("info", "No IPs have voted yet.", tp);
    else
      message("info", "IPs:\n"+format_page(sort_array(voted_ips, 1), 4), tp);
  }

  if (str == "all")
    message("info", "\n", tp);

  if (str == "votes" || str == "all") {
    if (!current_votes || !sizeof(current_votes))
      message("info", "No votes registered yet.", tp);
    else
      message("info", "Votes:\n"+
        format_page(sort_array(
          values(map(current_votes, (: $1 + ": " + $2 :) ) ), 1
        ), 4), tp);
  }

  message("info", "\n", tp);

  return 1;
}

int cmd_clear(string str) {
  object tp = this_player();

  if (!str || str != "votes")
    return notify_fail(
      "Please enter <clear votes> to clear out the current vote."
    );

  voted_ips = ({});
  current_votes = ([]);
  saveme();

  message("info", "Votes cleared.", tp);

  return 1;
}

void saveme() {
  seteuid(UID_VOTESAVE);
  save_object(DIR_VOTES+"/votingbooth");
  seteuid(geteuid());
}

void restoreme() {
  seteuid(UID_VOTESAVE);
  restore_object(DIR_VOTES+"/votingbooth");
  seteuid(geteuid());
}

