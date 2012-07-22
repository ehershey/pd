#include <save.h>
#include <security.h>

string *gags;

static void save() {
    seteuid(UID_DAEMONSAVE);
    save_object("/daemon/save/gag");
    seteuid(getuid());
}

static void restore() { restore_object("/daemon/save/gag"); }

void create() {
  seteuid( getuid() );
  restore();
  if(!gags || gags == ({}) || !sizeof(gags)) gags=({});
}

string strip_ip(string ip) {
   string *a;
   if(!ip) return ip;
   a=explode(ip, ".");
   if(sizeof(a) == 3) return ip;
   a[sizeof(a)-1]=0;
   return implode(a, ".");
}

int add_gag(string ip) {
   if(member_array(ip, gags) != -1) return 0;
   ip=strip_ip(ip);
   gags += ({ ip });
   save();
   return 1;
}

int remove_gag(string ip) {
   if(member_array(ip, gags) == -1) return 0;
   gags -= ({ ip });
   save();
   return 1;
}

int valid_gag(string ip) {
   ip=strip_ip(ip);
   if(member_array(ip, gags) == -1) return 0;
   return 1;
}

string * get_gags() { return gags; }
