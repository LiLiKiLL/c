#include "stdlib.h"
#include "stdio.h"
 
int main()
{
    int i;   //用作循环计数
    unsigned char ch[100];  //用来存储wav文件的头信息
    FILE *fp;
 
    fp=fopen("./music/esp.wav","rb");//为读，打开一个wav文件
 
    if((fp=fopen("./music/esp.wav","rb"))==NULL) //若打开文件失败，退出
    {
        printf("can't open this file\n");
        exit(0);
    }
 
/**********输出wav文件的所有信息**********/
    printf("该wav文件的所有信息:");
    for(i=0;i<58;i++)
    {
        ch[i]=fgetc(fp); //每次读取一个字符，存在数组ch中
        if(i%16==0)      //每行输出16个字符对应的十六进制数
            printf("\n");
        if(ch[i]<16)     //对小于16的数，在前面加0，使其用8bit显示出来
            printf("0%x ",ch[i]);   
        else
        printf("%x ",ch[i]);
    }
 
/*********RIFF WAVE Chunk的输出*********/
    printf("\n\nRIFF WAVE Chunk信息:");
//输出RIFF标志
    printf("\nRIFF标志:");
    for(i=0;i<4;i++)
    {
        printf("%x ",ch[i]);
    }
 
//输出size大小
    printf("\nsize:ox");
    for(i=7;i>=4;i--) //低字节表示数值低位，高字节表示数值高位
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出WAVE标志
    printf("\nWAVE标志:");
    for(i=8;i<12;i++)
    {
        if(ch[i]<16)
            printf("0%x ",ch[i]);
        else
        printf("%x ",ch[i]);
    }
 
/*******Format Chunk的输出*******/
    printf("\n\nFormat Chunk信息:");
//输出fmt 标志
    printf("\nfmt 标志:");
    for(i=12;i<16;i++)
    {
        if(ch[i]<16)
            printf("0%x ",ch[i]);
        else
        printf("%x ",ch[i]);
    }
 
//输出size段 
    printf("\nsize:ox");
    for(i=19;i>15;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出编码方式
    printf("\n编码方式:ox");
    for(i=21;i>19;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出声道数目
    printf("\n声道数目:ox");
    for(i=23;i>21;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
     
    if(ch[i+1]==1)   //1表示单声道，2表示双声道
        printf(" 单声道");
    else
        printf(" 双声道");
 
//输出采样频率 
    printf("\n采样频率:ox");
    for(i=27;i>23;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出每秒所需字节数 
    printf("\n每秒所需字节数:ox");
    for(i=31;i>27;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出数据块对齐单位 
    printf("\n数据块对齐单位:ox");
    for(i=33;i>31;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出每个采样所需bit数 
    printf("\n每个采样所需bit数:ox");
    for(i=35;i>33;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出附加信息
    if(ch[16]==18)  //若Format Chunk的size大小为18，则该模块的最后两个字节为附加信息
    {               //若为16，则无附加信息
        printf("\n附加信息:ox");
        for(i=37;i>35;i--)
        {
            if(ch[i]<16)
                printf("0%x",ch[i]);
            else
                printf("%x",ch[i]);
        }
    }
     
/*******Fact Chunk的输出*******/
    printf("\n\nFact Chunk信息:");
//输出fact标志 
    printf("\nfact标志:");
    for(i=38;i<42;i++)
    {
        if(ch[i]<16)
            printf("0%x ",ch[i]);
        else
        printf("%x ",ch[i]);
    }
     
//输出size 
    printf("\nsize:ox");
    for(i=45;i>41;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
//输出data段数据
    printf("\ndata段数据:");
    for(i=46;i<50;i++)
    {
        if(ch[i]<16)
            printf("0%x ",ch[i]);
        else
        printf("%x ",ch[i]);
    }
 
/*******Data Chunk的输出*******/
    printf("\n\nData Chunk信息:");
//输出data标志
    printf("\ndata标志:");
    for(i=50;i<54;i++)
    {
        if(ch[i]<16)
            printf("0%x ",ch[i]);
        else
        printf("%x ",ch[i]);
    }
 
//输出数据大小
    printf("\n数据大小:ox");
    for(i=57;i>53;i--)
    {
        if(ch[i]<16)
            printf("0%x",ch[i]);
        else
        printf("%x",ch[i]);
    }
 
    printf("\n");
 
    fclose(fp);
}