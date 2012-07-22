//  War Room for guilds.

#include <std.h>
#include <guild.h>

inherit ROOM;
static mapping data;
string status_bar(float per, int size);
void create() {
   int i,x;
   ::create();
   set_name("Guild War Room");
   set_short("Guild War Room");
   set_long("A large board shrouded in gold stands in the middle of "
     "of the room.  The board displays your current guild status with "
     "the other guilds.");
   set_exits((["north":"/d/guilds/meeting"]));
   
   set_items(([
     "":""
     ]));
    set_properties(([
        "light"       : 2, 
        "night light" : 2, 
        "no teleport" : 1, 
        "no attack"   : 1,  
        "no magic"    : 1,
        "no bump"     : 1,
        "no steal"    : 1,
        "indoors"     : 1,
      ]));
    data=([]);
    i=sizeof(VALID_GUILDS);
    while(i--) {
      data[VALID_GUILDS[i]]=([]);
      x=sizeof(VALID_GUILDS);
      while(x--)
        data[VALID_GUILDS[i]][VALID_GUILDS[x]]=500;
    }
}

void init() {
   ::init();
   add_action("look","look");
}

int look(string s) {
   string a,g;
   int i;

   if((s!="board" || sscanf(s, "at %s", a)!=1) && a!="board") return 0;
   g=this_player()->query_guild();
   write("The following is a display of your current status with the other guilds.  "
     "Many things change the combat status of your guild with another, whether "
     "it be from pking, or other things.  ");
   i=sizeof(data[g]);
   
}

string status_bar(float per, int size) {
   string bar="";
   int tmp;
   int amt;
   tmp=copy(size);
   if(per >= 100) {
     while(tmp--) bar += "|";
     return "["+bar+"]";
   }
   while(tmp--) bar += "-";
   amt=to_float("0."+to_int(per))*size;
   while(amt--) bar[amt..amt]="|";
   return "["+bar+"]";
}


