/*
 * imc_d.c 
 * Made for DarkeMUD
 * Created by Madoc@DarkeMUD
 * See file COPYING in this package for liscence
 * Copyright (c) 2004
 * Do not remove this header!
 * Description : A (hopefully) portable implementation of the IMC2 
 * 		 protocol, this is the daemon, it controls basically
 * 		 well, everything.
 * Changelog   :
 *               Madoc@DarkeMUD 0504 : File released.
 *               See file CHANGES for changelog.
 */		
 
#include "imc.h"

#ifdef IMC_LIMA
inherit M_ACCESS;
#include <security.h>
#endif


// NOTE: These may have to be remapped for your mud, chances are no it won't
	//	 but if your not using pinkfish@diskworlds color protocol and want color
	//       incomeing then yes, you are going to need to
	// see http://www.aethiamud.org/imc2-4.00c_dist/imc2-4.00c_dist/doc/colors.txt
	// see also Blitzkrieg client, imc.c
mapping imc_colormapping = ([ 
	"~x" : "%^BLACK%^",
	"~r" : "%^RED%^",
	"~g" : "%^GREEN%^",
	"~y" : "%^ORANGE%^",
	"~y" : "%^YELLOW%^",
	"~b" : "%^BLUE%^",
	"~p" : "%^MAGENTA%^", 
	"~m" : "%^MAGENTA%^",
	"~c" : "%^CYAN%^",
	"~w" : "%^WHITE%^",
	"~d" : "%^WHITE%^",
	"~D" : "%^BOLD%^%^BLACK%^",
	"~z" : "%^BOLD%^%^BLACK%^",
	"~G" : "%^BOLD%^%^GREEN%^",
	"~Y" : "%^BOLD%^%^YELLOW%^",
	"~B" : "%^BOLD%^%^BLUE%^",
	"~M" : "%^BOLD%^%^MAGENTA%^",
	"~P" : "%^BOLD%^%^MAGENTA%^",
	"~C" : "%^BOLD%^%^CYAN%^",
	"~W" : "%^BOLD%^%^WHITE%^",
	"~!" : "%^RESET%^",	
	"~L" : "%^BOLD%^",
	"~u" : imc_chr(27) + "]4m",
	"~$" : "%^FLASH%^",
	"~i" : imc_chr(27) + "]6m",
	"~v" : imc_chr(27) + "]7m",
	"^B" : "%^B_BLUE%^",	
	"^x" : "%^B_BLACK%^",
	"^r" : "%^B_RED%^",
	"^g" : "%^B_GREEN%^",
	"^O" : "%^B_ORANGE%^",
	"^p" : "%^B_MAGENTA%^",
	"^c" : "%^B_CYAN%^",
	"^w" : "%^B_WHITE%^",
	
]);

/* 
	These codes, although documented in blitzkrieg, dont appear to work
	
	"'x" : "%^FLASH%^%^BLACK%^",
	"'r" : "%^FLASH%^%^RED%^",
	"'g" : "%^FLASH%^%^GREEN%^",
	"'O" : "%^FLASH%^%^ORANGE%^",
	"'b" : "%^FLASH%^%^BLUE%^",
	"'p" : "%^FLASH%^%^CYAN%^",
	"'c" : "%^FLASH%^%^CYAN%^",
	"'g" : "%^FLASH%^%^BOLD%^%^WHITE%^",
	"'z" : "%^FLASH%^%^BOLD%^%^BLACK%^",
	"'R" : "%^FLASH%^%^BOLD%^%^RED%^",
	"'G" : "%^FLASH%^%^BOLD%^%^GREEN%^",
	"'Y" : "%^FLASH%^%^BOLD%^%^YELLOW%^",
	"'B" : "%^FLASH%^%^BOLD%^%^BLUE%^",
	"'P" : "%^FLASH%^%^BOLD%^%^MAGENTA%^",
	"'C" : "%^FLASH%^%^BOLD%^%^CYAN%^",
	"'W" : "%^FLASH%^%^BOLD%^%^WHITE%^", 
	
*/
mapping imc_colorescapes = ([
	"~~" : "~",	
	"^^" : "^",
]);

private string imc_convert_incomeing(string what); 
private string imc_convert_outgoing(string what);
private void IMC_read(object socket,string data);
private void IMC_close(object socket);
private void handle_packet(string info);
private void save_imc_d();
private string imc_who_reply(string type);
	void resolve_callback(string address, string resolved, int key);
	int imc_query_listening(object who, string line);
	int imc_query_setting(object who,string setting);
	string imc_query_afkmsg(object who); 
	string *imc_query_all_bans(int type);
	string imc_add_ban(string who, int type);
	int imc_query_ban(string who,int type);
	string *imc_dmesgs();
	void imc_dmesg(string type, string what);
	string* imc_query_linelist();
// These were also static but according to Tim@TimIMC2 he hit a mudlib that didnt have static
// Since I only save the one mapping, dosnt matter, compatability 4 all!
private object sock;
private int    resolve_key;
private string network_name;
private string cache;
private int seq;
private mapping mudinfo;
private mapping lineinfo;
// This is the only variable that saves
private mapping playersettings;

// Added almost as an afterthought, added to all functions that
// are not private, only the command, or ourselves may call us
// You may want to alter this if you split it into multiple commands
// There are much better ways to do security, but this is the only thing
// I could think of that would be completly portable
// had some problems with 'recurssion to deep' errors
private int imc_security_check()  {	
	/*
	string fname;
	if(!previous_object()) return 1;
	fname = file_name(previous_object());
	if(!fname) return 1; // very special cases
	if(fname != IMC_COMMAND && fname != file_name(this_object())) {		
		// The socket is always a cloned object, making
		// this wierd parseing neccicary
		if(fname[0..strlen(IMCFILE_SOCKET)-1] != IMCFILE_SOCKET) {		
			imc_dmesg("errors","Security check failed by object: "+fname);
			return 0;
		}
	}
	*/
	return 1;
}

