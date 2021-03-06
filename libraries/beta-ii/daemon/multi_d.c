#include <save.h>
#include <security.h>

mapping ip_data;

string get_user_ip(string);

static void save() {
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_MULTI);
    seteuid(getuid());
}

static void restore() { restore_object(SAVE_MULTI); }

void create() {
  seteuid( getuid() );
  ip_data=([]);
  restore();
  call_out("do_cleanup", 5);
}

string strip_ip(string ip) {
  int pos = strsrch(ip, ".", 1);
  return ip[0..pos-1];
}

int check_user(string user, string ip) {
   string si;
   si=strip_ip(ip);
   if(!ip_data) ip_data=([]);
   if(!ip_data[si]) ip_data[si]=([]);
   if(ip_data[si][user]) return 0;
   ip_data[si][user]=(["time":time(), "ip":ip]);
   save();
   return 1;
}

int new_user(string user, string ip) {
   string si;
   si=strip_ip(ip);
   if(!ip_data) ip_data=([]);
   if(!ip_data[si]) ip_data[si]=([]);
   ip_data[si][user]=(["time":time(), "ip":ip]);
   save();
   return 1;
}

int remove_user(string user) {
   string ip=get_user_ip(user);
   map_delete(ip_data[ip], user);
   save();
   return 1;
}

string get_user_ip(string user) {
   int i;
   string *k;
   if(!ip_data) return 0;
   i=sizeof(k=keys(ip_data));
   while(i--) {
     if(member_array(user, keys(ip_data[k[i]])) != -1) return k[i];
   }
   return 0;
}

mapping get_users(string ip) { return ip_data[strip_ip(ip)]; }

void do_cleanup() {
   remove_call_out("do_cleanup");
   call_out("do_cleanup", 3600);
}

