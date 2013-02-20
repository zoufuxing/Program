#!/usr/bin/perl -w
use strict;
use File::Find;

#1307432288.174      0 82.231.182.223 TCP_MEM_HIT/200 27825 GET http://img.utcbag.com/utcbag/index/p/G481190055.jpg - NONE/- image/jpeg
my $my_reg=qr{^(?:\d+.\d+)\s+\d+\s+(?:[0-9.]+)\s+(?:\w+\/\d+)\s+(\d+)\s+(?:\w+)\s(?:http://)([a-zA-Z0-9-.]+)(.*)};
#my $my_reg=qr{^(?:\d+.\d+)\s+\d+\s+(?:[0-9.]+)\s+(?:\w+\/\d+)\s+(\d+)\s+(?:\w+)\s(?:http://)([a-zA-Z0-9.]+(com|cn|net|org))(.*)};
my $file_dir;
my @file_list;
my $my_date=`date '+%Y-%m-%d'`;
chomp($my_date);

if($ARGV[0]){
   $file_dir=$ARGV[0];
}else{
   $file_dir="/data1/ka_squid_log/analyze/$my_date";	
}

#解压日志文件
system("/opt/scripts/Extract_tar_for_count_flow.sh $file_dir");

#LOG funciton
sub log_fun{
   my $log_context=shift;
   open LOG_FILE,">>/opt/squid_148_count.txt";
   print LOG_FILE  "$log_context\n";
}

&log_fun("$my_date");

find(\&wanted,"$file_dir");
sub wanted{
    push @file_list,"$File::Find::name" if(-f $_);
}


#主处理流程
foreach my $analyze_log_file (@file_list){
&analyze_log($analyze_log_file);
}

sub analyze_log{
#文件名以参数的形式传入
my $file_name=shift;
 
my $count=0;
my %squid_flow;
chomp($file_name);
#打开日志文件
open SQUID_FLOW,"$file_name";
#my $i=0;
my ($match_size,$match_domain);
while(<SQUID_FLOW>){
    ($match_size,$match_domain) = ($1,$2) if /$my_reg/;
    #print "$match_domain===>$match_size\n";
    #print "$1===$2\n" if(($1)&&($2));
    next if((!$match_domain)||(!$match_size));
    #$squid_flow{$match_domain} = $match_size + $squid_flow{$match_domain} if (($match_domain)&&($match_size));
    $squid_flow{$match_domain} = $match_size + $squid_flow{$match_domain};
    #sleep 1
}

#print
foreach my $key (keys %squid_flow){
    $count = $squid_flow{$key}/1024/1024/1024 if($squid_flow{$key});
    #print LOG_FILE "$key\t\t$count Gbit\n";
    &log_fun("$key\t\t$count Gbit");
}
    close SQUID_FLOW;
}

&log_fun(" "); 
close LOG_FILE;
