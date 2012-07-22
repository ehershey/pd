//  WebServices Agent
//  Whit

#include <daemons.h>
#include <socket.h>
#include <network.h>

#define DATA_DIR "/daemon/webservices/"

inherit DATA_DIR + "protocol.c";
inherit DATA_DIR + "authentication.c";
inherit DATA_DIR + "player.c";

void initConnection() {
	int fd;

	fd = socket_create(STREAM, "socket_readcallback", "listenClose");
	socket_bind(fd, 12333);
	socket_listen(fd, "listenInbound");
}

void listenInbound(int fd, string txt) {
	socket_accept(fd, "listenData", "listenClose");
}

void listenData(int fd, mixed hmm) {
	mixed ret;
	
//	CHAT_D->do_raw_chat("network", "Listen <network> Received: " + hmm);
	if(!ret = breakdown(hmm)) {
		socket_close(fd);
	} else {
		socket_write(fd, identify(ret));
	}
}

void listenClose(int fd) {
//	CHAT_D->do_raw_chat("network", "Inbound <network> Socket closed on fd " + fd);
}

void create() {
	call_out("initConnection", 2);
}

// Unneeded Callbacks
int socket_readcallback() {
}
