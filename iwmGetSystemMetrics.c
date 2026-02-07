//------------------------------------------------------------------------------
#define   IWM_COPYRIGHT       "(C)2026 iwm-iwama"
#define   IWM_FILENAME        "iwmGetSystemMetrics"
#define   IWM_UPDATE          "20260207"
//------------------------------------------------------------------------------
#include "lib_iwmutil2.h"

INT       main();
VOID      print_version();
VOID      print_help();

/*
	GetSystemMetrics 関数
	https://learn.microsoft.com/ja-jp/windows/win32/api/winuser/nf-winuser-getsystemmetrics
*/
MS *SM[] = {
	"54", "SM_CXMENUSIZE", "複数のドキュメントインターフェイスで使用される子ウィンドウの閉じるボタンなどのメニューバーボタンの幅。",
	"55", "SM_CYMENUSIZE", "複数のドキュメントインターフェイスで使用される子ウィンドウの閉じるボタンなどのメニューバーボタンの高さ。",
	"82", "SM_IMMENABLED", "入力メソッドマネージャー／入力メソッドエディター機能が有効なときは0以外、それ以外は0。",
	"38", "SM_CXICONSPACING", "大きなアイコンビューの項目のグリッドセルの幅。",
	"39", "SM_CYICONSPACING", "大きなアイコンビューの項目のグリッドセルの高さ。",
	"91", "SM_MOUSEHORIZONTALWHEELPRESENT", "水平スクロールホイールを持つマウスがインストールされているときは0以外。それ以外は0。",
	"21", "SM_CXHSCROLL", "水平スクロールバー上の矢印ビットマップの幅。",
	"3", "SM_CYHSCROLL", "水平スクロールバーの高さ。",
	"10", "SM_CXHTHUMB", "水平スクロールバーのサムボックスの幅。",
	"75", "SM_MOUSEWHEELPRESENT", "垂直スクロールホイールを持つマウスがインストールされているときは0以外。それ以外は0。",
	"20", "SM_CYVSCROLL", "垂直スクロールバー上の矢印ビットマップの高さ。",
	"2", "SM_CXVSCROLL", "垂直スクロールバーの幅。",
	"9", "SM_CYVTHUMB", "垂直スクロールバーのサムボックスの高さ。",
	"52", "SM_CXSMSIZE", "小さなキャプションボタンの幅。",
	"53", "SM_CYSMSIZE", "小さなキャプションボタンの高さ。",
	"51", "SM_CYSMCAPTION", "小さなキャプションの高さ。",
	"57", "SM_CXMINIMIZED", "最小化されたウィンドウの幅。",
	"58", "SM_CYMINIMIZED", "最小化されたウィンドウの高さ。",
	"47", "SM_CXMINSPACING", "最小化されたウィンドウのグリッドセルの幅。",
	"48", "SM_CYMINSPACING", "最小化されたウィンドウのグリッドセルの高さ。",
	"71", "SM_CXMENUCHECK", "既定のメニューチェックビットマップの幅。",
	"72", "SM_CYMENUCHECK", "既定のメニューチェックビットマップの高さ。",
	"78", "SM_CXVIRTUALSCREEN", "仮想画面の幅。",
	"77", "SM_YVIRTUALSCREEN", "仮想画面の上部の座標。",
	"76", "SM_XVIRTUALSCREEN", "仮想画面の左側の座標。",
	"79", "SM_CYVIRTUALSCREEN", "仮想画面の高さ。",
	"70", "SM_SHOWSOUNDS", "ユーザーがアプリケーションで情報を視覚的に提示する必要がある場合、それ以外は可聴形式でのみ情報を提示する必要があるときは0以外。それ以外は0。",
	"43", "SM_CMOUSEBUTTONS", "マウス上のボタンの数。",
	"68", "SM_CXDRAG", "マウスポインターがドラッグ操作を開始する前に移動できる、マウスの下向きポイントの両側のピクセル数。",
	"23", "SM_SWAPBUTTON", "マウスの左右のボタンの意味が入れ替わるときは0以外。それ以外は0。",
	"19", "SM_MOUSEPRESENT", "マウスがインストールされているときは0以外。それ以外は0。",
	"16", "SM_CXFULLSCREEN", "プライマリディスプレイモニターの全画面表示ウィンドウのクライアント領域の幅。",
	"17", "SM_CYFULLSCREEN", "プライマリディスプレイモニターの全画面表示ウィンドウのクライアント領域の高さ。",
	"61", "SM_CXMAXIMIZED", "プライマリディスプレイモニターの最大化されたトップレベルウィンドウの既定の幅。",
	"62", "SM_CYMAXIMIZED", "プライマリディスプレイモニターの最大化されたトップレベルウィンドウの既定の高さ。",
	"0", "SM_CXSCREEN", "プライマリディスプレイモニターの画面の幅。",
	"1", "SM_CYSCREEN", "プライマリディスプレイモニターの画面の高さ。",
	"63", "SM_NETWORK", "ネットワークが存在するときは最下位ビットが設定されます。それ以外はクリアされます。",
	"40", "SM_MENUDROPALIGNMENT", "ドロップダウンメニューが対応するメニューバー項目と右揃えのときは0以外。メニューが左揃えのときは0。",
	"69", "SM_CYDRAG", "ドラッグ操作が開始される前にマウスポインターが移動できる、マウスの上下のピクセル数。",
	"80", "SM_CMONITORS", "デスクトップ上のディスプレイモニターの数。",
	"36", "SM_CXDOUBLECLK", "ダブルクリックシーケンス内の最初のクリックの位置を囲む四角形の幅。",
	"37", "SM_CYDOUBLECLK", "ダブルクリックシーケンスでの最初のクリックの位置を中心とした四角形の高さ。",
	"81", "SM_SAMEDISPLAYFORMAT", "すべてのディスプレイモニターの色形式が同じときは0以外、それ以外は0。",
	"67", "SM_CLEANBOOT", "システムの起動方法を示す値。0:標準ブート、1:フェールセーフブート、2:ネットワークブート。",
	"11", "SM_CXICON", "システムのアイコンの大きな幅。",
	"18", "SM_CYKANJIWINDOW", "システムの2バイト文字セットバージョンの場合、漢字ウィンドウの高さです。",
	"56", "SM_ARRANGE", "システムによって最小化されたウィンドウの配置方法を指定するフラグ。",
	"95", "SM_MAXIMUMTOUCHES", "システムにデジタイザーがあるときは0以外。それ以外は0。",
	"74", "SM_MIDEASTENABLED", "システムがヘブライ語とアラビア語に対して有効になっているときは0以外。それ以外は0。",
	"32", "SM_CXSIZEFRAME", "サイズを変更できるウィンドウの周囲のサイズ変更境界線の太さ。",
	"33", "SM_CYSIZEFRAME", "サイズを変更できるウィンドウの周囲のサイズ変更境界線の太さ。",
	"73", "SM_SLOWMACHINE", "コンピューターにローエンド(低速)プロセッサがあるときは0以外。それ以外は0。",
	"44", "SM_SECURE", "このシステムメトリックは無視する必要があります。常に0を返します。",
	"4", "SM_CYCAPTION", "キャプション領域の高さ。",
	"92", "SM_CXPADDEDBORDER", "キャプション付きウィンドウの罫線のパディングの量。",
	"7", "SM_CXFIXEDFRAME", "キャプションを持つが、ピクセル単位ではサイズが大きくないウィンドウの周囲のフレームの太さ。",
	"8", "SM_CYFIXEDFRAME", "キャプションを持つが、ピクセル単位ではサイズが大きくないウィンドウの周囲のフレームの太さ。",
	"59", "SM_CXMAXTRACK", "キャプションとサイズ変更の境界線を持つウィンドウの既定の最大幅。",
	"60", "SM_CYMAXTRACK", "キャプションとサイズ変更の境界線を持つウィンドウの既定の最大高さ。",
	"13", "SM_CXCURSOR", "カーソルの標準幅。",
	"14", "SM_CYCURSOR", "カーソルのわずかな高さ。",
	"28", "SM_CXMIN", "ウィンドウの最小幅。",
	"34", "SM_CXMINTRACK", "ウィンドウの最小追跡幅。",
	"35", "SM_CYMINTRACK", "ウィンドウの最小追跡高さ。",
	"29", "SM_CYMIN", "ウィンドウの最小高さ。",
	"5", "SM_CXBORDER", "ウィンドウの境界線の幅。",
	"6", "SM_CYBORDER", "ウィンドウの境界線の高さ。",
	"30", "SM_CXSIZE", "ウィンドウキャプションまたはタイトルバー内のボタンの幅。",
	"31", "SM_CYSIZE", "ウィンドウキャプションまたはタイトルバー内のボタンの高さ。",
	"12", "SM_CYICON", "アイコンのシステムの大きな高さ。",
	"49", "SM_CXSMICON", "アイコンのシステムの小さな幅。",
	"50", "SM_CYSMICON", "アイコンのシステムの小さな高さ。",
	"86", "SM_TABLETPC", "WindowsXP／WindowsVista／Windows7でタブレットPC入力サービスが開始されているときは0以外。それ以外は0。",
	"87", "SM_MEDIACENTER", "WindowsXP／MediaCenterEditionのときは0以外。そうでないときは0。",
	"89", "SM_SERVERR2", "WindowsServer2003R2の場合のビルド番号。それ以外は0。",
	"88", "SM_STARTER", "Windows7StarterEdition／WindowsVistaStarter／WindowsXPStarterEditionのときは0以外。それ以外は0。",
	"94", "SM_DIGITIZER", "Windows7／WindowsServer2008R2でタブレットPC入力サービスが開始されているときは0以外。それ以外は0。",
	"42", "SM_DBCSENABLED", "User32.dllがDBCSをサポートするときは0以外。それ以外は0。",
	"22", "SM_DEBUG", "User.exeのデバッグバージョンがインストールされているときは0以外。それ以外は0。",
	"41", "SM_PENWINDOWS", "MicrosoftWindowsforPenコンピューティング拡張機能がインストールされているときは0以外。それ以外は0。",
	"84", "SM_CYFOCUSBORDER", "DrawFocusRectによって描画されるフォーカス四角形の上端と下端の高さ。",
	"83", "SM_CXFOCUSBORDER", "DrawFocusRectが描画するフォーカス四角形の左右の端の幅。",
	"45", "SM_CXEDGE", "3-D境界線の幅。このメトリックは、SM_CXBORDERに対応する3-Dです。",
	"46", "SM_CYEDGE", "3-D境界線の高さ。",
	"15", "SM_CYMENU", "1行のメニューバーの高さ。",
	NULL, NULL, NULL
};