void imc_link_on() {
	//if(!imc_security_check()) return;
	// securitycheeck had to be removed
	// if update tried to do it po would be 
	// the update command and thats not 
	// consistant accross muds
	cache = "";
	mudinfo = ([]);
	lineinfo = ([]);			
	// sends the hub address off to be resolved	
	resolve_key = resolve(IMCLOGIN_HUB,"resolve_callback");		
	playersettings["IMC-LINKDOWN"] = 0;
	save_imc_d();
}
void imc_link_off() {
	if(!imc_security_check()) return;
	if(sock) sock->remove();	
	playersettings["IMC-LINKDOWN"] = 1;
	save_imc_d();
}
int imc_query_linkdown() {
	if(!imc_security_check()) return -1;
	if(playersettings["IMC-LINKDOWN"] == 1) return 1;
	return 0;
}

void create() {	
#ifdef IMC_LIMA
		set_privilege(1);		
#endif 
	if(file_size(IMCFILE_SAVE) > -1) {
#ifdef IMC_LIMA
		playersettings = restore_variable(unguarded(1,(: read_file,IMCFILE_SAVE :)));
#else
		playersettings = restore_variable(read_file(IMCFILE_SAVE));
#endif
	}
	if(!playersettings) playersettings = ([]);		
	// This overwrites any stats already saved
	// comment this stuff to make them cumulative
	playersettings["IMC-STATS"] = ([]);
	playersettings["IMC-STATS"]["RX"] = 0;
	playersettings["IMC-STATS"]["RS"] = 0;
	playersettings["IMC-STATS"]["TX"] = 0;
	playersettings["IMC-STATS"]["TS"] = 0;		
	
	// Check if the link was down the last time d was saved
	// if it was, leave it down, if not, bring it up
	if(!playersettings["IMC-LINKDOWN"]) {
		imc_link_on();
	}	
}

private void save_imc_d() {
	int ret;
#ifdef IMC_LIMA	
	// I have no idea how unguarded works so no idea how to read the return and
	// see if it failed	
	unguarded(1, (: write_file, IMCFILE_SAVE, save_variable(playersettings),1 :));	
#else
	ret = write_file(IMCFILE_SAVE,save_variable(playersettings),1);	
	if(ret !=1) {
		// saveing failed
		imc_dmesg("errors",IMCERROR_SAVEFAILED);
	}
#endif
	
}
//All data thats writen to the socket pass threw this function
private void imc_send(string packet) {
	playersettings["IMC-STATS"]["TX"] += 1;
	playersettings["IMC-STATS"]["TS"] += sizeof(packet);
	sock->send(packet);
}

// make sure if we're updated or something, we close the socket
// loseing control of sockets BAD
void remove() { if(sock) sock->remove(); }

void resolve_callback(string address, string resolved,int key) {	
	if(!imc_security_check()) return;
	if(!resolve_key) {
		imc_dmesg("errors","No resolve key on resolve callback.");
		return;
	}
	if(key != resolve_key) { 
		imc_dmesg("errors","Invalid resolve key in resolve callback. "+key+"!="+resolve_key);
		return;
	}
	if(!resolved) {
		imc_dmesg("errors","Resolve FAILED to give us the hubs ip!");
		return;
	}
	imc_dmesg("misc",IMCLOGIN_HUB + " Resolved to: "+resolved);
	sock = new(IMCFILE_SOCKET,2,sprintf("%s %d",resolved,IMCLOGIN_HUBPORT), 
		(: IMC_read :), (: IMC_close :) );
	if(!sock) imc_dmesg("errors",IMCERROR_COULDNOTCREATESOCKET);
	// assemble and send the authentication 'packet'	
	imc_send("PW "+IMCLOGIN_LOCALNAME+ " " + IMCLOGIN_CLIENTPW + " version=2 autosetup " + IMCLOGIN_SERVERPW+"\n\r");
	
	//MUD Sends: PW <mudname> <clientpw> version=<version#> autosetup <serverpw> [md5]

}
string *imc_dmesgs() {
	if(!imc_security_check()) return ({ });
	return ({ "tellsnoop","outgoingpackets","incomeingpackets","login/logoff","errors", 
		  "misc","querys","channel"});
}

void imc_dmesg(string type, string what) {
		object *usrs;
		int i;
		if(!imc_security_check()) return;
		type = lower_case(type);		
		if(member_array(type,imc_dmesgs()) ==-1) return;		
		usrs = users();
		i = sizeof(usrs);
		if(!i) return;
		while(i--) {
			if(!imc_wizard(usrs[i])) continue;
			if(!imc_query_setting(usrs[i],type)) continue;
			if(imc_query_setting(usrs[i],"optionglobalblock")) continue;
			imcwrite(IMCSETTING_PRETEXT + "[%^YELLOW%^"+ type +"%^RESET%^] "+ what,usrs[i]);
		}
#ifdef IMCSETTING_LOGGING
		// You could change it here to log to different files based on msg type
		write_file(IMCFILE_LOGFILE, "["+type+"] " + what+"\n");
#endif		
		return;
}

