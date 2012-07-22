//      /adm/daemon/fprot_d
//      from the Primal Darkness lib
//      the flood protection control
//      ��� primaldarkness.com Monday January 22 2001 -- 04:21:02 -08:00

#include <daemons.h>

#define CONNECT_DELAY   30
#define MAX_CONNECTS    6
#define CHAT_DELAY      5 // Allow only MAX_CHATs in CHAT_DELAY
#define MAX_CHAT        7

mapping banished_ips;
mapping past_connections;
mapping past_chat;

int add_connection(string ip);
int add_chat(string person);
int clean_up_flood();
mapping query_connections();
mapping query_chat();

static void create()
{
    call_out("clean_up_flood", 60);
    past_connections = ([]);
    past_chat        = ([]);
    banished_ips     = ([]);
}

int firewall_ip(string ip)
{
 if (!banished_ips[ip])
 banished_ips = ([ ip : time() ]);

/*
 if (sscanf(file_name(previous_object()), "%s#%d", str, i)!=2)
   str = file_name(previous_object());
 if (str!="/adm/obj/login")
   return -1;

 external_start(1, ip);
*/
 return 1;
}

int add_connection(string ip)
{
    int x;

    if (banished_ips[ip]) {
      if ((time()-banished_ips[ip]) > 30) 
        map_delete(banished_ips, ip);
       return -1;
     }

    if (!past_connections) past_connections = ([]);
    if (!past_connections[ip])
    {
	past_connections[ip] = ({ 1, time() });
	return 1;
    }
    if (time() - past_connections[ip][1] > CONNECT_DELAY)
    {
	past_connections[ip] = ({ 1, time() });
	return 1;
    }

    x = (++past_connections[ip][0]);

    if (x >= MAX_CONNECTS)
    {
	map_delete(past_connections, ip);
	return 0;
    }
    past_connections[ip][0] = x;
    return 1;
}

int add_chat(string person)
{
    int x;
    if (!past_chat) past_chat = ([]);
    if (!past_chat[person])
    {
	past_chat[person] = ({ 1, time() });
	return 1;
    }
    if (time() - past_chat[person][1] > CHAT_DELAY)
    {
	past_chat[person] = ({ 1, time() }) ;
	return 1;
    }
    x = (++past_chat[person][0]);
    if (x >= MAX_CHAT)
    {
	map_delete(past_chat, person);
	return 0;
    }
    past_chat[person][0] = x;
    return 1;
}

int clean_up_flood()
{
    string *key, *ckey, *bkey;
    int i, a, b;

    call_out("clean_up_flood", 60);
    if (!(i = sizeof(key = keys(past_connections))) &&
      !(a = sizeof(ckey = keys(past_chat))) &&
      !(b = sizeof(bkey = keys(banished_ips)))) return 1;
  
    while(a--) 
	if (time()-past_chat[ ckey[a] ][1] > 7)
	    map_delete(past_chat, ckey[a]);
    while(b--)
        if (time()-banished_ips[bkey[b]] > 30)
            map_delete(banished_ips, bkey[b]);
    while(i--)
	if (time()-past_connections[ key[i] ][1] > 60)
	    map_delete(past_connections, key[i]);

    return 1;
}

mapping query_connections() { return past_connections; }
mapping query_chat()        { return past_chat;        }

