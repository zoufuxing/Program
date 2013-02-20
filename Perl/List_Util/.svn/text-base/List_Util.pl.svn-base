#!/usr/bin/perl -w
use strict;
use Data::Dumper;
use List::Util qw(first max reduce);



my $foo = max 1 .. 10;
my $fi = first {defined($_)} 1 .. 10;
print("$foo\n");
print("$fi\n");


my $red = reduce { $a > $b ? $a : $b } 1 .. 10;
print("\$red=$red\n");
