#include <save.h>
#include <security.h>

string *lans;

static void save() {
    seteuid(UID_DAEMONSAVE);
    save_object("/daemon/save/lans");
    seteuid(getuid());
}

static void restore() { restore_object("/daemon/save/lans"); }

void create() {
  seteuid( getuid() );
  restore();
  if(!lans || !sizeof(lans)) lans=({});
}

string strip_ip(string ip) {
  string a, b, c, d;
  if (!ip) return ip;
  if (sscanf(ip, "%s.%s.%s.%s", a, b, c, d) == 4) return a+"."+b+"."+c;
  else if (sscanf(ip, "%s.%s.%s", a, b, c) == 3) return a+"."+b+"."+c;
  else return ip;
}

int add_lan(string ip) {
   if(member_array(ip, lans) != -1) return 0;
   ip=strip_ip(ip);
   lans += ({ ip });
   save();
   return 1;
}

int remove_lan(string ip) {
   if(member_array(ip, lans) == -1) return 0;
   lans -= ({ ip });
   save();
   return 1;
}

int valid_lan(string ip) {
   ip=strip_ip(ip);
   if(member_array(ip, lans) == -1) return 0;
   return 1;
}

string * get_lans() { return lans; }