// all outgoing packets pass through this function
varargs void imc_send_packet(string type,string fromwho,string towho, string text,string args) {
	string ret;
	if(!type) return;
	if(!imc_security_check()) return;
	
	// Sequence number handleing
	seq = seq +1;	
	if(seq < time()) seq = time(); 
	
	if(!fromwho) fromwho = "*";	
	fromwho = capitalize(fromwho);
	type = lower_case(type);
	
	// Convert escaped items for outgoing	
	if(text) {		
		text = replace_string(text,"\n","\\n");
		text = replace_string(text,"\r","\\r");
		text = replace_string(text,imc_chr(34),imc_chr(92) + imc_chr(34));
		// add " escapes
		// convert color codes pinkfish->IMC2
		text = imc_convert_outgoing(text);
		
	}
	// Handleing of special types that just wont conform
	switch(type) {
		case "chat" : 
			// using ret as a tmp var
			sscanf(args,"channel=%s ",ret);			
			if(!ret) return;
			ret = lower_case(ret);
			if(!lineinfo) return;
			if(!lineinfo[ret]) return;
			if(lineinfo[ret]["policy"] == "open") type = "ice-msg-b";
			if(lineinfo[ret]["policy"] == "private") type = "ice-msg-p";
			args = replace_string(args,ret,lineinfo[ret]["channel"]);	
			if(!type) return;
#ifdef IMCSETTING_ECHOPACKET
			args += " echo=1";
#else
			args += " echo=0";
#endif
	}
	ret = fromwho + "@"+IMCLOGIN_LOCALNAME+" " + seq + " " 
	+IMCLOGIN_LOCALNAME+ " "+ type + " " + towho + " " + 
	"level=3 "+(args?args:"")+ " "+(text?"text=\""+ text+ "\"":"") + "\r\n";		
	imc_send(ret);
	imc_dmesg("outgoingpackets",ret);
#ifndef IMCSETTING_ECHOPACKET
	handle_packet(ret);
#endif
	return;
}

			
private void IMC_read(object socket, string data) {
	string *split;
	int i;
	if(!data) return;
	if(!cache) cache = "";	
	cache += data;			
	if((i=strsrch(cache,"\n\r"))==-1 ) return;	
	split = explode(cache," ");
	i= strsrch(cache,"\r",-1);
	if(i+1 != strlen(cache)) {
		// We've detected a half packet
		split = explode(cache[0..i],"\n\r");
		cache = cache[i+1..strlen(cache)];		
	}
	else {
		split = explode(cache,"\n\r");
		cache = "";
	}
	
	i=sizeof(split);
	while(i--) { 
		handle_packet(split[i]);	
		playersettings["IMC-STATS"]["RX"] += 1;
		playersettings["IMC-STATS"]["RS"] += sizeof(split[i]);	
	}	
	
}
//extracts blah= values making sure their not within a text field
private string extract(string src, string value) {
	int i,start;
	string ret;
	// if we're not looking for the text field
	// remove the text field THEN parse.careful
	// this this, its recursive, done 2 depth
	// to speed it up when it recurses
	// this allow being able to say emote=1 etc 
	// over lines without having it parsed
	if(value != "text") {
		if(strsrch(src,"text=") != -1) {
			ret = extract(src,"text");
			src = replace_string(src,ret,"");
		}
	}
	i=strsrch(src,value+"=");	
	if(i==-1) return "Unknown";
	start=sizeof(value)+i+1;
	if(value == "emote" || value == "md5") return src[start..start];
	if(src[start..start] == "\"") {		
		ret = src[start+1..strsrch(src,"\"",i+11)-1];
	}	
	else {
		ret = src[start..sizeof(src)];
		ret = ret[0..strsrch(ret," ")-1];
	}
	if(value == "text") ret = imc_convert_incomeing(ret);
	return 	ret;
}

