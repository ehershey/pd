#include <dirs.h>
#include <config.h> 
#include <security.h> 
#include <objects.h>
#include <daemons.h> 
#include <save.h> 


string *__Names, *__Sites, *__WatchNames, *__WatchSites; 
string *__Allowed, *__Guests, *__IllegalSubStrings; 
string *__BanishedIps, *__TotalBan;

static private int valid_access(object ob);
void register_site(string str);
void unregister_site(string str);
string *query_register();
int query_banished_ip(string str);
void banish_ip(string ip);
void unbanish_ip(string ip);
void banish_name(string str);
void unbanish_name(string str);
string *query_banished();
void watch_site(string str);
void unwatch_site(string str);
string *query_watched_sites();
void watch_name(string str);
void unwatch_name(string str);
string *query_watched_names();
void allow_name(string str);
void unallow_name(string str);
string *query_allowed();
void set_illegal_substring(string str);
void remove_illegal_substring(string str);
string *query_illegal_substrings();
void add_guest(string str);
void remove_guest(string str);
string *query_guests();
static private void save_banish();
static private void restore_banish();
int is_guest(string str);
int valid_name(string str);
int allow_logon(string nom, string ip);
static private int match_ip(string ip, string *sites);
 
void create() { 
    seteuid(getuid()); 
    __Names = ({}); 
    __Sites = ({}); 
    __WatchNames = ({}); 
    __WatchSites = ({}); 
    __Allowed = ({}); 
    __Guests = ({}); 
    __IllegalSubStrings = ({}); 
    __BanishedIps  = ({});
    __TotalBan = ({});
    if(file_exists(SAVE_BANISH+".o")) restore_banish(); 
} 
string *query_banished_ips()
{ 
 return __BanishedIps;
}
int query_banished_ip(string str)
{
 int i;
 if (!str || str=="") return 0; 
/*  Dont know why this is here  - Whit 10/5/03
 i = sizeof(__BanishedIps);
 while (i--)
   write("Name = "+__BanishedIps[i]);
*/
 if (match_ip(str, __BanishedIps))
   return 1;

 return 0;
}
void banish_ip(string str)
{
 if (!valid_access(previous_object())) return;
 if (!__BanishedIps)
  __BanishedIps = ({ str }); 
 else
  __BanishedIps += ({ str });
 save_banish();
}
void unbanish_ip(string str)
{
 if (!valid_access(previous_object())) return;
  __BanishedIps -= ({ str });
 save_banish();
}
static private int valid_access(object ob) { 
   if(archp(this_player())) return 1;
    return (geteuid(ob) == UID_BANISH || geteuid(ob) == UID_ROOT || archp(ob));
} 
 
void register_site(string str) { 
    if(!valid_access(previous_object())) return; 
    __Sites = distinct_array(__Sites + ({ str })); 
    save_banish(); 
} 
 
void unregister_site(string str) { 
    if(!valid_access(previous_object())) return; 
    __Sites -= ({ str }); 
    save_banish(); 
} 
 
string *query_registered() { 
    if(!valid_access(previous_object())) return ({}); 
    return __Sites; 
} 
 
void banish_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __Names = distinct_array(__Names + ({ lower_case(str) })); 
    save_banish(); 
} 
 
void unbanish_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __Names -= ({ lower_case(str) }); 
    save_banish(); 
} 
 
string *query_banished() { 
    if(!valid_access(previous_object())) return ({}); 
    return __Names; 
} 
 
void watch_site(string str) { 
    if(!valid_access(previous_object())) return; 
    __WatchSites = distinct_array(__WatchSites + ({ str })); 
    save_banish(); 
} 
 
void unwatch_site(string str) { 
    if(!valid_access(previous_object())) return; 
    __WatchSites -= ({ str }); 
    save_banish(); 
} 
 
string *query_watched_sites() { 
    if(!valid_access(previous_object())) return ({}); 
    return __WatchSites; 
} 
 
void watch_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __WatchNames = distinct_array(__WatchNames + ({ lower_case(str) })); 
    save_banish(); 
} 
 
void unwatch_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __WatchNames -= ({ lower_case(str) }); 
    save_banish(); 
} 
 
string *query_watched_names() { 
    if(!valid_access(previous_object())) return ({}); 
    return __WatchNames; 
} 
 
void allow_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __Allowed = distinct_array(__Allowed + ({ lower_case(str) })); 
    save_banish(); 
} 
 
void unallow_name(string str) { 
    if(!valid_access(previous_object())) return; 
    __Allowed -= ({ lower_case(str) }); 
    save_banish(); 
} 
 
string *query_allowed() { 
    if(!valid_access(previous_object())) return ({}); 
    return __Allowed; 
} 
 
