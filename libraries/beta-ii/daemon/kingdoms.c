//  Kingdoms System
//  Created by Whit
//    Ideas from Stormbringer

#include <daemons.h>
#include <security.h>
#include <kingdoms.h>

#define SAVE_FILE "/daemon/save/kingdoms"
/*  Configuration Section */
/*  The following options will change how the kingdom system works.  
    this is where you should add new kingdoms and such.
*/
#define KINGDOMS ([ \
"Subterra":(["directory":"/d/subterra", "line":"subterra", "outcasts":({}), "war":([]), "members":({}) ]), \
"Syntheria":(["directory":"/d/syntheria", "line":"syntheria", "outcasts":({}), "war":([]), "members":({}) ]), \
                  ])

/* DO NOT EDIT BELOW THIS LINE  -- DO NOT EDIT BELOW THIS LINE */

// kingdom_data[kingdom] = (["outcasts":({}), "war":([ "kingdom":(["status":"pending", "start":0]) "members":({})])])
// player_data[name] = (["kingdom":"member_of", "crimes":([]), ])
mapping kingdom_data, player_data;

static void save() {
   seteuid(UID_DAEMONSAVE);
   save_object(SAVE_FILE);
   seteuid(getuid());
}

static void restore() {
   seteuid(UID_DAEMONSAVE);
   restore_object(SAVE_FILE);
   seteuid(getuid());
}

string query_kingdom(string p) {
   if(!player_data[p]) return 0;
   return player_data[p]["kingdom"];
}

int add_member(string who, string kingdom) {
   if(member_array(kingdom, keys(KINGDOMS)) == -1) return INVALID_KINGDOM;
   if(!player_data[who]) player_data[who] = ([]);
   if(player_data[who]["kingdom"]) return IN_KINGDOM;
   if(member_array(who, kingdom_data[kingdom]["outcasts"]) != -1) return IS_OUTCAST;
   kingdom_data[kingdom]["members"] += ({ who });
   player_data[who] = ([ "kingdom":kingdom, "crimes":([]), ]);
   save();
   return TRUE;
}

int remove_member(string who, string kingdom) {
   if(member_array(kingdom, keys(KINGDOMS)) == -1) return INVALID_KINGDOM;
   if(player_data[who]["kingdom"]) return NOT_IN_KINGDOM;
   kingdom_data[kingdom]["members"] -= ({ who });
   player_data[who]["kingdom"] = 0;
   save();
   return TRUE;
}

int is_outcast(string who, string kingdom) {
   if(member_array(kingdom, keys(KINGDOMS)) == -1) return INVALID_KINGDOM;
   if(member_array(who, kingdom_data[kingdom]["outcasts"]) != -1) return TRUE;
   return FALSE;
}

string *query_kingdoms() { return keys(kingdom_data); }
string query_line(string k) { return kingdom_data[k]["line"]; }

mapping get_player_data() { return player_data; }
mapping get_kingdom_data() { return kingdom_data; }

void create() {
   int i;
   string *k;
   kingdom_data = ([]);
   player_data = ([]);
   restore();
   i=sizeof(k=keys(KINGDOMS));
   while(i--) {
     if(!kingdom_data[k[i]]) kingdom_data[k[i]] = KINGDOMS[k[i]];
   }
}
