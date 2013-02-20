#!/usr/bin/perl -w
use strict;
use DBI;

my $dbh=DBI->connect(qq(DBI:mysql:host=192.168.10.153;database=sample_db;user=sample;password=sample)) or die "Can't connect Database!\n";

my $sth=$dbh->prepare("select name,wins,losses from teams");

$sth->execute();
print "Contents of sample_db,the mysql database.\n\n";

while(my @row=$sth->fetchrow_array())
{
  print "name=$row[0]\n";
  print "wins=$row[1]\n";
  print "losses=$row[2]\n";
}

print $sth->rows,"rows were retrieved.\n";

$sth->finish();
$dbh->disconnect();
