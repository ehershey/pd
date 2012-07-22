// User Authentication Protocols

#include <socket.h>
#include <network.h>
#include <daemons.h>
#include <security.h>

#define SMTP_IP "217.160.230.51"
#define OK 1
#define ALREADY_EXISTS -1
#define NO_USER -2
#define INVALID_CODE -3
#define ALREADY_VERIFIED -4
#define CHAT(x) CHAT_D->do_raw_chat("system", "AUTH <system> "+x);

mapping data;
void save();

void do_end(string name, string email);
void do_mail(string name, string email, string code);
void do_reminder(string name, string email);
void load_socket();

void save() {
   seteuid(UID_DAEMONSAVE);
   save_object("/daemon/save/auth.o");
   seteuid(getuid());
}

void restore() {
   seteuid(UID_DAEMONSAVE);
   restore_object("/daemon/save/auth.o");
   seteuid(getuid());
}

void create() {
   data=([]);
   call_out("load_socket", 5);
   restore();
   call_out("do_cleanup", 60);
}

int add_user(string name, string email) {
   string code;

   code = time()+"";
   if(!data) create();
   if(data[name]) map_delete(data, name);
   if(email[0..0] == "*") email[0..0]="";
   data[name]=([ "Email":email, "Code":code, "Verified":0, "Time":time() ]);
   do_mail(name, email, code);
   save();
   return OK;
}

int remove_user(string name) {
   if(!data[name]) return 0;
   map_delete(data, name);
   save();
   return 1;
}

int check_verification(string name, string code) {
   if(!data) return NO_USER;
   if(!data[name]) return NO_USER;
   if(data[name]["Code"] != code) { CHAT("Invalid code ("+code+") for user "+name); return INVALID_CODE; }
   if(data[name]["Verified"]) { CHAT("Already verified ("+code+") for user "+name); return ALREADY_VERIFIED; }
   this_object()->verify(name);
   return OK;
}

int verified(string name) {
   if(member_group(name, "allowed")) return 1;
   if(!data) return 0;
   if(!data[name]) return 0;
   return data[name]["Verified"];
}

int change_email(string name, string email) {
   restore();
   if(!data[name]) return 0;
   data[name]["Email"]=email;
   save();
}

void load_socket() {
   int fd;
   fd = socket_create(STREAM, "");
   socket_bind(fd, 8002);
   socket_listen(fd, "incoming_connect");
}

void incoming_connect(int fd) {
   socket_accept(fd, "incoming_data", "");
}

int incoming_data(int fd, string txt) {
   string name;
   int code;
   int ret;
   sscanf(txt, "%s_%d", name, code);
   ret=check_verification(name, code+"");
   socket_write(fd, ""+ret);
   socket_close(fd);
   if(ret == OK) this_object()->verify(name);
}

mapping get_data() { restore(); return data; }

static int verify(string name) {
   CHAT("User "+name+" verified."); 
   data[name]["Verified"]=1;
   save();
}

void do_cleanup() {
   int i;
   string *k;
   return; //  Dont want to do this to the old port, only new.
   i=sizeof(k=keys(data));
   while(i--) {
     if(!user_exists(k[i])) {
       map_delete(data, k[i]);
       continue;
     }
     if(member_group(k[i], "allowed")) continue;
     if((time()-IP_D->query_last_on(k[i])) >= 10800 && !data[k[i]]["Verified"]) {
       CHAT_D->do_raw_chat("system" "Auth <system> System wiped "+k[i]+" do to no activation within 3 hours.");
       "/cmds/adm/_rid"->cmd_rid(k[i]);
       map_delete(data, k[i]);
      log_file("authenticate", "System wiped "+k[i]+" fo to no activiation within 3 hours.");
     }
     if(time()-12960000 < IP_D->query_last_on(k[i])) data[k[i]]["remind"]=0;
     if(time()-12960000 > IP_D->query_last_on(k[i]) && !data[k[i]]["remind"]) { do_reminder(k[i], data[k[i]]["Email"]); data[k[i]]["remind"]=1; }
     if(time()-15552000 > IP_D->query_last_on(k[i])) {
       do_end(k[i], data[k[i]]["Email"]);
       CHAT_D->do_raw_chat("system", "Auth <system> System wiped "+k[i]+" for being idle for 6 months.");
       "/cmds/adm/_rid"->cmd_rid(k[i]);
       log_file("authenticate", "System wiped "+k[i]+" for being idle for 6 months.\n");
     }
   }   
   save();
   call_out("do_cleanup", 60);
}

