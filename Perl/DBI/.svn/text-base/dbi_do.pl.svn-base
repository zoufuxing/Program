#!/usr/bin/perl -w
use strict;
use DBI;
use Data::Dumper;

my $dbh=DBI->connect("DBI:mysql:database=sample_db;host=192.168.10.153;user=sample;password=sample") or die "Can't connect:".DBI->errstr;

my ($name,$num,$ans);

print "Enter the team name you want to delete: ";
chomp($name=<STDIN>);

my $sth=$dbh->prepare("select count(*) from teams where name = ?");
$sth->execute($name);

print "Number of rows to be deleted: ",$sth->fetchrow_array(),"\n";
#print "Number of rows to be deleted: ",$sth->rows,"\n";
print "Continue? ";
chomp($ans=<STDIN>);
$ans=lc($ans);

if($ans =~ /y|yes/)
{
    $num=$dbh->do(qq/delete from teams where name = ?/,undef,$name);
    print ($num > 1 ? "$num rows deleted" : "$num row deleted.\n");
}else
{
    die "You have not choosen to delete any entries.Good-bye.\n";
}

$sth->finish();
$dbh->disconnect();
