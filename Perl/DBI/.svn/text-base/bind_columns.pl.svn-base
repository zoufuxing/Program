#!/usr/bin/perl -w
use strict;
use DBI;

my $driver="DBI:mysql";
my $database="sample_db";
my $user="sample";
my $passwd="sample";
my $host="192.168.10.153";

my $dbh=DBI->connect("$driver:database=$database;host=$host;user=$user;password=$passwd");

my $sth=$dbh->prepare("select name,wins,losses from teams");
$sth->execute() or die "Can't prepare sql statment".$sth->errstr;

my ($name,$wins,$losses);
$sth->bind_columns(\$name,\$wins,\$losses);

print "\n Selected data for teams.\n\n";
printf "\t%-20s%-8s%-8s\n","Name","Wins","Losses";

while($sth->fetch())
{
  printf "   %-25s%3d%8d\n",$name,$wins,$losses;
}

$sth->finish();
$dbh->disconnect();
