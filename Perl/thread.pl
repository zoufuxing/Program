#!/usr/bin/perl -w
use strict;
use threads;
use threads::shared;

$| = 1;
my $flag : shared = 0;

&printInfo();

sub printInfo()
{
  print("Start get remote file\n");
  my $thread_1 = threads->create(\&wait);
  while(1)
  {
    sleep(1);
    print(".");
    $flag && last;
  }
  $thread_1->join();
  print("\n");
}

sub wait()
{
  sleep(10);
  $flag = 1;
}
