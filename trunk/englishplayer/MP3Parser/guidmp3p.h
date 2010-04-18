#ifndef GUID_MP3P_H
#define GUID_MP3P_H

///////////////////////////////////////////////////////////////////////////////
// Interface GUIDs
///////////////////////////////////////////////////////////////////////////////

/*メインのGUID*/
// {13CEBFE0-256B-44ba-A27B-9F85CBDB972D}
DEFINE_GUID(CLSID_CMp3Parser, 
0x13cebfe0, 0x256b, 0x44ba, 0xa2, 0x7b, 0x9f, 0x85, 0xcb, 0xdb, 0x97, 0x2d);

/*インターフェースのGUID*/
// {0FF200D8-4679-4ca6-ADCD-914433C09717}
DEFINE_GUID(IID_IMp3Parser, 
0xff200d8, 0x4679, 0x4ca6, 0xad, 0xcd, 0x91, 0x44, 0x33, 0xc0, 0x97, 0x17);

/*プロパティページのGUID*/
// {B281DDA0-5493-11d7-9DEE// {3B1DFB5E-7E04-42d6-8717-2E1B8039E11D}
DEFINE_GUID(CLSID_CMp3ParserPropertyPage, 
0x3b1dfb5e, 0x7e04, 0x42d6, 0x87, 0x17, 0x2e, 0x1b, 0x80, 0x39, 0xe1, 0x1d);

///////////////////////////////////////////////////////////////////////////////
// DATA GUIDs
///////////////////////////////////////////////////////////////////////////////

/*入力のサブタイプCLSID(MEDIASUBTYPE_MPEG1 Audio)*/
// {E436EB87-524F-11CE-9F53-0020AF0BA770}
DEFINE_GUID(CLSID_mpeg1audio,
0xE436EB87, 0x524F, 0x11CE, 0x9F, 0x53, 0x00, 0x20, 0xAF, 0x0B, 0xA7, 0x70);

/*出力のサブタイプCLSID(MEDIASUBTYPE_MPEG1 Packet)*/
// {E436EB80-524F-11CE-9F53-0020AF0BA770}
DEFINE_GUID(CLSID_mpeg1packet,
0xE436EB80, 0x524F, 0x11CE, 0x9F, 0x53, 0x00, 0x20, 0xAF, 0x0B, 0xA7, 0x70);

/*出力のサブタイプCLSID(MEDIASUBTYPE_MPEG1 AudioPayload)*/
// {00000050-0000-0010-8000-00AA00389B71}
DEFINE_GUID(CLSID_mpeg1audiopayload,
0x00000050, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71);

/*出力のサブタイプCLSID(MP3)*/
// {00000055-0000-0010-8000-00aa00389b71}
DEFINE_GUID(CLSID_mp3,
0x00000055, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

/*
//プロパティページから呼び出すものはここで宣言するらしい。
DECLARE_INTERFACE_(Imp3parse, IUnknown)
{

    STDMETHOD(get_id3tag) (THIS_
    				  id3tag *_id3
				 ) PURE;

};
*/

#endif