private void handle_packet(string info) {
		string *split;
		string who, where, what,mud;		
		int i;
		object target,*usrs;	
		split = explode(info, " ");		
		// completely ignore anyone whos banned, either by mud or by person		
		if(imc_query_ban(lower_case(split[0]),IMCBAN_REMOTE) == 1) return;		
		if(sscanf(split[0],"%s@%s",who,mud) == 2) 
			if(imc_query_ban("*@"+lower_case(mud),IMCBAN_REMOTE) == 1) return;
		//////////////////////////////////////////////////////////////////
		// lets not log passwords
		if(split[3] != "accept" &&  split[3] != "reject") {
			imc_dmesg("incomeingpackets",info);
		}
		// fixes autoconfigure
		if(split[2] == "accept") split[3] == "accept";		
		switch(split[3]) {	
			case "accept" :
			case "version=2" :
				playersettings["IMC-STATS"]["RX"] += 1;
				playersettings["IMC-STATS"]["RS"] += sizeof(cache);	
				// TODO: checking of version?
				// Lets grab our network name
				network_name = replace_string(split[4],"\n\r","");					
				imc_dmesg("misc","Authentication successful on the "+ network_name + " network!");
				playersettings["IMC-LINKDOWN"] = 0;
				imc_send_packet("keepalive-request","*","*@*",0,"versionid=\""+ IMCINFO_VERSION+"\"");
				imc_send_packet("is-alive","*","*@*",0,"versionid=\"" IMCINFO_VERSION "\" networkname="+network_name+" url="IMCINFO_WEBPAGE);
				imc_send_packet("ice-refresh","*","ICE@*","channel=*");						
				break;				
			case "reject" : 
				imc_dmesg("errors", "Autosetup not allowed, or bad passwd.");
				imc_link_off();
				break;
			case "is-alive" :				
				mud = lower_case(split[0][2..]);
				mudinfo[mud] = ([]);
				mudinfo[mud]["name"] = split[0][2..];
				mudinfo[mud]["version"] = extract(info,"versionid");
				mudinfo[mud]["network"] = extract(info,"networkname"); 				
				mudinfo[mud]["url"] = extract(info,"url");
				mudinfo[mud]["status"] = 1;
				imc_dmesg("login/logoff",split[0][2..] + " logged on to IMC");
				break;										
			case "tell" :
				sscanf(split[4],"%s@",who);
				if(who) who = lower_case(who);
				where = capitalize(split[0]);
				if(!who) {
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);
					break;					
				}
				target=IMC_FIND_PLAYER(who);
				if(!target) {
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);
					break;					
				}
				if(!playersettings[who]) playersettings[who] = ([]);
				if(imc_query_setting(target,"tellblock")) {
					// we dont want invis wizards given away by the tell block msg
					if(imc_wizard(target) && imc_invis(target)) 
						imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);			
					else
						imc_send_packet("tell","*",where,IMCERROR_PLAYERBLOCKINGTELLS);						
					break;					
				}
				what=extract(info,"text");							
				playersettings[who]["reply"] = where;				
				if(!playersettings[who]["tellhist"]) playersettings[who]["tellhist"] = ({});
				if(sizeof(playersettings[who]["tellhist"]) > IMCSETTING_MAXHIST-1) {							
						playersettings[who]["tellhist"]  = 
						playersettings[who]["tellhist"][1..sizeof(playersettings[who]["tellhist"])];							
				}
				playersettings[who]["tellhist"] +=  ({ ctime(time()) +" "+ where+ ": " +  what });
				save_imc_d();				
				if(imc_query_setting(target,"afk") == 1) 
					imc_send_packet("tell","*",where,imc_query_afkmsg(target));
				
				imc_dmesg("tellsnoop","%^BOLD%^%^RED%^"+where + " tells "+ capitalize(who) +": %^RESET%^" + what);
				if(imc_wizard(target) && imc_invis(target)) {
					imcwrite(IMCSETTING_PRETEXT +"%^BOLD%^%^RED%^"+ where +" is unaware of telling you: %^RESET%^"+what,target);
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);			
				}								
				else imcwrite(IMCSETTING_PRETEXT +"%^BOLD%^%^RED%^"+ where +" tells you: %^RESET%^"+what,target);								
				break;				
			case "close-notify" :
				who = lower_case(extract(info,"host"));
				if(mudinfo[who]) {
					mudinfo[who]["status"] = 0;
					imc_dmesg("login/logoff",mudinfo[who]["name"]+" logged off of IMC");
				}
				break;	
			case "ice-msg-b" :
			case "ice-msg-r" :
			case "ice-msg-p" :				
				where = extract(info,"channel"); 
				what = extract(info,"text");
				who = extract(info,"sender");
				if(who == "Unknown") who = extract(info,"realfrom");
				if(who == "Unknown") who = split[0];				
				split = keys(lineinfo);
				i = sizeof(split);
				while(i--) {					
					if(!lineinfo) continue;
					if(!lineinfo[split[i]]) continue;										
					// Patched to lower_case
					if(lineinfo[split[i]]["channel"] == lower_case(where)) {
						where = split[i];						
						if(extract(info,"emote") == "1") 
							what = replace_string(IMCSETTING_LINEEMOTE,"$WHAT",what);
						else if(extract(info,"emote") == "2") {												
							what = replace_string(IMCSETTING_LINEEMOTE,"$WHAT",what);
							what = replace_string(what,"$WHO","");	
						}
						else 
							what = replace_string(IMCSETTING_LINESAY,"$WHAT",what);							
						what = replace_string(what,"$WHO",who);													
						what = replace_string(what,"$LN",where);													
						if(!lineinfo[split[i]]["history"]) lineinfo[split[i]]["history"] = ({});
						if(sizeof(lineinfo[split[i]]["history"]) > IMCSETTING_MAXHIST-1) {							
							lineinfo[split[i]]["history"]  = 
							lineinfo[split[i]]["history"][1..sizeof(lineinfo[split[i]]["history"])];							
						}
						lineinfo[split[i]]["history"] +=  
						({ "     " + ctime(time()) + " **" + what });						
						break;
					}
				}
				
				usrs = users();
				i = sizeof(usrs);
				if(!usrs) return;
				while(i--) {
					if(!interactive(usrs[i])) continue;
					if(!imc_query_listening(usrs[i],where)) continue;
					imcwrite(what,usrs[i]);					
				}		
				break;
			case "who-reply" :
				what = extract(info,"text");
				sscanf(split[4],"%s@",who);
				where = split[0];
				if(who) who = lower_case(who);
				if(where) where = capitalize(where);
				if(!who) {
					imc_dmesg("errors","Bad who reply recieved from " + who + ", no target");
					break;					
				}
				target=IMC_FIND_PLAYER(who);
				if(!target) {
					imc_dmesg("errors","Bad who reply recieved from " + who + ", could not find target");
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);
					break;					
				}	
			        imcwrite(IMCSETTING_PRETEXT+ where +" replied to a who request:\n" + what,target);
				break;
			case "who" :	
				who = split[0];			
				imc_send_packet("who-reply","*",who,imc_who_reply(extract(info,"type")));
				imc_dmesg("querys",capitalize(extract(info,"type")) + " from " + who + " replied to.");
				break;
			case "ice-update" :
				// local linename as index
				mud = extract(info,"localname");
				// Try to auto-detect a viable localname
				if(strsrch(mud,":") != -1) {
					mud = mud[strsrch(mud,":")+1..strlen(mud)];
					
				}
				// Changed to always lowercase, fixes game on muddomain
				mud = lower_case(mud);
				// Patched to lowercase to fix the openimc mudworld bridge
				what = lower_case(extract(info,"channel"));// what the hub calls it
				// Fixes changing of localname screwing up autolocalize
				split = imc_query_linelist();				
				i = sizeof(split);
				while(i--) {
					if(lineinfo[split[i]]["channel"] == what) 
						map_delete(lineinfo,split[i]);
				}
				lineinfo[mud] = ([]);
				lineinfo[mud]["channel"] = what;
				lineinfo[mud]["owner"] = extract(info,"owner");
				lineinfo[mud]["ops"] = extract(info,"operators");
				who = extract(info,"level");
				if(who == "Admin" || who == "Imm") lineinfo[mud]["adminonly"] = 1;
				// temp overriding to let players access ichat
				// disabled for distro
				//if(mud == "ichat") { lineinfo[mud]["adminonly"] = 0; }                
				lineinfo[mud]["policy"] = extract(info,"policy");
				lineinfo[mud]["invited"] = explode(extract(info,"invited")," ");
				imc_dmesg("channel","Channel " + lineinfo[mud]["channel"] + " configured as " + mud);				
				break;				
			case "ice-destroy" :
				// A hub has told us to destroy a channel
				// hub calls line this
				mud = extract(info,"channel");
				who = split[0];
				split = keys(lineinfo);
				if(!split) break;
				i = sizeof(split);
				if(!i) break;
				while(i--) {
					if(lineinfo[split[i]]["channel"] == mud) {
						map_delete(lineinfo,split[i]);
						imc_dmesg("misc", who + " instructed us to destroy the channel: " + mud);
						break;
					}
				}
				break;
					
			case "beep" :
				sscanf(split[4],"%s@",who);
				if(who) who = lower_case(who);
				where = capitalize(split[0]);
				if(!who) {
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);
					break;					
				}
				target=IMC_FIND_PLAYER(who);
				if(!target) {
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);					
					break;					
				}
				if(!playersettings[who]) playersettings[who] = ([]);
				if(imc_query_setting(target,"tellblock")) {
					// we dont want invis wizards given away by the tell block msg
					if(imc_wizard(target) && imc_invis(target)) 
						imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);			
					else
						imc_send_packet("tell","*",where,IMCERROR_PLAYERBLOCKINGTELLS);						
					break;					
				}
				if(imc_query_setting(target,"afk") == 1) 
					imc_send_packet("tell","*",where,imc_query_afkmsg(target));					
				imc_dmesg("tellsnoop","%^BOLD%^%^RED%^"+where + " beeps "+ capitalize(who) +"%^RESET%^");				
				if(imc_wizard(target) && imc_invis(target)) {
					imcwrite(IMCSETTING_PRETEXT +"%^BOLD%^%^RED%^"+ where +" is unaware of beeping you!"
						 +imc_chr(7)+"%^RESET%^",target);			
					imc_send_packet("tell","*",where,IMCERROR_COULD_NOT_FIND_PLAYER);			
				}								
				else imcwrite(IMCSETTING_PRETEXT +"%^BOLD%^%^RED%^"+ where +" beeps you!"+imc_chr(7)+"%^RESET%^",target);			
				break;
			case "whois-reply" :
				sscanf(split[4],"%s@",who);
				if(who) who = lower_case(who);				
				what = extract(info,"text");
				if(what == " " || !what) break; //To compensate for mudworlds broken I3:Bridge
				target = IMC_FIND_PLAYER(who);
				if(!target) break;
 				imcwrite(IMCSETTING_PRETEXT + split[0] + " replied to a find request :\n" + what,target);				
 				imc_dmesg("querys","Find reply to " + who);
 				break;
 			case "whois" :
 				sscanf(split[4],"%s@",who);
				if(who) who = lower_case(who);				
				target = IMC_FIND_PLAYER(who);
				if(!target) break;
 				if(imc_wizard(target) && imc_invis(target)) break;
 				what = replace_string(IMCMSG_FINDREPLY,"$WHO@WHERE",capitalize(who) + "@"+IMCLOGIN_LOCALNAME); 				
 				what = replace_string(what,"$WHO",capitalize(who));
 				imc_send_packet("whois-reply","*",split[0],what);
 				imc_dmesg("querys","Find query for " + who  + " replied to.");
 				break;
 			case "ping" :
 				imc_send_packet("ping-reply","*",split[0],"","path="+split[2]);
 				imc_dmesg("querys","Ping replied to from " + split[0]); 				
 				break;
 			case "ping-reply" :
 				sscanf(split[4],"%s@",who);
				if(who) who = lower_case(who);				
				what = replace_string(extract(info,"path")+"!","!","->");
				where = replace_string(split[2] +"!"+ IMCLOGIN_LOCALNAME,"!","->");				
				target = IMC_FIND_PLAYER(who);
				if(!target) break;	
				imc_dmesg("querys", capitalize(who) + " recieved a ping reply from " + split[0]);
				imcwrite(IMCSETTING_PRETEXT + "%^BOLD%^Traceroute for "+ split[0] + ":" ,target);
				imcwrite("%^CYAN%^Send path: %^BOLD%^  "  + what+ split[0][2..strlen(split[0])],target);		
				imcwrite("%^CYAN%^Return path: %^BOLD%^" + where,target); 		 				
 				break;
			case "emote" :
				what = extract(info,"text");
				who  = extract(info,"realfrom");
				imc_dmesg("channel",capitalize(who) + " " + what);
				break;				
			// This shouldnt trip on the ice-man network
			// its to stop my client from confusing the muddomain network
			case "keepalive-request" :
				imc_send_packet("is-alive","*",split[0],0,"versionid=\"" IMCINFO_VERSION "\" networkname="+network_name+" url="IMCINFO_WEBPAGE);
				break;					
			case "user-cache-request" :
			case "user-cache-reply" :
			case "user-cache" :
			case "ice-chan-who" :
				// on muddomain clients can get these but they should be ignored
			case "ice-refresh" :
				// old clients, this just prevents us from getting an unhandled packet				
				break;			
			default:			
				imc_dmesg("errors","Unhandled packet:" + split[3]);
				imc_dmesg("errors","%^BLUE%^PACKET:%^RESET%^"+info);
		
		}
		// everything breaks instead of returning
		// so anything here will be called on every packet, handled or not
		// so if you want to add something like that, do it here
	
}

