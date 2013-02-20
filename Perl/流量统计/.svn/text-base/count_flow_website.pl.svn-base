#!/usr/bin/perl -w
#------------------------------------#
#				     #
# 统计Nginx前端访问日志各站点的流量  #
# DATE：2011-06-09		     #
# Email：zoufuxing@shopex.cn	     #
# 统计结果单位：Gbit		     #
#------------------------------------#
use strict;
use File::Find;


my $domain_reg=qr{^(?:[0-9.]+)\s+-\s+-\s+\[([^]])+\]\s+"(?:[^"]+)"\s+(?:\d+)\s+(\d+)\s+"([^"]+)"\s+"(?:[^"]+)"};
my @file_list;
my @dir_list;
my $my_date=`date '+%Y-%m-%d'`;
chomp($my_date);
#my $my_date=chomp($tmp_date);
my $web_site;
my $log_dir;
#LOG 
open LOG_FILE,'>>/opt/website_count.txt';



#如果指定有日志的存放路径，则使用指定的路径，否则，用以当天日期为名的目录
if($ARGV[0]){
$log_dir=$ARGV[0];
}else{
$log_dir="/data1/ka_log_analyze/$my_date";
}

print "$log_dir";
#chomp($log_dir);


#LOG function
sub log_fun{
  my $log_context=shift;
  #open LOG_FILE,'>>/opt/website_count.txt';
  print LOG_FILE "$log_context\n";
}

system("/opt/scripts/Extract_tar_for_count_flow.sh $log_dir");


#print LOG_FILE "$my_date\n";

&log_fun("$my_date");

#列举指定目录里的文件名
#find(\&wanted,"/data1/ka_log_analyze/$my_date");
find(\&wanted,"$log_dir");
sub wanted{
#将文件的全路径写入数组中，往后的作为文件句柄直接打开，而无需再添加目录变量了。
   push @file_list,"$File::Find::name" if(-f $_);
}

#foreach (@dir_list){
#print ;
#print "\n";
#}

#日志分析函数
sub analyze_log(){

my $file_name=shift;
my $count=0;
my $result=0;
chomp($file_name);

open ANALYZE_FILE,"$file_name";
#open SKOMART,'cat /root/skomart.log|';
while(<ANALYZE_FILE>){
	my $num=$2 if /$domain_reg/;
	$count=$count+$num if ($num);
}

$web_site=$file_name;
#如果不匹配下面的规则，则用默认的文件名
$web_site='skomart' if($file_name =~ /skomart/);
$web_site='bbs.s.cn' if($file_name =~ /bbs.s.cn/);
$web_site='m.s.cn' if($file_name =~ /m_s_cn/);
$web_site='lusen'  if($file_name =~ /green3c/);
$web_site='utcbag'  if($file_name =~ /utcbag/);
$web_site='jockey'  if($file_name =~ /jockey/);
$web_site='hodbuy'  if($file_name =~ /hodbuy/);
$web_site='enwds'  if($file_name =~ /enwds/);


$result = $count/1024/1024/1024;
#print "$web_site : $result \n";
#print LOG_FILE "$web_site : $result G\n";
&log_fun("$web_site : $result Gbit");
close ANALYZE_FILE;
}


#程序主函数，对于目录中的文件逐一统计，通过循环，每次分析一个文件，分析函数逐一被调用。
foreach my $file_list (@file_list){
	#print "$file_list\n";
	&analyze_log($file_list);
}
#print LOG_FILE "\n";
&log_fun(" ");
close LOG_FILE;

