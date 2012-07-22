// Last message daemon by seeker
// February 21st of 2000
// Security hole fixed by NS
// November 16, 2001
//
// wtf was this shit??
// rewritten by Nulvect 2011-Feb-09
//
// adding new things per player should now be as easy as making two functions:
// int add_blah(string user, string msg) { return add_user(user, "blah", msg); }
// string get_blah(string user) { return get_user(user, "blah"); }

#include <std.h>

inherit DAEMON;


static private mapping UserData;
static private mapping LineData;


int add_user(string user, string line, string msg);
int add_say(string user, string msg);
int add_tell(string user, string msg);
int add_partyline(string user, string msg);
int add_honeyline(string user, string msg);
int add_buddylist(string user, string msg);
int add_enemylist(string user, string msg);
int add_last(string line, string msg);

string get_user(string user, string line);
string get_say(string user);
string get_tell(string user);
string get_partyline(string user);
string get_honeyline(string user);
string get_buddylist(string user);
string get_enemylist(string user);
string get_last(string line);

int query_saysize(string user);


void create() {
  seteuid(getuid());
  UserData = ([ ]);
  LineData = ([ ]);
}

int add_user(string user, string line, string msg) {
  int ret = 1;
  
  if (!UserData[user])
    UserData[user] = ([ ]);

  if (!UserData[user][line]) {
    UserData[user][line] = ({ });
    ret = 2;
  }

  msg = strip_color(msg);

  UserData[user][line] += ({ msg });
  if (sizeof(UserData[user][line]) > 25)
    UserData[user][line] = UserData[user][line][1..25];

  return ret;
}

int add_say(string user, string msg) { return add_user(user, "say", msg); }
int add_tell(string user, string msg) { return add_user(user, "tell", msg); }
int add_partyline(string user, string msg) { return add_user(user, "partyline", msg); }
int add_honeyline(string user, string msg) { return add_user(user, "honey", msg); }
int add_buddylist(string user, string msg) { return add_user(user, "buddylist", msg); }
int add_enemylist(string user, string msg) { return add_user(user, "enemylist", msg); }

int add_last(string line, string msg) {
  int ret = 1;
  
  if (!LineData[line]) {
    LineData[line] = ({ });
    ret = 2;
  }

  msg = strip_color(msg);

  LineData[line] += ({ msg });
  if (sizeof(LineData[line]) > 25)
    LineData[line] = LineData[line][1..25];

  return ret;
}

string get_user(string user, string line) {
  if (this_player() && this_player()->query_name() != user &&
      !archp(this_player()))
        return "No last info.\n";

  if (!UserData || !UserData[user] ||
      !UserData[user][line] || !sizeof(UserData[user][line]))
        return "No last info.\n";
  
  return implode(UserData[user][line], "\n")+"\n";
}

string get_say(string user) { return get_user(user, "say"); }
string get_tell(string user) { return get_user(user, "tell"); }
string get_partyline(string user) { return get_user(user, "partyline"); }
string get_honeyline(string user) { return get_user(user, "honey"); }
string get_buddylist(string user) { return get_user(user, "buddylist"); }
string get_enemylist(string user) { return get_user(user, "enemylist"); }

string get_last(string line) {
  if (!LineData || !LineData[line] || !sizeof(LineData[line]))
    return "No last info.\n";
  
  return implode(LineData[line], "\n")+"\n";
}

// Why??
int query_saysize(string user) {
  if (UserData && UserData[user] && UserData[user]["say"])
    return sizeof(UserData[user]["say"]);
  return 0;
}

