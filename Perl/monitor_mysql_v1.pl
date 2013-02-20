#!/usr/bin/perl -w

#---------------------------------#
#     author:zoufuxing            #
#     date:2012-05-23             #
#     version:v1.0                #
#---------------------------------#


use strict;
use DBI;
#For XML parse
use XML::Simple;
use Data::Dumper;
use Getopt::Long;

my $xml_file='/root/perl_test/test1.xml';


my $xml=new XML::Simple;
my $data=$xml->XMLin($xml_file);
#debug
#print Dumper($data);


my $parse_name='';
#my $parse_name='mysql3306_0_231';
my $mopt='';
my $status_name;

sub help_info()
{
  print("Useage:$0 --parse_name=[hostname] --mopt=[QPS|select|etc..] --status_name=[global_status|variable_status]\n");
  exit(22);
}

GetOptions('parse_name=s'=>\$parse_name,
           'mopt=s'=>\$mopt,
	   'status_name=s'=>\$status_name);



#默认取global status的状态值
$status_name='global_status' if(!$status_name);

#判断两个参数是否为空，如果为空，打印帮助，并且退出程序。
if((!$parse_name) || (!$mopt) )
{
   &help_info();
}


#解析xml，并将结果以hash引用返回，以便在后续使用中，直接可以使用。
sub get_xml_info()
{
  my $name = shift;
  return \%{$data->{host}->{$name}};
}

#连接Mysql，并获取相关运行状态信息
#这个函数返回值是指定的某个状态的值，如：在调用函数的时候&get_mysql_info(‘Uptime‘)，那么最后返回的就是Uptime的值。
#指定的状态，必须是执行MySQL语句“show global status”中的状态。
sub get_mysql_info()
{
  my $mysql_status=shift;
  my $get_status=shift;
  my $sql_stament;

  print("\$mysql_status=$mysql_status\n");
  print("\$get_status=$get_status\n");

#检查参数是否为空，如果为空的话，提示退出
  if(!$get_status)
  {
     print("Please input \$get_status\n");
     exit(55);
  }elsif(!$mysql_status){
	 print("Please input \$mysql_status\n"); 
	 exit(66);
  }


#检查输入的mysql_status参数，如果$mysql_status=global_status的话，就执行“show global status”，如果$mysql_status=variable_status
#就执行“show global variables”，如果不符合，提示退出
  if($mysql_status =~  /global_status/)
  {
     $sql_stament = qq(show global status);
  }elsif($mysql_status =~ /variable_status/){
     $sql_stament = qq(show global variables);
  }else{
    print("Please input corrent variable:--status_name='[global_status|variable_status]'\n");
    exit(44);
  }

  my ($key,$value);

#调用函数get_xml_info(),函数返回的是一个哈希引用
  my $parse_get_info=&get_xml_info($parse_name);
#debug
#print Dumper($parse_get_info);
  my %return_hash;

#由于get_xml_info()返回的哈希引用，所以，可以直接使用。
  my ($ip,$user,$pw,$port)=($parse_get_info->{ip},$parse_get_info->{user},$parse_get_info->{pw},$parse_get_info->{port});

#connect mysql
  my $dbh=DBI->connect(qq(DBI:mysql:database=mysql;host=$ip;user=$user;password=$pw;port=$port)) or die "Can't connect Database\n";

#  my $sth=$dbh->prepare("show global status");
  my $sth=$dbh->prepare($sql_stament);

  $sth->execute();

  while(my $row=$sth->fetchrow_hashref)
  {
   #将取到的状态值，存放在一个hash里。
   #print("$row->{Variable_name} => $row->{Value}\n");
   $key = $row->{Variable_name};
   $value = $row->{Value};
   $return_hash{$key} = $value;
  }

  $sth->diconnect();

#这里主要是确保要取值的状态是正确的，必须是Variable_name的值，例如，如果要得出Uptime的值，必须拼写正确，否则就提示退出。
#$check_tag是一个标志，如果有匹配项，$check_tag=1,否则$check_tag = 0。
my $check_tag = 0;

  foreach my $check_get_status(keys %return_hash)
  {
    #$check_tag = 1 if($get_status =~ /$check_get_status/);
    $check_tag = 1 if($get_status eq $check_get_status);
  }

#如果$check_tag = 0，则表明无法匹配，无法取到相关状态的值，提示退出！
  if(!$check_tag)
  {
    print("Can't get status:$get_status\n");
    exit(77);
  }

   print("$return_hash{$get_status}\n");
   return $return_hash{$get_status};
}




sub get_qps()
{
  my $qps;
  my $old_status=&get_mysql_info($status_name,'Queries'); 
  my $old_time=&get_mysql_info($status_name,'Uptime');
  sleep(3);
  my $new_status=&get_mysql_info($status_name,'Queries');  
  my $new_time=&get_mysql_info($status_name,'Uptime');

  #print("0\n"); if( ($new_status - $old_status) == 0 );

  if( ($new_status) && ($new_time) && ($old_status) && ($old_time) )
  {
    $qps=($new_status - $old_status)/( $new_time - $old_time);
  }
  print("$qps\n");
}

&get_qps;
