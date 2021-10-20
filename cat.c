#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
   int fd,fd1,ret,ret1,ret2;
   char buf[10];
   if(argc!=3)
    {
      printf("invalid input\n");
      exit(0);
    }
    fd=open(argv[1],O_RDONLY);
    if(fd<0)
     {
       printf("fail to open\n");
       exit(1);
     }
      while(ret=read(fd,buf,9)<0)
      {
      if(ret<0)
      {
       printf("fail to read\n");
       exit(2);
      }
      buf[ret]='\0';
     }
      fd1=open(argv[2],O_CREAT|O_WRONLY,0660);
      if(fd1<0)
      {
       printf("fail to open another file\n");
       exit(3);
      }
    ret2=write(fd1,buf,strlen(buf));
    if(ret2<0)
     {
       printf("fail to write another file\n");
       exit(4);
     }
     close(fd);
     close(fd1);
}