INT
main()
{
	// lib_iwmutil2 初期化
	imain_begin();

	///iCLI_VarList();

	// -h | --help
	if(! $ARGC || iCLI_getOptMatch(0, L"-h", L"--help"))
	{
		print_version();
		print_help();
		imain_end();
	}

	// -v | --version
	if(iCLI_getOptMatch(0, L"-v", L"--version"))
	{
		print_version();
		imain_end();
	}

	WS *wp1 = 0;

	for(UINT _u1 = 0; _u1 < $ARGC; _u1++)
	{
		// -key=
		if((wp1 = iCLI_getOptValue(_u1, L"-key=", NULL)))
		{
			WS **wa1 = iwsa_split(wp1, FALSE, 3, L",", L"\"", L"'");
				for(UINT _u2 = 0, _u3 = iwan_size(wa1); _u2 < _u3; _u2++)
				{
					MS *ms1 = W2M(wa1[_u2]);
						for(UINT _u4 = 0; SM[_u4]; _u4+=3)
						{
							if(! strcmp(SM[_u4 + 1], ms1))
							{
								P("%s\t%d\t%s\n",
									SM[_u4 + 1],
									GetSystemMetrics(atoi(SM[_u4])),
									SM[_u4 + 2]
								);
							}
						}
					ifree(ms1);
				}
			ifree(wa1);
		}
		// -a | -all
		if(iCLI_getOptMatch(_u1, L"-a", L"-all"))
		{
			$struct_iVBM *iVBM = iVBM_alloc();
				for(UINT _u2 = 0; SM[_u2]; _u2+=3)
				{
					// iVBM_push_sprintf(iVBM, "%s\t%d\t%s\n", ...) より約５％速い
					iVBM_push2(iVBM, SM[_u2 + 1]);
					iVBM_push(iVBM, "\t", 1);
					iVBM_push_sprintf(iVBM, "%d", GetSystemMetrics(atoi(SM[_u2])));
					iVBM_push(iVBM, "\t", 1);
					iVBM_push2(iVBM, SM[_u2 + 2]);
					iVBM_push(iVBM, "\n", 1);
				}
				P1(iVBM_getStr(iVBM));
			iVBM_free(iVBM);
		}
	}

	// 処理時間
	///P("-- %.3fsec\n\n", iExecSec_next());

	// Debug
	///idebug_map(); ifree_all(); idebug_map();

	// 最終処理
	imain_end();
}

