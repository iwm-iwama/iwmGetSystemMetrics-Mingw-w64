【実行に必要なファイル】

	iwmGetSystemMetrics.exe

【このプログラムについて】

	DOSプロンプトでWin32APIのGetSystemMetrics関数を実行し、
	指定したシステムメトリックまたはシステム構成設定を取得するコマンドです。

	(例１) 全取得
		iwmGetSystemMetrics.exe -all

	(例２) 指定して取得
		iwmGetSystemMetrics.exe -key=SM_CXSCREEN,SM_CYSCREEN