void do_end(string name, string email) {
   string crlf = "  ";
   crlf[0] = 13;
   crlf[1] = 10;
   seteuid("Mail");
   send_mail("no-reply@primaldarkness.com", email, "Character Removed",
"We regret to inform you that "+name+" has been removed from "
"Primal Darkness for being inactive for 6 months.  This action is irreversable.  "
"We value you as a player and do invite you to come play again with us.  "
""
""+crlf+crlf+
"Sincerely, "+crlf+
"The Administration"+crlf+crlf+crlf+
"DISCLAIMER"+crlf+crlf+
"This email is email has been sent because you have an account registered with "
"on Primal Darkness.  This email is in no way spam email.  If you are not "
"the character holder listed in this email, please disregard this email.  "
"Any and all questions may be asked via email to whit@primaldarkness.com "
"or stormbringer@primaldarkness.com"
);
   seteuid(getuid());
}

void do_reminder(string name, string email) {
   string crlf = "  ";
   crlf[0] = 13;
   crlf[1] = 10;
   seteuid("Mail");
   send_mail("no-reply@primaldarkness.com", email, "Important Information about your account",
"This email has been sent to remind you that you must log onto your Primal Darkness character "
"once every 6 months.  This email has been sent to remind you that you have not logged on "
+name+" for 5 months.  Logging into the web interface does not reset this counter.  "
+name+" has been marked for deletion and will be deleted in 30 days, unless you log "
"into your account before the time is up.  This action is irreversable."
""+crlf+crlf+
"Sincerely, "+crlf+
"The Administration"+crlf+crlf+crlf+
"DISCLAIMER"+crlf+crlf+
"This email is email has been sent because you have an account registered with "
"on Primal Darkness.  This email is in no way spam email.  If you are not "
"the character holder listed in this email, please disregard this email.  "
"Any and all questions may be asked via email to whit@primaldarkness.com "
"or stormbringer@primaldarkness.com"
);
   seteuid(UID_LOG);
   log_file("authenticate", "Reminder sent to "+name+"("+email+") for 5 mo inactive.\n");
   CHAT("Reminder sent to "+name+"("+email+") for 5 mo inactive.");
   seteuid(getuid());
}

void do_mail(string name, string email, string code) { 
   string crlf = "  "; 
   crlf[0] = 13; 
   crlf[1] = 10; 
   if(!name || !email || !code) return;
   seteuid("Mail");
   send_mail("no-reply@primaldarkness.com", email, "Welcome to Primal Darkness!", 
"Welcome "+name+" to Primal Darkness!  This email contains valuable information "
"on how to activate your character, and information for new players.  "+crlf+crlf+
"To activate your character, click "
"<a href=\"http://www.primaldarkness.com/tna/auth.php?Name="+name+"&Code="+code+"&Email="+email+"\">"
"here</a> to confirm your email account."+crlf+crlf+
"If at anytime you wish to change your email account, you may do so using the "
"chfn command.  If at anytime you change your email account, your account will have "
"to be re-verified, and the same time restrictions will apply."+crlf+crlf+
"One of the first things you should do when you log in for the first time is "
"type the faq command.  This will show you a page of the most frequently asked "
"questions for new players.  We encourage you to ask for help using any or all "
"of the communication commands."+crlf+crlf+
"Sincerely, "+crlf+
"The Administration"+crlf+crlf+crlf+
"DISCLAIMER"+crlf+crlf+
"This email is email has been sent because you have created a character "
"on Primal Darkness.  This email is in no way spam email.  If you are not "
"the character holder listed in this email, please disregard this email.  "
"Any and all questions may be asked via email to whit@primaldarkness.com "
"or stormbringer@primaldarkness.com"
); 
   seteuid(getuid());
} 