mapping imc_query_mudlist()  { if(!imc_security_check()) return ([]); return mudinfo; }
mapping imc_query_lineinfo() { if(!imc_security_check()) return ([]); return lineinfo; }
string *imc_query_linelist() { if(!imc_security_check()) return ({}); return keys(lineinfo); }
mapping imc_query_mud(string mud) {
	if(!imc_security_check()) return ([]);
	if(!mudinfo) return 0;
	if(!mudinfo[mud]) return 0;
	return mudinfo[mud];
}
mapping imc_query_line(string line) {
	line = lower_case(line);
	if(!imc_security_check()) return ([]);	
	if(!lineinfo) return 0;
	if(!lineinfo[line]) return 0;
	return lineinfo[line];
}       
string *imc_query_wholistening(string line) {
		object *usrs;
		string *ret;
		int i;
		if(!imc_security_check()) return ({});
		if(!line) return ({ });
		line = lower_case(line);
		if(member_array(line,imc_query_linelist()) == -1) return ({ });
		usrs = users();
		i = sizeof(usrs);
		ret = ({});
		while(i--) {
			if(!imc_query_listening(usrs[i],line)) continue;			
			if(imc_wizard(usrs[i]) && imc_invis(usrs[i])) continue;
			ret += ({ imc_name(usrs[i]) });
		}
		return ret;
}

int imc_query_line_access(string who, string line) {
	string *invites;
	int i;	
	object ob;
	if(!imc_security_check()) return -1;
	if(!who || !line) return 0;	
	if(!lineinfo[line]) return 0;
	who = lower_case(who);
	ob = IMC_FIND_PLAYER(who);
	if(!ob) return 0;	
	if(lineinfo[line]["adminonly"] == 1 && !imc_admin(ob)) return 0;
	if(lineinfo[line]["policy"] == "private") {
		invites = lineinfo[line]["invited"];
		i=sizeof(invites);
		if(!i) return 0;
		while(i--) {
			if(!invites[i]) continue;
			if(lower_case(invites[i]) == lower_case(IMCLOGIN_LOCALNAME)) return 1;
			if(lower_case(invites[i]) == lower_case(who+"@"+IMCLOGIN_LOCALNAME)) return 1;
		}		
		return 0;
	}
	return 1;
}
// return of 0 means its now blocked
// return of 1 means its no longer blocked
int imc_toggle_block(object who,string line) {
	string nme;
	if(!who || !line) return -1;
	if(!imc_security_check()) return -1;
	nme = lower_case(imc_name(who));	
	if(!nme) return -1;
	line = lower_case(line);
	if(member_array(line,imc_query_linelist()) == -1) return -1;
	if(imc_query_line_access(nme,line) == 0) return -1;	
	if(!playersettings[nme]) playersettings[nme] = ([]);
	if(!playersettings[nme]["blocked"]) !playersettings[nme]["blocked"] = ({});
	if(member_array(line,playersettings[nme]["blocked"]) == -1) {
		playersettings[nme]["blocked"] += ({ line });
		save_imc_d();
		return 0;
	}
	else {
		playersettings[nme]["blocked"] -= ({ line });
		save_imc_d();
		return 1;
	}
	return -1;
}
int imc_query_block(object who, string line) {
	string nme;
	if(!imc_security_check()) return -1;
	if(!who || !line) return -1;
	nme = lower_case(imc_name(who));	
	if(!nme) return -1;
	line = lower_case(line);
	if(!playersettings[nme]) return 0;
	if(!arrayp(playersettings[nme]["blocked"])) return 0;
	if(member_array(line,playersettings[nme]["blocked"]) != -1) return 1;
	return 0;
}
	
