#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


int main(int argc,char*argv[])
{
  FILE *fp;
  int i,se,c,ques,ans,fr;
  char jp[256],ch[256],pin[256],fname[256],ll1[256]="data/",ll2[256]=".txt";

  srand((unsigned int)time(NULL));


  printf("ファイル名を入力してください：");
  scanf("%s",fname);
  strcat(ll1, fname);
  strcat(ll1, ll2);
  printf("問題形式　日本語>>1:中国語>>2:ピンイン>>3\n>>");
  scanf("%d",&ques);
  printf("回答形式　日本語>>1:中国語>>2:ピンイン>>3\n>>");
  scanf("%d",&ans);
  printf("ランダムモード>>1:連続モード>>2\n>>");
  scanf("%d",&fr);
  if(fr==2){
    fp=fopen(ll1,"r+");
    if(fp == NULL) {
      return -1;
    }
    fscanf(fp,"%d",&i);
    while(i!=0){
      fscanf(fp,"%s",jp);
      fscanf(fp,"%s",ch);
      fscanf(fp,"%s",pin);
      if(ques==1){printf("「%s」の",jp);}
      else if(ques==2){printf("「%s」の",ch);}
      else if(ques==3){printf("「%s」の",pin);}

      if(ans==1){
        printf("日本語は？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",jp);
      }
      else if(ans==2){
        printf("中国語は？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",ch);
      }
      else if(ans==3){
        printf("ピンインは？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",pin);
      }
      
      i--;
      rewind(stdin);
      if ((c = getchar()) == '\n'){}
    }
    fclose(fp);
  }

  if(fr==1){
    while(1){
      fp=fopen(ll1,"r+");
      if(fp == NULL) {
        return -1;
      }
      fscanf(fp,"%d",&i);
      se=rand()%(i-1+1)+1;
      printf("%d\n",se);

      for(i=0;i<se;i++){
        fscanf(fp,"%s",jp);
        fscanf(fp,"%s",ch);
        fscanf(fp,"%s",pin);
      }
      if(ques==1){printf("「%s」の",jp);}
      if(ques==2){printf("「%s」の",ch);}
      if(ques==3){printf("「%s」の",pin);}

      if(ans==1){
        printf("日本語は？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",jp);
      }
      if(ans==2){
        printf("中国語は？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",ch);
      }
      if(ans==3){
        printf("ピンインは？");
        rewind(stdin);
        if ((c = getchar()) == '\n')
        printf("答え：「%s」\n",pin);
      }
      fclose(fp);
      rewind(stdin);
      if ((c = getchar()) == '\n'){}
    }
  }
  return 0;
}
