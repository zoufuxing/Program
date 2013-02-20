#!/usr/bin/perl -w
use strict;
use Cache::Memcached;
use Data::Dumper;


my $key='shopex16';
my $value='485';
my $expires = 1;

my $log='/tmp/mem.log';
my ($sec,$min,$hour,$day,$mon,$year,$wday,$yday,$isdst)=localtime();

open(LOG,">>$log");

#print LOG ("monitor memcache\n");
system("chmod 777 $log") if(-f $log);
print LOG ("$year-$mon-$day $hour:$min:$sec");

my $mem = new Cache::Memcached ({
 	  servers => ["192.168.10.153:11211"],
 	  });

$mem->set_connect_timeout(0.1);
#print("$mem->{'connect_timeout'}\n");
#print Dumper($mem);

$mem->set($key,$value,$expires);


my $result=$mem->get($key);

if($result){
  print("$result\n");
  print LOG ("	Memcache is ative\n");
}else{
  print("0\n");
  print LOG ("	Can't connect memcache or connect timeout\n");
}

$mem->disconnect_all;