string imc_query_reply(object who) {
	string nme;
	if(!imc_security_check()) return "";
	if(!who) return "Noone";
	nme = lower_case(imc_name(who));
	if(!nme) return "Noone";
	if(!playersettings[nme]) return "Noone";
	if(!playersettings[nme]["reply"]) return "Noone";
	return playersettings[nme]["reply"];
}
int imc_query_listening(object who, string line) {
	string nme;	
	if(!imc_security_check()) return -1;
	if(!who || !line) return -1;
	nme = lower_case(imc_name(who));
	if(!nme) return -1;
	line = lower_case(line);
	if(member_array(line,imc_query_linelist()) == -1) return -1;
	if(!imc_query_line_access(nme,line)) return 0;
	if(!playersettings[nme]) return 1;
	if(playersettings[nme]["globalblock"]) return 0;	
	if(!playersettings[nme]["blocked"]) return 1;
	if(!arrayp(playersettings[nme]["blocked"])) return 1;	
	if(member_array(line,playersettings[nme]["blocked"]) == -1) return 1;
	else return 0;		
	
}
string imc_query_afkmsg(object who)  {
	string nme;
	if(!imc_security_check()) return "";
	if(!who) return "";
	nme = lower_case(imc_name(who));
	if(!nme) return "";	
	if(!playersettings[nme]) return IMCMSG_DEFAULTAFK;
	if(!playersettings[nme]["afkmsg"]) return IMCMSG_DEFAULTAFK;
	return playersettings[nme]["afkmsg"];
}
string imc_setafkmsg(object who,string msg) {
	string nme;
	if(!imc_security_check()) return "";
	if(!who) return "";
	nme = lower_case(imc_name(who));
	if(!nme) return "";	
	if(!playersettings[nme]) playersettings[nme] = ([]);
	if(!msg) {
		playersettings[nme]["afkmsg"] = IMCMSG_DEFAULTAFK;		
	}
	else playersettings[nme]["afkmsg"] = msg;
	return (string)playersettings[nme]["afkmsg"];
	
}
// query_setting and toggle setting are only for (int) responses
int imc_query_setting(object who,string setting) {
	string nme;
	if(!imc_security_check()) return -1;
	if(!who) return -1;
	nme = lower_case(imc_name(who));
	if(!nme) return -1;	
	if(!playersettings[nme]) return 0;	
	setting = lower_case(setting);
	if(!playersettings[nme][setting]) return 0;
	return (int)playersettings[nme][setting];
}

