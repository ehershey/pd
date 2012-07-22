#!/usr/bin/perl -w

#
#  Written by Mats Persson  (matpe@lysator.liu.se)
#                           (god @ NannyMUD)
#

require 5.003;
use strict;

BEGIN { $ENV{PATH} = '/usr/ucb:/bin' }
use Socket;
use Carp;
 
#################################
#
# Configuration variables
#
#

my $port = shift || 9990;

my $topdir = "/home/primal/mud/libraries/beta-ii/ftp";
my $logfile = "/home/primal/mud/libraries/logs/ftp.log";

my $server = "Primal Darkness End-User";
my $usertype = "$server";
my $timeout = 1800;

my $passive_port = 9993;

## Trying to figure out your ip-number. Might need configure by hand.
my $hostname = "217.160.254.143";
##chomp($hostname);
my $passive_ip = join('.',unpack('C4',((gethostbyname($hostname))[4])[0]));

#################################
#
# Internal variables
#
#

my $dataport = 4002;
my $dataaddr;
my $proto = getprotobyname('tcp');

my $passive = 0;

my $user = "<none>";
my $crpt;
my $level;
my $cwd;
my $ipnumber;

my $Type = "A";

my $waitedpid = 0;
my $paddr;
 
sub spawn;
sub mine;
sub logmsg { print STDERR "$$: @_ at ", scalar localtime, "\n" }
#No log to STDERR:  sub logmsg {}

#################################
#
# Server code
#
#

socket(Server, PF_INET, SOCK_STREAM, $proto) || die "socket: $!";
setsockopt(Server, SOL_SOCKET, SO_REUSEADDR, pack("l", 1)) 
    || die "setsockopt: $!";
$port =~ /(\d+)/;
bind(Server, sockaddr_in($1, INADDR_ANY)) || die "bind: $!";
listen(Server,SOMAXCONN) || die "listen: $!";
 
logmsg "ftpserver started on port $port";
 
sub REAPER {
#    $SIG{CHLD} = \&REAPER;  # loathe sysV
    $waitedpid = wait;
    logmsg "reaped $waitedpid" . ($? ? " with exit $?" : '');
}
 
$SIG{CHLD} = \&REAPER;

while (1) {
 
    for ( $waitedpid = 0;
	 ($paddr = accept(Client,Server)) || $waitedpid;
	 $waitedpid = 0, close Client)
    {
#       next if $waitedpid;
	next unless $paddr;
	my($port,$iaddr) = sockaddr_in($paddr);
	$ipnumber = inet_ntoa($iaddr);
	$hostname = gethostbyaddr($iaddr,AF_INET) || $ipnumber;
	$dataaddr = $iaddr;
 
	logmsg "connection from $hostname [$ipnumber] at port $port";
 
	spawn \&mine;
    }

    sleep 5;
    logmsg "server restarted";
 
}
 
sub spawn {
    my $coderef = shift;
 
    unless (@_ == 0 && $coderef && ref($coderef) eq 'CODE') {
        confess "usage: spawn CODEREF";
    }
 
    my $pid;
    if (!defined($pid = fork)) {
        logmsg "cannot fork: $!";
        return;
    } elsif ($pid) {
        logmsg "begat $pid";
        return; # i'm the parent
    }
    # else i'm the child -- go spawn
    open(STDIN,  "<&Client")   || die "can't dup client to stdin";
    open(STDOUT, ">&Client")   || die "can't dup client to stdout";
    ## open(STDERR, ">&STDOUT") || die "can't dup stdout to stderr";
    exit &$coderef();
}

#################################
#
# Spawned child code
#
#

sub players_path {
    my $u = shift;
    return "$topdir/adm/save/users/".substr($u,0,1)."/$u";

    # or perhaps for some mudlibs that uses the path /players/m/mats
    # return "$topdir/players/".substr($u,0,1)."/$u";
}

