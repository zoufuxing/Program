#!/usr/bin/perl -w
use strict;
use Getopt::Long;

my $name='';
my $opt='';

GetOptions('name=s'=>\$name);

if(!$name)
{
  print("Please Specified the name!\n");
  exit(22);
}

print("$name\n");