// returns the state of the setting AFTER changing it
int imc_toggle_setting(object who, string setting) {
	string nme;
	if(!imc_security_check()) return -1;
	if(!who) return -1;
	nme = lower_case(imc_name(who));
	if(!nme) return -1;	
	if(!playersettings[nme]) playersettings[nme] = ([]);
	if(!playersettings[nme][setting]) {
		playersettings[nme][setting] = 1;
		save_imc_d();
		return 1;
	}
	playersettings[nme][setting] = 0;
	save_imc_d();
	return 0;
}
// banning someone whos already banned unbans em
string imc_add_ban(string who, int type) {
	string banclass;
	if(!imc_security_check()) return "";
	if(!who) return "";
	who = lower_case(who);
	if(type == IMCBAN_LOCAL) banclass = "local";
	else if(type == IMCBAN_REMOTE) banclass = "remote";	
	if(!banclass) return IMCERROR_NOSUCHBAN;
	if(!playersettings["IMC-BANS"]) playersettings["IMC-BANS"] = ([]);
	if(!arrayp(playersettings["IMC-BANS"][banclass])) playersettings["IMC-BANS"][banclass] = ({ });
	if(member_array(who,playersettings["IMC-BANS"][banclass]) != -1) {
		 playersettings["IMC-BANS"][banclass] -= ({ who });
		 save_imc_d();
		 return IMCMSG_BANOFF;
	}
	playersettings["IMC-BANS"][banclass] += ({ who });
	save_imc_d();
	return IMCMSG_BANON;
}
string *imc_query_all_bans(int type) {
	string banclass;
	if(!imc_security_check()) return ({});
	if(type == IMCBAN_LOCAL) banclass = "local";
	else if(type == IMCBAN_REMOTE) banclass = "remote";	
	if(!banclass) return ({ });
	if(!playersettings["IMC-BANS"]) return ({});
	if(!playersettings["IMC-BANS"][banclass]) return ({});
	return (string*)playersettings["IMC-BANS"][banclass];
}
int imc_query_ban(string who,int type) {
	string banclass;
	if(!imc_security_check()) return -1;
	if(!who) return 0;
	who = lower_case(who);
	if(type == IMCBAN_LOCAL) banclass = "local";
	else if(type == IMCBAN_REMOTE) banclass = "remote";	
	if(!banclass) return 0;
	if(!playersettings["IMC-BANS"]) return 0;
	if(!arrayp(playersettings["IMC-BANS"][banclass])) return 0;
	if(member_array(who,playersettings["IMC-BANS"][banclass]) != -1) {
		// if you want a message when a message gets bounced by a ban
		// do it here
		return 1;
	} 
	return 0;
}
string *imc_querytellhist(string who) {
	if(!imc_security_check()) return ({});
	who = lower_case(who);
	if(!playersettings[who]) return ({});
	if(!playersettings[who]["tellhist"]) return ({});
	else return playersettings[who]["tellhist"];
}
mapping imc_query_stats() {
	return playersettings["IMC-STATS"];	
}
string imc_purge_player(string nme) { 
	string ret;
	if(!imc_security_check()) return "";
	if(!playersettings[nme]) 
		ret = IMCERROR_NOPURGE;
	map_delete(playersettings,nme);
	if(!ret) ret = IMCMSG_PURGED;
	save_imc_d();
	return ret;

}
string *imc_query_players() {
	string *list;
	int i;		
	if(!imc_security_check()) return ({});
	list = ({})+ keys(playersettings);	
	// we dont want to show all the internal ones
	i = sizeof(list);
	while(i--) if(list[i][0..2] == "IMC") list -= ({ list[i] });
	return list;
	
}
private string imc_who_reply(string type) {
		string what,who,*lines, *adm,*plyr;
		object ob, *usrs;
		int i;		
		;
		if(sscanf(type,"finger %s",who) == 1) {
			ob = IMC_FIND_PLAYER(who);
			if(!ob) return replace_string(IMCERROR_COULD_NOT_FIND_PLAYER,"$N",capitalize(who));			
			what  = "%^CYAN%^Player Information%^RESET%^\n"
			        "%^BOLD%^------------------%^RESET%^";
			what += "\n%^RESET%^%^CYAN%^Name   %^BOLD%^: " + capitalize(who);
			what +=	"\n%^RESET%^%^CYAN%^Status %^BOLD%^: " + 
				((int)imc_query_setting(ob,"afk")?"Afk":"Active");
			what += "\n%^RESET%^%^CYAN%^Permission Level     %^BOLD%^: ";
			if(imc_admin(ob))          what += IMCINFO_ADMRANKNAME;
			else if(imc_wizard(ob))    what += IMCINFO_WIZRANKNAME;
			else                       what += IMCINFO_PLYRANKNAME;			
			what += "\n%^RESET%^%^CYAN%^Recieving IMC2 tells %^BOLD%^: "+ 
				((int)imc_query_setting(ob,"tellblock")?"No":"Yes");
			what += "\n%^RESET%^%^CYAN%^Subscribed channels  %^BOLD%^: ";
			lines = imc_query_linelist();
			i=sizeof(lines);
			if(!i) return what + "None";
			while(i--) if(imc_query_listening(ob,lines[i])) what += lines[i]+ " ";
			return what;			
		}
		// We know its not a finger, so it must be a one word reply
		// if we dont understand the type, we'll give em the who list
		switch(type) {
			case "help" :
				what = "%^BOLD%^Available imcminfo types:%^RESET%^\n"
				      "%^CYAN%^help       %^BOLD%^- this list%^RESET%^\n"
				      "%^CYAN%^who        %^BOLD%^- who listing%^RESET%^\n"
				      "%^CYAN%^info       %^BOLD%^- mud information%^RESET%^\n"
				      "%^CYAN%^list       %^BOLD%^- active IMC connections%^RESET%^\n"
				      "%^CYAN%^istats     %^BOLD%^- network traffic statistics%^RESET%^\n"
				      "%^CYAN%^finger xxx %^BOLD%^- finger player xxx%^RESET%^\n"
				      ;
				break;  
			case "info" :
				what = "%^BOLD%^Site Information"
				       "\n%^RESET%^%^CYAN%^IMC Version : %^BOLD%^" IMCINFO_VERSION
				       "\n%^RESET%^%^CYAN%^Address     : %^BOLD%^" IMCINFO_ADDRESS
				       "\n%^RESET%^%^CYAN%^Webpage     : %^BOLD%^" IMCINFO_WEBPAGE
				       "\n%^RESET%^%^CYAN%^Admin Email : %^BOLD%^" IMCINFO_ADMINEMAIL
				       "\n%^RESET%^%^CYAN%^Details     : %^BOLD%^" IMCINFO_DETAILS
				       ;						
				break;
			case "list" :
				what = imc_formated_mudlist(mudinfo);
				break;
			case "istats" :
				what  = "%^BOLD%^IMC2 Stats so far this session";
				what += "\n%^RESET%^CYAN%^ Recieved packets    : %^BOLD%^" + playersettings["IMC-STATS"]["RX"];
				what += "\n%^RESET%^CYAN%^ Recieved bytes      : %^BOLD%^" + playersettings["IMC-STATS"]["RS"];
				what += "\n%^RESET%^CYAN%^ Transmitted packets : %^BOLD%^" + playersettings["IMC-STATS"]["TX"];
				what += "\n%^RESET%^CYAN%^ Transmitted bytes   : %^BOLD%^" + playersettings["IMC-STATS"]["TS"];
				break;
			default:
				what = read_file(IMCFILE_WHOHEADER);
				if(!what) what = "ERROR: Could not read who header.\n";
				usrs = users();
				i=sizeof(usrs);
				adm = ({}); plyr = ({});
				while(i--) { 
					if(!interactive(usrs[i])) continue;
					if(imc_admin(usrs[i]) && imc_invis(usrs[i])) continue;
					if(imc_admin(usrs[i])) adm += ({ imc_name(usrs[i]) });
					else plyr +=  ({ imc_name(usrs[i]) });
				}
				if(!sizeof(adm) && !sizeof(plyr)) { 
					what += IMCMSG_NOONEHOME;
					break;
				}
				if(sizeof(adm)) what += "%^RED%^Immortals:%^RESET%^\n" + imc_format_page(adm,3);
				if(sizeof(plyr)) what += "%^BLUE%^\nPlayers:%^RESET%^\n" + imc_format_page(plyr,3);
				what += "\n\nTotal users shown: " + (sizeof(adm) + sizeof(plyr));
				what += "\nInvis immortals are not shown.";
				what += "\nLogin via: " IMCINFO_ADDRESS;
				what = replace_string(what,"\n","\n\r");
				what = replace_string(what,"%^MUDNAME%^",mud_name());
				break;
			}
		return what;
}
// If the hub closes the link, it goes down, and stays down
// till someone restarts it

private void IMC_close(object socket) {
	imc_dmesg("misc","Socket closed by hub, link is down.");	
	if(sock) sock->remove();
	playersettings["IMC-LINKDOWN"] = 1;
	save_imc_d();
}