void set_illegal_substring(string str) { 
    if(!valid_access(previous_object())) return; 
    __IllegalSubStrings = distinct_array(__IllegalSubStrings + 
      ({ lower_case(str) })); 
    save_banish(); 
} 
 
void remove_illegal_substring(string str) { 
    if(!valid_access(previous_object())) return; 
    __IllegalSubStrings -= ({ lower_case(str) }); 
    save_banish(); 
} 
 
string *query_illegal_substrings() {  
    if(!valid_access(previous_object())) return ({}); 
    else return __IllegalSubStrings; 
} 
 
void add_guest(string str) { 
    if(!valid_access(previous_object())) return; 
    __Guests = distinct_array(__Guests + ({ lower_case(str) })); 
    save_banish(); 
} 
 
void remove_guest(string str) { 
    if(!valid_access(previous_object())) return; 
    __Guests -= ({ lower_case(str) }); 
    save_banish(); 
} 
 
string *query_guests() { 
    if(!valid_access(previous_object())) return ({}); 
    else return __Guests; 
} 
 
static private void save_banish() { 
    seteuid(UID_SECURE_DAEMONSAVE); 
    save_object(SAVE_BANISH); 
    seteuid(getuid()); 
} 
 
static private void restore_banish() { 
    seteuid(UID_SECURE_DAEMONSAVE); 
    restore_object(SAVE_BANISH); 
    seteuid(getuid()); 
} 
 
int is_guest(string str) { 
    if(base_name(previous_object()) != OB_LOGIN) return 0; 
    else return (member_array(lower_case(str), __Guests) != -1); 
} 
 
int valid_name(string str) { 
    int i, x; 
 
    if(base_name(previous_object()) != OB_LOGIN) return 0; 
    if(member_array(str, __Names) != -1) return 0; 
    i = sizeof(__IllegalSubStrings);
    while(i--) if(strsrch(str, __IllegalSubStrings[i]) != -1) return 0;
    if((x = strlen(str)) > MAX_USER_NAME_LENGTH) return 0; 
    if(x < MIN_USER_NAME_LENGTH) return 0; 
    for(i=0; i<x; i++)  
      if(str[i] < 'a' || str[i] > 'z') return 0; 
    return 1; 
} 
 
int allow_logon(string nom, string ip) { 
    if(base_name(previous_object()) != OB_LOGIN) return 0; 
    if(member_array(nom, __WatchNames) != -1) { 
        seteuid(UID_LOG); 
        log_file("watch/names", sprintf("%s from %s at %s", nom, ip, 
          ctime(time()))); 
        seteuid(getuid()); 
    } 
    if(match_ip(ip, __WatchSites)) { 
        seteuid(UID_LOG); 
        log_file("watch/"+ip, sprintf("%s at %s", nom, ctime(time()))); 
        seteuid(getuid()); 
    } 
    if(member_array(nom, __Allowed) != -1) { 
        seteuid(UID_LOG); 
        log_file("watch/allowed", sprintf("%s from %s at %s", nom, ip, 
          ctime(time()))); 
        seteuid(getuid()); 
        __Allowed -= ({ nom }); 
        save_banish(); 
        return 1; 
    }     
    if(match_ip(ip, __Sites)) { 
        if(user_exists(nom)) { 
            seteuid(UID_LOG); 
            log_file("watch/"+ip, sprintf("%s allowed in from %s at %s", nom, ip, 
              ctime(time()))); 
            seteuid(getuid()); 
            return 1; 
        } 
        else { 
            seteuid(UID_LOG); 
            log_file("watch/"+ip, sprintf("%s failed from %s at %s", nom, ip, 
              ctime(time()))); 
            seteuid(getuid()); 
            return 0; 
        } 
    } 
    return 1; 
} 
 
static private int match_ip(string ip, string *sites) { 
    string a, b; 
    int i; 
 
    if(!(i = sizeof(sites))) return 0; 
    while(i--) { 
        if(sites[i] == ip) return 1; 
        if(sscanf(sites[i], "%s.*", a) && sscanf(ip, a+"%s", b)) 
          return 1; 
    } 
    return 0; 
} 

void total_ban_ip(string str) { 
    if(!__TotalBan) __TotalBan = ({});
    __TotalBan += ({str});
    save_banish(); 
} 

int remove_total_ban(string s) {
   if(member_array(s, __TotalBan)==-1) return 0;
   __TotalBan -= ({ s });
   save_banish();
   return 1;
}

int query_total_ban(string str)
{
 int i;
 if (!str || str=="") return 0; 

 if (match_ip(str, __TotalBan))
   return 1;

 return 0;
}

string *query_total_bans() {
   return __TotalBan;
}

