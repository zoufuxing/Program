#!/usr/bin/perl -w
use strict;
use  Net::SSH::Perl;
use  Net::SCP::Expect;

#my $ssh = Net::SSH::Perl->new('192.168.65.20');
my $net_ssh=Net::SCP::Expect->new;
$net_ssh->login('root','shopex');
$net_ssh->scp('gexec-0.3.7.tar.gz root@192.168.65.20:/opt');