VOID
print_version()
{
	P1(IESC_STR2);
	LN(60);
	P1(
		"\033[2G"	IWM_COPYRIGHT	"\n"
		"\033[5G"	IWM_FILENAME	"_"	IWM_UPDATE	" + "	LIB_IWMUTIL_FILENAME	"\n"
	);
	LN(60);
	P1(IESC_RESET);
}

VOID
print_help()
{
	P1(
		"\033[1G"	IESC_TITLE1 " サンプル "	IESC_RESET	"\n"
		"\n"
		"\033[5G"	IESC_STR1	IWM_FILENAME	IESC_OPT2	" [Option]"	"\n"
		"\n"
		"\033[2G"	IESC_LBL1	"(例)"	"\n"
		"\033[5G"	IESC_STR1	IWM_FILENAME	IESC_OPT2	" -key=SM_CXSCREEN,SM_CYSCREEN"	"\n"
		"\n"
		"\033[2G"	IESC_OPT2	"[Option]"	"\n"
		"\033[5G"	IESC_OPT21	"-all | -a"	"\n"
		"\033[9G"	IESC_STR1	"全情報出力"	"\n"
		"\n"
		"\033[5G"	IESC_OPT21	"-key=Key1,Key2,..."	"\n"
		"\033[9G"	IESC_LBL2	"[Key]"	IESC_STR1	" 情報出力"	"\n"
		"\n"
		"\033[2G"	IESC_LBL2	"[Key]"	IESC_STR2	"\n"
	);

	for(UINT _u1 = 0; SM[_u1]; _u1+=3)
	{
		P1("\033[5G");
		P1(SM[_u1 + 1]);
		P1("\033[37G");
		P1(SM[_u1 + 2]);
		P1("\n");
	}
	P1(IESC_STR2);
	LN(60);
	P1(IESC_RESET);
}