sub make_path {
    my ($c,$p) = @_;
    my @res;
    my $s;
    
    if ($p =~ /^\//) { 
	$p = "$topdir/$'";
    } else { 
	$p = "$c/$p";
    }
    foreach $s (split(/\//,$p)) {
	if ($s eq "..") {
	    pop @res;
	} elsif ($s eq ".") {
	    next;
	} elsif ($s eq "~") {
	    @res = split(/\//,&players_path($user));
	} elsif ($s =~ /~(\w+)/) {
	    @res = split(/\//,&players_path($1));
	} else {
	    push @res, $s;
	}
    }
    $s = join("/",@res);
    if ($s !~ /^$topdir/) { return $topdir; }
    $s;
}

sub read_acl {
    my $rest = "";

    $_[1] and open(ACL,"$_[0]/.acl:$_[1]")
    or open(ACL,"$_[0]/.acl")
    or ($_[0] eq $topdir) and return ""
    or return &read_acl(&make_path($_[0],".."));

    while (<ACL>) {
	chop;
	if (/^$user:\s*/io) {
	    close ACL;
	    return "PDALRWUX" if $' eq "ALL";
	    return "" if $' eq "NONE";
	    return $';
	}
	if (/^\$REST:\s*/io) {
	    $rest = "PDALRWUX" if $' eq "ALL";
	    $rest = "" if $' eq "NONE";
	    $rest = $';
	}
    }
    close ACL;
    $rest;
}

sub check_list_access {
    &read_acl(@_) =~ /L/o;
}

sub check_read_access {
    &read_acl(@_) =~ /R/o;
}

sub check_write_access {
    &read_acl(@_) =~ /W/o;
}

sub check_replace_access {
    &read_acl(@_) =~ /DA/o;
}

sub open_data_socket {
    print "150 File status okay; opens data connection.\n";
    if ($passive) {
	accept(SOCK,PASS) || die "accept: $!";;
    } else {
	socket(SOCK, PF_INET, SOCK_STREAM, $proto)  || die "socket: $!";
	connect(SOCK,sockaddr_in($dataport, $dataaddr)) || die "connect: $!";
    }
}

sub close_data_socket {
    print "226 Closing data connection.\n";
    close SOCK;
    close PASS if $passive;
}

sub cut_top {
    my $d = shift;
    $d =~ s/^$topdir//;
    $d eq "" ? "/" : $d;
}

sub print_dir {
    my ($cmd,$td, $match, $pre) = @_;
    my @dl;
    my $f;
    my $tmp;

    $tmp=1 if $cmd =~ /#/;
    opendir DL,$td;
    foreach $f (readdir DL) {
	$match and next unless $f =~ /^$match/;
	$tmp and next unless -d "$td/$f";
	$tmp and next unless &check_list_access("$td/$f");
	push @dl,[$f,(stat("$td/$f"))[7],(stat(_))[9]];
    }
    closedir DL;

    if ($cmd =~ /r/) {
	if ($cmd =~ /t/) {
	    @dl = sort {$b->[2] <=> $a->[2]} @dl;
	} else {
	    @dl = sort {$b->[0] cmp $a->[0]} @dl;
	}
    } else {
	if ($cmd =~ /t/) {
	    @dl = sort {$a->[2] <=> $b->[2]} @dl;
	} else {
	    @dl = sort {$a->[0] cmp $b->[0]} @dl;
	}
    }

    foreach $f (@dl) {
	next if $cmd !~ /a/ && ($f->[0] eq "." || $f->[0] eq "..");
	if (-d "$td/$f->[0]" && $match) {
	    &print_dir($cmd,"$td/$f->[0]",0,"$f->[0]/");
	    next;
	}
	if ($cmd =~ /l/) {
	    $tmp = scalar(localtime($f->[2]));
	    $tmp =~ s/..:..:..// if $f->[2]+15552000 < time;
	    print SOCK
		(-d _?"drwsrws---":"-rw-rw----"),
		"   1 mud      mud     ",
		sprintf("%10d",$f->[1]),
		substr($tmp,3,13)," ";
	}
	print SOCK "$pre$f->[0]",($cmd =~ /F/ && -d _?"/":""),"\r\n";
    }
}

sub do_dir {
    my $cmd = shift;
    my $td = shift;
    my $match = 0;
    my $file = "";

    if ($cmd eq "LIST") { 
	$td .= " -l";
    }
    $cmd = "";
    foreach (split(/ /,$td)) {
	if (/^-(\w+)/) {
	    $cmd .= $1;
	}
	elsif (/\*$/) {
	    $match = "$`.*";
	}
	else {
	    $file = $_;
	}
    }
#    logmsg "cmd $cmd  match $match  file $file";

    $file = $file ? &make_path($cwd,$file) : $cwd;
    if (!&check_list_access($file)) {
#	print "550 No access to ",&cut_top($file),".\n";
#	return;
	$cmd .= "#";
    }
    if (! -d $file) {
	print "550 No such directory, ",&cut_top($file),".\n";
	return;
    }

    &open_data_socket();

    &print_dir($cmd, $file, $match, "");

    &close_data_socket();
}

sub do_retr {
    my $td = shift;
    my $chunk = "";

    $td = &make_path($cwd,$td);
    $td =~ m|/([^/]*)$|;
    if (!&check_read_access($`,$1)) {
	print "550 No read access to ",&cut_top($td),".\n";
	return;
    }
    if (! -f $td) {
	print "550 No such file, ",&cut_top($td),".\n";
	return;
    }
    if (!open(TMP,$td)) {
	warn "Can't open $td for retrieve.\n";
	print "550 No read access to ",&cut_top($td),".\n";
	return;
    }

    &open_data_socket();

    read TMP,$chunk,1000000;
    $chunk =~ s/\n/\r\n/gs if ($Type eq "A");
    print SOCK $chunk;
    close TMP;

    &close_data_socket();

    if ($logfile && open(TMP,">>$logfile")) {
	print TMP "$user $hostname RETR $td $Type ",length($chunk),
	          substr(scalar localtime,3),"\n";
	close TMP;
    }
}

sub do_stor {
    my $td = shift;
    my $chunk = "";
    my $file;

    $td = &make_path($cwd,$td);
    ($file) = $td =~ m|/([^/]*)$|;
    if ($file =~ /^\.acl/) {
	print "550 No write access to ",&cut_top($td),".\n";
	return;
    }
    if (-e $td) {
	if (-f $td) {
	    if (!&check_replace_access($`,$file) || ! -w $td) {
		print "550 No write/replace access to ",&cut_top($td),".\n";
		return;
	    }
	} else {
	    print "550 No write access to ",&cut_top($td),".\n";
	    return;
	}
    } else {
	if (!&check_write_access($`,$file)) {
	    print "550 No write access to ",&cut_top($td),".\n";
	    return;
	}
    }
    if (!open(TMP,">$td")) {
	warn "Can't open $td for store.\n";
	print "550 No write access to ",&cut_top($td),".\n";
	return;
    }

    &open_data_socket();

    read SOCK,$chunk,1000000;
    $chunk =~ s/\r\n/\n/gs if ($Type eq "A");
    $chunk =~ s/\r\n/\n/gs if ($Type eq "A");
    print TMP $chunk;
    close TMP;

    &close_data_socket();

    if ($logfile && open(TMP,">>$logfile")) {
	print TMP "$user $hostname STOR $td $Type ",length($chunk),
	          substr(scalar localtime,3),"\n";
	close TMP;
    }

}

sub check_user {
    $user = shift;
    $user =~ s/^mud://;
    my $pfile = &players_path("$user.o");
    $crpt = 0;
    if (-f $pfile) {
	open(TMP,$pfile);
	while (<TMP>) {
	    /^password "([^"]+)"/ and $crpt = $1;
	    /^level (\d+)/ and $level = $1;
	}
	close TMP;
    }
    if (!$crpt) {
	print "530 No such user.\n";
	return;
    }
    if ($level<100) {
	print "530 Go away mortal.\n";
	$crpt = 0;
	return;
    }
    print "331 $usertype name ok, need password.\n";
}

sub check_password {
    if (crypt($_[0],substr($crpt,0,2)) eq $crpt) {
	$cwd = &players_path($user);
	if (! -d $cwd) {
	    $cwd = "$topdir/realms/$user";
	}
	print "230 $usertype $user logged in.\n";
	return;
    }
    print "530 Login incorrect.\n";
    $crpt = 0;
}

$SIG{ALRM} = sub { exit; };

sub mine {
    my (@DP,$tmp,$sent);
    $| = 1;
    select(undef,undef,undef,0.5);
    print "220 $server FTP server (mftpd v2.0) ready.\n";
    alarm $timeout;
    while (<>) {
	chop; chop;
	$sent = $_;
	select(undef,undef,undef,0.15);

	if (/^USER (.*)/i) {
	    &check_user($1);
	} 

	elsif (/^PASS (.*)/i) {
	    &check_password($1);
	    $sent = "PASS ********";
	}

	elsif (/^QUIT/i) {
	    return 0;
	}
	
	elsif ($_ && !$crpt) {
	    print "530 Not logged in.\n";
	}

	elsif (/^SYST/i) {
	    print "215 UNIX system type.\n";
	}

	elsif (@DP = /^PORT (\d+),(\d+),(\d+),(\d+),(\d+),(\d+)/i) {
	    $dataport = $DP[4]*256+$DP[5];
#	    $dataaddr = inet_aton("$DP[0].$DP[1].$DP[2].$DP[3]");
	    logmsg "data: $DP[0].$DP[1].$DP[2].$DP[3] $dataport";
	    print "200 PORT Command okay.\n";
	}

	elsif (/^(NLST) *(.*)/i || /^(LIST) *(.*)/i) { 
	    &do_dir($1,$2);
	}

	elsif (/^RETR *(.*)/i) {
	    &do_retr($1); 
	}

	elsif (/^STOR *(.*)/i) {
	    &do_stor($1); 
	}

	elsif (($tmp) = /^CWD *(.*)/i) {
	    $tmp = "~" unless $tmp;
	    $tmp = &make_path($cwd,$tmp);
	    if (-d $tmp) {
		$cwd = $tmp;
		print "250 CWD to ",&cut_top($cwd),"\n";
	    } else {
		print "550 CWD No such directory.\n";
	    }
	}

	elsif (/^CDUP/i) {
	    $tmp = &make_path($cwd,"..");
	    if (-d $tmp) {
		$cwd = $tmp;
		print "200 CDUP to ",&cut_top($cwd),"\n";
	    } else {
		print "550 CWD No such directory.\n";
	    }
	}

	elsif (/^PWD/i) {
	    print "250 \"",&cut_top($cwd),"\"\n";
	}

	elsif (/^MODE S/i) {
	    print "200 MODE Stream.\n";
	}
	elsif (/^TYPE A/i) {
	    print "200 TYPE ASCII.\n";
	    $Type = "A";
	}	
	elsif (/^TYPE I/i) {
	    print "200 TYPE Image.\n";
	    $Type = "I";
	}	
	elsif (/^PASV/i) {
	    socket(PASS, PF_INET, SOCK_STREAM, $proto) || die "socket: $!";
	    setsockopt(PASS, SOL_SOCKET, SO_REUSEADDR, pack("l", 1)) 
		|| die "setsockopt: $!";
	    bind(PASS, sockaddr_in($passive_port, INADDR_ANY)) || die "bind: $!";
	    listen(PASS,SOMAXCONN) || die "listen: $!";
	    $passive_ip =~ s/\./,/g;
	    print "227 Entering Passive Mode ($passive_ip,";
	    print int($passive_port/256),",",$passive_port % 256,").\n";
	    $passive = 1;
	}
	elsif (/^NOOP/i) {
	    print "200 OK.\n";
	}

	else {
	    print "502 Command not implemented.\n";
	}

	logmsg "$user sent $sent";
	alarm $timeout;
    }
}

####### TODO #########
#
# priority acl and groups
# bind to port 21 (uid 0)
#