// Notice we're not converting INITTERM WINDOW OR ENDTERM
// Also notice i added %^UNDERLINE%^ its part of the new pinkfish codes, but not the ver we use
// pinkfish oddity, orange and yellow, yellow, boldyellow, and bold orange are all the same color
// ansi has 8 colors, we have 9 codes:)
private string *pinkfish_codes = ({ "RED","BLUE","ORANGE","YELLOW","GREEN","BLACK","WHITE","CYAN","MAGENTA","B_RED","B_BLUE","B_ORANGE",
 		            "B_YELLOW","B_GREEN","B_MAGENTA","B_BLACK","B_WHITE","B_CYAN","FLASH","BOLD","RESET","UNDERLINE" });
// dont load this bigass mapping if outgoing color support is disabled
#ifdef IMCSETTING_COLORSUPPORTOUT 
private mapping imc_outmap = ([
	     "BLACK"   : "~x",
	     "RED"     : "~r",
	     "GREEN"   : "~g",
	     "ORANGE"  : "~y",
	     "YELLOW"  : "~Y",
	     "BLUE"    : "~b",
	     "MAGENTA" : "~p",
	     "CYAN"    : "~c",
	     "WHITE"   : "~w",
	     "BOLDBLACK"   : "~D",
	     "BOLDRED"     : "~R",
	     "BOLDGREEN"   : "~G",
	     "BOLDORANGE"  : "~Y",
	     "BOLDYELLOW"  : "~Y",
	     "BOLDBLUE"    : "~B",
	     "BOLDMAGENTA" : "~P",
	     "BOLDCYAN"    : "~C",
	     "BOLDWHITE"   : "~W",
	     "B_BLACK"   : "^x",
	     "B_RED"     : "^r",
	     "B_GREEN"   : "^g",
	     "B_ORANGE"  : "^O",
	     "B_YELLOW"  : "^Y",
	     "B_BLUE"    : "^B",
	     "B_MAGENTA" : "^p",
	     "B_CYAN"    : "^c",
	     "B_WHITE"   : "^w",
	     "RESET"     : "~!",
	     "BOLD"      : "~L",
	     "FLASH"     : "~$",
	     "UNDERLINE" : "~u", 
	     "REVERSE"   : "~v", /* test */
	     "ITALIC"    : "~i", 
]);	     
#endif
	     //"UNDERLINE" : "~u", // No such code on our local mud, so if you use it, it'll
	     			   //  look fine to them but not to us 	     
	     //"REVERSE"   : "~v"  /* same story as underline */
	     //"ITALIC"    : "~i", /* Even the ansi code for this one dosnt work in zmud, i wouldnt use it */     
	     


//pinkfish search, search for %^, goto next %^, if thing in between is a code, use it, if not, ignore and move on
//now when it moves on, it reuses the second %^, so %^BOLD%^RED%^ is valid (yea, i didnt know that either)
// found out while playing with it to make sure parser worked
// figured out explode does this much faster/cleaner
#define IMC_BOLD       1
#define IMC_FLASH      2
#define IMC_UNDERLINE  4
#define IMC_ITALIC     8
#define IMC_REVERSE    16


private string imc_convert_outgoing(string what) {
	string *split;
	int i,x;
// THis prevents us getting compiler warnings about
// unused variables if colorsupport is off
#ifdef IMCSETTING_COLORSUPPORTOUT	
	string codes;
	int bitfield;
	if(!what) return what;
	what = replace_string(what,"%^RESET%^","%^RESET%^"+IMCSETTING_RESETCOLOR);	
#endif	
	if(!what) return what;
	split = explode(what,"%^");
	x = sizeof(split);	
	for(i=0;i<x;i++) {
		if(member_array(split[i],pinkfish_codes) != -1) {
#ifdef IMCSETTING_COLORSUPPORTOUT 
				codes = imc_outmap[split[i]];;
				if(split[i] == "RESET") bitfield = 0; 						
				if(bitfield & IMC_BOLD)      codes += "~L";
				if(bitfield & IMC_FLASH)     codes += "~$";
				if(bitfield & IMC_UNDERLINE) codes += "~u";
				if(bitfield & IMC_ITALIC)    codes += "~i";
				if(bitfield & IMC_REVERSE)   codes += "~v";																
				switch(split[i]) {
					case "BOLD"      : bitfield |= IMC_BOLD;      break;
					case "FLASH"     : bitfield |= IMC_FLASH;     break;
					case "UNDERLINE" : bitfield |= IMC_UNDERLINE; break;
					case "ITALIC"    : bitfield |= IMC_ITALIC;    break;
					case "REVERSE"   : bitfield |= IMC_REVERSE;   break;
					
				}				
				split[i] = codes;				
#else
				split[i] = "";
#endif			
		}
	}
	return implode(split,"");
}
//incomeing translation, i did this as a quick hack
// did a proper 'parser' that only traversed
// the string once, cpu time on replace version 1000-1200
// on the other version, 7000-7500
// Times are from time_expression
// THe problem lies when i try and get replace string to deal
// with ^'s, it sees them in color codes plaed by previous 
// replace strings
// I made a workaround to deal with it, but it was slow
// So, we use the 'proper' parser
// Which still isnt perfect
// Still needs 1 more rewrite, will be in next version
private string imc_convert_incomeing(string what) {
	int marker,lastmarker;
	string ret;	
	string *escapes = ({"~", "^" });
	mapping cmap;
	if(!what) return what;
	marker = strlen(what)-1;
	lastmarker = marker;
	ret = "";
	cmap = ([]) + imc_colormapping + imc_colorescapes;
	while(marker--) {
		if(member_array(what[marker..marker],escapes) != -1) {
#ifdef IMCSETTING_COLORSUPPORTIN
			if(stringp(cmap[what[marker..marker+1]])) 
				ret = cmap[what[marker..marker+1]] + what[marker+2..lastmarker] + ret;
			else 
				ret = what[marker..lastmarker] + ret;
#else
			if(stringp(cmap[what[marker..marker+1]])) 
				ret = what[marker+2..lastmarker] + ret;
			else 
				ret = what[marker..lastmarker] + ret;

#endif
			lastmarker = marker-1;
		}
	}
	ret = what[0..lastmarker] + ret;
	return ret;
}


