#!/usr/bin/perl -w
use strict;

sub handler{
    my $sig = @_;
    print("Caught SIG $sig -- shutting down now\n");
    exit(22);
}

$SIG{'INT'} = 'handler';
print("Here I am \n");
