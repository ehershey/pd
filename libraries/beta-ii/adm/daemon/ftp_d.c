/* FTP DAEMON by seeker */

#include <std.h>
#include <daemons.h>
#include <socket.h>
#include <security.h>
#include <network.h>
#include <strings.h>
#include <dirs.h>

inherit "/std/user";
#define FTP_SERVER_NAME "Primal Darkness Beta II"
#define FTP_PORT 9007

static private mapping connections = ([]);
static private int listen_port;

string ftp_outp(int fd, string str);
void check_user(int fd, string name);
void check_pass(int fd, string pass);
void ftp_close(int fd);
void ftp_read(int fd, mixed msg);
int close_callback(int fd);

void create()
{
 seteuid(getuid());
}

string setup_ftp()
{
 int i;

 seteuid(UID_SOCKET);
 if ( (listen_port = socket_create(STREAM, "", "close_callback")) < 0)
   return socket_error(listen_port);
 if ( (i=socket_bind( listen_port, FTP_PORT )) < 0)
   return socket_error(i);
 if ( (i=socket_listen( listen_port, "ftp_connect" )) < 0 )
   return socket_error(i);
 seteuid(getuid());
 return "Setup FTP Sucessfuly";
}

string ftp_connect(int fd)
{
 int new_fd;
 if ( (new_fd = socket_accept(fd, "ftp_read", "write_callback")) < -1 )
   return socket_error(new_fd);
 ftp_outp( new_fd, "220 "+FTP_SERVER_NAME+" FTP server (pftpd v1.0) ready.\n");
 connections[ new_fd ] = ([ "user": "", "pass" : "", "cwd" : "" ]);
}
string ftp_outp(int fd, string str) { 
 int i;
 if ( (i = socket_write( fd, str)) < 0 ) 
   {
    ftp_close(fd);
    return socket_error(i);
   }
}

void ftp_read(int fd, mixed msg)
{
 string cmd, arg;
 int i;
 if (!connections[fd]) { ftp_outp(fd, "Not in database!\n"); return; }
 if (!connections[fd]["command"]) connections[fd]["command"]="";
 connections[fd]["command"] += msg;
 if ((i=strsrch(connections[fd]["command"],"\n"))==-1) return;
 msg=connections[fd]["command"][0..i-2];
 connections[fd]["command"]=connections[fd]["command"][i+1..];
 connections[fd]["command"]=trim_spaces(connections[fd]["command"]);
 if (!sscanf( msg, "%s %s", cmd, arg))
   cmd = msg;
if (!connections[fd]["connected"]) {
 switch(cmd) {
   case "USER": check_user(fd, arg); break;
   case "PASS": check_pass(fd, arg); break;
   case "SYST": break;
   default: ftp_outp(fd, "502 Login with USER first.\n"); break;
  }
}
 return;
}
void check_pass(int fd, string pass)
{
 if (!pass || pass == "")
   {
    ftp_outp(fd, "530 Login Incorrect.\n");
   }
 if (connections[fd]["connected"]) 
   {
    ftp_outp(fd, "530 You are already connected.\n");
    return;
   }
 if (!connections[fd]["user"] || connections[fd]["user"]=="")
   {
    ftp_outp(fd, "530 Login with USER first.\n");
    return;
   }

restore_object(DIR_USERS+"/"+connections[fd]["user"][0..0]+"/"+connections[fd]["user"]+".o",1);

 if (crypt(pass, password)!=password)
   {
    ftp_outp(fd, "530 Login incorrect.\n");
    connections[fd]["user"]=""; connections[fd]["password"]="";
    return;
   }
 
 ftp_outp(fd, "530 User "+connections[fd]["user"]+" logged in.\n");
 connections[fd]["password"] = password;
 connections[fd]["connected"] = 1;
 return;
}
void check_user(int fd, string name)
{
 if (!name || name == "")
   {
    ftp_outp(fd, "530 Enter a valid user.\n");
    return;
   }
 if (connections[fd]["connected"])
   {
    ftp_outp(fd, "530 Already logged in as "+connections[fd]["user"]+".\n");
    return;
   }
 seteuid( UID_USERSAVE );
 if (file_size(DIR_USERS+"/"+name[0..0]+"/"+name+".o")==-1)
   {
     ftp_outp(fd, "530 No such user.\n");
    return;
   }
 seteuid( getuid() );
 connections[fd]["user"] = name;
 ftp_outp(fd, "331 "+name+" name ok, need password.\n");
 return;
}

void ftp_close(int fd) {  map_delete(connections, fd); socket_close(fd);  } 
int write_callback(int fd) { }
int close_callback(int fd) {  ftp_close(fd);   }
mapping query_connections() { return connections; }
 
