#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


int main(int argc,char*argv[])
{
  FILE *fp;
  int i=0,se,c,ques,ans,fr;
  char jp[256],ch[256],pin[256],fname[256],ll1[256]="data/",ll2[256]=".txt";

  srand((unsigned int)time(NULL));

  printf("ファイル名を入力してください：");
  scanf("%s",fname);
  //ファイルのパスの結合
  //data/<入力ファイル名>.txt
  strcat(ll1, fname);
  strcat(ll1, ll2);

  printf("問題形式　日本語>>1:中国語>>2:ピンイン>>3\n>>");
  scanf("%d",&ques);//問題形式の選択
  printf("回答形式　日本語>>1:中国語>>2:ピンイン>>3\n>>");
  scanf("%d",&ans);//回答形式の選択
  printf("ランダムモード>>1:連続モード>>2\n>>");
  scanf("%d",&fr);//連続回答種類の選択

  if(ques==ans){//問題形式と回答形式が同じ時、終了
    return -1;
  }
  if(ques!=1&&ques!=2&&ques!=3){//問題形式が1、2、3以外の時、終了
    return -1;
  }
  if(ans!=1&&ans!=2&&ans!=3){//回答形式が1、2、3以外の時、終了
    return -1;
  }

  if(fr!=1&&fr!=2){//連続回答種類が1、2以外の時、終了
    return -1;
  }

  if(fr==2){//連続回答種類が連続モードの時
    fp=fopen(ll1,"r+");//ファイルを開く
    if(fp == NULL) {//ファイルが開ない場合終了
      return -1;
    }
    fscanf(fp,"%d",&i);//1行目(データの数)の取得
    while(i!=0){//i(データの数)を減らしていき、0になるまでループ
      fscanf(fp,"%s",jp);//日本語データの取得
      fscanf(fp,"%s",ch);//中国語データの取得
      fscanf(fp,"%s",pin);//拼音データの取得

      if(ques==1){printf("「%s」の",jp);}//問題形式が日本語の時、日本語データの表示
      else if(ques==2){printf("「%s」の",ch);}//問題形式が中国語の時、中国語データの表示
      else if(ques==3){printf("「%s」の",pin);}//問題形式が拼音の時、拼音データの表示

      if(ans==1){printf("日本語は？");}//回答形式が日本語の時
      else if(ans==2){printf("中国語は？");}//回答形式が中国語の時
      else if(ans==3){printf("ピンインは？");}//回答形式が拼音の時

      rewind(stdin);//キーボード バッファのクリア
      c = getchar();//エンターキーが押されるまでプログラムを止める

      if(ans==1){printf("答え：「%s」\n",jp);}//回答形式が日本語の時、日本語データの表示
      else if(ans==2){printf("答え：「%s」\n",ch);}//回答形式が中国語の時、中国語データの表示
      else if(ans==3){printf("答え：「%s」\n",pin);}//回答形式が拼音の時、拼音データの表示

      i--;//次の問題へ
      rewind(stdin);//キーボード バッファのクリア
      c = getchar();//エンターキーが押されるまでプログラムを止める
    }
    fclose(fp);//ファイルを閉じる
  }

  if(fr==1){//連続回答種類がランダムモードの時
    while(1){//強制終了されるまで無限ループ
      fp=fopen(ll1,"r+");//繰り返す毎に開きなおす
      if(fp == NULL) {//ファイルが開ない時、終了
        return -1;
      }

      fscanf(fp,"%d",&i);//1行目(データの数)の取得
      se=rand()%(i-1+1)+1;//ランダムでデータの選択

      for(i=0;i<se;i++){//se番目のデータを取得
        fscanf(fp,"%s",jp);//日本語データの取得
        fscanf(fp,"%s",ch);//中国語データの取得
        fscanf(fp,"%s",pin);//拼音データの取得
      }

      if(ques==1){printf("「%s」の",jp);}//問題形式が日本語の時、日本語データの表示
      if(ques==2){printf("「%s」の",ch);}//問題形式が中国語の時、中国語データの表示
      if(ques==3){printf("「%s」の",pin);}//問題形式が拼音の時、拼音データの表示

      if(ans==1){printf("日本語は？");}//回答形式が日本語の時
      if(ans==2){printf("中国語は？");}//回答形式が中国語の時
      if(ans==3){printf("ピンインは？");}//回答形式が拼音の時

      rewind(stdin);//キーボード バッファのクリア
      c = getchar();//エンターキーが押されるまでプログラムを止める

      if(ans==1){printf("答え：「%s」\n",jp);}//回答形式が日本語の時、日本語データの表示
      else if(ans==2){printf("答え：「%s」\n",ch);}//回答形式が中国語の時、中国語データの表示
      else if(ans==3){printf("答え：「%s」\n",pin);}//回答形式が拼音の時、拼音データの表示


      fclose(fp);//ファイルを閉じる
      rewind(stdin);//キーボード バッファのクリア
      c = getchar();//エンターキーが押されるまでプログラムを止める
    }
  }
  return 0;
}
