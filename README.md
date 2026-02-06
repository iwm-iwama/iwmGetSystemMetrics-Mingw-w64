【実行に必要なファイル】

	iwmGetSystemMetrics.exe

【このプログラムについて】

	DOSプロンプトでWin32APIのGetSystemMetrics関数を実行（指定したシステムメトリックまたはシステム構成設定を取得）するコマンドです。

	(例１) 全取得
		iwmGetSystemMetrics.exe -all

	(例２) 指定して取得
		iwmGetSystemMetrics.exe -id=SM_CXSCREEN,SM_CYSCREEN
