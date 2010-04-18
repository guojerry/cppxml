#ifndef MP3_INFO_H
#define MP3_INFO_H

#pragma once

#include <streams.h>

/*MP3情報構造体(mpg123よりパクリ)*/
#define         MPG_MD_STEREO           0
#define         MPG_MD_JOINT_STEREO     1
#define         MPG_MD_DUAL_CHANNEL     2
#define         MPG_MD_MONO             3

typedef struct mp3info {
	int freq,nch;
	int lsf,frames;
	LONGLONG nbytes,hpos;
	REFERENCE_TIME duration;
} mp3info;

/*id3TAG用構造体*/
typedef struct id3tag {
	char tag[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	unsigned char genre;
} id3tag;

/*フレームの時間とファイル上のオフセットを記録する構造体。*/
typedef struct tagFRAMEINFO
{
	REFERENCE_TIME time;
	LONGLONG offset;
	LONG size;
	struct tagFRAMEINFO * before;
	struct tagFRAMEINFO * next;
} FRAMEINFO;

LONGLONG address2time(LONGLONG address);
LONGLONG time2address(LONGLONG time);
int head_check(unsigned long head);
int ExtractI4(unsigned char *buf);
unsigned int BSwap(unsigned int Num);
FRAMEINFO * time2frame(REFERENCE_TIME time);

#endif //!define MP3_INFO_H